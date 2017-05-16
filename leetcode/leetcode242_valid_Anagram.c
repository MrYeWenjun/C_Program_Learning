#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int index = 26, i = 0;
    int temp[index];
    while(i < index)
    {
        temp[i++] = 0;
    }
    while((*s) != '\0')
    {
        temp[(int)(*(s++) - 'a')] += 1;
    }
    while((*t) != '\0')
    {
        temp[(int)(*(t++) - 'a')] -= 1;
    }
    for(i = 0; i < index; i++)
    {
        if(temp[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    //char *s = "anagram", *t = "nagaram";
    char *s = "rat", *t = "car";
    bool is = isAnagram(s, t);
    printf("%d\n", is);
    return 0;
}
