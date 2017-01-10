#ifndef _LIST_H_
#define _LIST_H_

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
Position FindPrevious( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );

/*
Add some functions.
*/
List InitList( ElementType X, List L );
void ShowList( List L );
void AddElement( ElementType X, List L );
List Inverse( List L );
#endif // _LIST_H_




