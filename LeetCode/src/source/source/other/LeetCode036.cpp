/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"

class Solution {
public:
	bool isValidSudoku(vector<vector<char> >& board) {
		map<char, char> m;
		for (int i = 0; i < 9; i++) {
			m.clear();
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
				} else if (m.find(board[i][j]) == m.end()) {
					m.insert(pair<char, char>(board[i][j],board[i][j]));
				} else
					return false;
			}
		}
		m.clear();
		for (int j = 0; j < 9; j++) {
			m.clear();
			for (int i = 0; i < 9; i++) {
				if (board[i][j] == '.') {
				} else if (m.find(board[i][j]) == m.end()) {
					m.insert(pair<char, char>(board[i][j],board[i][j]));
				} else
					return false;
			}
		}
		m.clear();
		int k = 0,n = 0;
		while(n <= 6){
				while(k <= 6){
					m.clear();
					for (int i = 0+k; i < 3+k; i++) {
						for (int j = 0+n; j < 3+n; j++) {
							if (board[i][j] == '.') {
							} else if (m.find(board[i][j]) == m.end()) {
								m.insert(pair<char, char>(board[i][j],board[i][j]));
							} else
								return false;
						}
					}
					k += 3;
				}
				k = 0;
				n+=3;
		}
		return true;
	}
};

