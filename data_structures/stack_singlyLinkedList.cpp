#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct node {
    int data;
    node *next;
};

typedef struct singlyLinkedlist {
    node *head;
    node *tail;
} singlyLinkedList;


class stack {
public:
    singlyLinkedlist *s;

    void *init();

    int size(singlyLinkedlist *l);

    int top(singlyLinkedlist *l);

    void pop(singlyLinkedlist *l);

    void push(singlyLinkedlist *l, int value);

    bool empty(singlyLinkedlist *l);

    void print(singlyLinkedList *l);
};

void *stack::init() {
    s = (singlyLinkedlist *) malloc(sizeof(singlyLinkedlist));
    s->head = NULL;
    s->tail = NULL;
}

int stack::size(singlyLinkedlist *l) {
    node *headNode = l->head;
    int count = 0;
    while (headNode != l->tail) {
        ++count;
        headNode = headNode->next;
    }
    return count;
}

int stack::top(singlyLinkedlist *l) {
    //return headNode data
    if (empty(l)) {
        printf("EMPTY");
    } else {
        return l->head->data;
    }
}

void stack::pop(singlyLinkedlist *l) {
    //delete headNode
    if (empty(l)) {
        printf("EMPTY");
    } else {
        if (l->head == l->tail) {
            node *headNode = l->head;
            free(headNode);
            l->head = l->tail = NULL;
        } else {
            node *headNode = l->head;
            l->head = headNode->next;
            free(headNode);
        };
    }

}

void stack::push(singlyLinkedlist *l, int value) {
    //insert at headNode
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    if (empty(l)) {
        l->head = l->tail = newNode;
    } else {
        newNode->next = l->head;
        l->head = newNode;
    }
}

bool stack::empty(singlyLinkedlist *l) {
    return l->tail == NULL;
}

void stack::print(singlyLinkedList *l) {
    if (empty(l)) {
        printf("EMPTY");
    } else {
        node *p = l->head;
        while (p != l->tail) {
            printf("%d ", p->data);
            p = p->next;
        }
    }
    printf("\n");
}

int main() {
    stack *s = new stack;
    s->init();
    singlyLinkedList *l = s->s;
    printf("size : %d\n", s->size(l));
    s->push(l, 1);
    s->push(l, 2);
    s->push(l, 3);
    s->push(l, 4);
    s->push(l, 5);
    s->push(l, 6);
    s->print(l);
    s->pop(l);
    printf("top : %d\n", s->top(l));
    printf("size : %d\n", s->size(l));
    printf("isEmpty? : %d", s->empty(l));
}