#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node node;

struct node {
    int value;
    node *next;
};

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
        printf("%d->", head->value);
        head = head->next;
    }
    printf("\\0\n");
}

void delete_list(node **head) {

    while (*head != NULL) {
        node *temp;
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

node* reverse_list(node *head) {

    node *new_head = NULL, *curr = NULL;

    while (head != NULL) {
        curr = head;
        head = head->next;
        curr->next = new_head;
        new_head = curr;
    }

    return new_head;
}

int main(void) {

    int n = 5, val = 0;
    srand(time(NULL));

    node *head = NULL;
    for (int i = 0; i < n; ++i) {
        val = rand() % 100;
        insert_node(&head, val);
    }

    print_list(head);

    head = reverse_list(head);

    print_list(head);

    delete_list(&head);

    return 0;
}
