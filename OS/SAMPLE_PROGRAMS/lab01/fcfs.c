#include<stdio.h>

struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};

float average(struct process p[], int n, int column) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        switch(column) {
            case 1: sum += p[i].at; break;
            case 2: sum += p[i].bt; break;
            case 3: sum += p[i].ct; break;
            case 4: sum += p[i].tat; break;
            case 5: sum += p[i].wt; break;
            case 6: sum += p[i].rt; break;
        }
    }

    return (float)sum / n;
}

void selection_sort(struct process p[], int n) {
    for (int i = 0; i < n - 1; i++) {

        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (p[j].at < p[min_index].at) {
                min_index = j;
            }
        }

        // Swap only once per outer loop
        if (min_index != i) {
            struct process temp = p[i];
            p[i] = p[min_index];
            p[min_index] = temp;
        }
    }
}


int main(){
    struct process p[4] = {
        {1, 0, 7, 0, 0, 0, 0},
        {2, 8, 3, 0, 0, 0, 0},
        {3, 3, 4, 0, 0, 0, 0},
        {4, 6, 6, 0, 0, 0, 0}
    };

    int n = 4;
    selection_sort(p, n);

}
