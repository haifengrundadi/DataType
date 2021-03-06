#include "leetcode.h"
#include<stdint.h>

class Solution {
public:
	int nthUglyNumber(int n) {
		int factor2= 2, factor3= 3,factor5 = 5;
		int index2 = 0,index3 = 0, index5 =0;
		int ugly[n], minNum = 0;
		ugly[0] = 1;
		for(int i = 1; i < n; i++){
			minNum = min(min(factor2,factor3),factor5);
			ugly[i] = minNum;
			//不能用if else 因为要排除相等的元素比如2*3 = 3*2
			if(factor2 == minNum){
				factor2 = 2 * ugly[++index2];
			}
			if(factor3 == minNum){
				factor3 = 3 * ugly[++index3];
			}
			if(factor5 == minNum){
				factor5 = 5 * ugly[++index5];
			}
		}
		return ugly[n-1];
	}
};

//int main() {
//	Solution * s = new Solution();
//	cout << s->nthUglyNumber(6) << endl;
//	cout << s->nthUglyNumber(7) << endl;
//	cout << s->nthUglyNumber(8) << endl;
//	cout << s->nthUglyNumber(9) << endl;
//	cout << s->nthUglyNumber(10) << endl;
//	cout << s->nthUglyNumber(11) << endl;
//	return 0;
//}
