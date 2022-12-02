#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
       
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number tracks containing data\n");
    scanf("%d",&n);
    int D[n+1];
    printf("Enter the tracks containing data\n");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&D[i]);
    }
    int head,r1,r2;
    printf("Enter the disk actuator arm track\n");
    scanf("%d",&head);
    printf("Enter the range of the track\n");
    scanf("%d%d",&r1,&r2);
    int seek_time = 0;
    
    D[n]=head;

    
    selectionSort(D,n+1);
    
    int idx;
    for(int i = 0;i<n+1;i++)
    {
        if(head == D[i])
        {
            idx = i;
            break;
        }
    }
    
    int curr = D[idx];
    for(int i= idx+1;i<n+1;i++)
    {
        seek_time+=abs(D[i]-curr);
        curr=D[i];
    }
    
    for(int i=idx;i>=0;i--)
    {
        seek_time+=abs(D[i]-curr);
        curr=D[i];
    }
    printf("Seek time is %d\n",seek_time);
    return 0;
}
