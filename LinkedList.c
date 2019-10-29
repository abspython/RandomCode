#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *link;
};

struct Node *top;

void push(int val){
	struct Node *tmp;
	tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->data = val;
	tmp->link=NULL;
	if(top==NULL){
		top = tmp;
	}else{
		tmp->link=top->link;
		top->link= tmp;
	}
}

void pop(){
	if(top==NULL){
		printf("Empty Stack!");
	}else{
		struct Node *tmp;
		tmp = top;
		top = top->link;
		printf("%s",tmp->data);
		free(tmp);
	}
}

void display(){
	struct Node *tmp;
	tmp = top;
	while(tmp->link!=NULL){
		printf("%s ",tmp->data);
		tmp=tmp->link;
	}
}

int main(){
	int ch=0,ex=0;
	int val;
	while(ex!=1||ch!=4){
		printf("Menu\n====\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice..");
		scanf("%d",&ch);
		switch(ch){
			case 1:scanf("%d",&val);push(val);break;
			case 2:pop();break;
			case 3:display();break;
			case 4:break;
			default: printf("Invalid choice!!");
		}
		printf("Press 1 to exit!!");
		scanf("%d",&ex);
	}
	return 0;
}
