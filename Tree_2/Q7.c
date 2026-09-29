#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
};

struct TrieNode *getNode() {
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    pNode->isEndOfWord = false;
    for (int i = 0; i < 26; i++) pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, const char *key) {
    struct TrieNode *pCrawl = root;
    for (int level = 0; key[level]; level++) {
        int index = key[level] - 'a';
        if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, const char *key) {
    struct TrieNode *pCrawl = root;
    for (int level = 0; key[level]; level++) {
        int index = key[level] - 'a';
        if (!pCrawl->children[index]) return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
    struct TrieNode *root = getNode();
    insert(root, "apple"); insert(root, "app");
    printf("Search 'apple': %s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("Search 'app': %s\n", search(root, "app") ? "Found" : "Not Found");
    printf("Search 'appl': %s\n", search(root, "appl") ? "Found" : "Not Found");
    return 0;
}