
//bisection

#include<stdio.h>
#include<math.h>
#define eps 0.001
double func(double x)
{
    return x*x*x -4*x-9;
}

void bisection(double a,double b)
{
    int count =1,itr;
    double c;
    if(func(a)*func(b)>0)
    {
        printf("Wrong Interval\n");
        return;
    }
    
    if(func(a)*func(b)==0)
    {
        printf("The root of the equation are %lf, %lf\n",a,b);
        return;
    }
    
    else
    {
        printf("Enter the number of iterations\n");
        scanf("%d",&itr);
        while(count<=itr)
        {
            c = (a+b)/2.0;
            if(func(c)==0.0)
                break;
                
            printf("The root after %d iterations is %lf\n",count,c);
            if(func(c)*func(a)<0)
                b=c;
            else
                a=c;
            
            count++;
        }
        if((b-a)>=eps)
        {
            printf("The root value is %lf",c);
        }
    }
}
int main()
{
    bisection(2.7,2.75);
}




//Regula false or false position method
#include<stdio.h>
#include<math.h>
#define eps 0.001
double f(double x)
{
    return x*x*x -4*x-9;
}

void Regula(double a,double b)
{
    int count =1,itr;
    double c,prev;
    if(f(a)*f(b)>0)
    {
        printf("Wrong Interval\n");
        return;
    }
    
    if(f(a)*f(b)==0)
    {
        printf("The root of the equation are %lf, %lf\n",a,b);
        return;
    }
    
    else
    {
        printf("Enter the number of iterations\n");
        scanf("%d",&itr);
        while(count<=itr)
        {
            c=prev;
            c =( a*f(b)-b*f(a))/(f(b)-f(a));
            if(f(c)==0.0)
                break;
                
            printf("The root after %d iterations is %lf\n",count,c);
            if(f(c)*f(a)<0)
                b=c;
            else
                a=c;
            
            count++;
        }
        if((f(c)-f(prev))>=eps)
        {
            printf("The root value is %lf",c);
        }
    }
}
int main()
{
    Regula(2,4);
}



//Newton Raphson
#include<stdio.h>
#include<math.h>
#define eps 0.001
double f(double x)
{
    return 3*x*x*x -2*x*x-1;
}
double derv(double x)
{
    return 9*x*x-4*x;
}

void Newton(double x)
{
    int count =1,itr;
    printf("Enter the number of iterations\n");
    scanf("%d",&itr);
    double h = f(x)/derv(x);
    while(count<=itr)
    {
        double h = f(x)/derv(x);
        x=x-h;
        printf("The root after %d iterations is %lf\n",count,x);
        count++;
    }
    if(fabs(h)>eps)
    {
        printf("The root value is %lf",x);
    }
}
int main()
{
    double a,b,x;
    a=-1,b=2;
    if(f(a)*f(b)>0)
    {
        printf("Wrong Interval\n");
        return 0;
    }
    
    if(f(a)*f(b)<0)
    {
       if(fabs(f(a)-0)>fabs(f(b)-0))
        x=a;
        else 
        x=b;
    }
    Newton(x);
}



//Guass Elimination
#include<stdio.h>
#include<math.h>
int main()
{
   
    int n = 3;
   float a[3][4]={{1,1,19,9},{2,-3,4,13},{3,4,5,40}};
    float p,s;
    float x[3];
    for(int k = 0;k<n;k++)
    {
        for(int i = k+1;i<n;i++)
        {
            p=a[i][k]/a[k][k];
            for(int j = k;j<=n;j++)
            {
                a[i][j]=a[i][j]-(p*a[k][j]);
            }
        }
    }
    
    for(int i= 0;i<n;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            printf("%f ",a[i][j]);
        }
        printf("\n");
    }
    
    x[n-1]=a[n-1][n]/a[n-1][n-1];
    for(int i = n-2;i>=0;i--)
    {
        s=0;
        for(int j = i+1;j<n;j++)
        {
            s+=(a[i][j]*x[j]);
            x[i]=(a[i][n]-s)/a[i][i];
        }
    }
    
    for(int i= 0;i<n;i++)
    {
        printf("%f\n",x[i]);
    }
}
