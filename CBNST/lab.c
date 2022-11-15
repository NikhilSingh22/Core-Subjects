
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
