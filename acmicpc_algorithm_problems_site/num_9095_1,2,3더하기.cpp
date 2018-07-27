#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int num) {
	if (num <= 1) {
		return 1;
	} else {
		return num * factorial(num - 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int result = 0;
		int t;
		scanf("%d", &t);
		for (int i = t / 3; i >= 0; --i) {
			int count3 = i;
			int temp = t;
			temp = temp - 3 * count3;
			for (int j = temp / 2; j >= 0; --j) {
				int count2 = j;
				int qwer = temp;
				qwer = qwer - 2 * count2;
				int count1 = qwer;
				int numerator = factorial(count1 + count2 + count3);
				int denominator = factorial(count1) * factorial(count2) * factorial(count3);
				result += numerator / denominator;
			}
		}
		cout << result << "\n";
	}
}
