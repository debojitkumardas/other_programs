#include "../hdr/helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST1_SZ 4
#define LIST2_SZ 5

int* gen_sort_list(int len) {
    int *list = malloc(sizeof(int) * len);
    int temp = 0;

    for (int i = 0; i < len; ++i)
        list[i] = (rand() % 10) + 1;

    // sorting the list; insertion sort
    for (int i = 1; i < len; ++i) {
        for (int j = i; j > 0; --j) {
            if (list[j] > list[j - 1]) {
                // swap j & j - 1
                temp = list[j];
                list[j] = list[j - 1];
                list[j - 1] = temp;
            }
        }
    }

    return list;
}

// recursive solution
node* merge_two_lists_rec(node *list1, node *list2) {

    if (list1 == NULL && list2 == NULL)
        return NULL;
    else if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    else {
        if (list1->value < list2->value) {
            list1->next = merge_two_lists_rec(list1->next, list2);
            return list1;
        }
        else {
            list2->next = merge_two_lists_rec(list1, list2->next);
            return list2;
        }
    }
}

// iterative solution
node* merge_two_lists_iter(node *list1, node *list2) {

    if (list1 == NULL && list2 == NULL)
        return NULL;
    else if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    else {
        node *head = NULL;
        node *prev = NULL;

        if (list1->value < list2->value) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }
        prev = head;

        while (list1 != NULL || list2 != NULL) {
            if (list1 == NULL) {
                prev->next = list2;
                break;
            }
            else if (list2 == NULL) {
                prev->next = list1;
                break;
            }
            else {
                if (list1->value < list2->value) {
                    prev->next = list1;
                    prev = list1;
                    list1 = list1->next;
                }
                else {
                    prev->next = list2;
                    prev = list2;
                    list2 = list2->next;
                }
            }
        }
        return head;
    }
}

int main(void) {

    node *list1 = NULL;
    node *list2 = NULL;
    node *head = NULL;
    int *ptr = NULL;

    // insert value in the lists
    srand(time(NULL));

    ptr = gen_sort_list(LIST1_SZ);
    for (int i = 0; i < LIST1_SZ; ++i)
        insert_node(&list1, ptr[i]);

    printf("list 1 is: ");
    print_list(list1);

    ptr = gen_sort_list(LIST2_SZ);
    for (int i = 0; i < LIST2_SZ; ++i)
        insert_node(&list2, ptr[i]);

    printf("list 2 is: ");
    print_list(list2);

    // head = merge_two_lists_rec(list1, list2);
    head = merge_two_lists_iter(list1, list2);
    printf("Merged list is: ");
    print_list(head);

    return 0;
}
