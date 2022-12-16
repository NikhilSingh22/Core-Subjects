#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (exp(x)/(1+x))

#define max 100

int main()
{
    int n;
    printf("Enter the number of subintervals\n");
    scanf("%d",&n);
    
    float x[max],y[max];
    printf("Enter teh interval (x0,x1): ");
    scanf("%f%f",&x[0],&x[n]);
    
    float h =( x[n]-x[0])/(float)n;
    
    for(int i = 1;i<n;i++)
    {
        x[i]= x[i-1]+h;
    }
    
    for(int i= 0;i<=n;i++)
    {
        y[i]=f(x[i]);
    }
    
    float ans = 0.0f;
    
    for(int i=  1;i<n;i++)
    {
        ans+=y[i];
    }
    ans*=2;
    ans+=y[0]+y[n];
    ans *= (h/2.0f);
    printf("%f",ans);
    return 0;
}

