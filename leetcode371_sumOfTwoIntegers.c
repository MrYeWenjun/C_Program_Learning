#include <stdio.h>

/*//��λ���㣬��λ�����ǵĸ�����
int getSum(int a, int b) {
    int x = 0, y = 0, temp = 0, t = 0;
    int size = 32;
    int i;
    int rtn_bit[size], rtn = 0;
    for(i = 0; i < size; i++, a >>= 1, b >>= 1)
    {
        x = 01 & a;
        y = 01 & b;
        temp = t^ x ^ y;
        rtn_bit[i] = temp;
        printf("%d", rtn_bit[i]);
        if(((x ^ y) & t ) ||( x & y))
           {
               t = 1;
           }
        else
            t = 0;
    }
    for(i = 0;i < size; i++)
    {
        rtn += rtn_bit[i] << i;
    }
    return rtn;
}
*/

/*
a ^ b �����һλ�ļӷ���(a & b) << 1����ÿһ�μӷ��Ľ�λ
*/
int getSum(int a, int b)
{
    if(b == 0)
        return a;
    return getSum(a ^ b, (a & b) << 1);
}
int main(void)
{
    int a = 20, b = 30, rtn;
    rtn = getSum(a, b);
    printf("\n");
    printf("%d\n", rtn);
    return 0;
}
