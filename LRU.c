#include <stdio.h>

int findLRU(int lastUsed[], int n) {
    int i, minIndex = 0;
    for (i = 1; i < n; i++) {
        if (lastUsed[i] < lastUsed[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex; // return index of least recently used page
}

int main() {
    int frames[10], lastUsed[10];
    int pages[30];
    int fCount = 0, time = 0, pageFaults = 0;
    int n, m, i, j, pos, hit;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter number of pages: ");
    scanf("%d", &m);

    printf("Enter reference string: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &pages[i]);
    }

    // initialize frames as empty
    for (i = 0; i < n; i++) {
        frames[i] = -1;
        lastUsed[i] = 0;
    }

    for (i = 0; i < m; i++) {
        hit = 0;

        // check if page is already in frame
        for (j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                time++;
                lastUsed[j] = time; // update its last used time
                break;
            }
        }

        if (hit == 0) {
            // if empty frame available
            if (fCount < n) {
                frames[fCount] = pages[i];
                time++;
                lastUsed[fCount] = time;
                fCount++;
                pageFaults++;
            } else {
                // replace LRU page
                pos = findLRU(lastUsed, n);
                frames[pos] = pages[i];
                time++;
                lastUsed[pos] = time;
                pageFaults++;
            }
        }

        // print current frames
        printf("\nReference %d -> ", pages[i]);
        for (j = 0; j < n; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}