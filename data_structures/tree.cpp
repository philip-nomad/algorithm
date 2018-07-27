#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

/*
 * ====problem solving idea====
 * rootNode, lectureNode, studentNode 로 구분해서 트리를 구성한다.
 * rootNode 를 root 로 그 밑에 lecture 노드들을 배열로, 그 밑에 student 노드들을 배열로 갖는다.
 */
typedef struct node {
    string name = "";
    int lectureNum = -1;
    string type = "";
    int id = 0;
    node *lecture[30] = {};
    node *student[30] = {};
};

//rootNode 를 저장한다
void inputRoot(string name, int lectureNum, string type, int id, node *n) {
    //노드 구조체에 데이터 입력
    n->name = name;
    n->lectureNum = lectureNum;
    n->type = type;
    n->id = id;
}

//lectureNode 를 저장한다
void inputLecture(string name, int lectureNum, string type, int id, node *root) {
    //새로운 노드 구조체에 메모리 할당
    node *newNode = new node;
    //노드 구조체에 데이터 입력
    newNode->name = name;
    newNode->lectureNum = lectureNum;
    newNode->type = type;
    newNode->id = id;
    //책임교수(root) 밑에 분반추가
    bool flag = true;
    for (int i = 0; i < 30; ++i) {
        if (root->lecture[i] == NULL) {
            root->lecture[i] = newNode;
            flag = false;
            break;
        }
    }
    if (flag) {
        //문제에는 없지만 분반 30개를 넘기면
        printf("추가할 수 없음\n");
        delete(newNode);
    }
}

//studentNode 를 저장한다
void inputStudent(string name, int lectureNum, string type, int id, node *lecture) {
    //새로운 노드 구조체에 메모리 할당
    node *newNode = new node;
    //노드 구조체에 데이터 입력
    newNode->name = name;
    newNode->lectureNum = lectureNum;
    newNode->type = type;
    newNode->id = id;
    //lecture 노드에 학생추가
    bool flag = true;
    for (int i = 0; i < 30; ++i) {
        if (lecture->student[i] == NULL) {
            lecture->student[i] = newNode;
            flag = false;
            break;
        }
    }
    if (flag) {
        //step 5. 수강생 수가 30명인 분반에 새로운 학생을 입력하려 할 때
        printf("추가할 수 없음\n");
        delete(newNode);
    }
}

//lectureNum 에 해당하는 lectureNode 를 찾아서 반환한다
node *findLecture(int lectureNum, node *root) {
    for (int i = 0; i < 30; ++i) {
        if (root->lecture[i] == NULL) {
            break;
        }
        if (root->lecture[i]->lectureNum == lectureNum) {
            return root->lecture[i];
        }
    }
    return NULL;
}

//자신을 포함한 하위트리 정보를 전부 출력한다
void printSubtree(node *n) {
    cout << n->name << " " << n->lectureNum << " " << n->type << " " << n->id << endl;
    for (int i = 0; i < 30; ++i) {
        if (n->student[i] == NULL) {
            break;
        } else {
            node *student = n->student[i];
            cout << student->name << " " << student->lectureNum << " " << student->type << " " << student->id << endl;
        }
    }
}

//트리 전체를 출력한다
void printAllTree(node *n) {
    cout << n->name << " " << n->lectureNum << " " << n->type << " " << n->id << endl;
    for (int i = 0; i < 30; ++i) {
        if (n->lecture[i] == NULL) {
            break;
        } else {
            printSubtree(n->lecture[i]);
        }
    }
}


//구성원 정보 검색 "s 분반번호"
void printByLectureNum(int lectureNum, node *root) {
    //책임교수인지 아닌지 구분
    if (lectureNum == 0) {
        //전체 분반 출력하기
        printAllTree(root);
    } else {
        //해당 분반 출력하기
        node *n = NULL;
        //해당 분반이 있는지 확인하는 반복문
        for (int i = 0; i < 30; ++i) {
            if (root->lecture[i] == NULL) {
                break;
            } else {
                if (root->lecture[i]->lectureNum == lectureNum) {
                    n = root->lecture[i];
                    break;
                }
            }
        }
        if (n == NULL) {
            //해당 분반이 없을 경우
            printf("없음\n");
        } else {
            //해당 분반이 있을 경우
            printSubtree(n);
        }
    }
}

//삭제질의 함수
void deleteByName(string name, node *root) {
    bool flag = true;
    bool subFlag = false;
    for (int i = 0; i < 30; ++i) {
        if (root->lecture[i] != NULL) {
            //강의교수 중에서 해당하는 이름이 있는지 검색
            if (root->lecture[i]->name == name) {
                if (root->lecture[i]->student[0] != NULL) {
                    //step 8. 수강생이 존재하는 분반의 강의교수를 삭제하려 할 때
                    printf("삭제할 수 없음\n");
                } else {
                    for (int j = i + 1; j < 30; ++j) {
                        if (root->lecture[j] == NULL) {
                            root->lecture[j - 1] = NULL;
                        }
                        root->lecture[j - 1] = root->lecture[j];
                    }
                    break;
                }
            }
            for (int j = 0; j < 30; ++j) {
                if (root->lecture[i]->student[j] == NULL) {
                    break;
                } else {
                    //수강생 중에서 해당하는 이름이 있는지 검색
                    if (root->lecture[i]->student[j]->name == name) {
                        subFlag = true;
                        for (int k = j + 1; k < 30; ++k) {
                            if (root->lecture[i]->student[k] == NULL) {
                                root->lecture[i]->student[k - 1] = NULL;
                                break;
                            }
                            root->lecture[i]->student[k - 1] = root->lecture[i]->student[k];
                        }
                    }
                }
            }
            if (subFlag) {
                break;
            }
        } else {
            flag = false;
            break;
        }
    }
    if (flag) {
        //step 7. 등록되지 않은 구성원을 삭제하려 할 때
        printf("삭제할 수 없음\n");
    }
}

int main() {
    node *rootNode = new node;

    string input = "";
    cout << "초기 입력 파일명 : ";
    //입력파일명 입력
    cin >> input;
    //초기 입력 파일 (입력 파일 경로 + 입력 파일명)
    ifstream inputTxt("/Users/chaemingyun/ClionProjects/" + input);

    //초기 입력 파일 한 줄씩 처리
    while (!inputTxt.eof()) {
        char inputString[100];
        inputTxt.getline(inputString, 100);
        string info[4];
        int i = 0;
        if (inputString[0] == NULL) {
            break;
        }
        for (int j = 0; j < 100; ++j) {
            if (inputString[j] == NULL) {
                break;
            }
            if (inputString[j] == ' ') {
                ++i;
                continue;
            }
            info[i] += inputString[j];
        }
        //직책(type) 별로 입력함수 호출
        if (info[2] == "책임교수") {
            inputRoot(info[0], atoi(info[1].c_str()), info[2], atoi(info[3].c_str()), rootNode);
        } else if (info[2] == "강의교수") {
            inputLecture(info[0], atoi(info[1].c_str()), info[2], atoi(info[3].c_str()), rootNode);
        } else if (info[2] == "수강생") {
            node *lectureNode = findLecture(atoi(info[1].c_str()), rootNode);
            inputStudent(info[0], atoi(info[1].c_str()), info[2], atoi(info[3].c_str()), lectureNode);
        }
    }

    //초기 입력 파일 스트림 닫기
    inputTxt.close();

    cout << "질의 입력 파일명 : ";
    string command;
    //질의 파일명 입력
    cin >> command;
    //질의 입력 파일 읽기(질의 파일 경로 + 질의 파일명)
    ifstream commandTxt("/Users/chaemingyun/ClionProjects/" + command);

    //질의 입력 파일 한 줄씩 처리
    while (!commandTxt.eof()) {
        char inputString[100];
        commandTxt.getline(inputString, 100);
        string info[5];
        int i = 0;
        for (int j = 0; j < 100; ++j) {
            if (inputString[j] == NULL) {
                break;
            }
            if (inputString[j] == ' ') {
                ++i;
                continue;
            }
            info[i] += inputString[j];
        }
        //질의별로 해당 함수호출
        if (info[0] == "s") {
            //검색질의
            printByLectureNum(atoi(info[1].c_str()), rootNode);
        } else if (info[0] == "i") {
            //추가질의
            if (info[3] == "수강생") {
                //수강생 추가 질의
                node *lectureNode = findLecture(atoi(info[2].c_str()), rootNode);
                if (lectureNode == NULL) {
                    //step 3. 개설되지 않은 분반에 학생을 입력하려 하였을 때
                    printf("추가할 수 없음\n");
                } else {
                    inputStudent(info[1], atoi(info[2].c_str()), info[3], atoi(info[4].c_str()), rootNode);
                }
            } else {
                //강의교수(분반) 추가 질의
                node *lectureNode = findLecture(atoi(info[2].c_str()), rootNode);
                if (lectureNode != NULL) {
                    //step 6. 담당 강의교수가 있는 분반에 새 강의교수를 추가하려 할 때
                    printf("추가할 수 없음\n");
                } else {
                    inputLecture(info[1], atoi(info[2].c_str()), info[3], atoi(info[4].c_str()), rootNode);
                }
            }
        } else if (info[0] == "d") {
            //삭제질의
            deleteByName(info[1], rootNode);
        }
    }

    //질의 입력 파일 스트림 닫기
    commandTxt.close();

    return 0;
}