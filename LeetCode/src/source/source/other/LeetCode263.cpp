#include "leetcode.h"
#include<stdint.h>

class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0)
			return 0;
		if (num <= 5)
			return 1;
		while (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
			num = num % 2 == 0 ? (num / 2) : num;
			num = num % 3 == 0 ? (num / 3) : num;
			num = num % 5 == 0 ? (num / 5) : num;
		}
		if (num != 1) {
			return false;
		}
		return true;
	}
};

//int main() {
//	Solution * s = new Solution();
//	cout << s->isUgly(6) << endl;
//	cout << s->isUgly(14) << endl;
//	cout << s->isUgly(8) << endl;
//	cout << s->isUgly(2) << endl;
//	cout << s->isUgly(3) << endl;
//	cout << s->isUgly(7) << endl;
//	return 0;
//}
