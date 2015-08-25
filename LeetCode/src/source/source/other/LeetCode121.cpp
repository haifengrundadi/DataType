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
		if (size <= 1)
			return 0;
		int min = prices[0], minIndex = 0;
		int max = 0, maxBegin = 0, maxEnd = 0;
		int i = 1;
		while (i < size) {
			if (prices[i] - min >= max) {
				maxBegin = minIndex;
				max = prices[i] - min;
				maxEnd = i;
			}
			if (prices[i] <= min) {
				min = prices[i];
				minIndex = i;
			}
			i++;
		}
		return max;
	}
};

//int main() {
//	Solution * s = new Solution();
//	vector<int> tem;
//	tem.push_back(9);
//	tem.push_back(18);
//	tem.push_back(7);
//	tem.push_back(17);
//	tem.push_back(5);
//	tem.push_back(6);
//	tem.push_back(9);
//	tem.push_back(10);
//	tem.push_back(18);
//	tem.push_back(1);
//	cout << s->maxProfit(tem) << endl;
//	return 0;
//}
