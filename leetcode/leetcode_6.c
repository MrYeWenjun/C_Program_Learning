#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int num = strlen(s);
    if((num <= numRows) || (numRows == 1))
    {
        return s;
    }
    int i = 0, j = 0, k = 0;
    char *rtn = (char*) malloc(num * sizeof(char) + 1);
    for(i = 0; i < numRows; i++)
    {
        for(j = i; j < num; j += 2 * numRows - 2)
            {
                rtn[k++] = s[j];
                if((i !=0) && (i != numRows - 1))
                {
                    int t = j + (2 * numRows - 2) - 2 *i;
                    if(t < num)
                        rtn[k++] = s[t];
                }
            }
    }
    rtn[k] = '\0';
    return rtn;
}
int main()
{
    //char* str = "PAYPALISHIRING";
    char* str = "clffrkeecbpdipufhidjcxjhrnxcxmjcxohqanxdrmgzebhnlmwpmhwdvthsfqueeexgrujigskmvrzgfwvrftwa";
    char* rtn = convert(str, 70);
    printf("%s\n", rtn);
    printf("%d\n", strlen(str));
    printf("%d\n", strlen(rtn));
    printf("%c", '\0');
    return 0;
}
