/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int h = 0, len = 0;
		if(C ==A || D ==B ) return (G-E)* (H -F);
		if(E == G || F== H) return (C - A )* (D  -B);
		int total = (C - A )* (D  -B) + (G-E)* (H -F);
		if(E >= C || G <= A || F>= D || H <= B) return total;
		if(E >= A && E <= C ){
			if(G>=C) len = C - E;
			else len = G - E;
		}else if(A >= E && A <=G){
			if(C >= G) len = G - A;
			else len = C - A;
		}
//		cout<<len<<"--len"<<endl;
		if(F >= B && F <= D ){
					if(H>=D) h = D - F;
					else h = H - F;
				}else if(B >= F && B <=H){
					if(D >= H) h = H - B;
					else h = D - B;
				}
//		cout<<h<<"--h"<<endl;
		return total - h * len;
	 }
};

//int main(){
//	Solution * s= new Solution();
//	cout<<s->computeArea(-3,0,3,4,0,-1,9,2)<<endl;
//	cout<<s->computeArea(-2, -2, 2, 2, 3, 3, 4, 4)<<endl;
//	return 0;
//}
