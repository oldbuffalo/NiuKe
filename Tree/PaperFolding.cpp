#include"packet.h"

/*
折纸问题 实质一个满二叉树的问题
             下
		 上      下
	   上  下  上  下 

	   打印顺序是 右 中 左
*/

class PaperFolding{

public:
	void Solution(int n){
		Print(n,"down");
	}

	void Print(int n,string str){
		if(n == 0)
			return;
		Print(n-1,"down");
		cout<<str<<" ";
		Print(n-1,"up");
	}

};

int main()
{
	PaperFolding test;
	test.Solution(3);


	getchar();
	return 0;
}