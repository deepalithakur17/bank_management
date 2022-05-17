#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
void deposit()
{
    char filename[45];
    printf("\nEnter your account name: ");
    scanf(" %s",filename);
    FILE *pt;
    float n;
    float m;
    pt=fopen(filename,"r");
    if(pt==NULL)
    {
        puts("\n\nYour account don't exist!");//exit(1);
    }
    else
    {
        printf("\n\nEnter the amount you want to deposit: ");
        scanf("%f",&n);
        fscanf(pt,"%f",&m);
        float  am=m+n;
        fclose(pt);
        pt=fopen(filename,"r+");
        fprintf(pt,"%f",am);
        printf("\n\nNow amount in your account is: %f",am);
        fclose(pt);
        pt=fopen(filename,"a+");
        time_t now=time(NULL);
        struct tm *cur_time=localtime(&now);
        char *string_now=ctime(&now);
        fprintf(pt,"\n%2d/%2d/%2d  %2d:%2d:%2d deposit %f money to your account\n",1900+cur_time->tm_year,cur_time->tm_mon,cur_time->tm_mday,cur_time->tm_hour,cur_time->tm_min,cur_time->tm_sec,n);
    }
    fclose(pt);
}
void withdraw()
{
    char filename[45];
    printf("\nEnter your account name: ");
    scanf(" %s",filename);
    FILE *pt;
    float m,n;
    pt=fopen(filename,"r+");
    if(pt==NULL)
    {
        puts("\n\nYour account don't exist");//exit(1);
    }
    else
    {
        printf("\n\nEnter the amount you want to withdraw: ");
        scanf(" %f",&n);
        fscanf(pt,"%f",&m);
        fclose(pt);
        pt=fopen(filename,"r+");
        if(m<n)
        {
            printf("\n\nNot having enough money in your account!");
        }
        else
        {
            // n=m-n;
            fprintf(pt,"%f",m-n);
            printf("\n\nNow amount in your account is: %f",m-n);
        }
        fclose(pt);
        pt=fopen(filename,"a+");
        time_t now=time(NULL);
        struct tm *cur_time=localtime(&now);
        char *string_now=ctime(&now);
        fprintf(pt,"\n%2d/%2d/%2d  %2d:%2d:%2d withdraw %f money from your account\n",1900+cur_time->tm_year,cur_time->tm_mon,cur_time->tm_mday,cur_time->tm_hour,cur_time->tm_min,cur_time->tm_sec,n);
    }
    fclose(pt);
}
void check_balance()
{
    char filename[45];
    printf("\nEnter your account name: ");
    scanf(" %s",filename);
    FILE *pt;
    float m;
    pt=fopen(filename,"r+");
    if(pt==NULL)
    {
        puts("\n\nYour account don't exist");//exit(1);
    }
    else
    {
        fscanf(pt,"%f",&m);
        printf("\n\nAmount in your account is: %f",m);
    }
    fclose(pt);
    //exit(1);
}
void new_account()
{
    char filename[100],name[19],fname[19],mname[19];
    int age, adr_no;
    printf("\nEnter your account name as you want to create:\n");
    scanf(" %s",filename);
    FILE *pt,*ptr;
    pt=fopen(filename,"r");
    fclose(pt);
    if(pt==NULL)
    {
        puts("\n\nYour account name is valid:");
        ptr=fopen(filename,"a+");
        printf("Enter your details:\n");
        fprintf(ptr,"0000000000000");
        fprintf(ptr,"\n IFSC code:DEEPALI00IND");
        printf("\nEnter your name: ");
        scanf(" %s",&name);
        fprintf(ptr,"\nName: %s",name);
        printf("\nEnter your age: ");
        scanf(" %d",&age);
        fprintf(ptr,"\nage: %2d",age);
        printf("\nEnter your Father's name: ");
        scanf(" %s",&fname);
        fprintf(ptr,"\nFather's Name:%s",fname);
        printf("\nEnter your Mother's name: ");
        scanf(" %s",&mname);
        fprintf(ptr,"\nMother's Name:%s",mname);
        fclose(ptr);
    }
    else
    {
        printf("\n\nThis account name is invalid!! Exist already!!\nTRY AGAIN!");//exit(1);
    }
}
void check_details()
{
    char filename[19], ch;
    FILE *ptr;
    printf("\nEnter your account name: ");
    scanf(" %s",&filename);
    ptr=fopen(filename,"r");
    if(ptr==NULL)
    {
        puts("\n\nAccount doesn't exist");//exit(1);
    }
    else
    {
        while(1)
        {
            ch=fgetc(ptr);
            printf("%c",ch);
            if(ch==EOF)
                break;
        }
    }
    //exit(1);
}
int main()
{
    while(1)
    {
        printf("\n\n\t**WELCOME TO MY BANK***\n\n");
        printf("\tHow can I help you!!!");
        char c;
        printf("\n\tDeposit\t\t\t(d or D)\n\tWithdraw\t\t(w or W)\n\tNew Account\t\t(n or N)\n");
        printf("\tCheck Balance\t\t(c or C)\n\tCheck Details\t\t(s or S)\n\tExit\t\t\t(e or E)");
        printf("\n\t\t\t\t\t\t\t\tEnter Code: ");
        scanf(" %c",&c);
        if(c=='d'||c=='D')
        {
            deposit();
        }
        else if(c=='w'||c=='W')
        {
            withdraw();
        }
        else if(c=='c'||c=='C')
        {
            check_balance();
        }
        else if(c=='n'||c=='N')
        {
            new_account();
        }
        else if(c=='s'||c=='S')
        {
            check_details();
        }
        else if(c=='e'||c=='E')
        {
            break;
        }
        else
        {
            printf("Invalid Code!!!\nPlease enter a Valid code\n");
        }
        
        char choice;
        printf("\n\nDo you want to keep above data? \n\tYes\t(y or Y)\n\tNo\t(n or N)");
        scanf(" %c", &choice);
        if(choice=='n'||choice=='N')
        {
            system("cls");
        }
    }
    return 0;
}
