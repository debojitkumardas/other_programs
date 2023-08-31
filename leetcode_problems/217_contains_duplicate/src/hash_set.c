#include "../hdr/hash_set.h"
#include <stdio.h>
#include <stdlib.h>

int hash_func(int key) {
    return abs(key) % SET_SIZE;
}

int contains_elem(hash_set *head, int key) {
    int hash_val = hash_func(key);

    node *temp = head->set_list[hash_val];
    while (temp != NULL) {
        if (temp->num == key)
            return 1;
        temp = temp->next;
    }

    return 0;
}

void insert_elem(hash_set *head, int key) {
    int hash_val = hash_func(key);

    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->num = key;
        new_node->next = head->set_list[hash_val];
        head->set_list[hash_val] = new_node;
    }
}

void print_set(hash_set *head) {
    for (int i = 0; i < SET_SIZE; ++i) {
        node *temp = head->set_list[i];
        while (temp != NULL) {
            printf("%d ", temp->num);
            temp = temp->next;
        }
        printf("\n");
    }
}

void delete_set(hash_set *head) {
    for (int i = 0; i < SET_SIZE; ++i) {
        node *temp = head->set_list[i];
        while (temp != NULL) {
            node *tmp = temp;
            temp = temp->next;
            free(tmp);
        }
    }
}
