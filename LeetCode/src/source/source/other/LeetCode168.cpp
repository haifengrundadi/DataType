/*
 * LeetCode168.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include<stdint.h>

class Solution {
public:
    string convertToTitle(int n) {
    	string str = "";
    	map<int,char> m;
    	vector<char> v;
    	for(int i = 1; i < 26; i++){
    		m.insert(pair<int,char>(i,'A'+i-1 ));
    	}
    	m.insert(pair<int,char>(0,'Z'));
    	if(n == 26) return "Z";
    	while(n){
    		v.push_back(m.find(n % 26 )->second);
    		n = (n-1) / 26 ;
    	}
    	int i = v.size() -1;
    	while(i >= 0){
    			str += v[i];
    		i--;
    	}
    	return str;
    }
};
//int main(){
//	Solution * s= new Solution();
//	for(int i = 1; i < 100; i++){
//		cout<<i<<"---"<<s->convertToTitle(i)<<endl;
//	}
//	return 0;
//}
