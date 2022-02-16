struct treenode;
typedef struct treenode Treenode;
typedef Treenode* TreenodePtr;

//general
struct treenode{
	char data;//or int val;
	TreenodePtr left,right;
}

TreenodePtr CreateNode( char data ){
	TreenodePtr new = malloc( sizeof(Treenode) );
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

//other
void printnode( TreenodePtr node ){
	if( !node )
		printf("\tNULL\t");
	else
		printf("\t%d\t",node->data);//%c or %d
}

void TreeTraversal( TreenodePtr node ){
	if( !node )
		return;
	printf("node:");
	printnode( node->left );
	printf("->");
	printnode( node );
	printf("<-");
	printnode( node->right );
	printf("\n");
	TreeTraversal( node->left );
	TreeTraversal( node->right );
}
