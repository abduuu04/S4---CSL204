#include <stdio.h>
#include <stdbool.h>

void printGanttChart(process[], int);
void getProcessDetails(process[], int);
void sort(process[], int);
void print(process[], int);
void calculateCompletionTime(process[], int);
void calculateTurnAroundTime(process[], int);
void calculateWaitingTime(process[], int);
void calculateAverageWaitingTime(process[], int);
bool thisArrivalTimeFound(int, process[], int);

typedef struct process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
    ;
    int completionTime;
} process;

void getProcessDetails(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the id of process %d: ", i + 1);
        scanf("%d", &p[i].processId);

        printf("Enter the arrival time of P%d: ", p[i].processId);
        scanf("%d", &p[i].arrivalTime);

        printf("Enter the burst time of P%d: ", p[i].processId);
        scanf("%d", &p[i].burstTime);
    }
}

void sort(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrivalTime > p[j + 1].arrivalTime)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void print(process p[], int n)
{
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].processId, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, p[i].turnAroundTime, p[i].waitingTime);
    }
}

void calculateCompletionTime(process p[], int n)
{
    p[0].completionTime = p[0].arrivalTime + p[0].burstTime;

    for (int i = 1; i < n; i++)
    {
        if (p[i].arrivalTime > p[i - 1].completionTime)
        {
            p[i].completionTime = p[i].arrivalTime + p[i].burstTime;
        }
        else
        {
            p[i].completionTime = p[i - 1].completionTime + p[i].burstTime;
        }
    }
}

void calculateTurnAroundTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
    }
}

void calculateWaitingTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
    }
}

void calculateAverageWaitingTime(process p[], int n)
{

    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += p[i].waitingTime;
    }

    printf("\nAverage waiting time = %.2f\n", sum / n);
}

void printGanttChart(process p[], int n)
{
    printf("\nGantt Chart\n");

    for (int i = 0; i < p[n - 1].completionTime * 5; i++)
    {
        printf("-");
    }

    printf("\n|");

    for (int i = 0; i <= p[n - 1].completionTime; i++)
    {
        if (thisArrivalTimeFound(i, p, n))
        {
        }
        else
        {
            printf(" ");
        }
    }

    printf("\n");

    for (int i = 0; i < p[n - 1].completionTime * 5; i++)
    {
        printf("-");
    }
}

void main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    process p[n];

    getProcessDetails(p, n);
    sort(p, n);

    calculateCompletionTime(p, n);
    calculateTurnAroundTime(p, n);
    calculateWaitingTime(p, n);
    calculateAverageWaitingTime(p, n);

    print(p, n);
    printGanttChart(p, n);
}