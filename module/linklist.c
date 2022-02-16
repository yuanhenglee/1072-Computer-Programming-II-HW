

struct linklist;
typedef struct linklist LinkList;
typedef LinkList* LinkListPtr;

//one way
struct linklist{
	char data;//or int val;
	LinkListPtr next;
}

LinkListPtr CreateNode( char data ){
	LinkListPtr new = malloc( sizeof(LinkList) );
	new->data = data;
	new->next = NULL;
	return new;
}

void push( LinkListPtr* stack,LinkListPtr node ){
	node->next = *stack;
	*stack = node;
}

void pop( LinkListPtr *stack ){
	if( !*stack )
		return;
	LinkListPtr tmp = *stack;
	*stack = tmp->next;
	free( tmp );
}

//two way
struct linklist{
	char data;//or int val;
	LinkListPtr pre, next;
}

LinkListPtr CreateNode( char data ){
	LinkListPtr new = malloc( sizeof(LinkList) );
	new->data = data;
	new->pre = NULL;
	new->next = NULL;
	return new;
}

void push( LinkListPtr* stack,LinkListPtr node ){
	node->next = *stack;
	if( *stack )
		*stack->pre = node;
	*stack = node;
}

void pop( LinkListPtr *stack ){
	if( !*stack )
		return;
	LinkListPtr tmp = *stack;
	*stack = tmp->next;
	if( *stack )
		*stack->pre = NULL;
	free( tmp );
}

//other
void printstack( TreenodePtr stack ){
	if( !stack )
		return;
	printstack( stack->next );
	printf("%c\t",stack->data);//%c or %d
}
