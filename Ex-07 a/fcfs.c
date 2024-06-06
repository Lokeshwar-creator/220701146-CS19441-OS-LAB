#include <stdio.h>

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n]; // Burst time for each process
    int wt[n]; // Waiting time for each process
    int tat[n]; // Turnaround time for each process

    // Input burst times for each process
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate waiting time for each process
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Calculate average waiting time
    float avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
    }
    avg_wt /= n;

    // Calculate average turnaround time
    float avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
    }
    avg_tat /= n;

    // Display results
    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time = %.2f\n", avg_wt);
    printf("Average turnaround time = %.2f\n", avg_tat);

    return 0;
}
