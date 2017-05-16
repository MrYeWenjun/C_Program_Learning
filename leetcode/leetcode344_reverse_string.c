#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* reverseString(char* s)
{
    int n = strlen(s);
    char temp;
    int i = 0;
    int j = n-1;
    while(i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return s;
}

int main(void)
{
    char s[] = "hello";
    printf("%s\n", s);
    char* revers = reverseString(s);
    printf("%s\n",revers);
    printf("\n");
    return 0;
}
