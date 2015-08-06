/*
 * LeetCode002.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int len = s.length();
    	if(len <= 0) return 0;
    	string subStr;
    	char ch = s[0];
    	int first = 0,max =1, i = 0, index = -1;
    	for(i = 1; i <len; i++)
    	{
    		ch = s[i];
    		subStr = s.substr(first, i - first);
    		index = subStr.find(ch);
    		if(index != -1)
    		{
    			first = first + index+1;
    		}
    		max = (i - first + 1) > max? (i -first + 1):max;
    	}
    	return max;
    	/*另一种方法
    	 * int index[256];
    	memset(index, -1, sizeof(index));*/

    }
};

/*int main()
{
	Solution * s = new Solution();
	string str = "bc";
	cout<<str.substr(1,1)<<endl;
	cout<<s->lengthOfLongestSubstring(str)<<endl;
	return 0;
}*/
