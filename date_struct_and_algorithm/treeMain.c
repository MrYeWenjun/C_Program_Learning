#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

int main( void )
{
    SearchTree T = NULL;

    int i;
    int a[5] = {1, 3, 2, 4, 0};
    for( i = 0; i < 5; ++i )
        T = Insert( a[ i ], T);
    printf("Max of the tree is :");
    printf("%d\n",Retrieve( FindMax( T ) ));
    printf("Min of the tree is :");
    printf("%d\n",Retrieve( FindMin( T ) ));
    ShowTree( T );
    T = Delete( 3, T );
    printf("\nMax of the tree is :");
    printf("%d\n",Retrieve( FindMax( T ) ));
    ShowTree( T );
    printf("\n");
    T = Insert( 3, T );
    ShowTree( T );
    return 0;
}
