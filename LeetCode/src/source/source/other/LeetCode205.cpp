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
		bool flag = true;
		int len = s.length();
		map<int,int> m;
		for(int i = 0; i < len; i++){
			if(m.find(s[i]) == m.end() && m.find(t[i]) == m.end() ){
				m.insert(pair<int,int>(s[i],t[i]));
				cout<<s[i]<<"---"<<t[i]<<endl;
			}else{
				if(m.find(s[i])->second != t[i]){
					return false;
				}
			}
		}
		return flag;
	 }
};

int main(){
	Solution * s= new Solution();
	cout<<s->isIsomorphic("paper","title");
	return 0;
}
