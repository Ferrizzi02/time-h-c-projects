#include<stdio.h>
#include<time.h>

int main(){
    struct tm end = {0};                                    // 23/01/2025
    end.tm_year = 2025-1900;
    end.tm_mon =0;
    end.tm_mday = 23;

    struct tm start = {0};                                  // 01/01/2025
    start.tm_year = 2025-1900;
    start.tm_mon=0;
    start.tm_mday =1;

    time_t start_data = mktime(&start);                     //converts to seconds since the epoch
    time_t end_data = mktime(&end);

    /*
    1 way: calculate the time elapsed and use a simple loop, idk if this is efficient tho
    */
    int daysPassed = (end_data - start_data)/86400 +1;          //86400 seconds in a day, also 23-1 = 22 so the loop will go til 22
    for(int i=0; i<daysPassed; i++){
        time_t current = start_data + i*86400;
        printf("%s", ctime(&current));
    }

    printf("\nsecond\n");

    /*
    2 way: just using the time
    */
   for(time_t current_data = start_data; current_data<end_data+1; current_data+=86400){
    printf("%s", ctime(&current_data));
   }

    printf("\nthird\n");


    return 0;
}