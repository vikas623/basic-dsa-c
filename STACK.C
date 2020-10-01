#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node *next;
}*first=NULL,*last=NULL,*ptr,*newnd,*prev; //LAST=TOP

struct node* create(int n)
{
    newnd=(struct node*)calloc(1,sizeof(struct node));
    newnd->num=n;
    newnd->next=NULL;
    return newnd;
}

void push()
{
    int nu;
    printf("\nEnter Value to push: ");
    scanf("%d",&nu);
    newnd=create(nu);
    if(first==NULL && last==NULL)
    {
        newnd->next=NULL;
        first=last=newnd;
    }
    else
    {
        last->next=newnd;
        last=last->next;
        last->next=NULL;
    }
}

void pop()
{
    ptr=first;
    while(ptr->next != NULL)
    { 
        prev=ptr;
        ptr=ptr->next;  
    }
        ptr->num=NULL;
        prev->next=NULL;
        last=prev;
}

void disp()
{
    ptr=first;
    printf("\nElements in stack : ");
    while(ptr != NULL)
    {
        printf("%d ",ptr->num);
        ptr=ptr->next;
    }
}

int main()
{
    while(1)
    {
    int ch;
    printf("\n1-> PUSH\n2-> POP\n3-> DISPLAY\n4-> Exit\nEnter Choice: ");
    scanf("%d",&ch);
    if(ch==1)
     push();
    else if(ch==2)
     pop();
    else if(ch==3)
     disp();
    else
     exit(0);
    } 
     return 0;

}