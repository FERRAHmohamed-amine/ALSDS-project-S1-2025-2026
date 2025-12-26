#ifndef SECAUD_ANA_H
#define SECAUD_ANA_H

 struct Sec_User {
    char name[50];
    char password [20];
    int score;
    

 };
// count  Uppercase
 int countUppercase(char text[]);
// count  Lowercase 
 int countLowercase(char text[]); 
// count Digits
 int countDigits(char text[]); 
 // count percentage of Uppercases 
 float percentUppercase(char text[]);
 // length  
 int textLength(char text[]); 
 // text statistics
 void displayTextStats(char text[]); 
 // checks strong password
 int veryStrongPassword(char pass[]); 
 // generate random key 
 void generateKey(int length, char key[]);
    // verifies hexadecimal format 
 int isHexKey(char key[]); 
    // generates random password
 void generateRandomPassword(int length, char pass[]);
    // calculates password score
 int passwordScore(char pass[]);
    // computes average score 
 float averageScore(struct Sec_User users[], int n);
    // displays global report 
 void displaySecurityReport(struct Sec_User users[], int n); 
    // counts users with strong passwords
 int countStrongUsers(struct Sec_User users[], int n);
    // prints general security advice
 void showSecurityTips(); 
    // verifies email format
 int checkEmailFormat(char email[]);
    // verifies login format 
 int checkLoginFormat(char name[]);
    // generates hexadecimal key 
 void generateHexKey(int length, char key[]);
    //  finds top 3 common passwords 
 void top3Passwords(struct Sec_User users[], int n);
    // calculates global security level 
 float globalSecurityLevel(struct Sec_User users[], int n);
 //........................................................................end of SecAud&Ana.h
#endif 