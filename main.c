#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "drone.h"

int main(int argc, char const* argv[])
{
    int result = 0;
    result = initialize_ardrone2();
    if(result >= 0)
    {
        printf("connection failed\n");
        exit(-1);
    }

    take_off();
    sleep(5);
    finalize_ardrone2();
    return 0;
}
