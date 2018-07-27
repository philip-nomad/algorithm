#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct position {
    int data;
    int rank;
};

class sequence {
public:
    const int maxSize = 10;
    position **arr;

    void init();

    int elemAtRank(int rank);

    void replaceAtRank(int rank, int value);

    void insertAtRank(int rank, int value);

    void removeAtRank(int rank);

    position *first();

    position *last();

    int before(position *p);

    int after(position *p);

    void replaceElement(position *p, int value);

    void swapElements(position *p, position *q);

    void insertBefore(position *p, int value);

    void insertAfter(position *p, int value);

    void insertFirst(int value);

    void insertLast(int value);

    void remove(position *p);

    position *atRank(int rank);

    int rankof(position *p);

    void print();
};

void sequence::init() {
    arr = (position **) malloc(sizeof(position));
}

void sequence::insertAtRank(int rank, int value) {
    position *newP = (position *) malloc(sizeof(position));
    newP->rank = rank;
    newP->data = value;
    arr[rank] = newP;
}

void sequence::removeAtRank(int rank) {

}

position *sequence::first() {
    return arr[0];
}

position *sequence::last() {

}

int sequence::before(position *p) {

}

void sequence::replaceElement(position *p, int value) {

}

void sequence::swapElements(position *p, position *q) {

}

void sequence::insertBefore(position *p, int value) {

}

void sequence::insertAfter(position *p, int value) {

}

void sequence::insertFirst(int value) {

}

int sequence::after(position *p) {

}

position *sequence::atRank(int rank) {
    return arr[rank];
}

int sequence::elemAtRank(int rank) {
    return arr[rank]->data;
}

void sequence::replaceAtRank(int rank, int value) {
    arr[rank]->data = value;
}

void sequence::remove(position *p) {

}

int sequence::rankof(position *p) {

}

void sequence::print() {

}

void sequence::insertLast(int value) {

}


