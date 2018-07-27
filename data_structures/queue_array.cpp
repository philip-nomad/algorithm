#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define MAXSIZE 10
int queue[MAXSIZE] = {NULL};
int i;
int first;

void init() {
    i = -1;
    first = 0;
}

bool empty() {
    return i == -1;
}

int size() {
    if (empty()) {
        printf("EMPTY\n");
    } else {
        if (i >= first) {
            return i - first + 1;
        } else {
            return MAXSIZE - (first - i) + 1;
        }
    }
}

int front() {
    return queue[first];
}

void enqueue(int value) {
    if (queue[(i + 1) % 10] == NULL) {
        i = (i + 1) % 10;
        queue[i] = value;
    } else {
        printf("FULL\n");
    };
}

void dequeue() {
    if (empty()) {
        printf("EMPTY\n");
    } else {
        queue[first] = NULL;
        if (i == first) {
            i = -1;
            first = 0;
        } else {
            first = (first + 1) % 10;
        }
    }
}

void print() {
    if (empty()) {
        printf("EMPTY");
    } else {
        int index = first;
        while (true) {
            if (queue[index] != NULL) {
                printf("%d ", queue[index]);
                ++index;
                index %= 10;
                if (index == first) {
                    break;
                }
            } else {
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    init();
    enqueue(1);
    print();
    dequeue();
    enqueue(2);
    dequeue();
    dequeue();
    print();
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    printf("front : %d\n", front());
    printf("size : %d\n", size());
    enqueue(6);
    print();
    dequeue();
    dequeue();
    print();
    enqueue(7);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    enqueue(7);
    enqueue(7);
    enqueue(7);
    enqueue(7);
    print();
    printf("size : %d\n", size());
    dequeue();
    dequeue();
    print();
}