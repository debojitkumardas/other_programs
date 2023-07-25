#ifndef HELPER_H
#define HELPER_H

typedef struct node node;

struct node {
    int value;
    node *next;
};

void insert_node(node **head, int value);
void print_list(node *head);
void delete_list(node **head);

#endif // !HELPER_H
