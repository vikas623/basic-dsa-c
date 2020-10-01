#include<stdio.h>

int d1,d2,i,j,l;

int max(int a, int b)
{
    if(a>b)
     return a;
    else 
     return b; 
}



void add(int arr1[], int arr2[])
{
    int arr3[l];
    for(i=0;i<=l;i++)
     arr3[i]=0;

    printf("\nPolynomial 1 + Polynomial 2:\n");
  
    for(i=0;i<=d1;i++)
     arr3[i]+=arr1[i];

    for(i=0;i<=d2;i++)
     arr3[i]+=arr2[i];
    
    for(i=0;i<=l;i++)
    {
     printf("%d ",arr3[i]);
     if(i!=0)
     printf("x^%d ",i);
     if(i<l)
      printf("+ ");
    }
}

void mull(int arr1[],int arr2[])
{
    int arrm[d1+d2+1];

    for(i=0;i<=d1+d2;i++)
     arrm[i]=0;


    for(i=0;i<=d1;i++)
    {
        for(j=0;j<=d2;j++)
        {
         arrm[i+j]+=(arr1[i]*arr2[j]);
        }
    }

    printf("\n\nPolynomial 1 x Polynomial 2:\n");

    for(i=0;i<=d1+d2;i++)
    {
     printf("%d ",arrm[i]);
     if(i!=0)
     printf("x^%d ",i);
     if(i<d1+d2)
      printf("+ ");
    }
}


int main()
{
    printf("Enter the highest degree of the polynomial 1: ");
    scanf("%d",&d1);
    int arr1[d1+1];
    for(i=0;i<=d1;i++)
    {
        printf("Enter coefficient for power %d: ",i);
        scanf("%d",&arr1[i]);
    }

    printf("Enter the highest degree of the polynomial 2: ");
    scanf("%d",&d2);
    int arr2[d2+1];
    for(i=0;i<=d2;i++)
    {
        printf("Enter coefficient for power %d: ",i);
        scanf("%d",&arr2[i]);
    }

    l=max(d1,d2);
    add(arr1,arr2);
    mull(arr1,arr2);
    return 0;
}