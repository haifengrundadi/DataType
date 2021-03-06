/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */
#include "leetcode.h"

class Solution {
public:
	bool isValid(string s) {
		vector<char> v;
		for(int i =0; i < s.length(); i++){
			if(s[i] == ')' && ! v.empty()){
				if(v.back() != '(')
					return false;
				else
					v.pop_back();
			}else if(s[i] == '}' && ! v.empty()){
					if(v.back() != '{')
						return false;
					else
						v.pop_back();
			}else if(s[i] == ']' && ! v.empty()){
				if(v.back() != '[')
					return false;
				else
					v.pop_back();
			}else{
				v.push_back(s[i]);
			}
		}
		if(!v.empty())
			return false;
		return true;
	}
};

//int main()
//{
//	Solution * s= new Solution();
//	fstream in;
//		  char buffer[256];
//		  in.open("src/source/source/in.txt",ios::in);
//		  if(in.is_open())
//		  {
//			  while(!in.eof())
//			  {
//				  in.getline(buffer,256);
//				  cout<<s->isValid(buffer)<<endl;
//			  }
//		  }
//	return 0;
//}
