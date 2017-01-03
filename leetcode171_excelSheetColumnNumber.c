#include <stdio.h>
#include <string.h>

int titleToNumber(char* s) {
    int s_len = strlen(s);
    int i = 0;
    int rtn = 0;
    for(i = 0; i < s_len; i++)
    {
        rtn = rtn * 26 + (int)(*(s + i) - 'A') + 1 ;
    }
    return rtn;
}

int main(void)
{
    char  *s = "AAA";
    int rtn = titleToNumber(s);
    printf("%d\n", rtn);
    return 0;
}
