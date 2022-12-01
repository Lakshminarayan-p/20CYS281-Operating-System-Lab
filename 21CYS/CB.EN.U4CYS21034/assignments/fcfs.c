/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
int main()
{
    int n,i,j;
    int av_wt_t=0;
    int avturn_ar_t=0;
    printf("Enter total number of processes:");
    scanf("%d",&n);
    int b_t[n];
    int wait_t[n];
    int turn_ar_t[n]; 
    for(i=0;i<n;i++)
    {
	printf("\nEnter Burst Time of process p[%d]:",i);
        scanf("%d",&b_t[i]);
    }
    wait_t[0]=0;
    for(i=1;i<n;i++)
    {
        wait_t[i]=0;
        for(j=0;j<i;j++)
	{
            wait_t[i]=wait_t[i]+b_t[j];
	}
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\t\t\tTurna762round Time");
    for(i=0;i<n;i++)
    {
        turn_ar_t[i]=b_t[i]+wait_t[i];
        av_wt_t=av_wt_t+wait_t[i];
        avturn_ar_t=avturn_ar_t+turn_ar_t[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i,b_t[i],wait_t[i],turn_ar_t[i]);
    }
    av_wt_t=av_wt_t/i;
    avturn_ar_t=avturn_ar_t/i;
    printf("\nAverage WT :%d",av_wt_t);
    printf("\nAverage TAT :%d\n",avturn_ar_t);
    return 0;
}