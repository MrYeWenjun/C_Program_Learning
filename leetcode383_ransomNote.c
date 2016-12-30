#include <stdio.h>
#include <stdbool.h>
/*
bool canConstruct(char* ransomNote, char* magazine) {
    char *pa = ransomNote, *pb = magazine;
    while((*pa != '\0') && (*pb != '\0'))
    {
        if(*pa == *pb)
        {
            pa++;
            pb++;
        }
        else
            pb++;
    }
    if(*pa == '\0')
        return true;
    return false;
}
*/
bool canConstruct(char * ransomNote, char * magazine)
{
    int index = 0, i = 0;
    int temp[26];
    while(index < 26)
        temp[index++] = 0;
    while(magazine[i] != '\0')
    {
        temp[(int)(magazine[i] - 'a')] += 1;
        i++;
    }
    i = 0;
    while(ransomNote[i] != '\0')
    {
        temp[(int)(ransomNote[i] - 'a')] -= 1;
        i++;
    }
    for(index = 0; index < 26; index++)
    {
        if(temp[index] < 0)
            return false;
    }
    return true;
}
int main(void)
{
    char *ransomNote = "ab";
    char *magazine = "ba";
    bool can = canConstruct(ransomNote, magazine);
    printf("%d\n", can);
    return 0;
}
