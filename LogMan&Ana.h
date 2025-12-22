#ifndef MODEXP_H
#define MODEXP_H


struct Log{
char user[20];
char action[50];
char date[20];
char time[10];
int code; // 0 info, 1 warning, 2 error
};
//...................................... Log Management and Analysis Functions ............................
//...................................... Initializes log list.
    void initLogs(struct Log logs[], int n);
//...................................... Adds a log entry.
    void addLog(struct Log logs[], int n, char user[], char action[], int code);
//...................................... Displays all logs.
    void displayLogs(struct Log logs[], int n);
//...................................... Searches logs by user.
    void searchLogsByUser(struct Log logs[], int n, char user[]);
//...................................... Searches logs by date.
    void searchLogsByDate(struct Log logs[], int n, char date[]);
//...................................... Counts error entries.
    int countErrors(struct Log logs[], int n);
//...................................... Counts login events.
    int countLogins(struct Log logs[], int n);
//...................................... Counts blocked attempts.
    int countBlockedAttempts(struct Log logs[], int n);
//...................................... Shows statistics.
    void showLogStatistics(struct Log logs[], int n);
//...................................... Sorts logs by date.
    void sortLogsByDate(struct Log logs[], int n);
//...................................... Sorts by username.
    void sortLogsByUser(struct Log logs[], int n);
//...................................... Detects anomalies.
    void detectAnomalies(struct Log logs[], int n);
//...................................... Counts daily connections.
    int countDailyConnections(struct Log logs[], int n, char date[]);
//...................................... Computes error percentage.
    float computeErrorPercentage(struct Log logs[], int n);
//...................................... Exports logs to CSV.
    void exportLogsToCSV(struct Log logs[], int n, char filename[]);
//...................................... Imports logs from CSV.
    void importLogsFromCSV(struct Log logs[], int n, char filename[]);
//...................................... Clears all logs.
    void clearLogs(struct Log logs[], int n);
//...................................... Displays last events.
    void displayLastEvents(struct Log logs[], int n, int count);
//...................................... Archives old logs.
    void archiveOldLogs(struct Log logs[], int n, int days);
//...................................... Displays top frequent errors. 
    void displayTopFrequentErrors(struct Log logs[], int n, int topN);
    
//........................................................................end of LogMan&Ana.h

#endif 