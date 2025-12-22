#include <stdio.h>
#include <stdlib.h>
#include "MST.h" 
#include "E&D.h"
#include "UserMan.h"
#include "secAud&Ana.h"


// Main function making use of the Math and Security Tools Library
int main() {
    // ---------- Array Operations ----------
    int arr[5] = {1, 2, 3, 4, 5};

    // Number-related functions
    printf("isEven(10) = %d\n", isEven(10));
    printf("isPrime(11) = %d\n", isPrime(11));
    printf("gcd(24,18) = %d\n", gcd(24,18));
    printf("lcm(4,6) = %d\n", lcm(4,6));
    printf("modExp(3,5,7) = %d\n", modExp(3,5,7));
    printf("factorial(5) = %d\n", factorial(5));
    printf("sumDigits(12345) = %d\n", sumDigits(12345));
    printf("reverseNumber(1234) = %d\n", reverseNumber(1234));
    printf("isPalindromeNumber(1221) = %d\n", isPalindromeNumber(1221));
    printf("sumDivisors(12) = %d\n", sumDivisors(12));
    printf("isPerfectNumber(28) = %d\n", isPerfectNumber(28));
    printf("isArmstrong(153) = %d\n", isArmstrong(153));
    printf("randominteger(1,10) = %d\n", randominteger(1,10));

    // Array-related functions
    printf("sumarrays(arr,5) = %d\n", sumarrays(arr,5));
    printf("averageArray(arr,5) = %.2f\n", averageArray(arr,5));
    printf("maxArray(arr,5) = %d\n", maxArray(arr,5));
    printf("minArray(arr,5) = %d\n", minArray(arr,5));

    // Sort array in ascending order
    sortAscending(arr, 5);
    printf("Sorted array: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ---------- Matrix Operations ----------
    // Define Matrix struct
    struct Matrix {
        int M[100][100];  // 2D array to store matrix elements
        int rows;         // Number of rows
        int cols;         // Number of columns
    };

    struct Matrix A, B, C;

    // Input matrix A
    printf("Enter rows and cols of matrix A: ");
    scanf("%d %d", &A.rows, &A.cols);

    printf("Enter matrix A values:\n");
    readMatrix(&A);           // Custom function to read matrix elements
    printf("Matrix A:\n");
    DisplayMatrix(A);         // Custom function to display matrix

    // Input matrix B
    printf("Enter rows and cols of matrix B: ");
    scanf("%d %d", &B.rows, &B.cols);

    printf("Enter matrix B values:\n");
    readMatrix(&B);
    printf("Matrix B:\n");
    DisplayMatrix(B);

    // Add matrices
    if (A.rows == B.rows && A.cols == B.cols) {
        addMatrix(&A, &B, &C);   // Custom function to add matrices
        printf("Result matrix C = (A + B):\n");
        DisplayMatrix(C);
    } else {
        printf("Matrix sizes do not match for addition!\n");
    }

    // Multiply matrices
    if (A.cols == B.rows) {
        multiplyMatrix(&A, &B, &C);  // Custom function to multiply matrices
        printf("Result matrix C = (A * B):\n");
        DisplayMatrix(C);
    } else {
        printf("Matrix sizes are incompatible for multiplication!\n");
    }
    //transpose matrix A
     struct Matrix T;
    transposeMatrix(&A, &T);  // Custom function to transpose matrix
    printf("Transposed Matrix T of A:\n");
    DisplayMatrix(T);
    // diterminent of 2x2 matrix
    if (A.rows == 2 && A.cols == 2) {
        int det = determinant2x2(A.M);
        printf("Determinant of matrix A: %d\n", det);
    } else {
        printf("Matrix A is not 2x2, cannot compute determinant 2*2 .\n");
    }
    // isSymmetric matrix 
    if (isSymmetric(A)) {
        printf("Matrix A is symmetric.\n");
    } else {
        printf("Matrix A is not symmetric.\n");
    }
    // isIdentity matrix
    if (isIdentityMatrix(A)) {
        printf("Matrix A is identity.\n");
    } else {
        printf("Matrix A is not identity.\n");
    }
    
     //................................................end of MATH AND SECURITY TOOLS LIBRARY ..................................................



  

//  Main function making use of Encryption and Decryption Library

    struct Message m[200];  // Array of messages 
    
    // Example substitution key
    char key[26] = "QWERTYUIOPASDFGHJKLZXCVBNM"; 

    // --- Input and display message ---
    inputMessage(&m[0]);  // Input message
    printf("Original message:\n");
    displayMessage(m[0]);

    // --- Convert message to uppercase ---
    toUppercase(m[0]);
    printf("After converting to uppercase:\n");
    displayMessage(m[0]);

    // --- Convert message to lowercase ---
    toLowercase(m[0]);
    printf("After converting to lowercase:\n");
    displayMessage(m[0]);

    // --- Reverse the message ---
    reverseMessage(m[0]);
    printf("After reversing the message:\n");
    displayMessage(m[0]);

    // --- Remove spaces ---
    removeSpaces(m[0]);
    printf("After removing spaces:\n");
    displayMessage(m[0]);

    // --- Caesar cipher encryption ---
    encryptCesar(m[0], 3);
    printf("After Caesar cipher encryption with key 3:\n");
    displayMessage(m[0]);

    // --- Caesar cipher decryption ---
    decryptCesar(m[0], 3);
    printf("After Caesar cipher decryption with key 3:\n");
    displayMessage(m[0]);

    // --- XOR cipher encryption ---
    encryptXOR(m[0], 5);
    printf("After XOR cipher encryption with key 5:\n");
    displayMessage(m[0]);

    // --- XOR cipher decryption ---
    decryptXOR(m[0], 5);
    printf("After XOR cipher decryption with key 5:\n");
    displayMessage(m[0]);

    // --- Substitution cipher encryption ---
    encryptSubstitution(m[0], key);
    printf("After Substitution cipher encryption:\n");
    displayMessage(m[0]);

    // --- Substitution cipher decryption ---
    decryptSubstitution(m[0], key);
    printf("After Substitution cipher decryption:\n");
    displayMessage(m[0]);

    // --- Validate substitution key ---
    if (isValidKey(key)) {
        printf("The substitution cipher key is valid.\n");
    } else {
        printf("The substitution cipher key is invalid.\n");
    }

    // --- Count occurrences of character 'A' ---
    int count = countCharacter(m[0], 'A');
    printf("The character 'A' occurs %d times in the message.\n", count);

    // --- Frequency analysis (function implementation assumed) ---
    printf("Frequency analysis of the message:\n");
    frequencyAnalysis(m[0]);
    //--- Calculate coincidence index ---
    float index = coincidenceIndex(m[0]);
    printf("Coincidence index of the message: %.4f\n", index);
    
  
//................................end of ENCRYPTION AND DECRYPTION LIBRARY ..............................................



//  Main function making use of User management Library
#define ACTIVE  0
#define BLOCKED 1
#define EMPTY   2

struct User {
    char name[20];
    char password[20];
    int role;   // 0: user, 1: admin
    int state;  // ACTIVE, BLOCKED, EMPTY
};


  
     struct User users[100];
     int n = 100; // Current number of users

      // -------Initialize users--------
     initUsers(users, 100);
      //-------- Display users----------
     displayUsers(users, n); 
      // --------Add a new user----------
     addUser(users, n);
      //--------- delete a user----------
        char nameToDelete[20];
     DeleteUser(users, n, nameToDelete);
      //----------  search for a user----
        char nameToSearch[20];
        int index = searchUser(users, n, nameToSearch);
        if (index != -1) {
            printf("User found at index %d\n", index);
        } else {
            printf("User not found\n");
        }
        // ............................Change password for a user
        char nameToChange[20];
        printf("Enter name of user to change password: ");
        scanf("%19s", nameToChange);
        changepassword(users, n, nameToChange);
        // ............................Check login credentials
        char loginName[20], loginPass[20];
        printf("Enter login name: ");
        scanf("%19s", loginName);
        printf("Enter login password: ");
        scanf("%19s", loginPass);
        if (checkLogin(users, n, loginName, loginPass)) {
            printf("Login successful.\n");
        } else {
            printf("Invalid credentials.\n");
        }
        // ............................Check if a password is strong
        char passwordToCheck[20];
        printf("Enter password to check strength: ");
        scanf("%19s", passwordToCheck);
        if (strongPassword(passwordToCheck)) {
            printf("The password is strong.\n");
        } else {
            printf("The password is weak.\n");
        }
        //............................ Block a user
        char nameToBlock[20];
        printf("Enter name of user to block: ");
        scanf("%19s", nameToBlock);
        blockUser(users, n, nameToBlock);
        // ...........................Unblock a user
        char nameToUnblock[20];
        printf("Enter name of user to unblock: ");
        scanf("%19s", nameToUnblock);
        unblockUser(users, n, nameToUnblock);
        // ............................Change role of a user
        char nameToChangeRole[20];
        printf("Enter name of user to change role: ");
        scanf("%19s", nameToChangeRole);
        int newRole;
        printf("Enter new role (0 for user, 1 for admin): ");
        scanf("%d", &newRole);
        changeRole(users, n, nameToChangeRole, newRole);
        // ............................List all admin users
        listAdmins(users, n);
        // ............................string length
        char strToMeasure[100];
        printf("Enter string to measure length: ");
        scanf("%99s", strToMeasure);
        int length = stringLength(strToMeasure);
        printf("Length of the string: %d\n", length);
        // ............................Check for uppercase, lowercase, digit, symbol
        char strToCheck[100];
        printf("Enter string to check for character types: ");
        scanf("%99s", strToCheck);
        containsUppercase(strToCheck);
        containsLowercase(strToCheck);
        containsDigit(strToCheck);
        containsSymbol(strToCheck);
        // ............................ Display user statistics
        userStatistics(users, n);
        // ............................ Save users to file
        saveUsers(users, n);
        // ............................ Load users from file
        loadUsers(users, n);
        //................................end of USER MANAGEMENT LIBRARY ..............................................
        

        //...............//  Main function making use of Security Audit and Analysis Library

        struct User {
    char name[50];
    char password [20];
    int score;

    };
    char text[200];
     char pass[50];
     char key [50];
     n = 50;
    //........................Counts uppercase letters.
    printf("Enter text for analysis: ");
       coutUppercase(text);
    //........................Counts lowercase letters.
       countLowercase(text);  
    //........................Counts digits.
       countDigits (text);
    //......................... calculates percentage of Uppercase letters in text
       percentUppercase(text);
    //......................... calculates length of text
       textLength(text);
    //........................displays text statistics
        displayTextStats(text);
    //.........................Checks if password is very strong
        veryStrongPassword(pass);
    //.........................Generates  key.
        generateKey(16, key); 
    //.........................Verifies hexadecimal format
        isHexKey(key);
    //.........................Generates random password.
        generateRandomPassword(12, pass);
    //..........................Calculates password score.
        passwordScore(pass);
    //.........................Computes average score
        averageScore(users, n);
    //.........................Displays global report
        displaySecurityReport(users, n);
    //..........................Counts users with strong passwords.
        countStrongUsers(users, n);
    //...........................Shows security tips.
        showSecurityTips();
    //...........................Verifies valid email format.
        isValidEmail("ferrahmohamedfrrh@gmail.com");
    //...........................Verifies login validity.
        isValidLogin("ferrah", "ZITKHARWA3");
    //...........................  Generates hexadecimal key.
        generateHexKey(16, key);
    //........................... Displays top 3 passwords.
        top3Passwords(users, n);
    //........................... Computes global level.
        globalSecurityLevel(users, n);



        //....................----------------------------------end of Security audit and analysis lib----------------------...................



         //...............//  Main function making use of Log management and analysis Library

    struct Log{
char user[20];
char action[50];
char date[20];
char time[10];
int code; // 0 info, 1 warning, 2 error
};
#define INFO 0
#define WARNING 1
#define ERROR 2

struct Log logs[100];
n = 100 ; // current number of logs


//...........................Initializes log list.
   initLogs(logs, n);
//...........................adds a log entry
    addLog(logs, n, "user1", "Login", INFO);
//...........................displays all logs
    DisplayLogs(logs, n);
//...........................searches logs by user
    searchLogsByUser(logs, n, "user1");
//..........................searches logs by date
    searchLogsByDate(logs, n, "20007-05-12");
//..................counts error entries
    countErrors(logs, n);
//..................counts login events
    countLoginLogs(logs, n);
//..................counts blocked attempts
    countBlockedAttempts(logs, n);
//..................shows statistics
    showLogStatistics(logs, n);
//...........................Sorts logs by date
    sortLogsByDate(logs, n);
//...........................sorts logs by user 
    sortLogsByUser(logs,n);
//...........................Detects anomalies.
    detectSuspiciousActivity(logs , n , "ferrah");
//...........................counts daily connections
   countDailyConnections(logs , n , "2007-05-12");*
//...........................computes error percentage
   computeErrorPercentage(logs,n);
//...........................Exports logs to CSV.
   exportLogsCSV(logs,n);
//...........................import logs from CSV
   importLogsCSV(logs,n);
//...........................clears all logs
   clearLogs(logs,n);
//...........................displays last events
   displayLastEvents(logs,n,5);
//...........................archives old logs
   archiveOldLogs(logs,n,30);
//...........................displays top frequent errors.
   showTopErrors(logs,n);

   //--------------------------------------------------------------------------end of Log management and analysis lib----------------------.....................

return 0 ; 
}