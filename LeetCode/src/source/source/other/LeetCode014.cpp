/*
 * LeetCode0013.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = strs.size();
		if(len == 0) return "";
		string str = strs[0];
		int strLen = strs[0].length();
//		for(int i = 0; i<len;i++){
//			if(strLen <= strs[i].length()){
//				str = strs[i];
//				strLen = strs[i].length();
//			}
//		}
//		strLen = strs[0].length();
		for(int i = 0; i<len;i++){
			for(int j = 0; j < strLen; j++){
				if(strs[i][j] != str[j]){
					strLen = j;
					str = strs[i].substr(0,j);
					break;
				}
			}
		}
		return str;
	 }
};

//int main()
//{
//	Solution * s = new Solution();
//	vector<string> strs;
//	fstream in;
//	  char buffer[256];
//	  in.open("src/source/source/other/in.txt",ios::in);
//	 	  if(in.is_open())
//	 	  {
//	 		  while(!in.eof())
//	 		  {
//	 			  in.getline(buffer,256);
//	 			  strs.push_back(buffer);
//	 		  }
//	 	  }
//	 	  cout<<s->longestCommonPrefix(strs)<<endl;
//	return 0;
//}
