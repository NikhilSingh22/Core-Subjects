#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max 100

int main()
{
    float x[max],y[max];
    int n;
    printf("Enter the number of terms");
    scanf("%d",&n);
    
    printf("Enter the values of x and f(x) ");
    for(int i =0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    float X;
    printf("Enter the value of x for which you need f(x)");
    scanf("%f",&X);
    
    float ans =0.0f;
    for(int i = 0;i<n;i++)
    {
        float num = 1.0f,den = 1.0f;
        for(int j = 0;j<n;j++)
        {
            if(i==j)continue;
            num*=X-x[j];
            den*=x[i]-x[j];
        }
        ans+=(num/den)*y[i];
    }
    printf("%f",ans);
    return 0;
}
