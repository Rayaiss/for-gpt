#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Structure for a trie node
typedef struct TrieNode {
    struct TrieNode *children[26];
    int endOfWord;
} TrieNode;

// Function prototypes
TrieNode *createTrieNode();
void freeTrie(TrieNode *root);
void insertTrie(TrieNode *root, const char *word);
int searchTrie(TrieNode *root, const char *word);

#endif // TRIE_H
