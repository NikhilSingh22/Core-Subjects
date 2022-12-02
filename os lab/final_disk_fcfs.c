#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number tracks containing data\n");
    scanf("%d",&n);
    int D[n];
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
    int curr = head;
    int seek_time = 0;
    for(int i= 0;i<n;i++)
    {
        seek_time += abs(D[i]-curr);
        curr=D[i];
    }
    printf("Seek time is %d\n",seek_time);
    return 0;
}
