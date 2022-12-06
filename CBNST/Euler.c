//  float x0 = 0;
//     float y0 = 1;
//     float h = 0.025;
//     float x = 0.1;



#include<stdio.h>
float func(float x, float y)
{
    return (x + y + x * y);
}
 
void euler(float x0, float y, float h, float x)
{
    float temp = 0;
    while (x0 < x) {
        temp = y;
        y = y + h * func(x0, y);
        x0 = x0 + h;
    }
    printf("The value of y at x = %f is %f",x,y);
}
 
int main()
{
    float x0,y0,h,x;
    printf("Enter the initial value of x and y\n");
    scanf("%f%f",&x0,&y0);
    
    printf("Enter the step size of the differential equation\n");
    scanf("%f",&h);
    
    printf("Enter the value of x at which you need the value of y\n");
    scanf("%f",&x);
    
    euler(x0, y0, h, x);
    return 0;
}
