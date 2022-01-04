/*
 * Assignment 1 - Encryption/Decryption (Redo-PostGrad Test #1)
 * CSCI 247 - Fall 2019
 * 
 * Rowena (Yum Bie) Tchao
 * #W00678226
 */

// Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Constant
#define SIZE 7 // maximum size of decimal array
#define sSIZE 8 // maxiumum size of septet bit array

// Function prototypes
void hexDec(char *hex, int dec[]);
void key2XOR(int dec[], int key2[], int size);
void shuffleNibbles(int dec[], int shuffle[], int size);
void key1XOR(int shuffle[], int key1[], int size);
void groupSeptets(char *septets1, char *septets2, char *septets3, char *septets4, int shuffle[], int size);
int binCon(int num);
void charBin(int bin, char *binChar);
void rotateSeptets(char *septets1, char *septets2, char *septets3, char *septets4, int size);
void translateSeptets(char *septets1, char *septets2, char *septets3, char *septets4, int size, char *translate);
void septChar(int dec, char *translate, int charNum);

int main (int argc, char *argv[]) {
    // Check for 2 command-line arguments
    if (argc < 2) {
        puts("Usage: ./A1_redo DBC2233\n");
        return 1; //Indicates unsuccessful termination.
    }

    // Key 1: E1879F3 (E, 1, 8, 7, 9, F, 3)
    int key1[SIZE] = {14, 1, 8, 7, 9, 15, 3};

    // Key 2: EFBF964 (E, F, B, F, 9, 6, 4)
    int key2[SIZE] = {14, 15, 11, 15, 9, 6, 4};

    // Decimal storage
    int dec[SIZE];

    printf("Encrypted hexadecimal digits: %s\n\n", argv[1]);

    hexDec(argv[1], dec);

    puts("Converting hexadecimal digits into decimal numbers.");
    for(int i = 0; i < SIZE; i++) {
        printf("Decimal #: %d\t", dec[i]);
    }

    key2XOR(dec, key2, SIZE);

    printf("\n\n");
    puts("Exclusive OR with Key 2.");
    for(int i = 0; i < SIZE; i++) {
        printf("K2XOR Decimal #: %d\t", dec[i]);
    }

    // Shuffled nibbles storage
    int shuffle[SIZE];

    shuffleNibbles(dec, shuffle, SIZE);

    printf("\n\n");
    puts("Shuffle the nibbles.");
    for(int i = 0; i < SIZE; i++) {
        printf("Shuffled Decimal #: %d\t", shuffle[i]);
    }

    key1XOR(shuffle, key1, SIZE);

    printf("\n\n");
    puts("Exclusive OR with Key 1.");
    for(int i = 0; i < SIZE; i++) {
        printf("K1XOR Decimal #: %d\t", shuffle[i]);
    }

    // Four 7-bit septets storage
    char septets1[sSIZE];
    char septets2[sSIZE];
    char septets3[sSIZE];
    char septets4[sSIZE];

    groupSeptets(septets1, septets2, septets3, septets4, shuffle, SIZE);

    rotateSeptets(septets1, septets2, septets3, septets4, SIZE);

    printf("\n\n");
    puts("Group the 28 bits into four 7 bit septets and rotate the septets left by 3 bits.");
    printf("Septet 1: %s\n", septets1);
    printf("Septet 2: %s\n", septets2);
    printf("Septet 3: %s\n", septets3);
    printf("Septet 4: %s\n", septets4);

    // Translated string
    char translate[5];

    translateSeptets(septets1, septets2, septets3, septets4, SIZE, translate);

    printf("\n");
    printf("Decrypted hexadecimal digits: %s\n", translate);

    return 0; // Indicates successful termination.
}

// Given a seven digit hexadecimal string, convert it into a decimal integer array.
void hexDec(char *hex, int dec[]) {
    for (int i = 0; i < strlen(hex); i++) {
        //printf("hex: %c, i: %d\t", hex[i], i);
        if(hex[i] >= '0' && hex[i] <= '9') {
            dec[i] = hex[i] - '0';
        }
        
        if(hex[i] >= 'A' && hex[i] <= 'F') {
            dec[i] = hex[i] - 'A' + 10;
        } 
        
        if(hex[i] >= 'a' && hex[i] <= 'f') {
            dec[i] = hex[i] - 'a' + 10;
        }

        if(hex[i] >= 'G' && hex[i] <= 'Z') {
            puts("Not a heximal digit. Exiting program.");
            exit(1);
        } 
        
        if(hex[i] >= 'g' && hex[i] <= 'z') {
            puts("Not a heximal digit. Exiting program.");
            exit(1);
        }
        //printf("dec: %d, i: %d\t", dec[i], i);
    }
}

// Exclusive OR (XOR) with Key 2.
void key2XOR(int dec[], int key2[], int size) {
    for(int i = 0; i < size; i++) {
        dec[i] = dec[i] ^ key2[i];
    }
}

// Shuffle the Nibbles
void shuffleNibbles(int dec[], int shuffle[], int size) {
    for(int i = 0; i < size; i++) {
        if(i == 0) {
            shuffle[3] = dec[i];
        }
        if(i == 1) {
            shuffle[5] = dec[i];
        }
        if(i == 2) {
            shuffle[4] = dec[i];
        }
        if(i == 3) {
            shuffle[6] = dec[i];
        }
        if(i == 4) {
            shuffle[2] = dec[i];
        }
        if(i == 5) {
            shuffle[1] = dec[i];
        }
        if(i == 6) {
            shuffle[0] = dec[i];
        }
    }
}

// Exclusive OR (XOR) with Key 1.
void key1XOR(int shuffle[], int key1[], int size) {
    for(int i = 0; i < size; i++) {
        shuffle[i] = shuffle[i] ^ key1[i];
    }
}

// Group the 28 bits in four 7-bit septets.
void groupSeptets(char *septets1, char *septets2, char *septets3, char *septets4, int shuffle[], int size) {
    // Binary storage
    int bin;

    // Buffer storage
    char buff[5];
    char buffBin[29];

    // Leading 0s
    char z1[] = "0";
    char z2[] = "00";
    char z3[] = "000";

    // Binary characters
    char bin4[5];
    char bin3[4];
    char bin2[3];
    char bin1[2];
    
    // Converting first decimal number into binary number.
    if(shuffle[0] >= 8 ) {
        bin = binCon(shuffle[0]);
        charBin(bin, bin4);
        strcpy(buff, bin4);
    } else if(shuffle[0] >= 4 && shuffle[0] <= 7) {
        bin = binCon(shuffle[0]);
        charBin(bin, bin3);
        strcpy(buff, z1);
        strcat(buff, bin3);
    } else if(shuffle[0] >= 2 && shuffle[0] <= 3) {
        bin = binCon(shuffle[0]);
        charBin(bin, bin2);
        strcpy(buff, z2);
        strcat(buff, bin2);
    } else {
        bin = binCon(shuffle[0]);
        charBin(bin, bin1);
        strcpy(buff, z3);
        strcat(buff, bin1);
    }
    
    // Store first binary number and then concatenate the rest.
    strcpy(buffBin, buff);

    for(int i = 1; i < size; i++) {
        
        if(shuffle[i] >= 8 ) {
            bin = binCon(shuffle[i]);
            charBin(bin, bin4);
            strcat(buffBin, bin4);
        } else if(shuffle[i] >= 4 && shuffle[i] <= 7) {
            bin = binCon(shuffle[i]);
            charBin(bin, bin3);
            strcpy(buff, z1);
            strcat(buff, bin3);
            strcat(buffBin, buff);
        } else if(shuffle[i] >=2 && shuffle[i] <= 3) {
            bin = binCon(shuffle[i]);
            charBin(bin, bin2);
            strcpy(buff, z2);
            strcat(buff, bin2);
            strcat(buffBin, buff);
        } else /*(shuffle[i] <= 1)*/ {
            bin = binCon(shuffle[i]);
            charBin(bin, bin1);
            strcpy(buff, z3);
            strcat(buff, bin1);
            strcat(buffBin, buff);
        }
    }

    buffBin[29] = '\0';

    // Septets index counter.
    int iSeptet = 0;

    // Grouping septets.
    for(int j = 0; j < strlen(buffBin); j++) {
        if(j >= 21) {
            if(j == 21) {
                //septets3[sSIZE] = '\0';
                iSeptet = 0;
            }
            septets4[iSeptet] = buffBin[j];
            iSeptet++;
        } else if(j >= 14 && j <= 20) {
            if(j == 14) {
                //septets2[sSIZE] = '\0';
                iSeptet = 0;
            }
            septets3[iSeptet] = buffBin[j];
            iSeptet++;
        } else if(j >= 7 && j <= 13) {
            if(j == 7) {
                //septets1[sSIZE] = '\0';
                iSeptet = 0;
            }
            septets2[iSeptet] = buffBin[j];
            iSeptet++;
        } else {
            septets1[iSeptet] = buffBin[j];
            iSeptet++;
         }
    }

    // No null character at the end of each septet.
}

// Decimal to binary conversion using while loop.
int binCon(int num) {
    int bin = 0;
    int i = 1;

    while(num != 0) {
        bin = bin + (num % 2) * i;
        num = num / 2;
        i = i * 10;
    }

    return bin;
}

// Convert binary integer into a string.
void charBin(int bin, char *binChar) {
    // Binary number string format
    char binString[] = "01";

    int num;

    // Count number of digits in the integer.
    int digit = bin;
    int count = 0;
    
    do {
        digit /= 10;
        ++count;
    } while (digit != 0);

    // Insert binary characters in reverse order.
    int rev = count - 1;

    // Insert null character in the end.
    int nullChar = count;

    for(int i = 0; i < count; i++) {
        num = bin % 10;
        if(num == 0) {
            binChar[rev] = binString[0];
        }
        if(num == 1) {
            binChar[rev] = binString[1];
        }
        bin = bin / 10;
        rev--;
    }

    binChar[nullChar] = '\0';
}

// Each septet is rotated to the left by 3 bits.
void rotateSeptets(char *septets1, char *septets2, char *septets3, char *septets4, int size) {
    int temp;

    // Rotate Septets 1
    // Rotate the left by 3 bits.
    for(int i = 0; i < 3; i++) {
        temp = septets1[0];
        for(int j = 0; j < (size - 1); j++) {
            septets1[j] = septets1[j + 1];
        }
        septets1[size - 1] = temp;
    }

    //printf("Septet 1: %s\n", septets1);

    // Rotate Septets 2
    // Rotate the left by 3 bits.
    for(int i = 0; i < 3; i++) {
        temp = septets2[0];
        for(int j = 0; j < (size - 1); j++) {
            septets2[j] = septets2[j + 1];
        }
        septets2[size - 1] = temp;
    }

    //printf("Septet 2: %s\n", septets2);

    // Rotate Septets 3
    // Rotate the left by 3 bits.
    for(int i = 0; i < 3; i++) {
        temp = septets3[0];
        for(int j = 0; j < (size - 1); j++) {
            septets3[j] = septets3[j + 1];
        }
        septets3[size - 1] = temp;
    }

    //printf("Septet 3: %s\n", septets3);

    // Rotate Septets 4
    // Rotate the left by 3 bits.
    for(int i = 0; i < 3; i++) {
        temp = septets4[0];
        for(int j = 0; j < (size - 1); j++) {
            septets4[j] = septets4[j + 1];
        }
        septets4[size - 1] = temp;
    }

    //printf("Septet 4: %s\n", septets4);
}

// Each septet (7-bit sequence) is now replaced by the character by their bit representation.
void translateSeptets(char *septets1, char *septets2, char *septets3, char *septets4, int size, char *translate) {
    // Binary number string format
    char binString[] = "01";

    // Decimal number storage.
    int dec = 0;

    // Decimal base starting point.
    int base = 0;

    // Translate Septet 1
    for(int i = (size - 1); i >= 0; i--) {
        if(septets1[i] == binString[1]) {
            dec += pow(2, base);
        }
        base++;
    }

    // Track number of characters.
    int charNum = 0;

    septChar(dec, translate, charNum);

    // Reset counters
    base = 0;
    dec = 0;

    // Translate Septet 2
    for(int i = (size - 1); i >= 0; i--) {
        if(septets2[i] == binString[1]) {
            dec += pow(2, base);
        }
        base++;
    }

    // Track number of characters.
    charNum++;

    septChar(dec, translate, charNum);

    // Reset counters
    base = 0;
    dec = 0;

    // Translate Septet 3
    for(int i = (size - 1); i >= 0; i--) {
        if(septets3[i] == binString[1]) {
            dec += pow(2, base);
        }
        base++;
    }

    // Track number of characters.
    charNum++;

    septChar(dec, translate, charNum);

    // Reset counters
    base = 0;
    dec = 0;

    // Translate Septet 4
    for(int i = (size - 1); i >= 0; i--) {
        if(septets4[i] == binString[1]) {
            dec += pow(2, base);
        }
        base++;
    }

    // Track number of characters.
    charNum++;

    septChar(dec, translate, charNum);
}

void septChar(int dec, char *translate, int charNum) {
    // Only alphabet characters.
    char ascii[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < strlen(ascii); i++) {
        if(dec >= 65 && dec <= 90) {
            translate[charNum] = ascii[dec - 65];
        }
        if(dec >= 97 && dec <= 122) {
            translate[charNum] = ascii[dec - 71];
        }
    }
}