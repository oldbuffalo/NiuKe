#include"packet.h"

/*之字型打印  
 1  2  3  4
 5  6  7  8	   ------------>  1 2 5 9 6 3 4 7 10 11 8 12
 9  10 11 12
*/

class ZigZagPrintMatrix{
public:
	void Solution(vector<vector<int>> &v){
		if(v.empty())
			return;
		//标记对角线的两头	x1,y1标记对角线右上角
		int x1 = 0;	 //x1,y1 先朝右走  走到底再往下
		int y1 = 0;
		int x2 = 0;	 //x2,y2 先朝下走  走到底再往右
		int y2 = 0;
		bool flag = false;

		while(x1 != v.size()){   //代表x1走到右下角 退出循环
			PrintDigLine(v,x1,y1,x2,y2,flag);
			x1 = y1 == v[0].size()-1 ? x1+1:x1;	 //要在y1改变之前判断
			y1 = y1 == v[0].size()-1 ? y1 :y1+1; 
			y2 = x2 == v.size()-1 ? y2+1:y2;  //要在x2改变之前判断
			x2 = x2 == v.size()-1 ? x2 : x2+1;
			
			flag = !flag;
		}

	}
	 
	void PrintDigLine(vector<vector<int>> &v,int x1,int y1,int x2,int y2,bool flag){
		if(flag){ //从右上到左下
			for(;x1<=x2 && y1>=y2;x1++,y1--){
				cout<<v[x1][y1]<<" ";
			}
		}
		else{
			for(;x2>=x1 && y2<=y1;x2--,y2++){
				cout<<v[x2][y2]<<" ";
			}
		}
	}
};


int main(){
	int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	vector<vector<int>> v(3);

	for(int i = 0;i<3;i++){
		v[i].insert(v[i].end(),a[i],a[i]+4);
	}
	ZigZagPrintMatrix test;
	test.Solution(v);

	getchar();
	return 0;
}