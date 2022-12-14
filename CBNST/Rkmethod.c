// NAME: NIKHIL SINGH
// SECTION: I
// BTECH CSE
// UNIVERSITY ROLL NO.: 2016880
// Enter the initial value of x and y
// 1 1.5
// Enter the step size of the differential equation
// 0.1
// Enter the value of x at which you need the value of y
// 1.2
// The value of y at x = 1.200000 is 2.504366
    
#include<stdio.h>
float func(float x, float y)
{
    return(x*x+y*y);
}
  
float rungeKutta(float x0, float y0, float x, float h)
{

    int n = (int)((x - x0) / h);
  
    float k1, k2, k3, k4, k5;

    float y = y0;
    
    for (int i=0; i<n; i++)
    {

        k1 = h*func(x0, y);
        k2 = h*func(x0 + 0.5*h, y + 0.5*k1);
        k3 = h*func(x0 + 0.5*h, y + 0.5*k2);
        k4 = h*func(x0 + h, y + k3);
  
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
  
        x0 = x0 + h;
    }
  
    return y;
}
 
int main()
{
    printf("NAME: NIKHIL SINGH\n");
    printf("SECTION: I\n");
    printf("BTECH CSE\n");
    printf("UNIVERSITY ROLL NO.: 2016880\n");
    
    float x0,y0,h,x;
    printf("Enter the initial value of x and y\n");
    scanf("%f%f",&x0,&y0);
    
    printf("Enter the step size of the differential equation\n");
    scanf("%f",&h);
    
    printf("Enter the value of x at which you need the value of y\n");
    scanf("%f",&x);
    
    printf("The value of y at x = %f is %f\n",x,rungeKutta(x0, y0, x, h));
    return 0;
}
