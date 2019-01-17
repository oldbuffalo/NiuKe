#include"packet.h"

/*将一个正方形旋转90度*/
/*分圈结构  从外圈开始旋转 从外向里*/
/*
1 2 3			  7 4 1
4 5 6   --------> 8 5 2
7 8 9			  9 6 3
*/

class RotateMatrix{
public:
	void Solution(vector<vector<int>> &v){
		if(v.size() != v[0].size() || v.size() <= 1)
			return;
		int x1 = 0;
		int y1 = 0;
		int x2 = v.size()-1;
		int y2 = v[0].size()-1;

		while(x1 <= x2 && y1 <= y2){
			RotateEdge(v,x1++,y1++,x2--,y2--);	
		}
	}

	void RotateEdge(vector<vector<int>> &v,int x1,int y1,int x2,int y2){
		/*抓住某个点的变换构成 进行数值交换*/
		int times = x2-x1; //整个边框旋转的次数
		int tmp = 0;
		for(int i = 0;i<times;i++){
			tmp = v[x1][y1+i];
			v[x1][y1+i] = v[x2-i][y1];
			v[x2-i][y1] = v[x2][y2-i];
			v[x2][y2-i] = v[x1+i][y2];
			v[x1+i][y2] = tmp;
		}
	}

	void PrintMatrix(vector<vector<int>> &v){
		for(int i = 0;i<v.size();i++){
			for(int j = 0;j<v[0].size();j++)
				cout<<v[i][j]<<" ";
			cout<<endl;
		}

	}

};

//int main()
//{
//	int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//	vector<vector<int>>	v(3);
//
//	for(int i = 0;i<3;i++){
//		v[i].insert(v[i].end(),a[i],a[i]+3);
//	}
//	
//	RotateMatrix test;
//	test.PrintMatrix(v);
//	test.Solution(v);
//	test.PrintMatrix(v);
//	
//	getchar();
//
//	return 0;
//}