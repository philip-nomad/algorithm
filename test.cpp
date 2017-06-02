////
//// Created by 채민균 on 2017. 6. 1..
////
//#include <fstream>
//#include <iostream>
//#include <string.h>
//
//using namespace std;
//
//int main() {
//    ifstream origin("입력파일명"), comp("비교입력파일명");
//    char originText[20], compText[20];
//    int lineCount = 0;
//    while (!origin.eof() && !comp.eof()) {
//        ++lineCount;
//        origin.getline(originText, 20);
//        comp.getline(compText, 20);
//        for (int i = 0; i < 20; ++i) {
//            //아스키 코드로 48~57은 0~9 입니다.
//            if (48 <= originText[i] && originText[i] < 58 && 48 <= compText[i] && compText[i] < 58) {
//                if (originText[i] != compText[i]) {
//                    cout << lineCount << "번째 줄이 다릅니다.";
//                    return 0;
//                }
//            }
//        }
//    }
//    origin.close();
//    comp.close();
//    cout << "문서 전체가 일치합니다.";
//    return 0;
//}