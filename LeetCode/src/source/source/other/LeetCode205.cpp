/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include<stdint.h>
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		bool flag1 = true;
		int len = s.length();
		map<int,int> m;
		map<int,int> m1;
		for(int i = 0; i < len; i++){
			if(m.find(s[i]) == m.end() && m1.find(t[i]) == m1.end()){
				m.insert(pair<int,int>(s[i],t[i]));
				m1.insert(pair<int,int>(t[i],s[i]));
			}else{
				if(m.find(s[i])->second != t[i] || m1.find(t[i])->second != s[i]){
					return false;
				}
			}
		}
		return flag1;
	 }
};
//
//int main(){
//	Solution * s= new Solution();
//	cout<<s->isIsomorphic("bar","foo");
//	return 0;
//}
