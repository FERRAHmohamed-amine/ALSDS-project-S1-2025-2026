#ifndef E_AND_D_H
#define E_AND_D_H

struct Message{
char text[200];
int length;
};
 

// Define your Message struct in your .c or another header before using these functions

// Input multiple messages (array of Message)
void inputMessage(struct Message m[]);

// Display a single message
void displayMessage(struct Message m);

// Check if character is uppercase letter
int isUppercase(char c);

// Check if character is lowercase letter
int isLowercase(char c);

// Check if character is alphabetic (A-Z or a-z)
int isAlphabetic(char c);

// Convert all characters in message to uppercase
void toUppercase(struct Message *m);

// Convert all characters in message to lowercase
void toLowercase(struct Message *m);

// Reverse the characters in message
void reverseMessage(struct Message *m);

// Remove all spaces from message
void removeSpaces(struct Message *m);

// Encrypt message using Caesar cipher with key
void encryptCesar(struct Message m, int key);

// Decrypt message using Caesar cipher with key
void decryptCesar(struct Message m, int key);

// Encrypt message using XOR cipher with key
void encryptXOR(struct Message m, int key);

// Decrypt message using XOR cipher with key
void decryptXOR(struct Message m, int key);

// Encrypt message using substitution cipher with given key array
void encryptSubstitution(struct Message m, int key[26]);

// Decrypt message using substitution cipher with given key array
void decryptSubstitution(struct Message m, int key[26]);

// Validate if substitution cipher key is valid (permutation of A-Z)
int isValidKey(char key[26]);

// Compare two messages for equality
int compareMessages(struct Message m1, struct Message m2);

// Count occurrences of character c in message
int countCharacter(struct Message m, char c);

// Perform frequency analysis of characters in message
void frequencyAnalysis(struct Message m);

// Calculate coincidence index for message (for cryptanalysis)
float coincidenceIndex(struct Message m);


#endif 