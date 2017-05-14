#include <stdio.h>

#define LENGTH(a) (sizeof(a) / sizeof(a[0]))

typedef struct ListNode
{
    int val;
    int val2;
    struct ListNode *next;
}ListNode;

int length(int a[])
{
   return sizeof(a) / sizeof(a[0]);
}
int main( void )
{
    printf("Size of int is %d\n", sizeof( int ));
    printf("Size of long is %d\n", sizeof( long ));
    printf("Size of long long is %d\n", sizeof( long long ));
    printf("Size of char is %d\n", sizeof( char ));
    printf("Size of float is %d\n", sizeof( float ));
    printf("Size of double is %d\n", sizeof( double ));
    printf("Size of ListNode is %d\n", sizeof( ListNode ));

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    char b[] = {'1', '2', '3'};
    char *p = "hello,world";

    printf("sizeof(a) / sizeof(a[0]) is %d\n", sizeof(a) / sizeof(a[0]));
    printf("sizeof a is %d\n", sizeof(a));
    printf("Use define: length of a[] is %d\n", LENGTH(a));
    printf("Use function length: length of a[] is %d\n", length(a));

    printf("sizeof(b) / sizeof(b[0]) is %d\n", sizeof(b) / sizeof(b[0]));
    printf("sizeof b is %d\n", sizeof(b));
    printf("Use define: length of b[] is %d\n", LENGTH(b));

    printf("sizeof(p) / sizeof(p[0]) is %d\n", sizeof(p) / sizeof(p[0]));
    printf("sizeof p is %d\n", sizeof(p));
    printf("sizeof p[0] is %d\n", sizeof(p[0]));
    printf("Use define: length of p[] is %d\n", LENGTH(p));
    printf("*p is %s\n", p);
    return 0;
}
