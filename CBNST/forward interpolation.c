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
    printf("find the y for the value of x = ");
    scanf("%f",&x);
    float u = (x-dt[0][0])/h;
    
    for(int j = 2;j<=n;j++)
    {
        for(int i = 0 ;i<n-j+1;i++)
        {
            dt[i][j]= dt[i+1][j-1]-dt[i][j-1];
        }
    }
    
    float ans = 0.0f;
    float ch = u;
    float fact = 1.0f;
    ans +=dt[0][1];
    
    for(int i = 2;i<=n;i++)
    {
        ans += (ch/fact)*dt[0][i];
        ch*= (u-(float)(i-1));
        fact *=i;
    }
    
    printf("%f",ans);
}
