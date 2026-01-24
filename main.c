#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include "E&D.h"
#include "LogMan&Ana.h" 
#include "MST.h" 
#include "UserMan.h" 
#include "secAud&Ana.h"

void subMenuEncryption() {
    struct Message msg, msg2;
    int choice;
    int key;
    int subKey[26];
    char subKeyInput[27];
    char ch;

    do {
        printf("\n--- Encryption and Decryption Library ---\n");
        printf("1. Caesar Cipher (Encrypt)\n");
        printf("2. Caesar Cipher (Decrypt)\n");
        printf("3. XOR Cipher (Encrypt/Decrypt)\n");
        printf("4. Substitution Cipher (Encrypt)\n");
        printf("5. Substitution Cipher (Decrypt)\n");
        printf("6. Character Frequency Analysis\n");
        printf("7. Calculate Coincidence Index\n");
        printf("8. Convert to Uppercase\n");
        printf("9. Convert to Lowercase\n");
        printf("10. Reverse Message\n");
        printf("11. Remove Spaces\n");
        printf("12. Compare Two Messages\n");
        printf("13. Count a Character\n");
        printf("14. Input New Message\n");
        printf("15. Display Current Message\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();   // clear newline

        if (choice >= 1 && choice <= 15 && choice != 12) {
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
                    for (int i = 0; i < 26; i++)
                        subKey[i] = (subKeyInput[i] >= 'a') ? subKeyInput[i] - 32 : subKeyInput[i];
                    encryptSubstitution(msg, subKey);
                } else {
                    printf("Invalid Key! Must be 26 unique letters.\n");
                }
                break;

            case 5:
                printf("Enter the 26-letter alphabet used for encryption: ");
                scanf("%s", subKeyInput);
                if (isValidKey(subKeyInput)) {
                    for (int i = 0; i < 26; i++)
                        subKey[i] = (subKeyInput[i] >= 'a') ? subKeyInput[i] - 32 : subKeyInput[i];
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

            case 8:
                toUppercase(&msg);
                printf("Converted to Uppercase: %s\n", msg.text);
                break;

            case 9:
                toLowercase(&msg);
                printf("Converted to Lowercase: %s\n", msg.text);
                break;

            case 10:
                reverseMessage(&msg);
                printf("Reversed Message: %s\n", msg.text);
                break;

            case 11:
                removeSpaces(&msg);
                printf("Spaces Removed: %s\n", msg.text);
                break;

           case 12:
    printf("Enter first message: ");
    fgets(msg.text, sizeof(msg.text), stdin);
    msg.text[strcspn(msg.text, "\n")] = 0;

    printf("Enter second message: ");
    fgets(msg2.text, sizeof(msg2.text), stdin);
    msg2.text[strcspn(msg2.text, "\n")] = 0;

    if (compareMessages(msg, msg2))
        printf("Messages are equal.\n");
    else
        printf("Messages are different.\n");
    break;

            case 13:
                printf("Enter character to count: ");
                scanf(" %c", &ch);
                printf("Count: %d\n", countCharacter(msg, ch));
                break;

            case 14:
                printf("Enter new message: ");
                fgets(msg.text, sizeof(msg.text), stdin);
                msg.text[strcspn(msg.text, "\n")] = 0;
                break;

            case 15:
                displayMessage(msg);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}


void subMenuMST() {
    int choice;
    int n, a, b;
    int T[100];   // For array operations
    int size;
    struct Matrix A, B, C, Tm; // Matrices
    int i, j;

    do {
        printf("\n--- Number, Array, and Matrix Library ---\n");
        printf("1. Check if number is even\n");
        printf("2. Check if number is prime\n");
        printf("3. GCD of two numbers\n");
        printf("4. LCM of two numbers\n");
        printf("5. Modular exponentiation\n");
        printf("6. Factorial\n");
        printf("7. Sum of digits\n");
        printf("8. Reverse a number\n");
        printf("9. Check if palindrome number\n");
        printf("10. Check perfect number\n");
        printf("11. Check Armstrong number\n");
        printf("12. Random integer between min and max\n");
        printf("13. Sum of array\n");
        printf("14. Average of array\n");
        printf("15. Max in array\n");
        printf("16. Min in array\n");
        printf("17. Sort array ascending\n");
        printf("18. Read and display matrix\n");
        printf("19. Add two matrices\n");
        printf("20. Multiply two matrices\n");
        printf("21. Transpose a matrix\n");
        printf("22. Determinant of 2x2 matrix\n");
        printf("23. Check if matrix is symmetric\n");
        printf("24. Check if matrix is identity\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {

            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("%d is %s\n", n, isEven(n) ? "even" : "odd");
                break;

            case 2:  
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPrime(n))
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);

    break;
}

            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD = %d\n", gcd(a, b));
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("LCM = %d\n", lcm(a, b));
                break;

            case 5:
                printf("Enter base, exponent, modulo: ");
                scanf("%d %d %d", &a, &b, &n);
                printf("Result = %d\n", modExp(a, b, n));
                break;

            case 6:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Factorial = %d\n", factorial(n));
                break;

            case 7:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Sum of digits = %d\n", sumDigits(n));
                break;

            case 8:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Reversed number = %d\n", reverseNumber(n));
                break;

            case 9:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("%d is %s palindrome\n", n, isPalindromeNumber(n) ? "" : "not a");
                break;

            case 10:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("%d is %s perfect number\n", n, isPerfectNumber(n) ? "" : "not a");
                break;

            case 11:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("%d is %s Armstrong number\n", n, isArmstrong(n) ? "" : "not an");
                break;

            case 12:
                printf("Enter min and max: ");
                scanf("%d %d", &a, &b);
                printf("Random number = %d\n", randominteger(a, b));
                break;

            case 13:
                printf("Enter array size: ");
                scanf("%d", &size);
                printf("Enter %d elements: ", size);
                for(i = 0; i < size; i++) scanf("%d", &T[i]);
                printf("Sum = %d\n", sumarrays(T, size));
                break;

            case 14:
                printf("Enter array size: ");
                scanf("%d", &size);
                printf("Enter %d elements: ", size);
                for(i = 0; i < size; i++) scanf("%d", &T[i]);
                printf("Average = %.2f\n", averageArray(T, size));
                break;

            case 15:
                printf("Enter array size: ");
                scanf("%d", &size);
                printf("Enter %d elements: ", size);
                for(i = 0; i < size; i++) scanf("%d", &T[i]);
                printf("Maximum = %d\n", maxArray(T, size));
                break;

            case 16:
                printf("Enter array size: ");
                scanf("%d", &size);
                printf("Enter %d elements: ", size);
                for(i = 0; i < size; i++) scanf("%d", &T[i]);
                printf("Minimum = %d\n", minArray(T, size));
                break;

            case 17:
                printf("Enter array size: ");
                scanf("%d", &size);
                printf("Enter %d elements: ", size);
                for(i = 0; i < size; i++) scanf("%d", &T[i]);
                sortAscending(T, size);
                printf("Sorted array: ");
                for(i = 0; i < size; i++) printf("%d ", T[i]);
                printf("\n");
                break;

            case 18:
                printf("Enter matrix rows and columns: ");
                scanf("%d %d", &A.rows, &A.cols);
                printf("Enter elements:\n");
                readMatrix(&A);
                printf("Matrix:\n");
                DisplayMatrix(A);
                break;

            case 19:
                printf("Enter rows and cols for matrix A: ");
                scanf("%d %d", &A.rows, &A.cols);
                printf("Enter elements of A:\n");
                readMatrix(&A);

                printf("Enter rows and cols for matrix B: ");
                scanf("%d %d", &B.rows, &B.cols);
                printf("Enter elements of B:\n");
                readMatrix(&B);

                addMatrix(&A, &B, &C);
                printf("Result of addition:\n");
                DisplayMatrix(C);
                break;

            case 20:
                printf("Enter rows and cols for matrix A: ");
                scanf("%d %d", &A.rows, &A.cols);
                printf("Enter elements of A:\n");
                readMatrix(&A);

                printf("Enter rows and cols for matrix B: ");
                scanf("%d %d", &B.rows, &B.cols);
                printf("Enter elements of B:\n");
                readMatrix(&B);

                multiplyMatrix(&A, &B, &C);
                printf("Result of multiplication:\n");
                DisplayMatrix(C);
                break;

            case 21:
                printf("Enter matrix rows and cols: ");
                scanf("%d %d", &A.rows, &A.cols);
                printf("Enter elements:\n");
                readMatrix(&A);
                transposeMatrix(&A, &Tm);
                printf("Transposed matrix:\n");
                DisplayMatrix(Tm);
                break;
case 22: // Determinant of 2x2 matrix
{
    int small[2][2];
    int i, j;

    printf("Enter 2x2 matrix elements:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &small[i][j]);

    printf("Determinant = %d\n", determinant2x2(small));
    break;
}


            case 23:
                printf("Enter matrix rows and cols: ");
                scanf("%d %d", &A.rows, &A.cols);
                printf("Enter elements:\n");
                readMatrix(&A);
                printf("Matrix is %ssymmetric\n", isSymmetric(A) ? "" : "not ");
                break;

            case 24:
                printf("Enter matrix rows and cols: ");
                scanf("%d %d", &A.rows, &A.cols);
                printf("Enter elements:\n");
                readMatrix(&A);
                printf("Matrix is %sidentity\n", isIdentityMatrix(A) ? "" : "not ");
                break;

            case 0:
                printf("Exiting MST menu...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);
}



void subMenuUserManagement() {
    struct User users[MAX_USERS];
    int n = MAX_USERS;
    int choice;
    char name[20], password[20];
    int role;

    // Initialize users
    initUsers(users, n);

    do {
        printf("\n===== Full User Management Menu =====\n");
        printf("0. Exit\n");
        printf("1. Display all users\n");
        printf("2. Add a new user\n");
        printf("3. Delete a user\n");
        printf("4. Change user password\n");
        printf("5. Search for a user\n");
        printf("6. Block a user\n");
        printf("7. Unblock a user\n");
        printf("8. Change user role\n");
        printf("9. List all admins\n");
        printf("10. Display user statistics\n");
        printf("11. Save users to file\n");
        printf("12. Load users from file\n");
        printf("13. String length\n");
        printf("14. Check contains uppercase\n");
        printf("15. Check contains lowercase\n");
        printf("16. Check contains digits\n");
        printf("17. Check contains symbol\n");
        printf("18. Check login credentials\n");
        printf("19. Strong password check\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        if (choice == 0) {
            printf("Exiting menu...\n");
            break;  // exit while loop
        }

        switch (choice) {
            case 1: displayUsers(users, n); break;
            case 2: addUser(users, n); break;
            case 3:
                printf("Enter username to delete: ");
                scanf("%s", name);
                deleteUser(users, n, name);
                break;
            case 4:
                printf("Enter username to change password: ");
                scanf("%s", name);
                changePassword(users, n, name);
                break;
            case 5:
                printf("Enter username to search: ");
                scanf("%s", name);
                int idx = searchUser(users, n, name);
                if (idx != -1)
                    printf("User found: Name=%s, Role=%d, State=%d\n",
                        users[idx].name, users[idx].role, users[idx].state);
                else
                    printf("User not found.\n");
                break;
            case 6:
                printf("Enter username to block: ");
                scanf("%s", name);
                blockUser(users, n, name);
                break;
            case 7:
                printf("Enter username to unblock: ");
                scanf("%s", name);
                unblockUser(users, n, name);
                break;
            case 8:
                printf("Enter username to change role: ");
                scanf("%s", name);
                printf("Enter new role (0=user, 1=admin): ");
                scanf("%d", &role);
                changeRole(users, n, name, role);
                break;
            case 9: listAdmins(users, n); break;
            case 10: userStatistics(users, n); break;
            case 11: saveUsers(users, n); break;
            case 12: loadUsers(users, n); break;
            case 13:
                printf("Enter string: ");
                scanf(" %[^\n]", name);
                printf("Length: %d\n", stringLength(name));
                break;
            case 14:
                printf("Enter string: ");
                scanf(" %[^\n]", name);
                printf("Contains uppercase: %d\n", containsUppercase(name));
                break;
            case 15:
                printf("Enter string: ");
                scanf(" %[^\n]", name);
                printf("Contains lowercase: %d\n", containsLowercase(name));
                break;
            case 16:
                printf("Enter string: ");
                scanf(" %[^\n]", name);
                printf("Contains digits: %d\n", containsDigits(name));
                break;
            case 17:
                printf("Enter string: ");
                scanf(" %[^\n]", name);
                printf("Contains symbol: %d\n", containsSymbol(name));
                break;
            case 18:
                printf("Enter username: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                if (checkLogin(users, n, name, password))
                    printf("Login valid.\n");
                else
                    printf("Login invalid.\n");
                break;
            case 19:
                printf("Enter password to check: ");
                scanf("%s", password);
                if (strongPassword(password))
                    printf("Password is strong.\n");
                else
                    printf("Password is weak.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }while(choice != 0);
}
#define MAX_USERS 100

void subMenuSecurity() {
    int choice;
    char text[500];
    char pass[50], key[50], email[50], name[50];
    int len;
    struct Sec_User users[MAX_USERS];
    int userCount = 0;

    do {
        printf("\n--- Security Audit & Analysis Menu ---\n");
        printf("1. Count uppercase letters\n");
        printf("2. Count lowercase letters\n");
        printf("3. Count digits\n");
        printf("4. Calculate percentage of uppercase letters\n");
        printf("5. Calculate text length\n");
        printf("6. Display text statistics\n");
        printf("7. Check if password is very strong\n");
        printf("8. Generate random key\n");
        printf("9. Verify hexadecimal key\n");
        printf("10. Generate random password\n");
        printf("11. Calculate password score\n");
        printf("12. Compute average score\n");
        printf("13. Display security report\n");
        printf("14. Count strong users\n");
        printf("15. Show security tips\n");
        printf("16. Check email format\n");
        printf("17. Check login format\n");
        printf("18. Generate hexadecimal key\n");
        printf("19. Top 3 common passwords\n");
        printf("20. Compute global security level\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1:
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                printf("Uppercase letters: %d\n", countUppercase(text));
                break;
            case 2:
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                printf("Lowercase letters: %d\n", countLowercase(text));
                break;
            case 3:
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                printf("Digits: %d\n", countDigits(text));
                break;
            case 4:
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                printf("Percentage of uppercase letters: %.2f%%\n", percentUppercase(text));
                break;
            case 5:
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                printf("Text length: %d\n", textLength(text));
                break;
            case 6:
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                displayTextStats(text);
                break;
            case 7:
                printf("Enter password: ");
                fgets(pass, sizeof(pass), stdin);
                pass[strcspn(pass, "\n")] = 0;
                if (veryStrongPassword(pass))
                    printf("Password is very strong.\n");
                else
                    printf("Password is NOT very strong.\n");
                break;
            case 8:
                printf("Enter key length: ");
                scanf("%d", &len); getchar();
                generateKey(len, key);
                printf("Generated key: %s\n", key);
                break;
            case 9:
                printf("Enter key to verify: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                if (isHexKey(key)) printf("Key is hexadecimal.\n");
                else printf("Key is NOT hexadecimal.\n");
                break;
            case 10:
                printf("Enter password length: ");
                scanf("%d", &len); getchar();
                generateRandomPassword(len, pass);
                printf("Generated password: %s\n", pass);
                break;
            case 11:
                printf("Enter password: ");
                fgets(pass, sizeof(pass), stdin);
                pass[strcspn(pass, "\n")] = 0;
                printf("Password score: %d\n", passwordScore(pass));
                break;
            case 12:
                if(userCount == 0) printf("No users available.\n");
                else printf("Average score: %.2f\n", averageScore(users, userCount));
                break;
            case 13:
                if(userCount == 0) printf("No users available.\n");
                else displaySecurityReport(users, userCount);
                break;
            case 14:
                if(userCount == 0) printf("No users available.\n");
                else countStrongUsers(users, userCount);
                break;
            case 15:
                showSecurityTips();
                break;
            case 16:
                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                if (checkEmailFormat(email)) printf("Email is valid.\n");
                else printf("Email is invalid.\n");
                break;
            case 17:
                printf("Enter username: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter password: ");
                fgets(pass, sizeof(pass), stdin);
                pass[strcspn(pass, "\n")] = 0;
                if (isValidLogin(name, pass)) printf("Login format is valid.\n");
                else printf("Login format is invalid.\n");
                break;
            case 18:
                printf("Enter hex key length: ");
                scanf("%d", &len); getchar();
                generateHexKey(len, key);
                printf("Generated hex key: %s\n", key);
                break;
            case 19:
                if(userCount == 0) printf("No users available.\n");
                else top3Passwords(users, userCount);
                break;
            case 20:
                if(userCount == 0) printf("No users available.\n");
                else printf("Global security level: %.2f\n", globalSecurityLevel(users, userCount));
                break;
            case 0:
                printf("Exiting Security menu...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 0);
}

#define INFO 0
#define WARNING 1
#define ERROR 2
#define EMPTY -1
#define MAX_LOGS 100
void subMenuLogs() {
    int choice;
    int n = 100;                // maximum number of logs
    struct Log logs[n];
    char user[50], action[50], date[20], time[10];
    int code, count, days;

    initLogs(logs, n);          // initialize logs

    do {
        printf("\n--- Log Management and Analysis ---\n");
        printf("1. Add log entry\n");
        printf("2. Display all logs\n");
        printf("3. Search logs by user\n");
        printf("4. Search logs by date\n");
        printf("5. Count error entries\n");
        printf("6. Count login events\n");
        printf("7. Count blocked attempts\n");
        printf("8. Show log statistics\n");
        printf("9. Sort logs by date\n");
        printf("10. Sort logs by user\n");
        printf("11. Detect suspicious activity\n");
        printf("12. Count daily connections\n");
        printf("13. Compute error percentage\n");
        printf("14. Export logs to CSV\n");
        printf("15. Import logs from CSV\n");
        printf("16. Clear all logs\n");
        printf("17. Display last events\n");
        printf("18. Archive old logs\n");
        printf("19. Display top frequent errors\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {

            case 1:
                printf("Enter user: ");
                fgets(user, sizeof(user), stdin);
                user[strcspn(user, "\n")] = 0;

                printf("Enter action: ");
                fgets(action, sizeof(action), stdin);
                action[strcspn(action, "\n")] = 0;

                printf("Enter code (0=INFO, 1=WARNING, 2=ERROR): ");
                scanf("%d", &code);

                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);

                printf("Enter time (HH:MM): ");
                scanf("%s", time);

                addLog(logs, n, user, action, code);
                break;

            case 2:
                displayLogs(logs, n);
                break;

            case 3:
                printf("Enter user to search: ");
                fgets(user, sizeof(user), stdin);
                user[strcspn(user, "\n")] = 0;
                searchLogsByUser(logs, n, user);
                break;

            case 4:
                printf("Enter date to search (YYYY-MM-DD): ");
                scanf("%s", date);
                searchLogsByDate(logs, n, date);
                break;

            case 5:
                printf("Total error entries: %d\n", countErrors(logs, n));
                break;

            case 6:
                printf("Total login events: %d\n", countLoginLogs(logs, n));
                break;

            case 7:
                printf("Total blocked attempts: %d\n", countBlockedAttempts(logs, n));
                break;

            case 8:
                showLogStatistics(logs, n);
                break;

            case 9:
                sortLogsByDate(logs, n);
                printf("Logs sorted by date.\n");
                break;

            case 10:
                sortLogsByUser(logs, n);
                printf("Logs sorted by user.\n");
                break;

            case 11:
                printf("Enter user to check suspicious activity: ");
                fgets(user, sizeof(user), stdin);
                user[strcspn(user, "\n")] = 0;
                detectSuspiciousActivity(logs, n, user);
                break;

            case 12:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Daily connections: %d\n", countDailyConnections(logs, n, date));
                break;

            case 13:
                printf("Error percentage: %.2f%%\n", computeErrorPercentage(logs, n));
                break;

            case 14:
                exportLogsCSV(logs, n);
                break;

            case 15:
                importLogsCSV(logs, n);
                break;

            case 16:
                clearLogs(logs, n);
                printf("All logs cleared.\n");
                break;

            case 17:
                printf("Enter number of last events to display: ");
                scanf("%d", &count);
                displayLastEvents(logs, n, count);
                break;

            case 18:
                printf("Enter number of days to archive old logs: ");
                scanf("%d", &days);
                archiveOldLogs(logs, n, days);
                printf("Old logs archived.\n");
                break;

            case 19:
                displayTopFrequentErrors(logs, n);
                break;

            case 0:
                printf("Exiting log menu...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 0);
}

void displayHelp() {
    printf("\n==================== PROGRAM HELP ====================\n");
    printf("HOW TO NAVIGATE:\n");
    printf("  [Numbers] : Type the number of the menu option and press Enter.\n");
    printf("  [M]       : Return to the Main Menu from any sub-menu.\n");
    printf("  [Q/0]     : Securely exit the application.\n");
    printf("\nCORE CONCEPTS:\n");
    printf("  - Encryption: Requires a valid key/passphrase to proceed.\n");
    printf("  - Analysis:   Generates reports in the /output/ directory.\n");
    printf("  - Logs:       Real-time monitoring of system events.\n");
    printf("\nNote: Ensure you have sufficient permissions for Option 3 & 4.\n");
    printf("======================================================\n");
}
void displayAbout(){
    printf("\n--- about ---\n");
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
                subMenuMST();
                break;
            case 3:
                // Sous-menu gestion des utilisateurs
                subMenuUserManagement();
                break;
            case 4:
                // Sous-menu audit de sécurité
                subMenuSecurity();
                break;

            case 5:
                // Sous-menu gestion des logs
               subMenuLogs();
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

 