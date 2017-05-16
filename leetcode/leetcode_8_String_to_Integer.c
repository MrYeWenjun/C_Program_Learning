#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* str) {
    int length = strlen( str );
    //空字符串
    if ( length == 0 )
        return 0;
    //去掉空格和非法字符
    long long value = 0, i;
    int sign = 1;//正负号,默认正
    int signCnt = 0;
    int cnt = 0;
    while( str[cnt] == ' ' )
    {
        ++cnt;
    }
    for( i = cnt;i < length; ++i )
    {
        if( signCnt > 1 )
            return 0;
        if( str[i] == '+' )
        {
            sign = 1;
            ++signCnt;
            continue;
        }
        if( str[i] == '-' )
        {
            sign = -1;
            ++signCnt;
            continue;
        }
        if( !(str[i] >= '0' && str[i] <= '9') )
            break;
        else
        {
            value = value * 10 + str[i] - '0';
                if( value * sign >= INT_MAX )
                    return INT_MAX;
                if( value * sign <= INT_MIN )
                    return INT_MIN;
        }
    }
    return value*sign;

}

int main (void)
{
    char * str = "9223372036854775809";
    int num = myAtoi( str );
    printf("%s\n", str);
    printf("%d\n", num);
    return 0;
}
