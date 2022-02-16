#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct operation* OPList = NULL;
int totallen;

void push( List *l,char data){
	NodePtr new = createNode( data );
	if( *l )
		new->next = *l;
	*l = new;
}

void creatOP( int op,int length,List buffer ){
	struct operation* new = malloc(sizeof( struct operation ));
	new->op = op;
	new->appendlength = length;
	new->deletebuffer = buffer;
	//push OPList to stack
	if( OPList )
		new->next = OPList;
	OPList = new;
}


int DeleteText( int k,List *TextStack ){//return the nums that been deleted successfully
	int i;
	for( i = 0; i < k && *TextStack; ++i,--totallen ){
		*TextStack = ( *TextStack )->next;
	}
	return i;
}

/////////////FOR TEST////////////////////
void TESTPrintOP(){
/*
	struct operation* tmp = OPList;
	printf("\nTEST: OPLIST AS BELOW\n");
	while( tmp ){
		printf("\nop:%d\tlen:%d\t",tmp->op,tmp->appendlength);
		printf("tmp ptr: %p\n",tmp->deletebuffer);
		if( tmp->deletebuffer )
			printf("buffer head:%c",tmp->deletebuffer->data);
		printf("\n");
		tmp = tmp->next;
	}
*/
}

void PrintStack( List s ){
/*
  	if( !s )
		return;
	PrintStack( s->next );
	printf("%c",s->data);
*/
}

////////////FOR TEST/////////////////////


int main()
{
	int firstprint = 1;
	List TextStack;
	int NumsOfOP; 
	scanf("%d",&NumsOfOP);
	while(NumsOfOP--){
		int OP; 
		scanf("%d%*c",&OP);
		switch( OP ){
			case 1:{
					   char tmpstr[101];
					   int i = 0;
					   scanf("%[^\n]%*c",tmpstr);
					   while( tmpstr[i]!='\0' ){
						   push( &TextStack,tmpstr[i] );
						   ++i;
						   ++totallen;	   
					   }
					   creatOP(1,i,NULL);
					   break;
				   }
			case 2:{
					   int k;
					   Position tmp = TextStack;
					   scanf("%d",&k);
					   creatOP(2,DeleteText( k,&TextStack ),tmp);
					   break;
				   }
			case 3:{
					   int k;
					   Position tmp = TextStack;
					   scanf("%d",&k);
					   if( k > totallen )
						   break;
					   for( int i = totallen; i != k; --i )
						   tmp = tmp->next;
					   if( firstprint )
						   firstprint = 0;
					   else
						   printf("\n");
					   printf("%c",tmp->data);
					   break;
				   }
			case 4:{
					   if( !OPList )//if no previous OP
						   break;
					   if( OPList->op ==1 ){//undo append == delete
						   //DeleteText( OPList->appendlength,&TextStack );
						   while( OPList->appendlength-- ){
							   Position tmp = TextStack;
							   TextStack = TextStack->next;
							   free( tmp );
							   --totallen;
						   }
					   }
					   else{//undo delete == append
						   TextStack = OPList->deletebuffer;
						   if( OPList->deletebuffer )
							   totallen += OPList->appendlength;
					   }  
					   struct operation* tmp = OPList;
					   OPList = OPList->next;
					   free( tmp );
					   break;
				   }
		}
/*		printf("\n\n----------------\n");
		printf("text len now is:%d\n",totallen);
		PrintStack( TextStack );
		TESTPrintOP();
		printf("\n----------------\n\n");
*/	}
	return 0;
}
