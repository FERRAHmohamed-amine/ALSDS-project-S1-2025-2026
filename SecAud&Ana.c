#include<stdio.h>
#include<string.h>
#include "secAud&Ana.h"



struct User {
    char name[50];
    char password [20];
    int score;
    

 };

//......................... counts Uppercase letters in text
int countUppercase(char text[]){
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            count++;
        }
    }
    return count;
}
//......................... counts Lowercase letters in text
int countLowercase(char text[]){
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            count++;
        }
    }
    return count;
}
//......................... counts Digits in text
int countDigits(char text[]){
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            count++;
        }
    }
    return count;
}
//......................... calculates percentage of Uppercase letters in text
float percentUppercase(char text[]){
    int total = strlen(text);
    if (total == 0) return 0.0;
    int uppercaseCount = countUppercase(text);
    return ((float)uppercaseCount / total) * 100;
}
//......................... calculates length of text
int textLength(char text[]){
     int Length = 0 ;
     while (text[Length] != '\0'){
        Length++ ;
     }
      return Length ;
    }
//..........................calculates spaces of text 
    int countSpaces(char text[]) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ')
            count++;
    }
    return count;
} 
//..........................calculates special characters 
int countSpecial(char text[]) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (!(text[i] >= 'A' && text[i] <= 'Z') &&
            !(text[i] >= 'a' && text[i] <= 'z') &&
            !(text[i] >= '0' && text[i] <= '9') &&
            text[i] != ' ' && text[i] != '\n')
            count++;
    }
    return count;
}
//....................calculates text's lines 
int countLines(char text[]) {
    int lines = 1;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n')
            lines++;
    }
    return lines;
}
//.....................calculates words in text 
int countWords(char text []){
    int word = 0 ;
    for (int i ; text[i] != '\0' ; i++)
    if ((text[i] != '' && text[i] != '\n')&&(text[i+1] == '' || text[i+1] ==  '\n' || text[i+1] == '\0'))
    word++ ;
return word ;
}
//......................... displays text statistics
void displayTextStats(char text[]) {

    printf("\n--- Text Statistics ---\n");
    printf("Characters : %d\n", textLength(text));
    printf("Words      : %d\n", countWords(text));
    printf("Lines      : %d\n", countLines(text));
    printf("Uppercase  : %d\n", countUppercase(text));
    printf("Lowercase  : %d\n", countLowercase(text));
    printf("Digits     : %d\n", countDigits(text));
    printf("Spaces     : %d\n", countSpaces(text));
    printf("Special    : %d\n", countSpecial(text));
}
//.........................Checks if password is very strong
 int  veryStrongPassword(char pass[]){
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int length = textLength(pass);

    for (int i = 0; pass[i] != '\0'; i++) {
        if (pass[i] >= 'A' && pass[i] <= 'Z') hasUpper = 1;
        else if (pass[i] >= 'a' && pass[i] <= 'z') hasLower = 1;
        else if (pass[i] >= '0' && pass[i] <= '9') hasDigit = 1;
        else hasSpecial = 1;
    }

    if (length >= 12 && hasUpper && hasLower && hasDigit && hasSpecial) {
        return 1; // Very strong password
    } else {
        return 0; // Not very strong
    }
 } 
 //.........................Generates random key
 void generateKey(int length, char key[]){
     char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()_+";
        for (int i = 0 ; i < length ; i++){
            int index = rand() % (sizeof(charset) -1 ) ;
            key[i] = charset[index] ;
        }
        key[length] = '\0' ;
 }
 //.........................verify hexadecimal format 
 int isHexKey(char key[]){
     int Length = textLength(key);
     for (int i = 0 ; i < Length ; i++){
        if (!((key[i]>='0' && key[i] <= '9') || (key[i] >= 'A' && key [i] <= 'F' ) || (key[i] >= 'a' && key [i] <= 'f')))
        return 0 ; // not hexadecimal 
    
     }
      return 1 ; // hexadecimal
 }
 //.........................Generates random password.
   void generateRandomPassword(int length, char pass[]){
     char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()_+";
        for (int i = 0 ; i < length ; i++){
            int index = rand() % (sizeof(charset) -1 ) ;
            pass[i] = charset[index] ;
        }
        pass[length] = '\0' ;
 }
 //...................................Calculates password score
      int passwordScore(char pass[]){
        int  score = 0 ;
        int length = textLength(pass);
        if (length >= 8) score += 2 ;
        if (length >= 12) score += 2 ;
        if (countUppercase(pass) > 0) score += 2 ;
        if (countLowercase(pass) > 0) score += 2 ;
        if (countDigits(pass) > 0) score += 2 ;
        if (countSpecial(pass) > 0) score += 2 ;
        return score ;
      }
 //.........................Computes average score
 float averageScore(struct User users[], int n){
    int totalScore = 0 ; 
     for (int i = 0 ; i < n ; i++){
        totalScore += users[i].score ;     
     }
     return (float)totalScore / n ;
 }
 //.........................Displays global report.
 void displaySecurityReport(struct User users[], int n){
    printf("-------*/Security Report*/-------\n");
    printf("The number of users : %d",n);
    printf("The Average Score : %d", averageScore(users,n));
    printf("\n");
    for (int i = 0 ; i < n ; i++){
        printf("User: %s , Score : %d\n", users[i].name , users[i].score);
    }
 }
 //..........................Counts users with strong passwords.
  int countStrongUsers(struct User users[], int n){
    int count = 0 ;
    for (int i = 0 ; i < n ; i++){
        if ( veryStrongPassword(users[i].password)){
            count++;
        }  
    }
    printf("Number of users with strong passwords : %d\n", count);
    return count ;
  }
// ..........................Prints general security advice.
 void showSecurityTips(){
    printf("-------*/Security Tips*/-------\n");
    printf("1. Use strong passwords with a mix of uppercase, lowercase, digits, and special characters.\n");
    printf("2. Change your passwords regularly and avoid reusing them across different accounts.\n");
    printf("3. Enable two-factor authentication (2FA) wherever possible for an added layer of security.\n");
    printf("4. Be cautious of phishing attempts and avoid clicking on suspicious links or attachments.\n");
    printf("5. Keep your software and systems updated to protect against known vulnerabilities.\n");
    printf("6. Regularly back up important data to prevent loss from cyber-attacks or hardware failures.\n");
    printf("7. Educate yourself and others about cybersecurity best practices.\n");
 }
 //........................Verifies valid email format.
 int isValidEmail(char email[]){
    int atCount = 0 , dotCount = 0 , Length = textLength(email);
    for (int i = 0 ; i<Length ; i++){
        if( email[i] == '@')
        atCount++;
        if(email[i] == '.')
        dotCount++ ;

    }
    if (atCount == 1 && dotCount >=1 
         && email[0] != '@' && email[Length - 1] != '.')
return 1 ;
    else 
    return 0 ;
 }
  // ........................verifies login validity
    int isValidLogin(char username[], char password[]){
        int userLength = textLength(username);
        int passLength = textLength(password);
        if (userLength < 5 || passLength < 8)
        return 0 ; // invalid login
        return 1 ; // valid login
    }
//..........................Generates hexadecimal key.
void generateHexKey(int length, char key[]){
     char hexkey ="0123456789"
                  "ABCDEF"
                  "abcdef";
        for (int i = 0 ; i < length ; i++){
            int index = rand() % (sizeof(hexkey) -1 ) ;
            key[i] = hexkey[index] ;
        }
        key[length] = '\0' ;
}
//.......................... finds top 3 common passwords 
 void top3Passwords(struct User users[], int n){
            char top1[50] = "", top2[50] = "", top3[50] = "";
            int score1 = -1, score2 = -1, score3 = -1;


            for (int i =0 ; i < n ; i++){
                int score = passwordScore(users[i].password);
                if (score > score1){
                    strcpy(top3,top2);
                    strcpy(top2,top1);
                    strcpy(top1,users[i].password);
                    score3 = score2;
                    score2 = score1;
                    score1 = score;
                } else if (score > score2){
                    strcpy(top3,top2);
                    strcpy(top2,users[i].password);
                    score3 = score2;
                    score2 = score;
                } else if (score > score3){
                    strcpy(top3,users[i].password);
                    score3 = score;
                }
             } 
            printf("Top 3 common passwords:\n");
            printf("1. %s\n", top1);
            printf("2. %s\n", top2);
            printf("3. %s\n", top3);

}
//............................Computes global level.
float globalSecurityLevel(struct User users[], int n){
    if (n==0) return 0 ;
    int score = 0 ;
  for(int i = 0 ; i < n ; i ++){
    score += passwordScore(users[i].password);
  }
 float avrScore = (float)score / n ;
    return avrScore ;
}