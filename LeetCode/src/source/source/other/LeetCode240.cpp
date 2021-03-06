#include "leetcode.h"
#include <sstream>

/*Search a 2D Matrix II */

class Solution {
public:
	bool searchMatrix(vector<vector<int> >& matrix, int target) {
		int m = matrix.size();
		if( m == 0) return false;
		int n = matrix[0].size();
		int i = 0, j = n -1;
		while( i < m && j >=0){
			if(matrix[i][j] < target) i++;
			else if(matrix[i][j] > target) j--;
			else
				return true;
		}
		return false;
	}
};

//int main() {
//	Solution * s = new Solution();
//	vector<vector<int> > matrix;
//	vector<int> v_in;
//	int arr1[] = { -5, 2, 3, 4, 5 };
//	int arr2[] = { 2, 5, 8, 12, 19 };
//	int arr3[] = { 3, 6, 9, 16, 22 };
//	int arr4[] = { 10, 13, 14, 17, 24 };
//	int arr5[] = { 18, 21, 23, 26, 30 };
//	for (int j = 0; j < sizeof(arr1) / sizeof(int); j++) {
//		v_in.push_back(arr1[j]);
//	}
//	matrix.push_back(v_in);
//	v_in.clear();
//	for (int j = 0; j < sizeof(arr2) / sizeof(int); j++) {
//		v_in.push_back(arr2[j]);
//	}
//	matrix.push_back(v_in);
//	v_in.clear();
//	for (int j = 0; j < sizeof(arr3) / sizeof(int); j++) {
//		v_in.push_back(arr3[j]);
//	}
//	matrix.push_back(v_in);
//	v_in.clear();
//	for (int j = 0; j < sizeof(arr4) / sizeof(int); j++) {
//		v_in.push_back(arr4[j]);
//	}
//	matrix.push_back(v_in);
//	v_in.clear();
//	for (int j = 0; j < sizeof(arr5) / sizeof(int); j++) {
//		v_in.push_back(arr5[j]);
//	}
//	matrix.push_back(v_in);
//	cout << s->searchMatrix(matrix, 1) << endl;
//	cout << s->searchMatrix(matrix, -10) << endl;
//	return 0;
//}
