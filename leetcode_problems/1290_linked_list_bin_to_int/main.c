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

void get_list(node *head) {

    while (head != NULL) {
        printf("%d->", head->value);
        head = head->next;
    }
    printf("\\0\n");
}

void delete_list(node **head) {

    while (*head != NULL) {
        node *temp = NULL;
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int get_decimal_value(node *head) {

    int res = 0;

    while (head != NULL) {
        res <<= 1;
        res += head->value;
        head = head->next;
    }

    return res;
}

int main(void) {

    int n = 4, value = 0;

    srand(time(NULL));

    node *head = NULL;
    for (int i = 0; i < n; i++) {
        value = rand() % 2;
        insert_node(&head, value);
    }

    printf("The binary number is: \n");
    get_list(head);

    printf("The result is: %d\n", get_decimal_value(head));

    return 0;

}
