#include<stdio.h>
int main()
{
    int i, n, tq, tat[20], wt[20], bt[20], temp[20], count = 0;
    int avg_wt, avg_tat;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    temp[20] = bt[20] = wt[20] = tat[20] = 0;

    printf("\n Enter Burst Time: \n");
    for(i = 0; i < n; i++)
    {
        printf("\n P%d: ", i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("\n Enter Time Quantum: ");
    scanf("%d", &tq);

    while(1)
    {
        int done = 1;
        for(i = 0; i < n; i++)
        {
            if(temp[i] > 0)
            {
                done = 0;
                if(temp[i] > tq)
                {
                    count = count + tq;
                    temp[i] = temp[i] - tq;
                }
                else
                {
                    count = count + temp[i];
                    wt[i] = count - bt[i];
                    temp[i] = 0;
                }
            }
        }
        if(done == 1)
            break;
    }

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d", i + 1, bt[i], wt[i], tat[i]);
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;
    printf("\n\nAverage Waiting Time: %d", avg_wt);
    printf("\nAverage Turnaround Time: %d", avg_tat);

    return 0;
}