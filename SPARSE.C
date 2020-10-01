#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num,row,col;
    struct node *next;
}*newnd,*spf=NULL,*spl=NULL;




struct node* create(int n,int r, int c)
{
    newnd=(struct node*)calloc(1,sizeof(struct node));
    newnd->num=n;
    newnd->row=r;
    newnd->col=c;
    newnd->next=NULL;
    return newnd;
}


void spar(int a,int b,int c)
{
    newnd=create(a,b,c);
    if(spf==NULL && spl==NULL)
    {
        newnd->next=NULL;
        spf=spl=newnd;
    }
    else
    {
        spl->next=newnd;
        spl=spl->next;
        spl->next=NULL;
    }
}

void printt(struct node *p)
{
    printf("\n\nNUM   ROW   COL\n");
    while(p!=NULL)
    {
        printf("\n %d     %d     %d",p->num,p->row,p->col);
        p=p->next;
    }
}

int main()
{
    int i,j;
    int ro,co;
    printf("Enter no. of rows: ");
    scanf("%d",&ro);
    printf("Enter no. of columns: ");
    scanf("%d",&co);
    int arr[ro][co];

    for(i=0;i<ro;i++)
    {
        for(j=0;j<co;j++)
        {
            printf("Enter value at [%d] [%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=0;i<ro;i++)
    {
        for(j=0;j<co;j++)
        {
            if(arr[i][j]!=0)
            spar(arr[i][j],i,j);
        }
    }

    printt(spf);
    return 0;


}
