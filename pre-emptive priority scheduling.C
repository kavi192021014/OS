#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
} Process;

void schedule(Process processes[], int num_processes) {
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        int highest_priority = 9999;  // A large number
        int next_process = -1;

        // Find the process with the highest priority among the waiting processes
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                next_process = i;
            }
        }

        if (next_process == -1) {
            // No process available to execute, move time forward
            current_time++;
        } else {
            // Execute the selected process for 1 time unit
            processes[next_process].remaining_time--;
            current_time++;

            printf("Time: %d, Executing Process: %d\n", current_time, processes[next_process].id);

            if (processes[next_process].remaining_time == 0) {
                completed_processes++;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESS] = {
        {1, 0, 5, 2, 5},
        {2, 1, 3, 1, 3},
        {3, 2, 2, 3, 2},
        {4, 3, 4, 4, 4},
        {5, 4, 6, 2, 6}
    };

    int num_processes = sizeof(processes) / sizeof(processes[0]);

    printf("Preemptive Priority Scheduling:\n");
    schedule(processes, num_processes);

    return 0;
}

OUTPUT:

Time: 1, Executing Process: 1
Time: 2, Executing Process: 2
Time: 3, Executing Process: 2
Time: 4, Executing Process: 2
Time: 5, Executing Process: 1
Time: 6, Executing Process: 1
Time: 7, Executing Process: 1
Time: 8, Executing Process: 1
Time: 9, Executing Process: 5
Time: 10, Executing Process: 5
Time: 11, Executing Process: 5
Time: 12, Executing Process: 5
Time: 13, Executing Process: 5
Time: 14, Executing Process: 5
Time: 15, Executing Process: 3
Time: 16, Executing Process: 3
Time: 17, Executing Process: 4
Time: 18, Executing Process: 4
Time: 19, Executing Process: 4
Time: 20, Executing Process: 4

