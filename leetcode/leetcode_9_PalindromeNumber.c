#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x) {
    if( x < 0 )
        return false;
    int temp, sum = 0;
    temp = x;
    while( temp != 0 )
    {
        sum =sum * 10 + temp % 10;
        temp /= 10;
    }
    if( sum == x )
        return true;
    return false;
}

int main( void )
{
    int x = 12321;
    bool is = isPalindrome( x );
    printf("%d\n", is);
    printf("%d\n",INT_MIN);
    return 0;
}
