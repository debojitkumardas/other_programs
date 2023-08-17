#include "hash_set.h"
#include <stdlib.h>
#include <stdio.h>

void insert_node_at_head(node **head, int num) {
    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->num = num;
        new_node->next = *head;
        *head = new_node;
    }
}
void remove_node(node **head, int num) {
    node *temp = *head;
    node *h_ptr = NULL;

    while (temp != NULL) {
        if (temp->num == num) {
            if (h_ptr == NULL)
                *head = temp->next;
            else
                h_ptr->next = temp->next;
            free(temp);
            return;
        }
        h_ptr = temp;
        temp = temp->next;
    }
}

int hash_func(int key) {
    return key % SET_SIZE;
}

bool_ contains(hash_set *hash_set_head, int key) {
    int hash_val = hash_func(key);

    node *temp = hash_set_head->set_list[hash_val];
    while (temp != NULL) {
        if (temp->num == key)
            return TRUE;
        temp = temp->next;
    }

    return FALSE;
}

void insert_data(hash_set *hash_set_head, int key) {

    if (!contains(hash_set_head, key)) {
        int hash_val = hash_func(key);
        // insert_node_at_head(&(hash_set_head->set_list[hash_val]), key);

        node *new_node = malloc(sizeof(node));

        if (new_node != NULL) {
            new_node->num = key;
            new_node->next = hash_set_head->set_list[hash_val];
            hash_set_head->set_list[hash_val] = new_node;
        }
    }
}

void remove_data(hash_set *hash_set_head, int key) {
    int hash_val = hash_func(key);

    remove_node(&(hash_set_head->set_list[hash_val]), key);
}

void print_set(hash_set *hash_set_head) {
    printf("[");
    for (int i = 0; i < SET_SIZE; ++i) {
        node *temp = hash_set_head->set_list[i];

        while (temp != NULL) {
            printf("%d, ", temp->num);
            temp = temp->next;
        }
    }
    printf("\\0]\n");
}

void delete_set(hash_set *hash_set_head) {
    for (int i = 0; i < SET_SIZE; ++i) {
        node *temp = hash_set_head->set_list[i];

        while (temp != NULL) {
            node *h_ptr = temp;
            temp = temp->next;
            free(h_ptr);
        }
    }
}
