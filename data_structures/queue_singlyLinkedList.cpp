#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    node *next;
};

typedef struct singlyLinkedList {
    node *head;
    node *tail;
};

class queue {
private:
    singlyLinkedList *s;
public:
    void init();

    void enqueue(int value);

    void dequeue();

    int front();

    int size();

    bool empty();

    void print();
};

void queue::init() {
    queue::s = (singlyLinkedList *) malloc(sizeof(singlyLinkedList));
    queue::s->head = NULL;
    queue::s->tail = NULL;
}

bool queue::empty() {
    return queue::s->head == NULL;
}

void queue::enqueue(int value) {
    //insert at tail
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    if (empty()) {
        queue::s->head = queue::s->tail = newNode;
    } else {
        node *tailNode = queue::s->tail;
        queue::s->tail = tailNode->next = newNode;
    }
}

void queue::dequeue() {
    //delete head
    if (empty()) {
        printf("EMPTY\n");
    } else {
        if (queue::s->head == queue::s->tail) {
            node *node = queue::s->head;
            node = NULL;
            queue::s->head = queue::s->tail = NULL;
        } else {
            node *headNode = queue::s->head;
            queue::s->head = headNode->next;
            headNode = NULL;
        }
    }
}

int queue::front() {
    //return headNode's data
    return queue::s->head->data;
}

int queue::size() {
    node *p = queue::s->head;
    int count = 0;
    while (p != queue::s->tail) {
        ++count;
        p = p->next;
    }
    return count;
}

void queue::print() {
    if (empty()) {
        printf("EMPTY\n");
    } else {
        node *p = queue::s->head;
        while (p != queue::s->tail) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }

}

int main() {
    queue *q = new queue;
    q->init();
    q->enqueue(1);
    q->print();
    q->dequeue();
    q->enqueue(1);
    q->print();
    q->enqueue(2);
    q->print();
    q->enqueue(3);
    q->print();
    q->enqueue(4);
    q->print();
    q->enqueue(5);
    q->print();
    printf("size : %d\n", q->size());
    printf("front : %d\n", q->front());
}

