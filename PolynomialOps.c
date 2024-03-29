 #include<math.h>
#include<stdio.h>
#define MAX 17
typedef struct node
  {
int coeff;
struct node *next;
  }node;
node *  init();
void read(node *h1);
void print(node *h1);
node * add(node *h1,node *h2);
node * multiply(node *h1,node *h2);
/*Polynomial is stored in a linked list, ith node  gives coefficient of x^i .
  a polynomial 3x^2 + 12x^4 will be represented as (0,0,3,0,12,0,0,â¦.)
*/
void main()
{
node *h1=NULL,*h2=NULL,*h3=NULL;
int option;
do
{
printf(ânn1 : create 1âst polynomialâ);
printf(ân2 : create 2ând polynomialâ);
printf(ân3 : Add polynomialsâ);
printf(ân4 : Multiply polynomialsâ);
printf(ân5 : Quitâ);
printf(ânEnter your choice :â);
scanf(â%dâ,&option);
switch(option)
{
case 1:h1=init();read(h1);break;
case 2:h2=init();read(h2);break;
case 3:h3=add(h1,h2);
      printf(ân1âst polynomial -> â);
      print(h1);
      printf(ân2ând polynomial -> â);
      print(h2);
      printf(ân Sum = â);
      print(h3);
      break;
case 4:h3=multiply(h1,h2);
      printf(ân1âst polynomial -> â);
      print(h1);
      printf(ân2ând polynomial -> â);
      print(h2);
      printf(ân Product = â);
      print(h3);
      break;
}
}while(option!=5);
}
void  read(node *h)
{
int n,i,j,power,coeff;
node *p;
p=init();
printf(ân Enter number of terms :â);
scanf(â%dâ,&n);
/* read n terms */
for (i=0;i<n;i++)
{       printf(ânenter a term(power  coeff.)â);
scanf(â%d%dâ,&power,&coeff);
for(p=h,j=0;j<power;j++)
   p=p->next;
p->coeff=coeff;
}
}
void print(node *p)
{
   int i;
for(i=0;p!=NULL;i++,p=p->next)
if(p->coeff!=0)
printf(â%dX^%d   â,p->coeff,i);
}
node * add(node *h1, node *h2)
{
    node *h3,*p;
    h3=init();
    p=h3;
    while(h1!=NULL)
     {
h3->coeff=h1->coeff+h2->coeff;
h1=h1->next;
h2=h2->next;
h3=h3->next;
     }
 return(p);
}
node * multiply(node *h1, node *h2)
{
node *h3,*p,*q,*r;
int i,j,k,coeff,power;
h3=init();
for(p=h1,i=0;p!=NULL;p=p->next,i++)
for(q=h2,j=0;q!=NULL;q=q->next,j++)
   {
coeff=p->coeff * q->coeff;
power=i+j;
for(r=h3,k=0;k<power;k++)
r=r->next;
r->coeff=r->coeff+coeff;
    }
  return(h3);
}
node * init()
{
    int i;
    node *h=NULL,*p;
    for(i=0;i<MAX;i++)
{
p=(node*)malloc(sizeof(node));
p->next=h;
p->coeff=0;
h=p;
}
  return(h);
}
