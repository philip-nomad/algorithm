//
// Created by 채민균 on 2017. 5. 7..
//

#include <stdio.h>

#define SIZE 5000
struct process {
    int processName;
    int burstTime;
    int priority;
    int waitTime;
};

int processName, burstTime, priority, inputSize = 0, totalBurstTime = 0, averageWaitTime = 0;


void selectScheduling() {
    printf("Select Scheduling\n"
                   "1. FCFS\n"
                   "2. Non-preemptive SJF\n"
                   "3. RR\n"
                   "4. Priority\n");
}

void printInfo(struct process pc[SIZE], int num) {
    for (int i = 1; i < inputSize; ++i) {
        for (int j = i; j > 0; --j) {
            if (pc[j].processName < pc[j - 1].processName) {
                struct process temp = pc[j];
                pc[j] = pc[j - 1];
                pc[j - 1] = temp;
            } else {
                break;
            }
        }
    }
    if (num == 1) {
        printf("FCFS\n");
    } else if (num == 2) {
        printf("Non-preemptive SJF\n");
    } else if (num == 3) {
        printf("RR\n");
    } else if (num == 4) {
        printf("Priority\n");
    }
    for (int i = 0; i < inputSize; ++i) {
        averageWaitTime += pc[i].waitTime;
        printf("name : %d\t Wait Time : %d\t Burst Time : %d\n", pc[i].processName, pc[i].waitTime, pc[i].burstTime);
    }
    printf("Total Burst Time : %d\nAverage Wait Time : %d\n", totalBurstTime, averageWaitTime / inputSize);
    averageWaitTime = 0;
    for (int k = 0; k < inputSize; ++k) {
        pc[k].waitTime = 0;
    }
}

void FCFS(struct process pc[SIZE]) {
    for (int i = 0; i < inputSize - 1; ++i) {
        for (int j = i + 1; j < inputSize; ++j) {
            pc[j].waitTime += pc[i].burstTime;
        }
    }
    printInfo(pc, 1);
}

void SJF(struct process pc[SIZE]) {
    for (int i = 1; i < inputSize; ++i) {
        for (int j = i; j > 0; --j) {
            if (pc[j].burstTime < pc[j - 1].burstTime) {
                struct process temp = pc[j];
                pc[j] = pc[j - 1];
                pc[j - 1] = temp;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < inputSize - 1; ++i) {
        for (int j = i + 1; j < inputSize; ++j) {
            pc[j].waitTime += pc[i].burstTime;
        }
    }
    printInfo(pc, 2);
}

void RR(struct process pc[SIZE]) {
    struct process newP[SIZE];
    for (int k = 0; k < inputSize; ++k) {
        newP[k].priority = pc[k].priority;
        newP[k].burstTime = pc[k].burstTime;
        newP[k].processName = pc[k].processName;
        newP[k].waitTime = pc[k].waitTime;
    }
    int remainProcess = inputSize;
    while (remainProcess != 0) {
        for (int i = 0; i < inputSize; ++i) {
            if (newP[i].burstTime == 0) {
                continue;
            } else {
                int num;
                if (newP[i].burstTime > 10) {
                    newP[i].burstTime -= 10;
                    num = 10;
                } else {
                    num = newP[i].burstTime;
                    newP[i].burstTime = 0;
                    remainProcess--;
                }
                for (int j = 0; j < inputSize; ++j) {
                    if (newP[j].burstTime != 0 && i != j) {
                        newP[j].waitTime += num;
                    }
                }
            }
        }
    }
    for (int k = 0; k < inputSize; ++k) {
        newP[k].burstTime = pc[k].burstTime;
    }
    printInfo(newP, 3);
};

void Priority(struct process pc[SIZE]) {
    for (int i = 1; i < inputSize; ++i) {
        for (int j = i; j > 0; --j) {
            if (pc[j].priority < pc[j - 1].priority) {
                struct process temp = pc[j];
                pc[j] = pc[j - 1];
                pc[j - 1] = temp;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < inputSize - 1; ++i) {
        for (int j = i + 1; j < inputSize; ++j) {
            pc[j].waitTime += pc[i].burstTime;
        }
    }
    printInfo(pc, 4);
}

int main() {
    //[start] input 파일 읽기
    FILE *input = fopen("[입력파일 경로]", "r");
    //[start] 초기입력
    struct process p[SIZE];
    while (fscanf(input, "%d%d%d", &processName, &burstTime, &priority) != EOF) {
        p[inputSize].processName = processName;
        p[inputSize].burstTime = burstTime;
        p[inputSize].priority = priority;
        totalBurstTime += burstTime;
        ++inputSize;
    }
    //[end] 초기입력
    fclose(input);
    //[end] input 파일 읽기
    selectScheduling();
    int selectNum;
    while(1) {
        while (scanf("%d", &selectNum) != 1);
        if (selectNum == 1) {
            FCFS(p);
        } else if (selectNum == 2) {
            SJF(p);
        } else if (selectNum == 3) {
            RR(p);
        } else if (selectNum == 4) {
            Priority(p);
        } else if (selectNum == 0) {
            return 0;
        }
    }
}