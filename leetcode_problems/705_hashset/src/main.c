#include "../hdr/hash_set.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    hash_set hash_set_head;
    bool_ res;
    char *text[2] = {"FALSE", "TRUE"};

    for (int i = 0; i < SET_SIZE; ++i)
        hash_set_head.set_list[i] = NULL;

    insert_data(&hash_set_head, 1);
    print_set(&hash_set_head);

    insert_data(&hash_set_head, 2);
    print_set(&hash_set_head);

    res = contains(&hash_set_head, 1);
    printf("set contains %d: %s\n", 1, text[res]);

    res = contains(&hash_set_head, 3);
    printf("set contains %d: %s\n", 3, text[res]);

    insert_data(&hash_set_head, 2);
    print_set(&hash_set_head);

    res = contains(&hash_set_head, 2);
    printf("set contains %d: %s\n", 2, text[res]);

    remove_data(&hash_set_head, 2);
    print_set(&hash_set_head);

    res = contains(&hash_set_head, 2);
    printf("set contains %d: %s\n", 2, text[res]);

    printf("%d\n", -4 % 3);

    return 0;
}
