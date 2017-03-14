#include <stdio.h>

typedef struct ListNode
{
    int val;
    int val2;
    struct ListNode *next;
}ListNode;

int main( void )
{
    printf("Size of int is %d\n", sizeof( int ));
    printf("Size of long is %d\n", sizeof( long ));
    printf("Size of long long is %d\n", sizeof( long long ));
    printf("Size of char is %d\n", sizeof( char ));
    printf("Size of float is %d\n", sizeof( float ));
    printf("Size of double is %d\n", sizeof( double ));
    printf("Size of ListNode is %d\n", sizeof( ListNode ));
    return 0;
}
