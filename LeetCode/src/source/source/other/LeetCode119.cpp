/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */
#include "leetcode.h"

class Solution {
public:
//	vector<int> getRow(int rowIndex) {
//
//	    }
	vector<int> generate(int numRows) {
		vector<int> tem;
		tem.push_back(1);
		if( numRows == 0) return tem;
		int k = 0,x =0;
		for(int i = 1; i <= numRows; i++){
			k = tem[0];
			for(int j = 1; j < i;j++){
				x= tem[j];
				tem[j] = k+tem[j];
				k = x;
			}
			tem.push_back(1);
		}
		return tem;
	 }
};

//int main()
//{
//	Solution * s= new Solution();
//	vector<int> tem;
//	tem = s->generate(2);
//	vector<int>::iterator it;
//				for(it = tem.begin(); it != tem.end(); it++){
//					 cout<<*it<<"\t";
//				}
//				cout<<endl;
//	return 0;
//}
