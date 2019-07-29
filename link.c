#include<stdio.h>
#include<stdlib.h>

struct x
{
int y;
struct x*link;
};

void append(struct x**q)
{
int a;
struct x*temp;
struct x*r;

printf("enter the data");
scanf("%d",&a);
if(*q==NULL)
{
temp=(struct x*)malloc(sizeof(struct x));
temp->y=a;
temp->link=NULL;
*q=temp;
}
else
{
temp=*q;
while(temp->link!=NULL)
temp=temp->link;
r=(struct x*)malloc(sizeof(struct x));
r->y=a;
r->link=NULL;
temp->link=r;
}
}

void delete(struct x**q)
{
struct x*temp,*old;
int a,k=0;                     
if(*q==NULL)
printf("LIST IS EMPTY");

printf("enter the element to be deleted");
scanf("%d",&a);

temp=*q;

while(temp!=NULL)
{
if(temp->y==a)
{
if(temp==*q)
{*q=temp->link;
}
else
old->link=temp->link;

free(temp);
return;
}
else
{
old=temp;
temp=temp->link;
}
}
printf("no such element is found");
}

void display(struct x*q)
{
while(q!=NULL)
{
printf("%d\n",q->y);
q=q->link;
}
}

void addatbeg(struct x**q)
{
int a;
struct x*temp;

temp=(struct x*)malloc(sizeof(struct x));

printf("enter the data");
scanf("%d",&a);

temp->y=a;
temp->link=*q;
*q=temp;
}

void add(struct x**q)
{
struct x*temp,*new,*old;
int a,loc,k=0;

printf("enter the data and its location you want to add");
scanf("%d%d",&a,&loc);

new=*q;

while(new!=NULL)
{
if(k==loc-1)
{
temp=(struct x*)malloc(sizeof(struct x));
temp->y=a;
temp->link=new;
old->link=temp;
return;
}
else
{
old=new;
new=new->link;
k++;
}
}
}

void main()
{
int k;
char q;
struct x*p;
p=NULL;
do
{
printf("which operation you want to do\n  1.Add an item in the last");
scanf("%d",&k);
 
switch(k)
{
case 1:
{
append(&p);
break;
}
case 2:
{
delete(&p);
break;
}

case 3:
{
display(p);
break;
}
case 4:
{
addatbeg(&p);
break;
}
case 5:
{
add(&p);
break;
}
}
printf("do you want to do more operations");
scanf("%d",&q);
}while(q==1||q=='Y');
}