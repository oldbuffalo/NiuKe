#include"packet.h"

/*
岛问题

1 0 1 0 0 0
1 1 1 0 1 0
1 0 0 1 0 1
0 1 1 1 0 1

上下左右相邻的1 构成一个岛  上面的例子中有4个岛


小规模的矩阵可以用感染的思想		深搜


大规模的矩阵(大数据)  用分治拆分矩阵  处理边界条件
*/

class Islands{
public:
	int Solution(vector<vector<int>> v){
		if(v.empty())
			return 0 ;
		int cnt = 0;
		int row = v.size();
		int col = v[0].size();
		for(int i = 0;i<row;i++){
			for(int j = 0;j<col;j++){
				cout<<v[i][j]<<" ";
				if(v[i][j] == 1){
					cnt++;
					Infect(v,i,j,row,col);
				}
			}
			cout<<endl;
		}
		return cnt;
	}

	void Infect(vector<vector<int>> &v,int i,int j,int row,int col){	//是1就感染
		if(i< 0 || i>=row || j<0 || j >= col || v[i][j] != 1)
			return;
		v[i][j] = 2;
		Infect(v,i-1,j,row,col); //上
		Infect(v,i+1,j,row,col); //下
		Infect(v,i,j-1,row,col); //左
		Infect(v,i,j+1,row,col); //右
	}

};


//int main(){
//	
//	int arr[][6] = {
//		{1,0,1,0,0,0},
//		{1,1,1,0,1,0},
//		{1,0,0,1,0,1},
//		{0,1,1,1,0,1}
//	};
//
//	vector<vector<int>> v(4);
//	for(int i = 0;i<4;i++){
//		v[i].insert(v[i].end(),arr[i],arr[i]+6);
//	}
//
//	
//
//	Islands test;
//	cout<<test.Solution(v)<<endl;
//
//
//	getchar();
//	
//	return 0;
//}