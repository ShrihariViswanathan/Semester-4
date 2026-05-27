#include <stdio.h>

#define MAX 50

void printFrames(int f[], int n, int pf)
{
    printf("PF No. %d: ", pf);

    for(int i = 0; i < n; i++)
    {
        if(f[i] == -1)
            printf("- ");
        else
            printf("%d ", f[i]);
    }
    printf("\n");
}

int search(int f[], int n, int key)
{
    for(int i = 0; i < n; i++)
        if(f[i] == key)
            return i;

    return -1;
}

// ---------------- FIFO ----------------
void FIFO(int p[], int n, int fn)
{
    int f[MAX], i, j = 0, faults = 0;

    for(i = 0; i < fn; i++)
        f[i] = -1;

    printf("\nFIFO Page Replacement Process:\n");

    for(i = 0; i < n; i++)
    {
        if(search(f, fn, p[i]) == -1)
        {
            f[j] = p[i];
            j = (j + 1) % fn;

            faults++;
            printFrames(f, fn, faults);
        }
    }

    printf("FIFO Page Faults: %d\n", faults);
}

// ---------------- LRU ----------------
void LRU(int p[], int n, int fn)
{
    int f[MAX], time[MAX], i, j, faults = 0, pos;

    for(i = 0; i < fn; i++)
        f[i] = -1;

    printf("\nLRU Page Replacement Process:\n");

    for(i = 0; i < n; i++)
    {
        pos = search(f, fn, p[i]);

        if(pos != -1)
        {
            time[pos] = i;
        }
        else
        {
            int min = 9999;

            for(j = 0; j < fn; j++)
            {
                if(f[j] == -1)
                {
                    pos = j;
                    break;
                }

                if(time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }
            }

            f[pos] = p[i];
            time[pos] = i;

            faults++;
            printFrames(f, fn, faults);
        }
    }

    printf("LRU Page Faults: %d\n", faults);
}

// ---------------- OPTIMAL ----------------
void Optimal(int p[], int n, int fn)
{
    int f[MAX], i, j, k, faults = 0, pos;

    for(i = 0; i < fn; i++)
        f[i] = -1;

    printf("\nOptimal Page Replacement Process:\n");

    for(i = 0; i < n; i++)
    {
        if(search(f, fn, p[i]) == -1)
        {
            int far, index = -1;

            for(j = 0; j < fn; j++)
            {
                if(f[j] == -1)
                {
                    index = j;
                    break;
                }
            }

            if(index == -1)
            {
                far = -1;

                for(j = 0; j < fn; j++)
                {
                    for(k = i + 1; k < n; k++)
                    {
                        if(f[j] == p[k])
                            break;
                    }

                    if(k > far)
                    {
                        far = k;
                        index = j;
                    }
                }
            }

            f[index] = p[i];

            faults++;
            printFrames(f, fn, faults);
        }
    }

    printf("Optimal Page Faults: %d\n", faults);
}

// ---------------- MAIN ----------------
int main()
{
    int frames, n, pages[MAX];

    printf("Enter the number of Frames: ");
    scanf("%d", &frames);

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    FIFO(pages, n, frames);
    LRU(pages, n, frames);
    Optimal(pages, n, frames);

    return 0;
}