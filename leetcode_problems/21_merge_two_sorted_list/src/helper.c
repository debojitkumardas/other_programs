#include "../hdr/helper.h"
#include <stdio.h>
#include <stdlib.h>

void insert_node(node **head, int val) {
    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->value = val;
        new_node->next = *head;
        *head = new_node;
    }
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d, ", head->value);
        head = head->next;
    }
    printf("\\0\n");
}

void delete_list(node **head) {
    while (*head != NULL) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
