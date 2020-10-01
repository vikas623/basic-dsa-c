#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(int);
int pop(void);
void display(void);
void sortinsert(int);
int main()
{
    int x;
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.SORTED PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                  printf(" Enter a value to be pushed:");
                 scanf("%d",&x);
                sortinsert(x);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void push(int x)
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

int pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        top--;
        return stack[top+1];
    }
}

void sortinsert(int ele)
{
    int x;
    if(top<=-1 || stack[top]<ele)
    {
        push(ele);
        return;
    }
    else
    {
        x=pop();
        sortinsert(ele);
        push(x);
    }
}


void display()
{
    int x;
    if(top==-1)
     return;
    else
    {
        x=pop();
        display();
        printf("%d",x);
        push(x);
    }
     
   
}