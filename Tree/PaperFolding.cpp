#include"packet.h"

/*
��ֽ���� ʵ��һ����������������
             ��
		 ��      ��
	   ��  ��  ��  �� 

	   ��ӡ˳���� �� �� ��
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