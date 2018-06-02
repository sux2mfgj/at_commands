#include "drone.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int ARDRONE2_PORT = 5556;
const char* ARDRONE2_IP_ADDR = "192.168.1.1";

int sock;
struct sockaddr_in addr;
char content[30];
int sequence_number;

// 初期化処理
//  - AR.Drone2との接続.
int initialize_ardrone2(void)
{
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(ARDRONE2_PORT);
    addr.sin_addr.s_addr = inet_addr(ARDRONE2_IP_ADDR);

    sequence_number = 1;

    return sock;
}

// 終了処理
int finalize_ardrone2(void)
{
    landing();
    sleep(5);
    return close(sock);
}

static void send_instruction(char* content)
{
    sendto(sock, content, strlen(content), 0,
            (struct sockaddr*)&addr, sizeof(struct sockaddr));
}

void landing(void)
{
    const char* format = "AT*REF=%u,290717696\r";
    sprintf(content, format, sequence_number);
    send_instruction(content);
}

void take_off(void)
{
    const char* format = "AT*REF=%u,290718208\r";
    sprintf(content, format, sequence_number);
    send_instruction(content);
}
