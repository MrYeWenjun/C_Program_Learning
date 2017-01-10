#include <stdio.h>
#include <stdlib.h>

struct set
{
    int a;
    int b;
};

struct Node
{
    int a;
    int b;
} RealNode;

typedef struct Position
{
    int a;
    int b;
} RealPositon;

typedef struct list
{
    int a;
    int b;
} *RealList;

void ChangeElement( RealList L )
{
    L->a++;
    L->b--;
}

int main(void)
{
    struct set set1;
    set1.a = 1;
    set1.b = 2;
    printf( "set1.a = %d, set1.b = %d\n", set1.a, set1.b );

    struct set *set2;
    set2 = &set1;
    printf( "set2.a = %d, set2.b = %d\n", set2->a, set2->b );

    RealNode.a = 10;
    RealNode.b = 20;
    printf( "RealNode.a = %d, RealNode.b = %d\n", RealNode.a, RealNode.b );

    RealPositon Position1;
    Position1.a = 100;
    Position1.b = 200;
    printf( "Position1.a = %d, Position1.b = %d\n", Position1.a, Position1.b );

    //RealList是指针类型，并不分配内存空间
    RealList List1 = malloc( sizeof( RealList ) );
    List1->a = 1000;
    List1->b = 2000;
    printf( "List1->a = %d, List1->b = %d\n", List1->a, List1->b );

    ChangeElement( List1 );
    printf( "List1->a = %d, List1->b = %d\n", List1->a, List1->b );

    return 0;
}
