#include <stdio.h>

int hammingDistance(int x, int y);

int main(void)
{
  int x = 2;
  int y = 4;
  printf("disctance of %d and %d is %d\n", x, y, hammingDistance(x, y));
  return 0;
}

int hammingDistance(int x, int y)
{
  int disctance = 0;
  int val = x ^ y;
  while(val != 0)
  {
    disctance++;
    val &= val - 1;
  }
  return disctance;
}
