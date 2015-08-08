/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include <stdlib.h>
#include <limits>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x)
	{
		if(x < 0) return 0;
		int len =int( log10(abs(x*1.0))) + 1;
		int flag= -1;
		int m = abs(x*1.0);
		while(len > 0){
			flag = m%10 == m / int(pow(10,len-1)) ? 1:0;
			m = m % int(pow(10,len-1)) / 10;
			if(flag){
				len -= 2;
			}else{
				return false;
			}
		}
		return flag;
	}
};

/*int main()
{
	  Solution * s= new Solution();
	  cout<<abs(-2147447412 * 1.0)<<endl;
	  int x = 2147483647;
	  cout<< (numeric_limits<int>::max)()<<"   "<<(numeric_limits<int>::min)()<<endl;
	  cout<<x<<endl;
	  cout<<s->isPalindrome(4294967295)<<endl;
	   char buffer[256];
	   int num = 0;
		fstream in;
		in.open("src/source/source/other/in.txt",ios::in);
		if(in.is_open())
		{
			 while (!in.eof())
			 {
				in.getline(buffer,256);
				num = atoi(buffer);
				cout<<abs(num*1.0)<<"--len--"<<log10(abs(num*1.0))+1<<"--reverse \t"<<s->isPalindrome(num)<<endl;
			}
		}
	//cout<<s->reverse(11)<<endl;
	return 0;
}
*/
