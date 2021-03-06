/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"

class Solution {
public:
	 string convert(string s, int numRows) {
	  string str1 = "";
	  vector<vector<char> > v;
	  vector<char> v_in;
	  for(int i = 0; i < numRows; i++){
		  v.push_back(v_in);
	  }
	  int len = s.length();
	  int i = 0, d = 1, k = 0,m = 0;
	  m = numRows * 2 -2;
	  if(len == 0 || numRows <= 1) return s;
	  while(i < len){
		  while(d == 1 && i < len && k <numRows){
			  v[i%m].push_back(s[i]);
			  k++;
			  i++;
		  }
		  while(d == 0 && i < len && k < numRows - 2){
			  v[numRows - k -2].push_back(s[i]);
			  i++;
			  k++;
		  }
		  d = d == 1?0:1;
		  k = 0;
	  }
	  vector<char>::iterator it;
	  for(int i = 0 ; i < numRows; i++){
		  for(it = v[i].begin(); it!=v[i].end();it++){
			  str1+=*it;
		  }
	  }
	  return str1;
  }
};

//int main()
//{
//	Solution * s= new Solution();
//	string str = "PAYPALISHIRING";
//	cout<<s->convert(str, 3);
//	return 0;
//}
