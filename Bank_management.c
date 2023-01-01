//Digital-Clock
//Digital Clock by using C Language
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{

    for(int i=0;i<24;i++)
    {
        for(int j=0;j<60;j++)
        {
            for(int k=0;k<60;k++)
            {
                time_t now=time(NULL);
                sleep(1);
                time_t two_secs=time(NULL);
                char *string_now=ctime(&now);
                struct tm *cur_time=localtime(&now);
                system("cls");
                printf("\n%02d:%02d:%02d",cur_time->tm_hour,cur_time->tm_min,cur_time->tm_sec);
            }
        }
    }
    return 0;
}
