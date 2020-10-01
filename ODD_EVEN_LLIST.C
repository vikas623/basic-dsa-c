#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *next;
}*head=NULL,*temp,*endnode;
void insert(int item,int j,int n);
void segregate();
void print();
int main() 
{
  
    int n;
    int item,t,j;
         head=NULL;
         endnode=NULL;
         printf("Enter no. of elements: ");
         scanf("%d",&n);
         for(j=0;j<n;j++)
         {
             scanf("%d",&item);
             insert(item,j,n);
         }   
         segregate();
           print();
         printf("\n");
    return 0;
}

void insert(int item,int j,int n)
{
      if(head==NULL)
      {
           temp=(struct node*)malloc(sizeof(struct node));
           temp->data=item;
           temp->next=NULL;
           head=temp;
      }
      else
      {
          temp->next=(struct node*)malloc(sizeof(struct node));
          temp=temp->next;
          temp->data=item;
          temp->next=NULL;
          if(j==n-1)
          {
                 endnode=temp;
          }

      }
}
void segregate()
{
     struct node *current,*prev=NULL;
     struct node *end=endnode;
     temp=NULL;
     current=head;
     while(current!=NULL)
     {
           if(current->data%2!=0)
           {
                if(current->next==NULL)
                {
                    return;
                }
                else
                {
                    current=current->next;
                }
           }
           else
           {
                 break;
           }
     }
     current=head;
     while(current!=end && current->data%2!=0)
     {
            temp=current;
            current=current->next;
            endnode->next=temp;
            endnode->next->next=NULL;
            endnode=endnode->next;
            
     }
     head=current;
     if(current->data%2==0)
     {
             while(current!=end)
             {
                    if(current->data%2==0)
                    {
                           prev=current;
                           current=current->next;
                    }
                    else
                    {
                           temp=current;
                           prev->next=current->next;
                           current=current->next;
                           endnode->next=temp;
                           endnode->next->next=NULL;
                           endnode=endnode->next;
                    }
             }
     }
     else
     {
          prev=current;
     }
     if(endnode!=end && end->data%2!=0)
     {
          prev->next=end->next;
          end->next=NULL;
          endnode->next=end;
     }
     
}
void print()
{
     temp=head;
     while(temp!=NULL)
     {
         printf("%d ",temp->data);
         temp=temp->next;
     }
}