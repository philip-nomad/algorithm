#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class vector {
public:
    int maxSize = 4;
    int *arr;

    void init();

    int at(int i);

    void set(int i, int data);

    void insert(int i, int data);

    void erase(int i);

    int size();

    bool empty();

    void doubling();

    void print();
};

void vector::init() {
    arr = (int *) calloc((size_t) maxSize, sizeof(int));
}

int vector::at(int i) {
    if (arr[i] == 0) {
        printf("비어있는 공간");
        return 0;
    }
    return arr[i];
}

void vector::set(int i, int data) {
    arr[i] = data;
}

void vector::insert(int i, int data) {
    if (i >= maxSize - 1) {
        doubling();
    }
    int s = size();
    for (int from = i; from < s; ++from) {
        arr[from + 1] = arr[from];
    }
    arr[i] = data;
}

void vector::erase(int i) {
    if (i >= maxSize) {
        printf("배열의 크기를 넘어서는 인덱스입니다");
    } else {
        if (arr[i] == NULL) {
            printf("원래 비어있는 공간입니다");
        } else {
            int s = size();
            for (int from = i; from < s; ++from) {
                arr[from] = arr[from + 1];
            }
            arr[s - 1] = 0;
        }
    }
}

int vector::size() {
    int count = 0;
    int k = 0;
    while (true) {
        if (arr[k] != 0) {
            ++count;
        } else {
            break;
        }
        ++k;
    }
    return count;
}

bool vector::empty() {
    return arr[0] == 0;
}

void vector::doubling() {
    int *temp = arr;
    arr = (int *) calloc((size_t) (maxSize * 2), sizeof(int));
    for (int i = 0; i < maxSize; ++i) {
        arr[i] = temp[i];
    }
    maxSize *= 2;
}

void vector::print() {
    for (int i = 0; i < maxSize; ++i) {
        if (arr[i] == 0) {
            break;
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    vector *v = new vector;
    v->init();
    v->insert(0, 1);
    v->insert(1, 2);
    v->insert(2, 3);
    v->insert(3, 4);
    v->print();
    v->erase(0);
    v->print();
    v->set(1, 7);
    v->print();
    printf("%d\n", v->at(2));

    return 0;
}