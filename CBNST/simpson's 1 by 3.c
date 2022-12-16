#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define f(x) (1.0f/(1.0f+(x*x)))

#define max 100

int main()
{
    int n;
    printf("Enter the number of subintervals\n");
    scanf("%d",&n);
    
    assert(n%2==0);
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
    
    for(int i = 1;i<n;i++)
    {
        if((i&1)==1) ans+=4*y[i];
        else ans+=2*y[i];
    }
    
    
    ans +=y[0]+y[n];
    ans *= (h/3.0f);
    printf("%f",ans);
    return 0;
}

// Enter the number of subintervals
// 6
// Enter teh interval (x0,x1): 0 6
// 1.366174
