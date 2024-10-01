#include <stdio.h>
#include <string.h>

#include "queue.h"

int FerryCrosses(QUEUE left, QUEUE right, int ferryLength);

int main(int argc, char* argv[]) {
    int n, l, m, i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &l, &m);
        l *= 100;

        QUEUE left = queue_init_default();
        QUEUE right = queue_init_default();

        for (j = 0; j < m; j++) {
            int length;
            char bank[6];
            scanf("%d %s", &length, bank);
            if (strcmp(bank, "left") == 0) {
                enqueue(left, length, bank);
            } else {
                    enqueue(right, length, bank);
            }
        }

        printf("%d\n", FerryCrosses(left, right, l));

        queue_destroy(&left);
        queue_destroy(&right);
    }

    return 0;
}

int FerryCrosses(QUEUE left, QUEUE right, int ferryLength) {
    int bank = 0;
    int trips = 0;

    while (!is_queue_empty(left) || !is_queue_empty(right)) {
        int currentLoad = 0;
        Queue* currentQueue;
        if (bank == 0) {
            currentQueue = (Queue*)left;
        } else {
            currentQueue = (Queue*)right;
        }


        while (!is_queue_empty(currentQueue) && (currentLoad + currentQueue->front->length <= ferryLength)) {
            currentLoad += service(currentQueue);
        }

        bank = 1 - bank;
        trips++;
    }

    return trips;
}
