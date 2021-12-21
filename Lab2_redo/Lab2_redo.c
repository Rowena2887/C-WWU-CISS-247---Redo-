/*
 * Lab2.c (Redo-PostGrad Test #1)
 * CSCI 247, Fall 2019
 * 
 * main() written by Rowena (Yum Bie) Tchao, October, 2019
 * 
 */

// Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Function prototypes
int numSize(char *digit);
void digitValue(char *digit, int num[]);
int toDecimal(int base, int num[], int sizeNum);
void fromDecimal(int total);

int main(int argc, char *argv[]) {

    // check for the correct number of command-line arguments
    if (argc < 4) {
        puts("Usage: ./Lab2_redo base num1 num2\n");
        return 1; // Indicates unsuccessful termination.
    }

    // Converting the base as a string into a integer. Make sure the value is between 2 and 36.
    int base = atoi(argv[1]);
    
    if(base < 2 || base > 36) {
        puts("Please pick a base number between 2 and 36.");
        return 1;
    }

    // Returning the length of each digit.
    int sizeNum1 = numSize(argv[2]);
    int sizeNum2 = numSize(argv[3]);

    // Converting character string to digit value and inserting into num1 array.
    int num1[sizeNum1];
    digitValue(argv[2], num1);
    
    // Calculating Digit 1 using the given base.
    int baseNum1 = toDecimal(base, num1, sizeNum1);
    
    // Converting character string to digit value and inserting into num2 array.
    int num2[sizeNum2];
    digitValue(argv[3], num2);
    
    // Calculating Digit 2 using the given base.
    int baseNum2 = toDecimal(base, num2, sizeNum2);

    // Adding digits
    int total = baseNum1 + baseNum2;

    printf("Total: %d\n", total);

    fromDecimal(total);
    
    return 0; // Indicates successful termination.
}

// Return the string length of the digit.
int numSize(char *digit) {
    int count = 0;
    for(int i = 0; i < strlen(digit); i++) {
        count++;
    }
    return count;
}

// Returns the decimal value of a digit character. Digit must be in the range '0'-'9', 'a'-'z', or 'A'-'Z'.
void digitValue(char *digit, int num[]) {
    for(int i = 0; i < strlen(digit); i++) {
        if(digit[i] >= '0' && digit[i] <= '9') {
            num[i] = digit[i] - '0';
        }
        
        if(digit[i] >= 'A' && digit[i] <= 'Z') {
            num[i] = digit[i] - 'A' + 10;
        } 
        
        if(digit[i] >= 'a' && digit[i] <= 'z') {
            num[i] = digit[i] - 'a' + 10;
        }
    }
}

// Calculate digit using the given base.
int toDecimal(int base, int num[], int sizeNum) {
    int baseCounter = sizeNum - 1;
    int digit = 0;
    
    for(int i = 0; i < sizeNum; i++) {
        digit += num[i]*(pow(base, baseCounter));
        /*printf("Num: %d, i: %d\n", num[i], i);
        printf("Base: %d, baseCounter: %d\n", base, baseCounter);
        printf("Digit: %d\n", digit);*/
        baseCounter--;
    }

    return digit;
}

// Converting the digit from a integer to a string.
void fromDecimal(int total) {
    if(total > 35) {
        puts("The total is greater than 35. It is outside the numeric string.");
    } else {
        switch(total) {
            case 0: puts("Digit: 0");
                break;
            case 1: puts("Digit: 1");
                break;
            case 2: puts("Digit: 2");
                break;
            case 3: puts("Digit: 3");
                break;
            case 4: puts("Digit: 4");
                break;
            case 5: puts("Digit: 5");
                break;
            case 6: puts("Digit: 6");
                break;
            case 7: puts("Digit: 7");
                break;
            case 8: puts("Digit: 8");
                break;
            case 9: puts("Digit: 9");
                break;
            case 10: puts("Digit: A");
                break;
            case 11: puts("Digit: B");
                break;
            case 12: puts("Digit: C");
                break;
            case 13: puts("Digit: D");
                break;
            case 14: puts("Digit: E");
                break;
            case 15: puts("Digit: F");
                break;
            case 16: puts("Digit: G");
                break;
            case 17: puts("Digit: H");
                break;
            case 18: puts("Digit: I");
                break;
            case 19: puts("Digit: J");
                break;
            case 20: puts("Digit: K");
                break;
            case 21: puts("Digit: L");
                break;
            case 22: puts("Digit: M");
                break;
            case 23: puts("Digit: N");
                break;
            case 24: puts("Digit: O");
                break;
            case 25: puts("Digit: P");
                break;
            case 26: puts("Digit: Q");
                break;
            case 27: puts("Digit: R");
                break;
            case 28: puts("Digit: S");
                break;
            case 29: puts("Digit: T");
                break;
            case 30: puts("Digit: U");
                break;
            case 31: puts("Digit: V");
                break;
            case 32: puts("Digit: W");
                break;
            case 33: puts("Digit: X");
                break;
            case 34: puts("Digit: Y");
                break;
            case 35: puts("Digit: Z");
                break;
        }
    }
}