//
// Created by 채민균 on 2017. 6. 3..
//

#include <stdio.h>
#include <stdlib.h>

int *pageFrame;
int pageFrameSize, len = 0, arr[1005];

/**
 * 측정한 page fault 를 출력한다
 */
void printPageFault(int pageFault) {
    printf("Page Fault: %d\n\n", pageFault);
}

/**
 * pageFrame 들을 모두 -1 로 초기화한다
 */
void pageFrameInit() {
    for (int i = 0; i < pageFrameSize; ++i)
        pageFrame[i] = -1;
}

/**
 * pageFrame 의 상태를 출력한다
 */
void printStatus(int i) {
    printf("Number : %d\t", arr[i]);
    for (int k = 0; k < pageFrameSize; ++k) {
        printf("%d\t", pageFrame[k]);
    }
    printf("\n");
}

/**
 * 어떤 알고리즘을 선택할지 사용자에게 물어본다
 */
void selectOption() {
    printf("Select Scheduling\n"
                   "1. FIFO\n"
                   "2. OPT\n"
                   "3. LRU\n"
                   "4. Second-Chance\n");
}

/**
 * FIFO 알고리즘
 */
void FIFO() {
    printf("FIFO\n");
    int pageFault = 0, turn = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < pageFrameSize; ++j) {
            //pageFrame 내에 해당하는 수가 있으면
            if (pageFrame[j] == arr[i]) goto out;
        }
        //pageFrame 내에 해당하는 수가 없으면
        ++pageFault;
        pageFrame[turn] = arr[i];
        turn = (turn + 1) % pageFrameSize; //배열을 환형 큐처럼 사용하는 부분
        printStatus(i);
        continue;

        out:;
        printf("Number : %d\n", arr[i]);
    }
    printPageFault(pageFault);
}

/**
 * OPT 알고리즘
 */
void OPT() {
    printf("OPT\n");
    int pageFault = 0, status;

    for (int i = 0; i < len; ++i) {
        status = 0;
        for (int j = 0; j < pageFrameSize; ++j) {
            if (pageFrame[j] == arr[i]) { //pageFrame 내에 해당하는 수가 있으면
                status = 1;
                break;
            } else if (pageFrame[j] == -1) { //pageFrame 내에 빈자리가 있으면
                pageFrame[j] = arr[i];
                ++pageFault;
                status = 2;
                break;
            }
        }
        if (status == 0) {
            //pageFrame 내에 해당하는 수가 없으면
            int index = 0, maxi = 0, count, isFind;
            for (int j = 0; j < pageFrameSize; ++j) {
                count = isFind = 0;
                for (int k = i + 1; k < len; ++k) {
                    ++count;
                    if (pageFrame[j] == arr[k]) {
                        if (maxi < count) {
                            maxi = count;
                            index = j;
                        }
                        isFind = 1;
                        break;
                    }
                }
                if (isFind == 0) { //앞으로 참조되지 않는다면 그 페이지를 교체대상으로 선정해준다.
                    index = j;
                    break;
                }
            }
            pageFrame[index] = arr[i];
            ++pageFault;
            printStatus(i);
        } else if (status == 1) printf("Number : %d\n", arr[i]);
        else printStatus(i);
    }
    printPageFault(pageFault);
}

/**
 * LRU 알고리즘
 */
void LRU() {
    printf("LRU\n");
    //counter 배열 동적할당 및 0으로 초기화
    int *counter = (int *) malloc(sizeof(int) * pageFrameSize);
    for (int i = 0; i < len; ++i) {
        counter[i] = 0;
    }
    int pageFault = 0, status;

    for (int i = 0; i < len; ++i) {
        status = 0;
        for (int j = 0; j < pageFrameSize; ++j) {
            if (pageFrame[j] == arr[i]) { //pageFrame 내에 해당하는 수가 있으면
                counter[j] = i;
                status = 1;
                break;
            } else if (pageFrame[j] == -1) { //pageFrame 내에 빈자리가 있으면
                pageFrame[j] = arr[i];
                ++pageFault;
                counter[j] = i;
                status = 2;
                break;
            }
        }
        if (status == 0) {
            //pageFrame 내에 해당하는 수가 없으면
            int mini = 1005, index = 0;
            for (int j = 0; j < pageFrameSize; ++j) {
                if (mini > counter[j]) {
                    mini = counter[j];
                    index = j; //가장 참조한지 오래된 페이지를 찾는다
                }
            }
            pageFrame[index] = arr[i];
            counter[index] = i;
            ++pageFault;
            printStatus(i);
        } else if (status == 1)printf("Number : %d\n", arr[i]);
        else printStatus(i);
    }
    printPageFault(pageFault);
    free(counter);
}

/**
 * second chance 알고리즘
 */
void SecondChance() {
    printf("Second-Chance\n");
    int pageFault = 0, status, turn = 0;
    //referenceBits 를 동적할당하고 0으로 초기화한다
    int *referenceBits = (int *) malloc(sizeof(int) * pageFrameSize);
    for (int i = 0; i < pageFrameSize; ++i) {
        referenceBits[i] = 0;
    }

    for (int i = 0; i < len; ++i) {
        status = 0;
        for (int j = 0; j < pageFrameSize; ++j) {
            if (pageFrame[j] == arr[i]) {//pageFrame 내에 해당하는 수가 있으면
                referenceBits[j] = 1;
                status = 1;
                break;
            } else if (pageFrame[j] == -1) { //pageFrame 내에 빈자리가 있으면
                pageFrame[j] = arr[i];
                referenceBits[j] = 1;
                ++pageFault;
                status = 2;
                break;
            }
        }
        if (status == 0) {
            //pageFrame 내에 해당하는 수가 없으면
            while (1) {
                if (referenceBits[turn] == 0) {
                    pageFrame[turn] = arr[i];
                    ++pageFault;
                    referenceBits[turn] = 1;
                    break;
                } else {
                    referenceBits[turn] = 0;
                }
                turn = (turn + 1) % pageFrameSize;
            }
            turn = (turn + 1) % pageFrameSize;
            printStatus(i);
        } else if (status == 1) printf("Number : %d\n", arr[i]);
        else printStatus(i);
    }
    printPageFault(pageFault);
    free(referenceBits);
}

int main() {
    //초기에 pageFrame 사이즈를 입력받는다.
    scanf("%d", &pageFrameSize);
    pageFrame = (int *) malloc(sizeof(int) * pageFrameSize);
    FILE *dataSet = fopen("[입력파일 경로]/dataset.txt", "r");
    int num;
    while (fscanf(dataSet, "%d", &num) != EOF) {
        arr[len] = num;
        ++len;
    }
    fclose(dataSet);

    //알고리즘 선택을 반복하되, 0이 입력값으로 들어오면 프로그램을 종료한다
    selectOption();
    pageFrameInit();
    int selectNum;
    while (1) {
        while (scanf("%d", &selectNum) != 1);
        if (selectNum == 1) FIFO();
        else if (selectNum == 2) OPT();
        else if (selectNum == 3) LRU();
        else if (selectNum == 4) SecondChance();
        else if (selectNum == 0) {
            free(pageFrame);
            return 0;
        }
        selectOption();
        pageFrameInit();
    }
}