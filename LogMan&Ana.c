#include<stdio.h>
#include<string.h>
#include "LogMan&Ana.h"


#define INFO 0
#define WARNING 1
#define ERROR 2
#define EMPTY -1
struct Log {
char user[20];
char action[50];
char date[20];
char time[10];
int code; // 0 info, 1 warning, 2 error , -1 empty
};
 //...................................... Log Management and Analysis Functions ............................
  
 //...................Initializes log list.
  void initLogs(struct Log logs[], int n){
    for (int i = 0 ; i < n ; i++ ){
        strcpy(logs[i].user , "");
        strcpy(logs[i].action , "");
        strcpy(logs[i].date , "");
        strcpy(logs[i].time , "");
        logs[i].code = EMPTY ; 
    }
  }
  //..................adds a log entry 
    void addLog(struct Log logs[], int n, char user[], char action[], int code){
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code == EMPTY){
                strcpy(logs[i].user , user);
                strcpy(logs[i].action , action);
                logs[i].code = code ;
               
     printf("Log added successfully.\n");
                return ;
            }
        }
printf("Log list is full.\n");
     }
    //..................displays all logs
    void  DisplayLogs(struct Log logs[] , int n){
        printf("Logs List : \n ");
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code !=EMPTY){
                printf("User = %s",logs[i].user);
                printf(" Action = %s",logs[i].action);
                printf(" Date = %s",logs[i].date);
                printf(" Time = %s",logs[i].time);
                printf(" Code = %d\n",logs[i].code);
            }
        }
    }
//..................searches logs by user
    void searchLogsByUser(struct Log logs[], int n, char user[]){
        printf("Logs for user %s : \n", user);
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code != EMPTY && strcmp(logs[i].user , user) == 0){
                printf("Action = %s",logs[i].action);
                printf(" Date = %s",logs[i].date);
                printf(" Time = %s",logs[i].time);
                printf(" Code = %d\n",logs[i].code);
            }
        }
    }
//..................searches logs by date
    void searchLogsByDate(struct Log logs[], int n, char date[]){
        printf("Logs for date %s : \n", date);
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code != EMPTY && strcmp(logs[i].date , date) == 0){
                printf("User = %s",logs[i].user);
                printf(" Action = %s",logs[i].action);
                printf(" Time = %s",logs[i].time);
                printf(" Code = %d\n",logs[i].code);
            }
        }
    }
//..................counts error entries
    int countErrors(struct Log logs[], int n){
        int count = 0 ;
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code == ERROR){
                count++ ;
            }
        }
        return count ;
    }
//..................counts login events
    int countLoginLogs(struct Log logs[], int n){
        int count = 0 ;
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code != EMPTY &&  logs[i].action == "Login"){
                count++ ;
            }
        return count ;
        }
    }
//..................counts blocked attempts
    int countBlockedAttempts(struct Log logs[], int n){
        int count = 0 ;
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code != EMPTY &&  logs[i].action == "Blocked"){
                count++ ;
            }
        }
    }
//..................shows statistics
    void showLogStatistics(struct Log logs[], int n){
        int infoCount = 0 , warningCount = 0 , errorCount = 0 ;
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code == INFO)
            infoCount++ ;
            else if (logs[i].code == WARNING)
            warningCount++ ;
            else if (logs[i].code == ERROR)
            errorCount++ ;
        }
        printf("Log Statistics : \n");
        printf("Info logs : %d\n", infoCount);
        printf("Warning logs : %d\n", warningCount);
        printf("Error logs : %d\n", errorCount);
    }
//...........................Sorts logs by date
   void sortLogsByDate(struct Log logs[], int n){
    struct log temp ;
    for ( int i = 0 ; i < n - 1 ; i++){
         for (int j ; j < n -i-1 ; j++){
              if ( strcmp(logs[j].date , logs[j+1].date) > 0){
                temp = logs[j] ;
                logs[j] = logs[j+1] ;
                logs[j+1] = temp ;
              }
         }
    }
   }
//...........................Sorts by username
    void sortLogsByUser(struct Log logs[], int n){
     struct log temp ;
     for ( int i = 0 ; i < n - 1 ; i++){
            for (int j ; j < n -i-1 ; j++){
                  if ( strcmp(logs[j].user , logs[j+1].user) > 0){
                 temp = logs[j] ;
                 logs[j] = logs[j+1] ;
                 logs[j+1] = temp ;
                  }
            }
     }
    }
//...........................Detects anomalies
int detectSuspiciousActivity(struct Log logs[], int n, char user[]){
     for (int i = 0 ; i < n ; i ++ ){
         if (logs[i].code == ERROR &&  strcmp(logs[i].action , "login failed") == 0
              && strcmp(logs[i].user , user) == 0 ){
             return 1 ; // suspicious activity detected
         }  
        return 0 ; // no suspicious activity detected
     }
}
//...........................counts daily connections
    int countDailyConnections(struct Log logs[], int n, char date[]){
        int count = 0 ;
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code != EMPTY && strcmp(logs[i].date , date) == 0){
                count++ ;
            }
        }
    }
//...........................computes error percentage
    float computeErrorPercentage(struct Log logs[], int n){
        int errorCount = 0 , totalCount = 0 ;
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code != EMPTY){
                totalCount++ ;
                if (logs[i].code == ERROR)
                errorCount++ ;
            }
        }
        if (totalCount == 0) return 0.0 ;
        return ((float)errorCount / totalCount) * 100 ;
    }
//..........................Exports logs to CSV.
      void exportLogsCSV(struct Log logs[], int n){
        FILE *file = fopen("logs.txt","w");
        if (file==NULL){
            printf("Error opening file!\n");
            return ;
        }
         else {
            for (int i = 0 ; i < n ; i++){
                fprintf(file, "%s,%s,%s,%s\n", logs[i].date, logs[i].user, logs[i].action, logs[i].code);
                break;
            }
        }
        fclose(file);
    }

//..........................imports logs from CSV.
    void importLogsCSV(struct Log logs[], int n){
        FILE *file = fopen("logs.txt","r");
        if (file==NULL){
            printf("Error opening file!\n");
            return ;
        }
         else {
            for (int i = 0 ; i < n ; i++){
                fscanf(file, "%[^,],%[^,],%[^,],%d\n", logs[i].date, logs[i].user, logs[i].action, &logs[i].code);
                break;   
            }
        }
        fclose(file);
    }
//..........................clears all logs
    void clearLogs(struct Log logs[], int n){
        for (int i = 0 ; i < n ; i++ ){
            strcpy(logs[i].user , "");
            strcpy(logs[i].action , "");
            strcpy(logs[i].date , "");
            strcpy(logs[i].time , "");
            logs[i].code = EMPTY ; 
        }
    }
//..........................displays last events
    void displayLastEvents(struct Log logs[], int n, int count){
        printf("Last %d events : \n", count);
        for (int i = n - count ; i < n ; i++){
            if (logs[i].code != EMPTY){
                printf("User = %s",logs[i].user);
                printf(" Action = %s",logs[i].action);
                printf(" Date = %s",logs[i].date);
                printf(" Time = %s",logs[i].time);
                printf(" Code = %d\n",logs[i].code);
            }
        }
    }
//..........................archives old logs
    void archiveOldLogs(struct Log logs[], int n, int days){
        for (int i = 0 ; i < n - days ; i++ ){
            strcpy(logs[i].user , "");
            strcpy(logs[i].action , "");
            strcpy(logs[i].date , "");
            strcpy(logs[i].time , "");
            logs[i].code = EMPTY ; 
        }
    }
//..........................displays top frequent errors.
        void showTopErrors(struct Log logs[], int n){
        int errorCounts[3] = {0,0,0}; // assuming 3 types of errors
        for (int i = 0 ; i < n ; i++){
            if (logs[i].code == ERROR){
                errorCounts[0]++ ; 
            }
            else if (logs[i].code == WARNING){
                errorCounts[1]++ ; 
            }
            else if (logs[i].code == INFO){
                errorCounts[2]++ ; 
            }
        }
        printf("Top Frequent Errors : \n");
        for (int i = 0 ; i < 3 ; i++){
            printf("Error Type %d : %d occurrences\n", i, errorCounts[i]);
        }
    }