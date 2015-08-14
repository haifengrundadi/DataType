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
    int titleToNumber(string s) {
		int len = s.length();
		if(len <= 0) return 0;
		map<char,int> m;
		int col = 0;
		for(int i = 0; i < 26; i++){
			m.insert(pair<char,int>(('A'+i),i+1));
		}
		int i = 0;
		while(i < len){
			col += m.find(s[i])->second * pow(26, len - i -1);
			i++;
		}
		return col;
	}
};
