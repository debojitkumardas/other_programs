#ifndef HASH_SET
#define HASH_SET

#define SET_SIZE 3

typedef struct node node;
typedef struct hash_set hash_set;

struct node {
    int num;
    node* next;
};

struct hash_set {
    node* set_list[SET_SIZE];
};

int hash_func(int key);
int contains_elem(hash_set* head, int key);
void insert_elem(hash_set* head, int key);
void print_set(hash_set* head);
void delete_set(hash_set* head);

#endif // !HASH_SET
