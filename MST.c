#include <stdio.h>
#include <stdlib.h>   // For rand()
#include <math.h>
#include "MST.h"      


struct Matrix{
int data[10][10];
int n, p;
}; 

// ------------------- Number Functions -------------------

// Check if a number is even
int isEven(int n) {
    if (n % 2 == 0) 
    return 1;
    return 0;
}

// Check if a number is prime
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

// GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM using GCD
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result = (result * base) % mod;
    return result;
}

// Factorial
int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

// Sum of digits
int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Reverse a number
int reverseNumber(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

// Check if number is a palindrome
int isPalindromeNumber(int n) {
    return n == reverseNumber(n);
}

// Sum of proper divisors
int sumDivisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0)
            sum += i;
    return sum;
}

// Check perfect number
int isPerfectNumber(int n) {
    return sumDivisors(n) == n;
}

// Check Armstrong number
int isArmstrong(int n) {
    int original = n;
    int digits = 0, temp = n, sum = 0;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp > 0) {
        int d = temp % 10;
        sum += pow(d, digits);
        temp /= 10;
    }

    return sum == original;
}

// Random integer between min and max
int randominteger(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// ------------------- Array Functions -------------------

// Sum of array
int sumarrays(int T[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += T[i];       // Fixed typo: sum=+T[i] -> sum += T[i]
    return sum;
}

// Average of array
float averageArray(int T[], int n) {
    if (n <= 0) return 0;
    return (float)sumarrays(T, n) / n;
}

// Maximum element in array
int maxArray(int T[], int n) {
    if (n <= 0) return 0;
    int max = T[0];
    for (int i = 1; i < n; i++)
        if (T[i] > max) max = T[i];
    return max;
}

// Minimum element in array
int minArray(int T[], int n) {
    if (n <= 0) return 0;
    int min = T[0];
    for (int i = 1; i < n; i++)
        if (T[i] < min) min = T[i];
    return min;
}

// Sort array in ascending order (Bubble Sort)
void sortAscending(int T[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

// ------------------- Matrix Structures -------------------

struct Matrix {
    int M[100][100];
    int rows;
    int cols;
};

// Display a matrix
void DisplayMatrix(struct Matrix A) {
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++)
            printf("%d  ", A.M[i][j]);
        printf("\n");
    }
}

// Read matrix from input
void readMatrix(struct Matrix *A) {
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            scanf("%d", &A->M[i][j]);
}

// Add two matrices
void addMatrix(struct Matrix *A, struct Matrix *B, struct Matrix *C) {
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("Matrix sizes do not match for addition!\n");
        return;
    }

    C->rows = A->rows;
    C->cols = A->cols;

    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            C->M[i][j] = A->M[i][j] + B->M[i][j];
}

// Multiply two matrices
void multiplyMatrix(struct Matrix *A, struct Matrix *B, struct Matrix *C) {
    if (A->cols != B->rows) {
        printf("Incompatible matrix sizes for multiplication!\n");
        return;
    }

    C->rows = A->rows;
    C->cols = B->cols;

    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C->M[i][j] = 0;
            for (int k = 0; k < A->cols; k++)
                C->M[i][j] += A->M[i][k] * B->M[k][j];
        }
    }
}

// Transpose a matrix
void transposeMatrix(struct Matrix *A, struct Matrix *T) {
    T->rows = A->cols;
    T->cols = A->rows;

    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            T->M[j][i] = A->M[i][j];
}
// determine matrix 2*2
int determinant2x2(int A[2][2]){
    return (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
}
// isSymmetric matrix
struct Matrix T ;
int isSymmetric(struct Matrix A) {
    if (A.rows != A.cols) return 0;
    transposeMatrix(&A, &T);
    for (int i = 0 ; i <A.rows ; i++){
        for (int j = 0 ; j < A.cols ; j++ ){
            if( A.M[i][j] == T.M[i][j]){
                return 1 ;
            }
            else
            return 0 ;
        }
    }
}
 // isIdentity matrix
int isIdentityMatrix(struct Matrix A) {
    if(A.rows != A.cols) return 0;
    for (int i = 0 ; i < A.rows ; i++ ){
    for (int j = 0 ; j < A.rows ; j++ ){
        if (i==j && A.M[i][j] ==1 || i != j && A.M[i][j] == 0){
            return 1 ;
            else 
            return 0 ;
        }

    }
}
}
// End of MST.c
 //..................if you want to use this function call it in main.c  .............................................................................. 