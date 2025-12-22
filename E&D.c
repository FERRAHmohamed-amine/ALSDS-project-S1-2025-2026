#include<stdio.h>
#include<string.h>


struct Message{
char text[200];
int length;
};

 // Function to input a message
 void inputMessage(struct Message m[]){
    printf("Enter a message:");
    scanf("%s", m[0].text);
 }
 // Function to display a single message
 void displayMessage(struct Message m){
    printf("Message: %s\n", m.text);
 }
 // Check if character is uppercase letter
 int isUppercase(char c){
    if (c >= 'A' && c <= 'Z')
    return 1 ;
    else 
    return 0 ;
 }
    // Check if character is lowercase letter
    int isLowercase(char c){    
    if (c >= 'a' && c <= 'z')
    return 1 ;
    else            
    return 0 ;
 }
    // Check if character is alphabetic (A-Z or a-z)
    int isAlphabetic(char c){
    if( (isUppercase(c)) || (isLowercase(c)) )
    return 1 ;
    else 
    return 0 ;
    }
    // Convert all characters in message to uppercase
    void toUppercase(struct Message m){
    for(int i=0; m.text[i]!='\0'; i++){
        if(isLowercase(m.text[i])){
            m.text[i] = m.text[i] - ('a' - 'A');
        }
    }
}
    // Convert all characters in message to lowercase
    void toLowercase(struct Message m){
    for(int i=0; m.text[i]!='\0'; i++){
        if(isUppercase(m.text[i])){
            m.text[i] = m.text[i] + ('a' - 'A');
        }
    }
}
    // Reverse the characters in message
void reverseMessage(struct Message m){
    int len = strlen(m.text) ;
    for (int i = 0 ; i < len / 2 ; i++){
         char temp = m.text[i] ;
         m.text[i] = m.text[len - 1 - i] ;
         m.text[len - 1 - i] = temp ;        
    }
}
    // remove all spaces from message 
    void removeSpaces(struct Message m){
      int i , j ; 
    for ( i = 0 ; i < strlen(m.text) ; i++ ){
        if(m.text[i] == ' ') 
        for ( j = i ; j < strlen(m.text) ; j++){
            m.text[j] = m.text[j+1] ; 
             }
             i-- ;
        }
    }
    // Encrypt message using Caesar cipher with key
    void encryptCesar(struct Message m, int key){
         for (int i = 0 ; m.text[i] != '\0' ; i++ ){
            if (isUppercase(m.text[i])){
                m.text[i] = ( (m.text[i] - 65 + key) % 26 ) + 65 ;
            }
            else if(isLowercase(m.text[i])){
                m.text[i] = ( (m.text[i] - 97 + key + 26) % 26 ) + 97 ;
            }
         }
         printf ("Encryption done using Caesar cipher with key %d\n", key);
         printf ("Encrypted message: %s\n", m.text);
    }
   // Decrypt message using Caesar cipher with key
    void decryptCesar(struct Message m, int key){
            for (int i = 0 ; m.text[i] != '\0' ; i++ ){
                if (isUppercase(m.text[i])){
                 m.text[i] = ( (m.text[i] - 65 - key + 26) % 26 ) + 65 ;
                }
                else if(isLowercase(m.text[i])){
                 m.text[i] = ( (m.text[i] - 97 - key + 26) % 26 ) + 97 ;
                }
            }
            printf ("Decryption done using Caesar cipher with key %d\n", key);
            printf ("Decrypted message: %s\n", m.text);
     }
     // Encrypt message using XOR cipher with key
     void encryptXOR(struct Message m, int key){
        for (int i = 0 ; m.text[i] != '\0' ; i++ ){
            m.text[i] = m.text[i] ^ key ;
        }
        printf ("Encryption done using XOR cipher with key %d\n", key);
        printf ("Encrypted message: %s\n", m.text);
     }
        // Decrypt message using XOR cipher with key
        void decryptXOR(struct Message m, int key){ 
        for (int i = 0 ; m.text[i] != '\0' ; i++ ){
            m.text[i] = m.text[i] ^ key ;
        }
        printf ("Decryption done using XOR cipher with key %d\n", key);
        printf ("Decrypted message: %s\n", m.text);
        }
    // Encrypt message using substitution cipher with given key array
    void encryptSubstitution(struct Message m, int key[26]){
        for (int i = 0 ; m.text[i] != '\0' ; i++ ){
            if (isUppercase(m.text[i])){
                m.text[i] = key[m.text[i] - 65] ;
            }
            else if(isLowercase(m.text[i])){
                m.text[i] = key[m.text[i] - 97] + 32 ;
            }
        }
         printf ("Encryption done using Substitution cipher\n");
            printf ("Encrypted message: %s\n", m.text);
    }
    // Decrypt message using substitution cipher with given key array
    void decryptSubstitution(struct Message m, int key[26]){
        char reverseKey[26];
        for (int i = 0 ; i < 26 ; i++ ){
            reverseKey[key[i] - 65] = i + 65 ;
        }
        for (int i = 0 ; m.text[i] != '\0' ; i++ ){
            if (isUppercase(m.text[i])){
                m.text[i] = reverseKey[m.text[i] - 65] ;
            }
            else if(isLowercase(m.text[i])){
                m.text[i] = reverseKey[m.text[i] - 97] + 32 ;
            }
        }
         printf ("Decryption done using Substitution cipher\n");
            printf ("Decrypted message: %s\n", m.text);
    }
    // Validate if substitution cipher key is valid 
   int isValidKey(char key[26]) {
    int count[26] = {0};

    for (int i = 0; i < 26; i++) {
       
        char c = key[i];
        if (c >= 'a' && c <= 'z')
         c -= 32; 

        if (c < 'A' || c > 'Z') {
            return 0;  
        }
        count[c - 'A']++;
    }

   
    for (int i = 0; i < 26; i++) {
        if (count[i] != 1) return 0;
    }

    return 1; 
 } // Compare two messages for equality
int compareMessages(struct Message m1, struct Message m2){
    if (strcmp(m1.text, m2.text) == 0) 
    return 1 ;
    else 
    return 0 ;
}
    // Count occurrences of character c in message
int countCharacter(struct Message m, char c){
    int count = 0 ;
    for (int i = 0 ; m.text[i] != '\0' ; i++ ){
        if (m.text[i] == c){
            count++ ;
        }
    }
    return count ;
}
   // Perform frequency analysis of characters in message
   void frequencyAnalysis(struct Message m) {
    printf("Letter frequency analysis:\n");

    for (char c = 'A'; c <= 'Z'; c++) {
            int count = countCharacter(m, c);
        if (count > 0) {
            printf("%c : %d\n", c, count);
        }

    } for (char c = 'a'; c <= 'z'; c++) {
            int count = countCharacter(m, c);
        if (count > 0) {
            printf("%c : %d\n", c , count);
        }
         
    }
}
 // Calculate coincidence index for message (
 float coincidenceIndex(struct Message m){
    int T = 0 ;
    int N = strlen(m.text);
    int count[26] = {0};
    for (int i = 0 ; i < N ; i++ ){
        char c = m.text[i] ;
        if (isUppercase(c)){
            count[c - 'A']++ ;
            T++ ;
        }
        else if (isLowercase(c)){
            count[c - 'a']++ ;
            T++ ;
        }
    }
     
    float index = 0.0 ;
    for (int i = 0 ; i < 26 ; i++ ){
        index += (count[i] * (count[i] - 1)) ;
    }
    index /= (T * (T - 1)) ;
    return index ;
 }

 //..............................................................................................................................end of E&D.c......
 //.........if you want to check go to main.c and call the functions there ............................................................................