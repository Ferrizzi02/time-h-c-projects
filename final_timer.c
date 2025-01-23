#include<stdio.h>
#include<time.h>
#include<conio.h>

int main(){
    clock_t start, end;
    printf("press spacebar to start the timer\n");
    while(1){
        if(kbhit() && getch()==' '){
            start = clock();
            printf("press spacebar to end\n");
            break;
        }
    }
    while(1){
        if(kbhit() && getch()==' '){
            end = clock();
            break;
        }
    }
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    int minutes = (int)((int)time/60);
    printf("timer:%d minutes with %lf seconds", minutes, time-(minutes*60));

    return 0;
}