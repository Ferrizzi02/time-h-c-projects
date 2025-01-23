/*
In this code im testing some functions i found
*/
#include <stdio.h>
#include<time.h>

int main(){
    //clock(): return the tick of the clock
    clock_t start = clock(); //get te clock at the start (ticks)

    //get the current date and time() return the number of seconds since Unix Epoch
    time_t current;
    time(&current);

    //ctime() converts to string especifying  the week day, month, day, time with seconds and year 
    printf("%s", ctime(&current));

    /*localtime() converts to a struct the time_t: a bit complicated.
    localtime returns a pointer that points to a struct managed by the library, so it could be overwritten!
    do not call it two times if you need the first one again */

    struct tm *current_to_struct = localtime(&current);
    printf("this is the current day i got from localtime() %d\n", current_to_struct->tm_mday);

    //mktime() converts the struct of time into time_t (seconds since unix epoch);
    struct tm ExampleToTime_t = {0};
    ExampleToTime_t.tm_year = 2025 - 1900; //remember how in the first code i added 1900
    ExampleToTime_t.tm_mon = 0; //january, 1 = feb, 2= march, ...
    ExampleToTime_t.tm_mday =2;
    ExampleToTime_t.tm_hour = 19;
    // in DD/MM/YY = 2/01/2025 at 19:00

    time_t converted = mktime(&ExampleToTime_t);
    printf("time_t of the date you made %ld\n", converted); //you can convert again localtime()



    clock_t end = clock(); 
    printf("time it took %lfs\n", (double)(end - start)/CLOCKS_PER_SEC);
}