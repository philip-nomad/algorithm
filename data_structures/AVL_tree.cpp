#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
struct stdNode {
    int id;
    string name;
    string department;
    int grade;
    int height;
    stdNode *left;
    stdNode *right;
    stdNode *parent;
};

struct avlTree {
    stdNode *root;
};

void restructure(stdNode *std, avlTree *tree) {
    stdNode *rootStd = tree->root;

    stdNode *parentNode = std->parent;
    stdNode *me = std;
    while (true) {
        stdNode *comparator;
        int heightComparator = 0;
        if (me == parentNode->left) {
            //내가 부모노드의 왼쪽자식노드인 경우
            if (parentNode->right != NULL) {
                comparator = parentNode->right;
                heightComparator = comparator->height;
            }
        } else {
            //내가 부모노드의 오른쪽자식노드인 경우
            if (parentNode->left != NULL) {
                comparator = parentNode->left;
                heightComparator = comparator->height;
            }
        }

        //형제노드와 높이비교 후 avlTree의 구조적 문제가 발생했는지 검사한다.
        if (abs(me->height - heightComparator) < 2) {
            //구조적 문제가 없는 경우이다.
            if (parentNode == rootStd) {
                //부모노드가 루트노드일 경우 더 이상 타고 올라갈 부모노드가 없으므로 함수종료한다.
                return;
            } else {
                //me 노드랑 parentNode 를 다시 세팅해준다.
                me = parentNode;
                parentNode = parentNode->parent;
                continue;
            }
        } else {
            //구조적 문제가 있는 경우
            //1단계 : a,b,c(키 값이 a<b<c),
            //       x,y,z(y는 z의 자식 중에서 가장 큰 높이를 갖는 노드. x는 y의 자식 중에서 가장 큰 높이를 갖는 노드.),
            //       t1,t2(x,y,z의 자식 중 x,y,z 로 선택되지 않은 자식들이며, 키 값이 t0<t1<t2<t3) 세팅.
            stdNode *a = NULL, *b = NULL, *c = NULL;
            stdNode *t1 = NULL, *t2 = NULL;
            stdNode *z = parentNode;
            stdNode *y = NULL;
            stdNode *x = NULL;
            bool flagA = true;
            if (z->left != NULL) {
                if (z->right != NULL) {
                    if (z->left->height > z->right->height) {
                        y = z->left;
                        flagA = false;
                    } else {
                        y = z->right;
                    }
                } else {
                    y = z->left;
                    flagA = false;
                }
            } else {
                y = z->right;
            }
            bool flagB = true;
            if (y->right != NULL) {
                if (y->left != NULL) {
                    if (y->right->height > y->left->height) {
                        x = y->right;
                    } else {
                        x = y->left;
                        flagB = false;
                    }
                } else {
                    x = y->right;
                }
            } else {
                x = y->left;
                flagB = false;
            }

            if (flagA) {
                if (flagB) {
                    /*
                     * z
                     *     y
                     *         x
                     * 인경우
                     */
                    a = z;
                    b = y;
                    c = x;
                    if (y->left != NULL) {
                        t1 = y->left;
                    }
                    if (x->left != NULL) {
                        t2 = x->left;
                    }
                } else {
                    /*
                     * z
                     *         y
                     *     x
                     * 인경우
                     */
                    a = z;
                    b = x;
                    c = y;
                    if (x->left != NULL) {
                        t1 = x->left;
                    }
                    if (x->right != NULL) {
                        t2 = x->right;
                    }

                }
            } else {
                if (flagB) {
                    /*
                     *         z
                     * y
                     *     x
                     * 인경우
                     */
                    a = y;
                    b = x;
                    c = z;
                    if (x->left != NULL) {
                        t1 = x->left;
                    }
                    if (x->right != NULL) {
                        t2 = x->right;
                    }
                } else {
                    /*
                     *         z
                     *     y
                     * x
                     * 인경우
                     */
                    a = x;
                    b = y;
                    c = z;
                    if (x->right != NULL) {
                        t1 = x->right;
                    }
                    if (y->right != NULL) {
                        t2 = y->right;
                    }
                }
            }
            //2단계 : z의 위치에 b가 오게끔 한다.
            //       a와 c를 각각 b의 왼쪽, 오른쪽 자식으로 갖게끔 한다. t1을 a의 오른쪽 자식으로, t2를 c의 왼쪽 자식으로 붙여주고,
            //       height 값을 다시 세팅해준다.
            //2.1단계 : z 가 루트노드인지 아닌지 구분하고 z의 위치에 b가 오게끔 해주고 b와 z를 이어준다.
            if (z == rootStd) {
                tree->root = b;

                b->parent = NULL;
            } else {
                stdNode *parentOfZ = z->parent;
                if (z == parentOfZ->right) {
                    parentOfZ->right = b;
                    b->parent = parentOfZ;
                } else if (z == parentOfZ->left) {
                    parentOfZ->left = b;
                    b->parent = parentOfZ;
                }
            }
            //2.2단계 : a와 c를 각각 b의 왼쪽, 오른쪽 자식으로 갖게끔 한다. t1을 a의 오른쪽 자식으로, t2를 c의 왼쪽 자식으로 붙여주고, height 값을 다시 세팅해준다.
            b->left = a;
            a->parent = b;

            a->right = t1;
            if (t1 != NULL) {
                t1->parent = a;
            }
            int newHeightOfA;
            if (t1 != NULL) {
                if (a->left != NULL) {
                    newHeightOfA = max(a->left->height, t1->height) + 1;
                } else {
                    newHeightOfA = t1->height + 1;
                }
            } else {
                if (a->left != NULL) {
                    newHeightOfA = a->left->height + 1;
                } else {
                    newHeightOfA = 1;
                }
            }
            a->height = newHeightOfA;

            b->right = c;
            c->parent = b;

            c->left = t2;
            if (t2 != NULL) {
                t2->parent = c;
            }
            int newHeightOfC;
            if (t2 != NULL) {
                if (c->right != NULL) {
                    newHeightOfC = max(c->right->height, t2->height) + 1;
                } else {
                    newHeightOfC = t2->height + 1;
                }
            } else {
                if (c->right != NULL) {
                    newHeightOfC = c->right->height + 1;
                } else {
                    newHeightOfC = 1;
                }
            }
            c->height = newHeightOfC;

            int newHeightOfB = max(a->height, c->height) + 1;
            b->height = newHeightOfB;

            while (true) {
                if (b->parent != NULL) {
                    stdNode *bParent = b->parent;
                    if (b == bParent->left) {
                        if (bParent->right != NULL) {
                            bParent->height = max(bParent->right->height, b->height) + 1;
                        } else {
                            bParent->height = b->height + 1;
                        }
                    } else {
                        if (bParent->left != NULL) {
                            bParent->height = max(bParent->left->height, b->height) + 1;
                        } else {
                            bParent->height = b->height + 1;
                        }
                    }
                    b = b->parent;
                } else {
                    break;
                }
            }
            return;
        }
    }
}

string findStudent(avlTree *tree, int id) {
    string returnValue = "";
    stdNode *comparator = tree->root;
    //비교연산 횟수를 세기위한 변수를 선언해준다.
    int count = 0;
    while (true) {
        count++;
        if (comparator->id == id) {
            //해당하는 학번이 avlTree에 존재하므로 정보와 비교연산 횟수를 출력하고 함수를 종료한다.
            returnValue += to_string(comparator->id) + " " + comparator->name + " " + comparator->department + " "
                           + to_string(comparator->grade) + " " + to_string(count) + "\n";
            return returnValue;
        } else if (comparator->id < id) {
            if (comparator->right != NULL) {
                comparator = comparator->right;
            } else {
                break;
            }
        } else {
            if (comparator->left != NULL) {
                comparator = comparator->left;
            } else {
                break;
            }
        }
    }
    //while문을 빠져나온 경우이므로, 해당하는 학번이 avlTree 안에 없는 경우이다.
    returnValue += "없음 " + to_string(count) + "\n";
    return returnValue;
}

string putStudent(stdNode *std, avlTree *tree, char type) {
    string returnValue = "";
    //비교연산 횟수를 세기위한 변수를 선언해준다.
    int count = 0;
    stdNode *rootStd = tree->root;

    if (rootStd->id == 0) {
        //루트노드가 비어있으면 학생 구조체 노드를 루트노드로 설정해주고 함수를 종료한다.
        tree->root = std;
        return returnValue;
    } else {
        //루트노드가 비어있지 않은 경우이다.
        stdNode *comparator = rootStd;
        bool flag;
        while (true) {
            count++;
            if (comparator->id < std->id) {
                if (comparator->right != NULL) {
                    comparator = comparator->right;
                    continue;
                } else {
                    //flag가 true면 comparator의 오른쪽자식 노드에 학생 구조체 노드를 추가해줘야한다.
                    flag = true;
                    break;
                }
            } else if (comparator->id == std->id) {
                //해당하는 학번이 이미 avlTree 안에 존재하므로 추가할 수 없음과 비교연산 횟수를 출력한다.
                returnValue += "추가할 수 없음 " + to_string(count) + "\n";
                return returnValue;
            } else {
                if (comparator->left != NULL) {
                    comparator = comparator->left;
                    continue;
                } else {
                    //flag 가 false 면 comparator의 왼쪽자식 노드에 학생 구조체 노드를 추가해줘야한다.
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            //flag 가 true 이므로 comparator의 오른쪽자식 노드에 학생 구조체 노드를 추가해준다.
            comparator->right = std;
            std->parent = comparator;
        } else {
            //flag 가 false 이므로 comparator의 왼쪽자식 노드에 학생 구조체 노드를 추가해준다.
            comparator->left = std;
            std->parent = comparator;
        }

        if (type == 'i') {
            //추가 질의 입력일 경우 비교연산 횟수를 출력해준다.
            returnValue += to_string(count) + "\n";
        }

        //부모들의 height 값을 증가시켜야 하는 경우, 증가시켜준다.
        stdNode *parentNode = std->parent;
        stdNode *me = std;
        while (true) {
            if (me->height >= parentNode->height) {
                //부모의 height 값이 나의 height 값 보다 작거나 같으므로 부모의 height 값을 증가시켜준다.
                parentNode->height++;

                if (parentNode == rootStd) {
                    //부모노드가 루트노드이므로 height 값을 증가시키는 루프를 빠져나온다.
                    break;
                } else {
                    //부모랑 나자신 노드를 다시 세팅.
                    me = parentNode;
                    parentNode = parentNode->parent;
                }
            } else {
                //부모의 height 값이 나의 height 값 보다 크므로 height 값을 증가시키는 루프를 빠져나온다.
                break;
            }
        }

        //avlTree 의 구조적 문제가 있는지 확인하고 문제가 있다면 문제를 해결한다.
        restructure(std, tree);
        return returnValue;
    }
}

int main() {
    avlTree *tree = new avlTree;
    tree->root = new stdNode;
    //root node의 키(=학번)값을 0으로 초기화
    tree->root->id = 0;

    string input;
    cout << "초기 입력 파일명 : ";
    //입력파일명 입력
    cin >> input;
    //초기 입력 파일 (입력 파일 경로 + 입력 파일명)
    ifstream inputTxt("/Users/chaemingyun/Desktop/" + input);

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
        stdNode *std = new stdNode;
        std->id = atoi(info[0].c_str());
        std->name = info[1];
        std->department = info[2];
        std->grade = atoi(info[3].c_str());
        std->height = 1;
        std->left = NULL;
        std->parent = NULL;
        std->right = NULL;
        putStudent(std, tree, 'p');
    }
    //초기 입력 파일 스트림 닫기
    inputTxt.close();

    cout << "질의 입력 파일명 : ";
    string command;
    //질의 파일명 입력
    cin >> command;
    //질의 입력 파일 읽기(질의 파일 경로 + 질의 파일명)
    ifstream commandTxt("/Users/chaemingyun/Desktop/" + command);

    string writeData = "";
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
            writeData += findStudent(tree, atoi(info[1].c_str()));
        } else if (info[0] == "i") {
            //추가질의
            stdNode *std = new stdNode;
            std->id = atoi(info[1].c_str());
            std->name = info[2];
            std->department = info[3];
            std->grade = atoi(info[4].c_str());
            std->height = 1;
            std->left = NULL;
            std->parent = NULL;
            std->right = NULL;
            writeData += putStudent(std, tree, 'i');
        }
    }

    //질의 입력 파일 스트림 닫기
    commandTxt.close();

    cout << "출력 파일명 : ";
    string output;
    //출력 파일명 입력
    cin >> output;
    ofstream outputTxt("/Users/chaemingyun/Desktop/" + output);

    for (int k = 0; k < writeData.size(); ++k) {
        outputTxt << writeData[k];
    }

    //출력 파일 스트림 닫기
    outputTxt.close();

    return 0;
}