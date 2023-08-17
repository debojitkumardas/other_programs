#ifndef HASH_TABLE
#define HASH_TABLE

#define TABLE_SIZE 26

typedef struct node node;
typedef struct hash_table hash_table;

struct node {
    int num;
    char ch;
};

struct hash_table {
    node* table_list[TABLE_SIZE];
};

int hash_func(int key);
int contains_elem(hash_table *head, char ch);
void insert_elem(hash_table *head, char ch);
void print_elem(hash_table *head);
void delete_table(hash_table *head);

#endif // !HASH_TABLE
