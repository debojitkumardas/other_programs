#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

#define GET_KEY(ch) (int)ch - (int)'a' + 1

int hash_func(int key) {
    return key % TABLE_SIZE;
}

int contains_elem(hash_table *head, char ch) {
    int key = GET_KEY(ch); // (int)ch - (int)'a' + 1;
    int hash_val = hash_func(key);

    if (head->table_list[hash_val] != NULL) {
        if (head->table_list[hash_val]->ch == ch) {
            head->table_list[hash_val]->num += 1;
            return 1;
        }
    }

    return 0;
}

void insert_elem(hash_table *head, char ch) {
    int key = GET_KEY(ch); // (int)ch - (int)'a' + 1;
    int hash_val = hash_func(key);

    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->num = 1;
        new_node->ch = ch;
        head->table_list[hash_val] = new_node;
    }
}

void print_elem(hash_table *head) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (head->table_list[i] != NULL)
            printf("%c: %d\n", head->table_list[i]->ch, head->table_list[i]->num);
    }
}

void delete_table(hash_table *head) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        node *temp = head->table_list[i];
        if (temp != NULL)
            free(temp);
    }
}
