#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NOTHING -555
#define UPPERQ -999

int target;

struct treenode;
typedef struct treenode Treenode;
typedef Treenode* TreenodePtr;
struct treenode{
	int data;
	TreenodePtr left;
	TreenodePtr right;
	TreenodePtr next;
};

////////////////FOR TEST/////////////////
void printstack( TreenodePtr stack ){
	if( !stack )
		return;
	printstack( stack->next );
	printf("%d\t",stack->data);
}
////////////////FOR TEST/////////////////


TreenodePtr CreatNode( int data ){
	TreenodePtr new = malloc( sizeof( Treenode ) );
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	new->next = NULL;
	return new;
}

void SetTreenode( TreenodePtr *stack ){
	TreenodePtr right = *stack;
	TreenodePtr left = right->next;
	TreenodePtr root = left->next;
	if( left->data == NOTHING )
		left = NULL;
	if( right->data == NOTHING )
		right = NULL;
	root->left = left;
	root->right = right;
	TreenodePtr upq = root->next;
	root->next = upq->next;
	*stack = root;
}

void push( TreenodePtr *stack, int data ){
	TreenodePtr new = CreatNode( data );
	new->next = *stack;
	*stack = new;
}

void pop( TreenodePtr *stack ){
	if( !*stack )
		return;
	TreenodePtr tmp = *stack;
	*stack = tmp->next;
	free( tmp );
}

bool checksum( TreenodePtr node, int sum ){
	if( !node )
		return false;
	if( !node->left && !node->right ){
		if( sum + node->data == target )
			return true;
		return false;
	}
	return checksum( node->left, node->data + sum ) || checksum( node->right, node->data + sum ) ;
}

int main() {
	char tmpchar;
	int tmpinput;
	while( scanf("%d",&target) > 0 ){
		TreenodePtr stack = NULL;
		while( 1 ){
			if( scanf("%d",&tmpinput) == 1 ){
				push( &stack, tmpinput );
			}
			else{
				tmpchar = getchar();
				if( tmpchar == ')' ){
					if( stack->data == UPPERQ ){
						pop( &stack );
						push( &stack, NOTHING );
					}
					else{
						SetTreenode( &stack );
					}

				}
				else if( tmpchar == '(' )
					push( &stack, UPPERQ );
				else if( tmpchar == ' ' )
					continue;
			}
			if( stack->data != UPPERQ && !stack->next )
				break;
		}
		if( !checksum( stack, 0) || stack->data == NOTHING )
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}
