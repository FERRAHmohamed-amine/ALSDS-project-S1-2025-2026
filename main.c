#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include "E&D.h"
#include "LogMan&Ana.h" 
#include "MST.h" 
#include "UserMan.h" 
#include "secAud&Ana.h"


// the function needed in the menu
void subMenuEncryption(){

    struct Message msg;
    int choice;
    int key;
    int subKey[26];
    char subKeyInput[27];

    do {
        printf("\n--- Encryption and Decryption Library ---\n");
        printf("1. Caesar Cipher (Encrypt)\n");
        printf("2. Caesar Cipher (Decrypt)\n");
        printf("3. XOR Cipher (Encrypt/Decrypt)\n");
        printf("4. Substitution Cipher (Encrypt)\n");
        printf("5. Substitution Cipher (Decrypt)\n");
        printf("6. Character Frequency Analysis\n");
        printf("7. Calculate Coincidence Index\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice >= 1 && choice <= 7) {
            printf("Enter the message text: ");
            fgets(msg.text, sizeof(msg.text), stdin);
            msg.text[strcspn(msg.text, "\n")] = 0; 
        }

        switch (choice) {
            case 1:
                printf("Enter integer key (e.g., 3): ");
                scanf("%d", &key);
                encryptCesar(msg, key);
                break;

            case 2:
                printf("Enter integer key (e.g., 3): ");
                scanf("%d", &key);
                decryptCesar(msg, key);
                break;

            case 3:
                printf("Enter XOR key (integer 0-255): ");
                scanf("%d", &key);
                encryptXOR(msg, key); 
                break;

            case 4:
                printf("Enter 26-letter substitution alphabet: ");
                scanf("%s", subKeyInput);
                if (isValidKey(subKeyInput)) {
                    for(int i=0; i<26; i++) subKey[i] = (subKeyInput[i] >= 'a') ? subKeyInput[i]-32 : subKeyInput[i];
                    encryptSubstitution(msg, subKey);
                } else {
                    printf("Invalid Key! Must be 26 unique letters.\n");
                }
                break;

            case 5:
                printf("Enter the 26-letter alphabet used for encryption: ");
                scanf("%s", subKeyInput);
                if (isValidKey(subKeyInput)) {
                    for(int i=0; i<26; i++) subKey[i] = (subKeyInput[i] >= 'a') ? subKeyInput[i]-32 : subKeyInput[i];
                    decryptSubstitution(msg, subKey);
                } else {
                    printf("Invalid Key!\n");
                }
                break;

            case 6:
                frequencyAnalysis(msg);
                break;

            case 7:
                printf("Coincidence Index: %.4f\n", coincidenceIndex(msg));
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

}

void subMenuMath() {
    int choice;

    do {
        printf("\n--- Math Utility Library ---\n");
        printf("1. GCD using Euclidean algorithm\n");
        printf("2. Factorial\n");
        printf("3. Random integer between min and max\n");
        printf("4. Sort array in ascending order (Bubble Sort)\n");
        printf("5. Transpose a matrix\n");
        printf("6. Check if matrix is symmetric\n");
        printf("7. Determine 2x2 matrix determinant\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                int a, b , c;
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                c = gcd(a,b);
                printf("GCD(%d, %d) = %d\n", a, b, c);
                break;
            }

            case 2: {
                int n;
                printf("Enter an integer: ");
                scanf("%d", &n);
                printf("%d! = %d\n", n, factorial(n));
                break;
            }

            case 3: {
                int min, max;
                printf("Enter min and max: ");
                scanf("%d %d", &min, &max);
                printf("Random integer: %d\n", randominteger(min, max));
                break;
            }

            case 4: {
                int n, arr[100];
                printf("Enter array size: ");
                scanf("%d", &n);

                printf("Enter %d integers:\n", n);
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);

                sortAscending(arr, n);

                printf("Sorted array: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            }

            case 5: {
                struct Matrix A, T;

                printf("Enter number of rows and columns: ");
                scanf("%d %d", &A.rows, &A.cols);

                printf("Enter matrix elements:\n");
                for (int i = 0; i < A.rows; i++)
                    for (int j = 0; j < A.cols; j++)
                        scanf("%d", &A.M[i][j]);

                transposeMatrix(&A, &T);

                printf("Transposed matrix:\n");
                for (int i = 0; i < T.rows; i++) {
                    for (int j = 0; j < T.cols; j++)
                        printf("%d ", T.M[i][j]);
                    printf("\n");
                }
                break;
            }

            case 6: {
                struct Matrix A;

                printf("Enter number of rows and columns: ");
                scanf("%d %d", &A.rows, &A.cols);

                printf("Enter matrix elements:\n");
                for (int i = 0; i < A.rows; i++)
                    for (int j = 0; j < A.cols; j++)
                        scanf("%d", &A.M[i][j]);

                if (isSymmetric(A))
                    printf("Matrix is symmetric.\n");
                else
                    printf("Matrix is not symmetric.\n");

                break;
            }

            case 7: {
                int mat[2][2];

                printf("Enter 2x2 matrix elements:\n");
                for (int i = 0; i < 2; i++)
                    for (int j = 0; j < 2; j++)
                        scanf("%d", &mat[i][j]);

                printf("Determinant = %d\n", determinant2x2(mat));
                break;
            }

            case 0:
                printf("Exiting Math Utility...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}
 

void subMenuUserManagement() {
    int choice;
    struct User users[100];
    

    initUsers(users,100);

    do {
        printf("\n--- User Management System ---\n");
        printf("1. Display all users\n");
        printf("2. Add a new user\n");
        printf("3. Delete a user\n");
        printf("4. Block a user\n");
        printf("5. Unblock a user\n");
        printf("6. Change user role\n");
        printf("7. List admins\n");
        printf("8. User statistics\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        char name[20];

        switch (choice) {

        case 1:
            displayUsers(users, 100);
            break;

        case 2:
            addUser(users, 100);
            break;

        case 3:
            printf("Enter username to delete: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            deleteUser(users, 100, name);
            break;

        case 4:
            printf("Enter username to block: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            blockUser(users, 100, name);
            break;

        case 5:
            printf("Enter username to unblock: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            unblockUser(users, 100, name);
            break;

        case 6:
            printf("Enter username: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            changeRole(users, 100, name, 1);
            break;

        case 7:
            listAdmins(users, 100);
            break;

        case 8:
            userStatistics(users, 100);
            break;

        case 0:
            printf("Exiting User Management...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);
}

void subMenuSecurityAudit(){
    int choice;
    char buffer[500];
    char keyBuffer[100];

    // Note: In a real app, you would pass your global users array here
    // For this example, we'll use a local mock array if needed
    struct Sec_User auditUsers[MAX_USERS]; 
    int numUsers = 0; 

    do {
        printf("\n--- Security Audit and Analysis ---\n");
        printf("1. Text Statistics (Length, Words, Case)\n");
        printf("2. Password Strength Checker (Score)\n");
        printf("3. Generate Random Secure Password\n");
        printf("4. Generate Hexadecimal Key\n");
        printf("5. Validate Email Format\n");
        printf("6. Show General Security Tips\n");
        printf("7. Global Security Report (Mock Data)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) break;
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter text to analyze: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                displayTextStats(buffer);
                break;

            case 2:
                printf("Enter password to test: ");
                scanf("%s", buffer);
                int score = passwordScore(buffer);
                printf("Password Score: %d/12\n", score);
                if(veryStrongPassword(buffer)) printf("Status: Very Strong!\n");
                else printf("Status: Could be stronger.\n");
                break;

            case 3:
                printf("Enter desired length: ");
                int len;
                scanf("%d", &len);
                generateRandomPassword(len, buffer);
                printf("Generated Password: %s\n", buffer);
                break;

            case 4:
                printf("Enter key length: ");
                scanf("%d", &len);
                generateHexKey(len, keyBuffer);
                printf("Generated Hex Key: %s\n", keyBuffer);
                break;

            case 5:
                printf("Enter email to validate: ");
                scanf("%s", buffer);
                if(checkEmailFormat(buffer)) printf("Valid email format.\n");
                else printf("Invalid email format.\n");
                break;

            case 6:
                showSecurityTips();
                break;

            case 7:
                // This assumes you have users loaded in your system
                displaySecurityReport(auditUsers, numUsers);
                break;

            case 0:
                printf("Exiting Audit Module...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
}
#define INFO 0
#define WARNING 1
#define ERROR 2
#define EMPTY -1
#define MAX_LOGS 100
void subMenuLogManagement() {

    struct Log logs[MAX_LOGS];
    int  logCount = 0;
    int  choice;
    char userSearch[20];
    char user[20];
    char action[50];
    char date[20];
    char time[10];
    int  code;
    int c;
    initLogs(logs, MAX_LOGS);

    do {
        printf("\n--- Logging Management and Analysis Library ---\n");
        printf("1. Add a log entry\n");
        printf("2. Detect anomalies\n");
        printf("3. Display all logs\n");
        printf("4. Search logs by user\n");
        printf("5. Show statistics\n");
        printf("6. Count daily connections\n");
        printf("7. Display top frequent errors\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear buffer

        switch (choice) {

            case 1:
                printf("Enter username: ");
                fgets(user, sizeof(user), stdin);
                user[strcspn(user, "\n")] = 0;
                printf("Enter action: ");
                fgets(action, sizeof(action), stdin);
                action[strcspn(action, "\n")] = 0;
                printf("Enter code (0: info, 1: warning, 2: error): ");
                scanf("%d", &code);
                addLog(logs, MAX_LOGS, user, action, code);
                logCount++;
                break;

            case 2:
                printf("Enter username to check for anomalies: ");
                fgets(user, sizeof(user), stdin);
                user[strcspn(user, "\n")] = 0;

                detectSuspiciousActivity(logs, logCount, user);

                break;

            case 3:
                displayLogs(logs, logCount);
                break;

            case 4:
                printf("Enter username to search: ");
                fgets(userSearch, sizeof(userSearch), stdin);
                userSearch[strcspn(userSearch, "\n")] = 0;
                searchLogsByUser(logs, logCount, userSearch);
                break;

            case 5:
                showLogStatistics(logs, logCount);
                break;

            case 6:
                c = countDailyConnections(logs, logCount, date);
                printf("Connections on %s: %d\n", date, c);
                break;

            case 7:
                displayTopFrequentErrors(logs, MAX_LOGS);
                break;

            case 0:
                printf("Exiting Log Management...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}
void displayHelp(){
    printf("\n--- Help ---\n");
    printf("This program provides various security utilities including:\n");
    printf("1. Encryption and Decryption tools\n");
    printf("2. Mathematical and Security Tools\n");
    printf("3. User Management System\n");
    printf("4. Security Audit and Analysis\n");
    printf("5. Log Management and Monitoring\n");
    printf("Select the desired option from the main menu to access specific functionalities.\n");
}
void displayAbout(){
    printf("\n--- Help ---\n");
    printf("This program provides various security utilities including:\n");
    printf("1. Encryption and Decryption tools\n");
    printf("2. Mathematical and Security Tools\n");
    printf("3. User Management System\n");
    printf("4. Security Audit and Analysis\n");
    printf("5. Log Management and Monitoring\n");
    printf("Select the desired option from the main menu to access specific functionalities.\n");
}


int main() {
    int choice;

    do {
        // Affichage du menu principal selon le sujet
        printf("\n==============================\n");
        printf(" SECURITY UTILITY LIBRARY SYSTEM \n");
        printf("==============================\n");
        printf("1. Encryption and Decryption Library\n");
        printf("2. Mathematical and Security Tools\n");
        printf("3. User Management System\n");
        printf("4. Security Audit and Analysis\n");
        printf("5. Log Management and Monitoring\n");
        printf("6. Help\n");
        printf("7. About\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Appel d'une fonction qui gère le sous-menu de cryptographie
                subMenuEncryption(); 
                break;
            case 2:
                // Sous-menu mathématiques
                subMenuMath();
                break;
            case 3:
                // Sous-menu gestion des utilisateurs
                subMenuUserManagement();
                break;
            case 4:
                // Sous-menu audit de sécurité
                subMenuSecurityAudit();
                break;

            case 5:
                // Sous-menu gestion des logs
                subMenuLogManagement();
                break;  
            case 6:
                // Afficher l'aide
                displayHelp();
                break;
            case 7:
                // Afficher les informations "À propos"
                displayAbout();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while(choice != 0);

    return 0;
}

 