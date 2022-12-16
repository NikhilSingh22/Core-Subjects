#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max 100

int main()
{
    float dt[max][max];
    int n;
    printf("Enter the number of data points");
    scanf("%d",&n);
    
    printf("enter the data points");
    for(int i = 0;i<n;i++)
    {
        scanf("%f%f",&dt[i][0],&dt[i][1]);
    }
   
   float h = dt[1][0]-dt[0][0];
   float x;
   printf("Enter the value of x for which you find y");
   scanf("%f",&x);
   float u = (x-dt[n-1][0])/h;
   
   for(int j=2 ;j<=n;j++)
   {
       for(int i = n-1;i>j-2;i--)
       {
           dt[i][j] = dt[i][j-1]-dt[i-1][j-1];
       }
   }
   
   float ans = dt[n-1][1];
   float ch = u;
   float fact = 1.0f;
   
   for(int i = 2 ;i<=n;i++)
   {
       ans += (ch/fact)*dt[n-1][i];
       ch *= (u+(float)(i-1));
       fact *=i;
   }
   printf("%f",ans);
}
