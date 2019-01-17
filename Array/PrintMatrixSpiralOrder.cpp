#include"packet.h"

/*תȦ��ӡ����
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16  

��ӡ���Ϊ1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

class PrintMatrixSpiralOrder{

public:
	void Solution(vector<vector<int>> &v){
		if(v.empty())
			return; 
		//������Ϻ����µ�����
		int x1 = 0;
		int y1 = 0;
		int x2 =  v.size()-1;
		int y2 = v[0].size()-1;

		while(x1<=x2 && y1 <=y2){
			//ÿ�δ�ӡ������ı߿� ���Ͻǵĵ㳯�����ƶ�  ���µĵ㳯�����ƶ�
			PrintEdge(v,x1++,y1++,x2--,y2--);
		}
	}

	void PrintEdge(vector<vector<int>> &v,int x1,int y1,int x2,int y2){
		if(x1 == x2){
			for(int i = y1;i<=y2;i++){
				cout<<v[x1][i]<<" ";
			}
		}
		else if(y1 == y2){
			for(int i = x1;i<=x2;i++){
				cout<<v[i][y1]<<" ";
			}
		}
		else{
			int CurRow = x1;
			int CurCol = y1;

			/*ע�����ظ���ӡ������*/
			while(CurCol != y2){
				cout<<v[CurRow][CurCol++]<<" ";		
			}

			while(CurRow != x2){
				cout<<v[CurRow++][CurCol]<<" ";
			}

			while(CurCol != y1){
				cout<<v[CurRow][CurCol--]<<" ";		
			}

			while(CurRow != x1){
				cout<<v[CurRow--][CurCol]<<" ";		
			}

		}
	
	}

};


//int main()
//{
//	
//	int a[4][4];
//	for(int i = 0;i<4;i++){
//		for(int j = 0;j<4;j++){
//			a[i][j] = i*4+j+1;  //��ֵ1-16
//		}
//	} 
//	vector<vector<int>> v(4);
//	for(int i = 0;i<4;i++){
//		v[i].insert(v[i].end(),a[i],a[i]+4);
//	}
//	PrintMatrixSpiralOrder	test;
//	test.Solution(v);
//
//	getchar();
//	return 0;
//}