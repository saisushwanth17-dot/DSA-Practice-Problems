#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    unsigned pageNumber;
} QNode;

typedef struct Queue {
    int count;
    int numberOfFrames;
    int frames[10];
} Queue;

QNode* newQNode(unsigned pageNumber) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->pageNumber = pageNumber;
    return temp;
}

Queue* createQueue(int numberOfFrames) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->numberOfFrames = numberOfFrames;
    queue->count = 0;
    return queue;
}

void referencePage(Queue* q, int page) {
    int found_idx = -1;
    for (int i = 0; i < q->count; i++) {
        if (q->frames[i] == page) {
            found_idx = i;
            break;
        }
    }
    if (found_idx != -1) {
        for (int i = found_idx; i < q->count - 1; i++) {
            q->frames[i] = q->frames[i + 1];
        }
        q->frames[q->count - 1] = page;
    } else {
        if (q->count < q->numberOfFrames) {
            q->frames[q->count++] = page;
        } else {
            for (int i = 0; i < q->numberOfFrames - 1; i++) {
                q->frames[i] = q->frames[i + 1];
            }
            q->frames[q->numberOfFrames - 1] = page;
        }
    }
}

int main() {
    int n, frames;
    while (scanf("%d %d", &n, &frames) == 2) {
        Queue* q = createQueue(frames);
        for (int i = 0; i < n; i++) {
            int page;
            scanf("%d", &page);
            referencePage(q, page);
        }
        for (int i = q->count - 1; i >= 0; i--) {
            printf("%d", q->frames[i]);
            if (i > 0) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
