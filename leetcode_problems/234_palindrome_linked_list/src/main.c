#include "../hdr/helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_SZ 10

typedef enum {FALSE, TRUE} bool_;


bool_ is_palindrome(node *head) {
    int len = 0;
    node *temp = head;
    bool_ res = TRUE;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    int *ptr_1 = malloc(sizeof(int) * len);
    int *ptr_2 = malloc(sizeof(int) * len);
    int i = 0, j = len - 1;

    temp = head;
    while (temp != NULL) {
        ptr_1[i] = temp->value;
        ptr_2[j] = temp->value;
        i++;
        j--;
        temp = temp->next;
    }

    for (int k = 0; k < len; ++k)
        if (ptr_1[k] != ptr_2[k])
            res = FALSE;

    free(ptr_1);
    free(ptr_2);

    return res;
}

// solution in time ~ O(n) and space ~ O(1)
bool_ is_palindrome_adv(node *head) {

    int len = 0, mid = 1;
    node *ptr = NULL, *temp = NULL;
    bool_ res = TRUE;

    temp = head;
    ptr = head;
    while (temp != NULL) {
        len++;
        if (len >= 2 * mid) {
            ptr = ptr->next;
            mid++;
        }
        temp = temp->next;
    }

    if (len % 2 != 0)
        ptr = ptr->next;

    // reversing the linked list
    node *n_head = NULL;
    temp = NULL;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        temp->next = n_head;
        n_head = temp;
    }

    while (n_head != NULL) {
        if (n_head->value != head->value)
            res = FALSE;

        n_head = n_head->next;
        head = head->next;
    }

    return res;
}

int main(void) {

    node *head = NULL;
    char *text[2] = {"FALSE", "TRUE"};
    bool_ res;

    srand(time(NULL));

    #if NR
    for (int i = 0; i < LIST_SZ; ++i)
        insert_node(&head, rand() % 10);
    #endif

    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 2);
    insert_node(&head, 1);

    printf("The list is: ");
    print_list(head);

    res = is_palindrome_adv(head);
    printf("Is the given list a palindrome? %s\n", text[res]);

    delete_list(&head);

    return 0;
}
