#include "../../Headers/Words/trie.h"

// Create a new trie node
TrieNode *createTrieNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    if (node == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for TrieNode.\n");
        return NULL;
    }
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    node->endOfWord = 0;
    return node;
}

// Insert a word into the trie
void insertTrie(TrieNode *root, const char *word) {
    TrieNode *node = root;
    while (*word) {
        int index = *word - 'a';
        if (node->children[index] == NULL)
            node->children[index] = createTrieNode();
        node = node->children[index];
        word++;
    }
    node->endOfWord = 1;
}

// Search for a word in the trie
int searchTrie(TrieNode *root, const char *word) {
    TrieNode *node = root;
    while (*word) {
        int index = *word - 'a';
        if (node->children[index] == NULL)
            return 0;
        node = node->children[index];
        word++;
    }
    return node->endOfWord;
}

// Free the memory allocated for the Trie
void freeTrie(TrieNode *root) {
    if (root == NULL) return;
    for (int i = 0; i < 26; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}
