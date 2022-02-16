#include<string.h>
#include <stdio.h>
#include <stdlib.h>
struct treenode{
	char data;
	struct treenode* next;
};
typedef struct treenode* TreeNodePtr;

void ReversePrint(char *str){
	if( *str == '\0' )
		return;
	ReversePrint( str+1 );
	printf("%c",*str);
}

TreeNodePtr createnode(char data){
	TreeNodePtr new = malloc(sizeof(TreeNodePtr));
	new->data = data;
	new->next = NULL;
	return new;
}

void push(TreeNodePtr* s,char data){
	TreeNodePtr new = createnode(data);	
	if( *s == NULL )
		*s = new;
	else{
		new->next = *s;
		*s = new;
	}	
}

void pop(TreeNodePtr *s){
	if(*s == NULL)
		return;
	TreeNodePtr tmp = *s;
	*s = tmp ->next;
	free(tmp);
}

int OPCmp(char c){
	switch(c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return 0;
}

int main()
{
	char str[9999];
	while(scanf("%s",str)>0){
		char res[9999];
		int i,j;
		TreeNodePtr s = NULL;
		for( i=strlen(str)-1,j=0; i>=0 ; --i ){
			switch(str[i]){
				case '(':
					while( s->data != ')'){
						res[j++] = s->data;
						pop(&s);
					}
					pop(&s);
					break;
				case ')':
					push(&s,str[i]);
					break;
				default:
					if( OPCmp(str[i]) ){  //case for +-*/
						while( OPCmp(s->data) >= OPCmp(str[i])){
							res[j++] = s->data;
							pop(&s);
							if( !s )
								break;		
						}
						push(&s,str[i]);
					}
					else{
						res[j++] = str[i];
					}

			}
		}	
		res[j] = '\0';
		ReversePrint(res);
		printf("\n");
	}
	return 0;
}
