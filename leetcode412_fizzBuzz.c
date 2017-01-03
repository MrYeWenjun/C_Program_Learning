#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) {
    char** ptr = (char**) malloc(n * sizeof(char *));
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if ((i + 1) % 3 == 0 && (i + 1) % 5 ==0)
        {
            ptr[i] = (char *) malloc(strlen("FizzBuzz") + 1);
            ptr[i] = "FizzBuzz";
        }
        else if ((i + 1) % 3 ==0)
        {
            ptr[i] = (char *) malloc(strlen("Fizz") + 1);
            ptr[i] = "Fizz";
        }
        else if ((i + 1) % 5 ==0)
        {
            ptr[i] = (char *) malloc(strlen("Buzz") + 1);
            ptr[i] = "Buzz";
        }
        else
        {
        ptr[i] = (char *) malloc(sizeof(char));
        sprintf(ptr[i], "%d", i+1);
        }
    }
    *returnSize = n;
    return ptr;
}

int main(void)
{
    int n = 20;
    int i;
    char** ret = (char**) malloc(n * sizeof(char *));
    int* returnSize = (int*) malloc(sizeof(int));
    ret = fizzBuzz(n, returnSize);
    for(i = 0; i < *returnSize; i++)
        printf("%s\n", ret[i]);
    return 0;
}
