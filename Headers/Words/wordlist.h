#ifndef WORDLIST_H
#define WORDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "trie.h"

// Structure for a linked list node
typedef struct WordList {
    int wordLength;
    struct WordList *next;
    TrieNode *trie;
} WordList;

// Function prototypes
WordList *createWordList(int length);
void freeWordList(WordList *head);
void insertWord(WordList **head, const char *word);
int searchWord(WordList *head, const char *word);
void loadWords(const char *filename, WordList **head);
void testPerformance(WordList *head, const char *word);

#endif // WORDLIST_H
