#ifndef MST_H
#define MST_H



 
// ---------------- Number Functions ----------------

// Check if a number is even
int isEven(int n);

// Check if a number is prime
int isPRIME(int n);

// Compute the Greatest Common Divisor of a and b
int gcd(int a, int b);

// Compute the Least Common Multiple of a and b
int lcm(int a, int b);

// Compute (base^exp) % mod efficiently
int modExp(int base, int exp, int mod);

// Compute factorial of n
int factorial(int n);

// Sum of digits of n
int sumDigits(int n);

// Reverse the digits of n
int reverseNumber(int n);

// Check if n is a palindrome number
int isPalindromeNumber(int n);

// Sum of proper divisors of n
int sumDivisors(int n);

// Check if n is a perfect number
int isPerfectNumber(int n);

// Check if n is an Armstrong number
int isArmstrong(int n);

// Generate a random integer between min and max (inclusive)
int randominteger(int min, int max);

// ---------------- Array Functions ----------------

// Sum of elements in array T of length n
int sumarrays(int T[], int n);

// Average of elements in array T of length n
float averageArray(int T[], int n);

// Maximum element in array T of length n
int maxArray(int T[], int n);

// Minimum element in array T of length n
int minArray(int T[], int n);

// Sort array T of length n in ascending order
void sortAscending(int T[], int n);

// ---------------- Data Structures ----------------

struct Matrix{
int M[100][100];
int rows;
int cols;
}; 

struct Array {
int T[100][100];
int n;          // Usually size or dimension 
};
 
// ---------------- Matrix Functions ----------------

// Display contents of struct Matrix
void DisplayArray(struct Matrix A);
// Read matrix elements into struct Matrix
void readMatrix(struct Matrix *A);
// Add matrices A and B, store result in C
void addMatrix(struct Matrix *A, struct Matrix *B, struct Matrix *C);

// Multiply matrices A and B, store result in C
void multiplyMatrix(struct Matrix *A, struct Matrix *B, struct Matrix *C);

// Compute transpose of matrix A and store in T
void transposeMatrix(struct Matrix *A, struct Matrix *T);

// Compute determinant of 2x2 matrix A
int determinant2x2(int A[2][2]);

// Check if matrix A is symmetric (A == transpose of A)
int isSymmetric(struct Matrix A);

// Check if matrix A is an identity matrix
int isIdentityMatrix(struct Matrix A);

#endif 