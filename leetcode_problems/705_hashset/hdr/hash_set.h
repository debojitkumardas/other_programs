#ifndef HASH_SET_H
#define HASH_SET_H

#define SET_SIZE 3

typedef enum {FALSE, TRUE} bool_;

typedef struct node node;
typedef struct hash_set hash_set;

struct node {
    int num;
    node *next;
};

void insert_node_at_head(node **head, int num);
void remove_node(node **head, int num);

struct hash_set {
    node* set_list[SET_SIZE];
};

int hash_func(int key);
bool_ contains(hash_set *hash_set_head, int key);
void insert_data(hash_set *hash_set_head, int key);
void remove_data(hash_set *hash_set_head, int key);
void print_set(hash_set *hash_set_head);
void delete_set(hash_set *hash_set_head);

#endif // !HASH_SET_H
