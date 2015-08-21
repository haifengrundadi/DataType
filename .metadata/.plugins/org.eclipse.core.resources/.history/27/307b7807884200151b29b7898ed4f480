/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */
#include "leetcode.h"

class Solution {
public:
	vector<  vector<int>  > generate(int numRows) {
		vector<  vector<int>  > v;
		if( numRows == 0) return v;
		vector<int> v_in;
		v_in.push_back(1);
		v.push_back(v_in);
		vector<int> tem, v_arr;
		for(int i = 2; i <= numRows; i++){
			tem = v.back();
			v_arr.clear();
			v_arr.push_back(1);
			for(int j = 1; j < tem.size(); j++){
				v_arr.push_back(tem[j-1]+tem[j]);
			}
			v_arr.push_back(1);
			v.push_back(v_arr);
		}
		return v;
	 }
};

//int main()
//{
//	Solution * s= new Solution();
//	vector<  vector<int>  > v;
//	 v = s->generate(3);
//	 vector<int> tem;
//	 for(int i = 1; i <= 3; i++){
//	 	tem = v.back();
//	 	v.pop_back();
//	 	vector<int>::iterator it;
//	 	for(it = tem.begin(); it != tem.end(); it++){
//	 		cout<<*it<<"\t";
//	 	}
//	    cout<<endl;
//	 }
//	return 0;
//}
