
#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* a, int* b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

void print_array(int* nums, int nums_size)
{
    int i;
    for(i = 0; i < nums_size; i++)
    {
        printf("%3d", nums[i]);
    }
    printf("\n");
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* return_ptr = malloc(sizeof(int) * numsSize);
    int i;
    *returnSize = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[abs(nums[i]) - 1] < 0){
            return_ptr[*returnSize] = abs(nums[i]);
            *returnSize += 1;
        }else{
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];

        }
    }
    return return_ptr;
}

int main(void)
{

    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int* return_size = malloc(sizeof(int));
    int* return_ptr = findDuplicates(nums, nums_size, return_size);
    print_array(return_ptr, *return_size);
    free(return_size);
    free(return_ptr);
    /* test
    int a = 1;
    int b = 2;
    printf("a = %d b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d b = %d\n", a, b);
    */
    return 0;

}
