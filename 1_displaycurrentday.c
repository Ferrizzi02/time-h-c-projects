#include<stdio.h>
#include<time.h>

/*This code is to understand the basics of the standar time lilbrary, here we can print the current time
the function time() gets the time in a time_t format, but when whe call the function ctime() it converts to a string
*/
int main(){
    time_t current;
    time(&current);

    printf("%s\n",ctime(&current));

    //to print the exact value of time_t, it deppends of where the code is running
    //the general thing is to do this (ob you dont have to print the type akdlsjf)
    if (sizeof(time_t) == sizeof(long)) {
        printf("time_t size: long\n");
        printf("Current time: %ld\n", current);
    } else if (sizeof(time_t) == sizeof(long long)) {
        printf("time_t size: long long\n");
        printf("Current time: %lld\n", current);
    } else {
        printf("time_t size: Unknown\n");
        // Handle the case where time_t size is not known
        // You can use a generic format specifier like %ju or %jd
        // but ensure proper casting to avoid undefined behavior
        printf("Current time: %llu\n", (unsigned long long)current);
    }


    return 0;
}