//
// Created by 채민균 on 2017. 5. 6..
//
// 입력으로 주어진 배열을 선형시간에 수행되는 construct heap 알고리즘을 이용하여 힙을 만들고,
// HeapSort 와 Acclerated HeapSort 를 이용하여 주어진 문제를 해결하는 코드입니다.
//

#include <iostream>
#include <vector>
#include <array>
#include <time.h>
#include <cmath>

using namespace std;

unsigned int
fixHeap(array<unsigned int, 10000002> *pVector, unsigned int index, unsigned int k, unsigned int lastIndex);

unsigned int n, m1, m2, m1Count;
int D;
double T, I;
bool isEnd;
array<unsigned int, 10000002> v = {0,}, v2 = {0,};

/**
 * 힙정렬 알고리즘
 * @param pVector : 힙정렬을 수행할 벡터의 주소값
 */
void heapSort(array<unsigned int, 10000002> *pVector) {
    unsigned int size = n;
    for (unsigned int i = size; i > 1; --i) {
        ++m1Count;//m1 이랑 같아질 때를 찾기 위해서 ++ 해준다
        unsigned int curMax = pVector->at(1); // 힙에서 현재 최대값을 curMax에 할당해준다.
        if (m1Count == m1) {
            D = fixHeap(pVector, 1LL, pVector->at(i), i - 1);;
        } else {
            fixHeap(pVector, 1LL, pVector->at(i), i - 1);
        }
        pVector->at(i) = curMax;
    }
}

/**
 * heap의 partial order를 만족시켜주는 알고리즘
 * @param pVector : 입력으로 주어진 배열을 저장하고 있는 벡터의 주소값
 * @param index : fixHeap을 수행할 인덱스
 * @param k : 처음 fixHeap 알고리즘을 호출한 root 노드의 값
 * @return : fixHeap을 마지막으로 호출한 노드의 depth
 */
unsigned int
fixHeap(array<unsigned int, 10000002> *pVector, unsigned int index, unsigned int k, unsigned int lastIndex) {
    unsigned int maxi = 0;
    bool goLeft = true;
    if (index * 2 <= lastIndex) { // 왼쪽 자식이 있다면
        maxi = pVector->at(index * 2);
    }
    if (index * 2 + 1 <= lastIndex) { // 오른쪽 자식이 있다면
        if (maxi < pVector->at(index * 2 + 1)) {
            maxi = pVector->at(index * 2 + 1);
            goLeft = false;
        }
    }
    if (maxi == 0) {
        pVector->at(index) = k;
        if (index == 1) {
            return 0;
        } else {
            return (unsigned int) log2(index / 2);
        }
    } else {
        if (k > maxi) {
            pVector->at(index) = k;
            if (index == 1) {
                return 0;
            } else {
                return (unsigned int) log2(index / 2);
            }
        } else {
            if (goLeft) {
                pVector->at(index) = pVector->at(index * 2);
                return fixHeap(pVector, index * 2, k, lastIndex);
            } else {
                pVector->at(index) = pVector->at(index * 2 + 1);
                return fixHeap(pVector, index * 2 + 1, k, lastIndex);
            }
        }
    }
}

/**
 * 선형시간에 힙을 만들어주는 알고리즘
 * @param pVector : 입력으로 주어진 배열을 저장하고 있는 벡터의 주소값
 * @param index : 힙을 구성할 root 노드의 인덱스
 */
void constructHeap(array<unsigned int, 10000002> *pVector, unsigned int index) {
    bool isLeaf = true;
    if (index * 2 <= n) {
        constructHeap(pVector, index * 2);
        isLeaf = false;
    }
    if (!isLeaf) {
        if (index * 2 + 1 <= n) {
            constructHeap(pVector, index * 2 + 1);
        }
        unsigned int k = pVector->at(index);
        fixHeap(pVector, index, k, (unsigned int) n);
    }
}

/**
 * accelerated heapsort 부함수
 * @param pVector
 * @param hStop
 * @param vacant
 * @param h
 * @return
 */
unsigned int promote(array<unsigned int, 10000002> *pVector, unsigned int hStop, unsigned int vacant, unsigned int h) {
    unsigned int vacStop;
    if (h <= hStop) {
        vacStop = vacant;
    } else if (pVector->at(2 * vacant) <= pVector->at(2 * vacant + 1)) {
        pVector->at(vacant) = pVector->at(2 * vacant + 1);
        vacStop = promote(pVector, hStop, 2 * vacant + 1, h - 1);
    } else {
        pVector->at(vacant) = pVector->at(2 * vacant);
        vacStop = promote(pVector, hStop, 2 * vacant, h - 1);
    }
    return vacStop;
}

/**
 * accelerated heapsort 부함수
 * @param pVector
 * @param root
 * @param k
 * @param vacant
 */
void bubbleUpHeap(array<unsigned int, 10000002> *pVector, unsigned int root, unsigned int k, unsigned int vacant) {
    if (vacant == root) {
        pVector->at(vacant) = k;
    } else {
        unsigned int parent = vacant / 2;
        if (k <= pVector->at(parent)) {
            pVector->at(vacant) = k;
        } else {
            pVector->at(vacant) = pVector->at(parent);
            bubbleUpHeap(pVector, root, k, parent);
        }
    }
}

/**
 * accelerated heapsort 부함수
 * @param pVector
 * @param k
 * @param vacant
 * @param h
 * @param lastIndex
 */
void fixHeapFast(array<unsigned int, 10000002> *pVector, unsigned int k, unsigned int vacant, unsigned int h,
                 unsigned int lastIndex) {
    if (h <= 1) {
        if (vacant * 2 + 1 <= lastIndex) {
            unsigned int qwe;
            if (pVector->at(vacant * 2 + 1) > pVector->at(vacant * 2)) {
                qwe = vacant * 2 + 1;
            } else {
                qwe = vacant * 2;
            }
            if (pVector->at(qwe) >= k) {
                pVector->at(vacant) = pVector->at(qwe);
                pVector->at(qwe) = k;
            } else {
                pVector->at(vacant) = k;
            }
        } else if (vacant * 2 <= lastIndex) {
            if (pVector->at(vacant * 2) >= k) {
                pVector->at(vacant) = pVector->at(vacant * 2);
                pVector->at(vacant * 2) = k;
            } else {
                pVector->at(vacant) = k;
            }
        } else {
            pVector->at(vacant) = k;
        }
    } else {
        unsigned int hStop = h / 2;
        unsigned int vacStop = promote(pVector, hStop, vacant, h);
        unsigned int vacParent = vacStop / 2;
        if (pVector->at(vacParent) <= k) {
            if (m2 == 0 && !isEnd) {
                cout << pVector->at(vacStop) << "\n";
                isEnd = true;
            }
            pVector->at(vacStop) = pVector->at(vacParent);
            bubbleUpHeap(pVector, vacant, k, vacParent);
        } else {
            fixHeapFast(pVector, k, vacStop, hStop, lastIndex);
            if (m2 == 0 && !isEnd) {
                cout << 0 << "\n";
                isEnd = true;
            }
        }
    }
}

/**
 * acceleratedHeapSort
 * @param pVector
 */
void acceleratedHeapSort(array<unsigned int, 10000002> *pVector) {
    unsigned int size = n;
    for (unsigned int i = size; i > 1; --i) {
        --m2;
        unsigned int curMax = pVector->at(1);
        --size;
        fixHeapFast(pVector, pVector->at(i), 1, (unsigned int) log2(i), size);
        pVector->at(i) = curMax;
    }
}

/**
 * D : HeapSort를 사용하여 m1번째로 큰 수를 힙에서 삭제한 뒤 힙을 재구성할 때,
 * fixHeap을 마지막으로 호출한 노드의 depth를 출력한다.(root 노드의 depth를 0으로 계산한다.)
 *
 * K : Accelerated HeapSort를 사용하여,
 * m2번째로 큰 수를 찾을 때 첫 번째 bubbleUpHeap을 발생시키는 위치에 원래 저장되어 있던 값을 출력한다.
 * bubbleUpHeap 이 발생하지 않을 경우, 0을 출력한다.
 *
 * T : Accelerated HeapSort의 수행시간을 출력한다.
 *
 * I : 기존 HeapSort의 수행시간을 출력한다.
 *
 * @return D K T I
 */
int main() {
//    std::ios::sync_with_stdio(false);
    //[start] 테스트 케이스 수 입력
    unsigned int test;
    cin >> test;
    //[end] 테스트 케이스 수 입력
    //[start] 테스트
    for (unsigned int goTest = 0; goTest < test; ++goTest) {
        //[start] 초기값 입력
        cin >> n;
        //[info] 벡터 v는 accelerated HeapSort 에 사용하고, 벡터 v2 는 HeapSort 에 사용한다.
        m1 = 0, m2 = 0;
        for (unsigned int i = 1; i <= n; ++i) {
            unsigned int dummy;
            cin >> dummy;
            v[i] = dummy;
        }
        cin >> m1 >> m2;
        m1Count = 0;
        D = -1;
        isEnd = false;
        //[end] 초기값 입력

        //[start] T,I 값을 구하기 위한 시간변수 세팅
        clock_t T_start_time, T_end_time, I_start_time, I_end_time;
        //[end] T,I 값을 구하기 위한 시간변수 세팅

        //[start] (0)힙 생성
        constructHeap(&v, 1);
        //[end] (0) 힙 생성

        //[info] 아직 정렬되지 않은 힙 벡터 v를 벡터 v2에 복사한다.
        v2 = v;

        //[start] D,I 값 구하기
        I_start_time = clock();
        heapSort(&v2);
        I_end_time = clock();
        I = (double) (I_end_time - I_start_time) / CLOCKS_PER_SEC;
        //[end] D,I 값 구하기
        cout << D << " ";

        //[start] K,T 값 구하기
        T_start_time = clock();
        acceleratedHeapSort(&v);
        T_end_time = clock();
        T = (double) (T_end_time - T_start_time) / CLOCKS_PER_SEC;
        //[end] K,T 값 구하기

        cout << T << " " << I << "\n";
    }
    //[end] 테스트
    return 0;
}