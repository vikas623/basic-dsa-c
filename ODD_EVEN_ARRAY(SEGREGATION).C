#include<stdio.h> 
  
void changePlace (int *ar, int *br); 
void EvenOddSegre(int arr1[], int size) 
{ 
    int l_index = 0, r_index = size-1; 
    while (l_index < r_index) 
    { 
        while (arr1[l_index]%2 == 0 && l_index < r_index) 
            l_index++; 
        while (arr1[r_index]%2 == 1 && l_index < r_index) 
            r_index--; 
        if (l_index < r_index) 
        { 
            changePlace(&arr1[l_index], &arr1[r_index]); 
            l_index++; 
            r_index--; 
        } 
    } 
} 
  
void changePlace(int *ar, int *br) 
{ 
    int temp = *ar; 
    *ar = *br; 
    *br = temp; 
} 
  
int main() 
{ 
    int arr1[] = {17, 42, 19, 7, 27, 24, 30, 54, 73}; 
    int arr_size = sizeof(arr1)/sizeof(arr1[0]); 
    int i = 0; 

	printf("The given array is:  \n");
	for(i = 0; i < arr_size; i++)
		{
			printf("%d  ", arr1[i]);
		}
	printf("\n");

    EvenOddSegre(arr1, arr_size); 
    printf("The array after segregation is:  "); 
    for (i = 0; i < arr_size; i++) 
        printf("%d ", arr1[i]); 
    return 0; 
}  