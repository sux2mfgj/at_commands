#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "drone.h"

int main(int argc, char const* argv[])
{
    int result = 0;
    result = initialize_ardrone2();
    if (result < 0) {
        printf("connection failed\n");
        exit(-1);
    }

    for (int i = 0; i < 5; ++i) {
        take_off();
        sleep(1);
    }
    for (int i = 0; i < 30; ++i) {
        hover();
        sleep(1);
    }
    /*
    for (int i = 0; i < 20; ++i) {
        //forward();
        left();
        usleep(100 * 1000);
    }
    for (int i = 0; i < 2; ++i) {
        hover();
        sleep(1);
    }
    */

    finalize_ardrone2();
    return 0;
}

/* for force landing
int main(int argc, char const* argv[])
{
    int result = 0;
    result = initialize_ardrone2();
    if(result < 0)
    {
        printf("connection failed\n");
        exit(-1);
    }
    finalize_ardrone2();
    return 0;
}
*/
