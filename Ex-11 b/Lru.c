#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i) {
        if(time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[MAX_FRAMES], pages[MAX_PAGES], time[MAX_FRAMES];
    int num_pages, num_frames = MAX_FRAMES, page_faults = 0;
    int counter = 0, flag1, flag2, pos, i, j;

    // Sample input
    int incomingStream[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    num_pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    
    // Initialize frames
    for(i = 0; i < num_frames; ++i) {
        frames[i] = -1;
    }

    printf("Page\tFrames\n");

    for(i = 0; i < num_pages; ++i) {
        flag1 = flag2 = 0;

        for(j = 0; j < num_frames; ++j) {
            if(frames[j] == incomingStream[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0) {
            for(j = 0; j < num_frames; ++j) {
                if(frames[j] == -1) {
                    counter++;
                    page_faults++;
                    frames[j] = incomingStream[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0) {
            pos = findLRU(time, num_frames);
            counter++;
            page_faults++;
            frames[pos] = incomingStream[i];
            time[pos] = counter;
        }

        printf("%d\t", incomingStream[i]);
        for(j = 0; j < num_frames; ++j) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    return 0;
}
