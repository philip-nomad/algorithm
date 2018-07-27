#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
int stack[MAXSIZE];
int i;

void initStack() {
    i = -1;
}

bool empty() {
    return i == -1;
}

void push(int value) {
    if (i < MAXSIZE) {
        stack[++i] = value;
    } else {
        printf("stackoverFlow");
    }
}

void pop() {
    if (empty()) {
        printf("EMPTY!");
    } else {
        --i;
    }
}


int top() {
    if (empty()) {
        printf("EMPTY!");
    } else {
        return stack[i];
    }
}

int size() {
    return i + 1;
}

void printStack() {
    if (empty()) {
        printf("EMPTY");
    } else {
        for (int j = i; j >= 0; --j) {
            printf("%d ", stack[j]);
        }
    }
    printf("\n");
}

int main() {
    initStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();
    push(4);
    printStack();
    push(5);
    printStack();
    pop();
    printStack();
    printf("top : %d\n", top());
    printf("size : %d\n", size());
}