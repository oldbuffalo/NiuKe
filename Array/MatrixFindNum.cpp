#include"packet.h"

/*
二维数组从左到右 从上到下有序  找数
0 1 2 5
2 3 4 7	      -------->  找7
4 4 4 8 
5 7 7 9

特性  找一个点通过比较能去除一半
*/

class MatrixFindNum{
public:
	bool Solution(vector<vector<int>> v,int num){
		if(v.empty())
			return false;
		//从右上开始找      左下也可以
		int x = 0;
		int y = v[0].size()-1;

		while(x < v.size() && y>=0){
			if(v[x][y] == num)
				return true;
			else if(v[x][y] < num){	   //去除该行
				x++;
			}
			else if(v[x][y] > num){
				y--;
			}
		}

		 return false;
	}

};

int main(){
	
	int a[4][4] = {{0,1,2,5},{2,3,4,7},{4,4,4,8},{5,7,7,9}};

	vector<vector<int>>	 v(4);
	for(int i = 0;i<4;i++){
		v[i].insert(v[i].end(),a[i],a[i]+4);
	}

	MatrixFindNum test;
	cout<<test.Solution(v,7)<<endl;

	getchar();
	return 0;
}