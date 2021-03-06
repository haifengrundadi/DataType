/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */
#include "leetcode.h"

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (size == 0)
			return 0;
		vector<int> left(size);
		vector<int> right(size);
		int reuslt = 0;
		int min = prices[0], max = 0;
		int maxFE = prices[size - 1], maxM = 0;
		int i = 0;
		while (i < size) {
			if (prices[i] - min >= max) {
				max = prices[i] - min;
			}
			left[i] = max;
			if (prices[i] <= min) {
				min = prices[i];
			}
			i++;
		}
		i = 0;
		while (size - 1 - i >= 0) {
			if ( maxFE - prices[size - 1 - i]>= maxM) {
				maxM =  maxFE - prices[size - 1 - i];
				right[size - 1 - i] = maxM;
			}
			if (prices[size - 1 - i] >= maxFE) {
				maxFE = prices[size - 1 - i];
			}
			i++;
		}
		i = 0;
		while( i < size){
			reuslt =( left[i] + right[i]) >= reuslt ? (right[i] + left[i]) : reuslt;
			i++;
		}
		return reuslt;
	}
};

//int main() {
//	Solution * s = new Solution();
//	vector<int> tem;
//	int nums[] = { 8, 3, 6, 2, 8, 8, 8, 4, 2, 0,17, 2, 9, 4, 9 };
//	for (int i = 0; i < 15; i++) {
//		tem.push_back(nums[i]);
//	}
//	cout << s->maxProfit(tem) << endl;
//	return 0;
//}
