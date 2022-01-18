/*
 * Assignment 3 - Seven Segment Displays (Redo-PostGrad Test #1)
 * CISS 247 - Fall 2019
 * 
 * Rowena (Yum Bie) Tchao
 * #W00678226
 */

// Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constant
#define LENGTH 10

// Function prototypes
int intTrans(char *digits, int num[]);
void printNum(int num[], int numCount, int scale);
void topZone(int num, int scale);
void middleZone(int num, int scale, int level);
void bottomZone(int num, int scale);

int main (int argc, char *argv[]) {
    // check for 3 command-line arguments
    if (argc < 3) {
        puts("Usage: ./A3_redo 0123456789 1\n");
        return 1; // Indicates unsuccessful termination.
    }

    // Digits storage
    int num[LENGTH];

    int scale = atoi(argv[2]);

    if(scale <= 0) {
        puts("Please choose a scale above 1.");
        exit(1);
    }

    int numCount = intTrans(argv[1], num);

    printNum(num, numCount, scale);

    return 0; // Indicates successful termination.
}

// Translating digits string into integers and count how many digits the user inputted.
int intTrans(char *digits, int num[]) {
    // Count number of digits.
    int count = 0;

    for(int i = 0; i < strlen(digits); i++) {
        num[i] = digits[i] - '0';
        count++;
    }

    return count;
}

// Printing integers.
void printNum(int num[], int numCount, int scale) {
    scale = scale * 2;

    for(int i = 0; i < numCount; i++) {
        topZone(num[i], scale);
    }

    printf("\n");

    for(int j = 1; j < scale; j++) {
        for(int jj = 0; jj < numCount; jj++) {
            middleZone(num[jj], scale, j);
        }
        printf("\n");
    }

    for(int k = 0; k < numCount; k++) {
        bottomZone(num[k], scale);
    }
}

// Print top zone of the integer.
void topZone(int num, int scale) {
    switch(num) {
        case 0:
            printf(" ");
            for(int a = 1; a < scale + 1; a++) {
                printf("_");
            }
            printf(" ");
            break;
        case 1:
            printf(" ");
            break;
        case 2:
            printf(" ");
            for(int b = 1; b < scale + 1; b++) {
                printf("_");
            }
            printf(" ");
            break;
        case 3:
            for(int c = 1; c < scale + 1; c++) {
                printf("_");
            }
            printf(" ");
            break;
        case 4:
            printf(" ");
            for(int d = 1; d < scale + 1; d++) {
                printf(" ");
            }
            printf(" ");
            break;
        case 5:
            printf(" ");
            for(int e = 1; e < scale + 1; e++) {
                printf("_");
            }
            printf(" ");
            break;
        case 6:
            printf(" ");
            for(int f = 1; f < scale + 1; f++) {
                printf("_");
            }
            printf(" ");
            break;
        case 7:
            for(int g = 1; g < scale + 1; g++) {
                printf("_");
            }
            printf(" ");
            break;
        case 8:
            printf(" ");
            for(int h = 1; h < scale + 1; h++) {
                printf("_");
            }
            printf(" ");
            break;
        case 9:
            printf(" ");
            for(int i = 1; i < scale + 1; i++) {
                printf("_");
            }
            printf(" ");
            break;
    }
}

// Print middle zone of the integer.
void middleZone(int num, int scale, int level) {
    switch(num) {
        case 0:
            printf("|");
            for(int a = 1; a < scale + 1; a++) {
                printf(" ");
            }
            printf("|");
            break;
        case 1:
            printf("|");
            break;
        case 2:
            if(level < scale / 2) {
                printf(" ");
                for(int b = 1; b < scale + 1; b++) {
                    printf(" ");
                }
                printf("|");
            } 
            if(level == scale / 2) {
                printf(" ");
                for(int c = 1; c < scale + 1; c++) {
                    printf("_");
                }
                printf("|");
            }
            if(level > scale / 2) {
                printf("|");
                for(int d = 1; d < scale + 2; d++) {
                    printf(" ");
                }
            }
            break;
        case 3:
            if(level < scale / 2) {
                for(int e = 1; e < scale + 1; e++) {
                    printf(" ");
                }
                printf("|");
            } 
            if(level == scale / 2) {
                for(int f = 1; f < scale + 1; f++) {
                    printf("_");
                }
                printf("|");
            }
            if(level > scale / 2) {
                for(int g = 1; g < scale + 1; g++) {
                    printf(" ");
                }
                printf("|");
            }
            break;
        case 4:
            if(level < scale / 2) {
                printf("|");
                for(int h = 1; h < scale + 1; h++) {
                    printf(" ");
                }
                printf("|");
            } 
            if(level == scale / 2) {
                printf("|");
                for(int i = 1; i < scale + 1; i++) {
                    printf("_");
                }
                printf("|");
            }
            if(level > scale / 2) {
                printf(" ");
                for(int j = 1; j < scale + 1; j++) {
                    printf(" ");
                }
                printf("|");
            }
            break;
        case 5:
            if(level < scale / 2) {
                printf("|");
                for(int k = 1; k < scale + 1; k++) {
                    printf(" ");
                }
                printf(" ");
            } 
            if(level == scale / 2) {
                printf("|");
                for(int l = 1; l < scale + 1; l++) {
                    printf("_");
                }
                printf(" ");
            }
            if(level > scale / 2) {
                printf(" ");
                for(int m = 1; m < scale + 1; m++) {
                    printf(" ");
                }
                printf("|");
            }
            break;
        case 6:
            if(level < scale / 2) {
                printf("|");
                for(int n = 1; n < scale + 1; n++) {
                    printf(" ");
                }
                printf(" ");
            } 
            if(level == scale / 2) {
                printf("|");
                for(int o = 1; o < scale + 1; o++) {
                    printf("_");
                }
                printf(" ");
            }
            if(level > scale / 2) {
                printf("|");
                for(int p = 1; p < scale + 1; p++) {
                    printf(" ");
                }
                printf("|");
            }
            break;
        case 7:
            for(int q = 1; q < scale + 1; q++) {
                printf(" ");
            }
            printf("|");
            break;
        case 8:
            if(level < scale / 2) {
                printf("|");
                for(int r = 1; r < scale + 1; r++) {
                    printf(" ");
                }
                printf("|");
            } 
            if(level == scale / 2) {
                printf("|");
                for(int s = 1; s < scale + 1; s++) {
                    printf("_");
                }
                printf("|");
            }
            if(level > scale / 2) {
                printf("|");
                for(int t = 1; t < scale + 1; t++) {
                    printf(" ");
                }
                printf("|");
            }
            break;
        case 9:
            if(level < scale / 2) {
                printf("|");
                for(int u = 1; u < scale + 1; u++) {
                    printf(" ");
                }
                printf("|");
            } 
            if(level == scale / 2) {
                printf("|");
                for(int v = 1; v < scale + 1; v++) {
                    printf("_");
                }
                printf("|");
            }
            if(level > scale / 2) {
                printf(" ");
                for(int w = 1; w < scale + 1; w++) {
                    printf(" ");
                }
                printf("|");
            }
            break;
    }
}

// Print bottom zone of the integer.
void bottomZone(int num, int scale) {
    switch(num) {
        case 0:
            printf("|");
            for(int a = 1; a < scale + 1; a++) {
                printf("_");
            }
            printf("|");
            break;
        case 1:
            printf("|");
            break;
        case 2:
            printf("|");
            for(int b = 1; b < scale + 1; b++) {
                printf("_");
            }
            printf(" ");
            break;
        case 3:
            for(int c = 1; c < scale + 1; c++) {
                printf("_");
            }
            printf("|");
            break;
        case 4:
            printf(" ");
            for(int d = 1; d < scale + 1; d++) {
                printf(" ");
            }
            printf("|");
            break;
        case 5:
            printf(" ");
            for(int e = 1; e < scale + 1; e++) {
                printf("_");
            }
            printf("|");
            break;
        case 6:
            printf("|");
            for(int f = 1; f < scale + 1; f++) {
                printf("_");
            }
            printf("|");
            break;
        case 7:
            for(int g = 1; g < scale + 1; g++) {
                printf(" ");
            }
            printf("|");
            break;
        case 8:
            printf("|");
            for(int h = 1; h < scale + 1; h++) {
                printf("_");
            }
            printf("|");
            break;
        case 9:
            printf(" ");
            for(int i = 1; i < scale + 1; i++) {
                printf("_");
            }
            printf("|");
            break;
    }
}