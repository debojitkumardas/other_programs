#include <stdio.h>

/** m - number of elements in nums1, n - number of elements in nums2 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1, j = n - 1, index = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[index] = nums1[i];
            --index;
            --i;
        }
        else {
            nums1[index] = nums2[j];
            --index;
            --j;
        }
    }

    while(j >= 0) {
        nums1[index] = nums2[j];
        --index;
        --j;
    }
}

int main() {

    int a[7] = {1, 2, 3, 7, 0, 0, 0};
    int b[3] = {2, 5, 6};

    merge(a, 7, 4, b, 3, 3);

    for (int i = 0; i < 7; ++i)
        printf("%d\n", a[i]);

    return 0;
}
