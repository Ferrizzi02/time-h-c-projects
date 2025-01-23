/*
This code is to experiment with the struct provided by the library, here we get the current time, converts to the struct
so we can print especific details about the date. for example the year or even the day
notice that we need to add +1900 to the year to convert to gregorian
also add +1 to month

*/
#include<stdio.h>
#include<time.h>
int main(){
    time_t current;
    struct tm *current_st;
    time(&current);
    current_st = localtime(&current);
    printf("ano: %d\n", current_st->tm_year +1900);
    printf("mes %d\n", current_st->tm_mon+1);
    printf("dia %d\n", current_st->tm_mday);
    printf("dia relacion ano %d\n", current_st->tm_yday);
    printf("whatever this is %d\n", current_st->tm_isdst);
    return 0;
}