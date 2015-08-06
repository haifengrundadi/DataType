/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
	     string subStr = "",result = "";
	     int len = s.length();
	     if(len == 0 || len == 1)return s;
	     int index = -1,first = 0,j =0,k = 0,max = 0;
	     for(int i = 0; i < len; i++)
	     {
	    	 //subStr = s.substr(i,i-first);
	    	 index = s.find_first_of(s[i],i+1);
	    	// cout<<"1---index="<<index<<"\tfirst="<<first<<"\t i="<<i<<"\t"<<s[i]<< endl;
	    	 if(max == 0)
	    	 {
	    		 result = s[0];
	    	 }
			while(index != -1){
				 k = i;
				 j = index;
				// cout<<"k="<<k<<"\tj="<<j<<endl;
				while(k < j){
					if(s[j] == s[k]){
						j--;k++;
					}else {
						break;
					}
			    }
				//cout<<"k="<<k<<"\tj="<<j<<endl;
				if(k >= j){
					//cout<<"max index "<<max<<" "<<index- i + 1<<endl;
					if(max < index - i)
					{
						result = s.substr(i,1+index);
						max = index;
					}
				}
				index = s.find_first_of(s[i],index+1);
				// cout<<"index="<<index<<"max="<<max<<"result="<<result<< endl;
			  }
	    	 first++;
	    	 k = j = 0;
	     }
	     return result;
	}
};

/*int main()
{
	Solution * s= new Solution();
	string sr = "au";
	cout<<sr.find_first_of('a',0)<<endl;
	cout<<sr.find_first_of('a',1)<<endl;
	cout<<s->longestPalindrome(sr)<<endl;
	return 0;
}*/
