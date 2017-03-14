#ifndef _Tree_H
#define _Tree_H

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMax( SearchTree T );
Position FindMin( SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
SearchTree Delete( ElementType X, SearchTree T );
ElementType Retrieve( PositionP );

//add some functions
void ShowTree( SearchTree T );
#endif // _Tree_H
