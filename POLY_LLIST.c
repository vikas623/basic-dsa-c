#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num,pow;
    struct node *next;
}*p1f=NULL,*p2f=NULL,*p1l=NULL,*p2l=NULL,*p3f=NULL,*p3l=NULL,*ptr=NULL,*newnd,*ptr2,*p4f=NULL,*p4l=NULL,*prev;

int d1,d2,i;

struct node* create(int n)
{
    newnd=(struct node*)calloc(1,sizeof(struct node));
    newnd->num=n;
    newnd->next=NULL;
    return newnd;
}

void lastt1(int p)
{
    int nu;
    printf("\nEnter coeff. for power %d: ",p);
    scanf("%d",&nu);
    newnd=create(nu);
    newnd->pow=p;
    if(p1f==NULL && p1l==NULL)
    {
        newnd->next=NULL;
        p1f=p1l=newnd;
    }
    else
    {
        p1l->next=newnd;
        p1l=p1l->next;
        p1l->next=NULL;
    }
}

void lastt2(int p)
{
    int nu;
    printf("\nEnter coeff. for power %d: ",p);
    scanf("%d",&nu);
    newnd=create(nu);
    newnd->pow=p;
    if(p2f==NULL && p2l==NULL)
    {
        newnd->next=NULL;
        p2f=p2l=newnd;
    }
    else
    {
        p2l->next=newnd;
        p2l=p2l->next;
        p2l->next=NULL;
    }
}

void printt(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ^%d ",p->num,p->pow);
        if(p->next != NULL)
         printf("+ ");
        p=p->next;
    }
}

int ismax(struct node *a,struct node *b)
{
    int cnt1=0,cnt2=0;
    while(a!=NULL)
    {
     cnt1++;
     a=a->next;
    }

    while(b!=NULL)
    {
        cnt2++;
        b=b->next;
    } 

    if(cnt1>cnt2)
     return cnt1;
    else 
     return cnt2; 
}


void addd(struct node *p1, struct node *p2)
{
    int l;
    l=ismax(p1f,p2f);
    for(int i=0;i<l;i++)
    {
    newnd=create(0);
    newnd->pow=i;
    if(p3f==NULL && p3l==NULL)
    {
        newnd->next=NULL;
        p3f=p3l=newnd;
    }
    else
    {
        p3l->next=newnd;
        p3l=p3l->next;
        p3l->next=NULL;
    }
    }
    ptr=p3f;

    while(p1 != NULL)
    {
        ptr->num+=p1->num;
        p1=p1->next;
        ptr=ptr->next;
    }

    ptr=p3f;

     while(p2 != NULL)
    {
        ptr->num+=p2->num;
        p2=p2->next;
        ptr=ptr->next;
    }

}


void mull(struct node *p1, struct node *p2)
{
    
    for(int i=0;i < ((d1+1)*(1+d2));i++)
    {
    newnd=create(0);
    if(p4f==NULL && p4l==NULL)
    {
        newnd->next=NULL;
        p4f=p4l=newnd;
    }
    else
    {
        p4l->next=newnd;
        p4l=p4l->next;
        p4l->next=NULL;
    }
    }
   

    ptr=p4f;

    while(p1 != NULL)
    {
        for(ptr2=p2;ptr2!=NULL;ptr2=ptr2->next)
        {
            ptr->pow=p1->pow + ptr2->pow;
            ptr->num+= (p1->num * ptr2->num);
            ptr=ptr->next;
        }
        p1=p1->next;
    }
}

void ans()
{
    ptr=p4f;
    while(ptr != NULL)
    {
        prev=ptr;
        for(ptr2=ptr->next;ptr2 != NULL;prev=ptr2, ptr2=ptr2->next)
        {
            if(ptr->pow == ptr2->pow)
            {
                ptr->num+=ptr2->num;
                prev->next=ptr2->next;
            }
        }
        ptr=ptr->next;

    }
}

int main()
{
    printf("\n\nEnter the highest degree of the polynomial 1: ");
    scanf("%d",&d1);
    for(i=0;i<=d1;i++)
    {
        lastt1(i);
    }

   printf("\n\nEnter the highest degree of the polynomial 2: ");
    scanf("%d",&d2);
    for(i=0;i<=d2;i++)
    {
        lastt2(i);
    }
    printf ("\n\nPoly 1: ");
    printt(p1f);
    printf ("\n\nPoly 2: ");
    printt(p2f);
    

    addd(p1f,p2f);

    printf ("\n\nPoly 1 + Poly 2: ");
    printt(p3f);

    mull(p1f,p2f);
    ans();


    printf ("\n\nPoly 1 X Poly 2: ");
    printt(p4f);
    return 0;
}
