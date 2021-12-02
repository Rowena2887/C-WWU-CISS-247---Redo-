/*
 * Lab 1 - Text Replacement (Redo-PostGrad Test #2)
 * CSCI 247 - Fall 2019
 * 
 * Rowena (Yum Bie) Tchao
 * #W00678226
 */

// Libraries
#include <stdio.h>
#include <string.h>

// Constant
#define MAX_LINE    1024

// Function prototypes
int find(char *substr, char *str);
void replace(char *str, int pos, char *newstr);

int main (int argc, char *argv[]) {
    
    // check for 3 command-line arguments
    if (argc < 3) {
        puts("Usage: ./Lab1 word1 word2\n");
        return 1; // Indicates unsuccessful termination.
    }
    
    // check that word1 and word2 are of equal length
    if (strlen(argv[1]) != strlen(argv[2])) {
        puts("The two words must have the same length.\n");
        return 1; // Indicates unsuccessful termination.
    }
    
    // for each line of input, perform string replacement
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stdin)) {
        
        printf("This is argv[1]: %s\n", argv[1]);
        printf("This is argv[2]: %s\n", argv[2]);
        printf("This is line: %s\n", line);

        // remove the \n from the end of the line
        line[strlen(line)-1] = 0;
        
        // find word1 in line
        // int find(char *substr, char *str);
        int pos = find(argv[1], line);
        //printf("Substring location index @: %d\n", pos);

        // replace word
        // void replace(char *str, int pos, char *newstr);
        //replace(line, pos, argv[2]);

        // while word1 found in line, replace it
        while (pos >= 0) {
            replace(line, pos, argv[2]);
            pos = find(argv[1], line);
        }
         
        puts(line);
    }

    return 0; // Indicates successful termination.
}

/*The find function return the starting index of the substring (substr) in string (str). If substring cannot be found, return -1.*/
// int pos = find(argv[1], line);
int find(char *substr, char *str) {
    int strCounter;
    int i; // substring "for loop" counter
    int substrCounter = 0;
    int substrLocation;
    char compStr[strlen(substr)]; // New string array to compare word to substring.
    int compStrCounter = 0;

    for(strCounter = 0; strCounter < strlen(str); strCounter++) {
        //printf("Each character: %c in string.\t", str[strCounter]);
        for(i = substrCounter; i < strlen(substr); i++) {
            if(substr[substrCounter] == str[strCounter]) {
                //printf("Character %c matches substring in string.\t", substr[substrCounter]);
                
                if(substrCounter == 0) {
                    substrLocation = strCounter;
                }
                
                //printf("Match distance @ %d.\t", substrLocation);
                compStr[compStrCounter] = substr[substrCounter];
                //printf("Storing character: %c\t", compStr[compStrCounter]);
                compStrCounter++;

                //NULL character for end of string.
                compStr[compStrCounter] = '\0';
                
                //printf("yes string: %c and yes substring: %c\t", str[strCounter], substr[i]);
                substrCounter++;
                break;
            } else {
                compStrCounter = 0;
                
                //printf("no string: %c and no substring: %c\t", str[strCounter], substr[i]);
                substrCounter = 0;
                break;
            }
        }
    }
    
    //printf("New string: %s\n", compStr);
    //printf("This is the length of the new string array: %d.\n", strlen(compStr));

    if(strcmp(compStr, substr) == 0) {
        //printf("Substring location index @: %d\n", substrLocation);
        return substrLocation;
    }

    return -1;
}

/*This function replaces the characters in the string (str) using the starting index (pos) with newstring (newstr)*/
// replace(line, pos, argv[2]);
void replace(char *str, int pos, char *newstr) {
    int newstrCounter = 0;

    for(int i = pos; i < strlen(str); i++) {
        for(int j = newstrCounter; j < strlen(newstr); j++) {
            str[i] = newstr[j];
            //printf("String character: %c\t", str[i]);
            //printf("New string character: %c\t", newstr[j]);
            newstrCounter++;
            break;
        }
    }

    //puts(str);
}