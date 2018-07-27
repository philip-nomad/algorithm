#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct student {
    int id;
    string name;
    string department;
    int grade;
};

//1차 해쉬함수
int h1Id(int id, int N) {
    return id % N;
}

//2차 해쉬함수
int h2Id(int id, int M) {
    return M - (id % M);
}

string doSomething(student *arr, int N, int M, int id, char type, student std) {
    int h1 = h1Id(id, N);
    int h2 = h2Id(id, M);
    int i = h1;
    //검색 프로브 횟수
    int p = 0;
    string returnValue = "";
    while (true) {
        p++;
        if (0 <= arr[i].id && arr[i].id < 100000000 && p <= N) {
            if (arr[i].id == id) {
                //해당하는 학번이 존재함
                if (type == 's') {
                    returnValue = to_string(arr[i].id) + " "
                                  + arr[i].name + " "
                                  + arr[i].department + " "
                                  + to_string(arr[i].grade) + " "
                                  + to_string(p) + "\n";
                    return returnValue;
                } else if (type == 'i') {
                    returnValue = "추가할 수 없음 " + to_string(p) + "\n";
                    return returnValue;
                } else if (type == 'd') {
                    //id 를 0 으로 만듦으로써 삭제표시를 남겨둔다.
                    arr[i].id = 0;
                    returnValue = to_string(p) + "\n";
                    return returnValue;
                }
            } else {
                i = (i + h2) % N;
            }
        } else if (type == 'i' && p > N) {
            //해당하는 학번이 배열에 존재하지는 않지만 배열이 꽉차서 추가할 수 없는 경우
            returnValue = "배열이 꽉 차서 추가할 수 없음\n";
        } else {
            //해당하는 학번이 배열에 존재하지 않음
            if (type == 's') {
                returnValue = "없음 " + to_string(p) + "\n";
                return returnValue;
            } else if (type == 'i') {
                //추가하기 위한 프로브 횟수
                int index = h1;
                while (true) {
                    if (arr[index].id == -1 || arr[index].id == 0) {
                        //원래 비어있던 셀이거나, 데이터가 있었으나 삭제된 상태인 셀인 경우
                        arr[index] = std;
                        returnValue = to_string(p) + "\n";
                        return returnValue;
                    } else {
                        index = (index + h2) % N;
                    }
                }
            } else if (type == 'p') {
                int index = h1;
                while (true) {
                    //id 가 정수 8자리이니, 최소 8자리 정수부터 최대 8자리 정수 일때
                    if (!(10000000 <= arr[index].id && arr[index].id < 100000000)) {
                        arr[index] = std;
                        return returnValue;
                    } else {
                        index = (index + h2) % N;
                    }
                }
            } else if (type == 'd') {
                returnValue = "삭제할 수 없음 " + to_string(p) + "\n";
                return returnValue;
            }
        }
    }
}

int main() {
    string input = "";
    cout << "초기 입력 파일명 : ";
    //입력파일명 입력
    cin >> input;
    //초기 입력 파일 (입력 파일 경로 + 입력 파일명)
    ifstream inputTxt("/Users/chaemingyun/Desktop/" + input);

    int N = 0, M = 0;
    student *arr;
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
        if (info[0].size() != 8) {
            //입력한 데이터가 N,M
            N = atoi(info[0].c_str());
            M = atoi(info[1].c_str());

            //배열 동적할당
            arr = new student[N];
            //동적할당 받은 배열의 각 인덱스별로 학번을 -1로 초기화 (즉, 학번이 -1인 셀은 데이터가 없는 셀과 동일함)
            for (int j = 0; j < N; ++j) {
                arr[j].id = -1;
            }
        }
        if (info[0].size() == 8) {
            //입력한 데이터가 학생정보
            student std{atoi(info[0].c_str()), info[1], info[2], atoi(info[3].c_str())};
            doSomething(arr, N, M, std.id, 'p', std);
        }
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
            student std{};
            writeData += doSomething(arr, N, M, atoi(info[1].c_str()), 's', std);
        } else if (info[0] == "i") {
            //추가질의
            student std{atoi(info[1].c_str()), info[2], info[3], atoi(info[4].c_str())};
            writeData += doSomething(arr, N, M, atoi(info[1].c_str()), 'i', std);
        } else if (info[0] == "d") {
            //삭제질의
            student std{};
            writeData += doSomething(arr, N, M, atoi(info[1].c_str()), 'd', std);
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