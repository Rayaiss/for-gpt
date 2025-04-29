#include "../../Headers/Words/wordlist.h"

// Create a new word list node
WordList *createWordList(int length) {
    WordList *node = (WordList *)malloc(sizeof(WordList));
    if (node == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for WordList node.\n");
        return NULL;
    }
    node->next = NULL;
    node->trie = createTrieNode();
    node->wordLength = length;
    return node;
}

// Insert a word into the word list
void insertWord(WordList **head, const char *word) {
    int length = strlen(word);
    WordList *current = *head, *previous = NULL;
    while (current && current->wordLength < length) {
        previous = current;
        current = current->next;
    }
    if (current && current->wordLength == length) {
        insertTrie(current->trie, word);
    } else {
        WordList *newNode = createWordList(length);
        if (newNode == NULL) return;
        insertTrie(newNode->trie, word);
        newNode->next = current;
        if (previous)
            previous->next = newNode;
        else
            *head = newNode;
    }
}

// Search for a word in the word list
int searchWord(WordList *head, const char *word) {
    int length = strlen(word);
    while (head && head->wordLength < length) {
        head = head->next;
    }
    if (head && head->wordLength == length)
        return searchTrie(head->trie, word);
    return 0;
}

// Load words from a file into the word list
void loadWords(const char *filename, WordList **head) {
    printf("Attempting to open file: %s\n", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    printf("File opened successfully: %s\n", filename);
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, file)) {
        word[strcspn(word, "\n")] = 0; // Remove newline character
        printf("Inserting word: %s\n", word);
        insertWord(head, word);
    }
    fclose(file);
    printf("File closed: %s\n", filename);
}

// Test the performance of searching for a word in the word list
void testPerformance(WordList *head, const char *word) {
    clock_t start = clock();
    int found = searchWord(head, word);
    clock_t end = clock();
    printf("Word '%s' %s in %lf ms\n", word, found ? "found" : "not found", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);
}

// Free the memory allocated for the WordList
void freeWordList(WordList *head) {
    while (head != NULL) {
        WordList *temp = head;
        head = head->next;
        freeTrie(temp->trie);
        free(temp);
    }
}
