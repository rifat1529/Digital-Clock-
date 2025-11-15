#include<stdio.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

char* get_time(char* formated_time , int choice);
int format_time(int choice);
char* print_date();



 int main() {
    char formated_time[50];
    char date[100];
    int choice = format_time(choice);

    while(1){
        system("clear");
        char* time = get_time(formated_time , choice);
        char* date_format = print_date();
        printf("current time : %s", time);    
        printf("current date : %s", date_format);
        sleep(1);
    }
   
 }


 char* get_time(char* formated_time , int choice){
    time_t rawtime;
    struct tm *time_info;
    time(&rawtime);
    time_info = localtime(&rawtime);
    if(choice == 2){
        strftime(formated_time, 50 , "%H:%M:%S \n", time_info); 
        return formated_time; 
    }
    else
    strftime(formated_time, 50 , "%I:%M:%S:%P \n", time_info); 

    return formated_time; 
 }


 int format_time(int choice){
  printf("Choose time formate :\n");
    printf("1. 12 hour format (default)\n");
    printf("2. 24 hour format\n");
    printf("Enter your choice : ");
    //int choice; 
    scanf("%d", &choice);
    return choice;
 }

 char* print_date(){
    time_t rawtime;
    struct tm *time_info;
    static char date[100];
    time(&rawtime);
    time_info = localtime(&rawtime); 
    strftime(date, 100 , "%A , %d-%m-%Y \n", time_info); 
    return date; 
 }


 