/* This is a command-line clock in C, made with \r */

#include <stdio.h>
#include <time.h>

void delay(int number_of_milliseconds)
{
    int nanoseconds = 1000 * number_of_milliseconds;
    clock_t start_time = clock();
    while (clock() < start_time + nanoseconds);
}

int main (void) {
int timer;
while (1){
    fflush(stdout);
    timer = time(NULL) % (24 * 60 * 60);
    printf(" |  %.2d:%.2d:%.2d  |\r", timer / (60 * 60) + 3, timer / (60) % 60, timer % 60);
    delay(1000);

}
return 0;
}
