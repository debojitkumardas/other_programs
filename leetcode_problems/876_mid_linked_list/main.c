#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node node;

struct node {
    int value;
    node *next;
};

void insert_node(node **head, int value) {

    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->value = value;
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

node* middle_node(node *head) {

    node *temp = head;
    int l1 = 0, l2 = 1;

    while (head != NULL) {

        l1++;
        // for even number of elements consider the (n/2 + 1)th element
        if (l1 >= 2 * l2) {
            l2++;
            temp = temp->next;
        }
        head = head->next;
    }

    return temp;
}

int main(int argc, char *argv[]) {

    int n = 5, val;
    node *head = NULL;
    node *temp = NULL;

    srand(time(NULL));

    if (argc == 2)
        n = atoi(argv[1]);
    else
        printf("Insufficient commandline argument. Going with the default value %d.\n", n);

    for (int i = 0; i < n; ++i) {
        val = rand() % 100 + 1;
        insert_node(&head, val);
    }

    print_list(head);

    temp = middle_node(head);

    printf("The middle of list is \n");

    print_list(temp);

    delete_list(&head);

    return 0;
}
