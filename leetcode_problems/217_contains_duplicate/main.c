#include "hash_set.h"
#include <stdio.h>

int ContainsDuplicate(int *num, int len) {
    if (len == 1)
        return 0;
    else {
        hash_set head;

        for (int i = 0; i < SET_SIZE; ++i) {
            head.set_list[i] = NULL;
        }

        for (int i = 0; i < len; ++i) {
            // if element doesn't exist in set
            if (contains_elem(&head, num[i]) == 0) {
                // insert element
                insert_elem(&head, num[i]);
            }
            else {
                // delete set
                delete_set(&head);
                printf("set deleted\n");
                return 1;
            }
        }
    }

    return 0;
}

int main(void) {

    int num[] = {1,5,-2,-4,0};
    int len = sizeof(num) / sizeof(int);

    int res = ContainsDuplicate(num, len);

    printf("Duplicate? %d\n", res);

    return 0;
}
