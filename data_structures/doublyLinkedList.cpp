#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    struct node *head;
    struct node *tail;
} doublyLinkedList;

typedef struct node {
    int data;
    struct node *prev = NULL;
    struct node *next = NULL;
} node;

bool isHeadNull(doublyLinkedList *l) {
    return l->head == NULL;
}

bool isTailNull(doublyLinkedList *l) {
    return l->tail == NULL;
}

void insertAtHeadNode(doublyLinkedList *l, int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (isHeadNull(l)) {
        l->head = l->tail = newNode;
    } else {
        newNode->next = l->head;
        l->head = newNode->next->prev = newNode;

    }
}

void removeHeadNode(doublyLinkedList *l) {
    if (isHeadNull(l)) {
        l->tail = NULL;
        printf("EMPTY\n");
    } else {
        node *headNode = l->head;
        l->head = headNode->next;
        free(headNode);
    }
}

void insertAtTailNode(doublyLinkedList *l, int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (isTailNull(l)) {
        l->head = l->tail = newNode;
    } else {
        newNode->prev = l->tail;
        l->tail = newNode->prev->next = newNode;
    }
}

void removeTailNode(doublyLinkedList *l) {
    if (isTailNull(l)) {
        l->head = NULL;
        printf("EMPTY\n");
    } else {
        node *tailNode = l->tail;
        l->tail = tailNode->prev;
        free(tailNode);
    };
}

void printDoublyLinkedList(doublyLinkedList *l) {
    node *p = l->head;
    while (p != l->tail) {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    doublyLinkedList *l = (doublyLinkedList *) malloc(sizeof(doublyLinkedList));
    l->head = NULL;
    l->tail = NULL;

    insertAtHeadNode(l, 1);
    printDoublyLinkedList(l);
    insertAtHeadNode(l, 2);
    printDoublyLinkedList(l);
    removeHeadNode(l);
    printDoublyLinkedList(l);
    insertAtHeadNode(l, 3);
    printDoublyLinkedList(l);
    insertAtHeadNode(l, 4);
    printDoublyLinkedList(l);
    removeHeadNode(l);
    printDoublyLinkedList(l);
    insertAtTailNode(l, 5);
    printDoublyLinkedList(l);
    insertAtTailNode(l, 6);
    printDoublyLinkedList(l);
    insertAtTailNode(l, 7);
    printDoublyLinkedList(l);
    removeTailNode(l);
    printDoublyLinkedList(l);
    removeTailNode(l);
    printDoublyLinkedList(l);
    removeTailNode(l);
    printDoublyLinkedList(l);
    removeTailNode(l);
    printDoublyLinkedList(l);
    removeTailNode(l);
    printDoublyLinkedList(l);
    removeTailNode(l);
    printDoublyLinkedList(l);
    return 0;
}

