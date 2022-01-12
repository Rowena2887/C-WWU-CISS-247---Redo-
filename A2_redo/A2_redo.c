/*
 * Assignment 2 - Spelling Correction (Redo-PostGrad Test #1)
 * CISS 247 - Fall 2019
 * 
 * Rowena (Yum Bie) Tchao
 * #W00678226
 */

// Libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constant
#define LENGTH 46 // maximum size of word length

// Function prototypes
void toLower(char *word);
int hamDist(char *word, char *dictWord);

int main() {
    // Dictionary word
    char dictWord[LENGTH];
    
    // Word storage.
    char word[LENGTH];

    // Prompting user to enter a word until user exits.
    printf("Enter word: "); // prompt user
    scanf("%s", word);
    
    toLower(word);

    // Boolean: 0 is used to represent false, and 1 is used to represent true.
    int lookWord = 0;

    // To store hamming distance.
    int hamNum;
 
    FILE *wfPtr;

    if((wfPtr = fopen("words.txt", "r")) == NULL) {
        puts("File could not be opened.");
    } else {

        while(!feof(wfPtr)) {
            fscanf(wfPtr, "%s", dictWord);
            if(strcmp(word, dictWord) == 0) {
                printf("Word found in the dictionary: %s", word);
                lookWord++;
            }
        }

        if(lookWord == 0) {
            printf("Word not found in the dictionary: %s\n", word);
            rewind(wfPtr);
            while(!feof(wfPtr)) {
                fscanf(wfPtr, "%s", dictWord);
                // Focus on words with the same first characters.
                if(dictWord[0] == word[0]) {
                    hamNum = hamDist(word, dictWord);
                    if(hamNum == 1) {
                        printf("Spelling: %s\n", dictWord);
                    }
                }
            }
        }

        fclose(wfPtr);
    }

    // No null character at the end of the word string.

    return 0; // Indicates successful termination.
}

// Setting characters to lowercase.
void toLower(char *word) {
    for(int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

// Calculating hamming distance.
int hamDist(char *word, char *dictWord) {
    int hamCount = 0;

    for(int i = 0; i < strlen(word); i++) {
        if(word[i] == dictWord[i]) {
            hamCount++;
        }
    }
    
    hamCount = strlen(word) - hamCount;

    return hamCount;
}