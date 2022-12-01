#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <stdbool.h>
#include<math.h>

struct Process{
    int pid,bt,art;
}typedef Process;

void findWaitingTime (Process proc[],int n, int wt[])
{
    int rt[n];
    for(int i = 0;i<n;i++)
    {
        rt[i]=proc[i].bt;
    }
    int complete = 0,t=0,minm = INT_MAX,shortest=0,finish_time;
    bool check = false;
    
    while(complete!=n)
    {
        for(int j = 0;j<n;j++)
        {
            if((proc[j].art<=t)&&(rt[j]<minm)&&rt[j]>0)
            {
                minm=rt[j];
                shortest=j;
                check=true;
            }
        }
        if(check==false)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if(minm==0)
            minm = INT_MAX;
        if(rt[shortest]==0)
        {
            complete++;
            check=false;
            finish_time=t+1;
            wt[shortest]=finish_time-proc[shortest].bt-proc[shortest].art;
            if(wt[shortest]<0)
                wt[shortest]=0;
        }
        t++;
    }
}

void findTurnAround(Process proc[],int n,int wt[],int tat[])
{
    for(int i =0;i<n;i++)
    {
        tat[i]=proc[i].bt+wt[i];
    }
}

void findAvgTime(Process proc[],int n)
{
    int wt[n],tat[n],total_wt=0,total_tat=0;
   findWaitingTime(proc,n,wt);
    findTurnAround(proc,n,wt,tat);
    printf("P\tat\tbt\twt\ttat\n");
    for(int i = 0;i<n;i++)
    {
        total_wt = total_wt+wt[i];
        total_tat=total_tat+tat[i];
        printf ("%d\t%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].art,proc[i].bt,wt[i],tat[i]);
    }
    printf("%d",total_wt);
    printf("%d",total_tat);
    printf("Average Waiting Time = %f",(float)total_wt/(float)n);
    printf("Average Turn Around Time = %f",(float)total_tat/(float)n);
    
}

int main()
{
    int n ;
    printf("Enter total number of process: ");
    scanf("%d",&n);
    
    Process proc[n];
    printf("Enter process id  burst time, arrival time respec. for %d processess\n",n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d%d%d",&proc[i].pid,&proc[i].bt,&proc[i].art);
    }
    findAvgTime(proc,n);
    return 0;
}
