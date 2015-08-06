/*
 * LeetCode243.cpp
 *
 *  Created on: 2015年8月1日
 *      Author: juanecho
 */
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        {
        	return false;
        }else{
        	int length = s.size();
        	int map[26] = {0};
        	for(int i = 0; i < length; i++)
        	{
        		map[s[i] - 'a']++;
        		map[t[i] - 'a']--;
        	}
        	for(int i = 0; i < 26; i++)
        	{
        		if(map[i] != 0 )
        			return false;
        	}
        	return true;
        }
    }
};

