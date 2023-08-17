#include "hash_table.h"
#include <stdio.h>

int compare_hash_table(hash_table *head_1, hash_table *head_2) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        // both entries are not null
        if ((head_1->table_list[i] != NULL) && (head_2->table_list[i] != NULL)) {
            if ((head_1->table_list[i]->ch == head_2->table_list[i]->ch) &&
                (head_1->table_list[i]->num == head_2->table_list[i]->num))
                continue;
            else
                return 0;
        }
        // both entries are null
        else if ((head_1->table_list[i] == NULL) && (head_2->table_list[i] == NULL))
            continue;
        else
            return 0;
    }

    return 1;
}

int main(void) {

    char *input_1 = "anagram";
    char *input_2 = "nagaram";
    int len_1 = 0;
    int len_2 = 0;

    char *ptr_1 = input_1;
    char *ptr_2 = input_2;

    while ((*ptr_1 != '\0') || (*ptr_2 != '\0')) {
        if (*ptr_1 != '\0') {
            len_1++;
            ptr_1++;
        }
        if (*ptr_2 != '\0') {
            len_2++;
            ptr_2++;
        }
    }

    if (len_1 == 1 && len_2 == 1) {
        if (input_1[0] == input_2[0]) {
            printf("Yes, it's an anagram.\n");
        }
    }
    else if (len_1 != len_2) {
        printf("Not an anagram.\n");
    }
    else {
        hash_table head_1;
        hash_table head_2;

        for (int i = 0; i < TABLE_SIZE; ++i) {
            head_1.table_list[i] = NULL;
            head_2.table_list[i] = NULL;
        }

        while (*ptr_1 != '\0') {
            if (contains_elem(&head_1, *ptr_1) == 0) {
                insert_elem(&head_1, *ptr_1);
            }
            if (contains_elem(&head_2, *ptr_2) == 0) {
                insert_elem(&head_2, *ptr_2);
            }
            ptr_1++;
            ptr_2++;
        }

        print_elem(&head_1);
        print_elem(&head_2);

        int res = compare_hash_table(&head_1, &head_2);
        printf("Are they anagram? %d\n", res);

        delete_table(&head_1);
        delete_table(&head_2);
    }


    return 0;
}
