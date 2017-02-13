#include <stdio.h>
#include <limits.h>
/*
int reverse(int x) {
    long long temp = 0;
    while( x )
    {
        temp = temp * 10 + x % 10;
        x /= 10;
    }
    return ( temp > INT_MAX || temp < INT_MIN )? 0 : temp;
}
*/
int reverse ( int x )
{
    int ans = 0;
    while ( x )
    {
        int temp = ans * 10 + x % 10;
        printf("ans = %d, temp = %d\n", ans, temp);
        if ( temp / 10 != ans )  //如果temp越界，结果会不同
        {
            return 0;
        }
        ans = temp;
        x /= 10;
    }
    return ans;
}
int main( void )
{
    int x = 1534236469;
    //int x = 123;
    printf("%d\n", reverse(x));
    printf("%d %d\n", INT_MIN, INT_MAX);
    printf("%ld %ld\n", LONG_MIN, LONG_MAX);
    printf("%lld %lld\n", LLONG_MIN, LLONG_MAX);
    return 0;
}
