#include"packet.h"

struct Node{
	int nValue;
	Node* pleft;
	Node* pRight;
	Node(int x):nValue(x),pleft(NULL),pRight(NULL){}
};


/*
��֪һ����ɶ�����  ��ڵ���� ��ͨ�������ķ�ʽ  Ҳ����Ҫ��ʱ�临�Ӷ�С��O(N)
*/

/*
1.�ȱ�����������߽�  O(logN)  ��¼����
2.Ȼ�������������������߽�
  2.1��� ��������������߽絽�����һ��  ��������������������   ��ô�����������������
     �����ݹ�������
  2.2��� ��������������߽�û�����һ�㣬Ҳ���ǵ����ڶ���  �������������������� �����������������
     �����ݹ�������
*/

class CalNodeNum{
public:
	int Solution(Node* pTree){
		if(pTree == NULL)
			return 0;
		return Process(pTree,1,GetTotalLevel(pTree,1));
	}
	int Process(Node* pTree,int curlevel,int totallevel){
		if(curlevel == totallevel)	
			return 1;

		//�ж�����������߽��λ��
		if(GetTotalLevel(pTree->pRight,curlevel+1) == totallevel)	//����������+��
			return 	(1<<(totallevel-curlevel))+
			        Process(pTree->pRight,curlevel+1,totallevel);
		else
		   	return 	(1<<(totallevel-curlevel-1))+
					Process(pTree->pleft,curlevel+1,totallevel);
	}

	int GetTotalLevel(Node* pTree,int curlevel){
		while(pTree){
			curlevel++;
			pTree = pTree->pleft;
		}

		return 	curlevel-1;
	}




};

/*
                      5
				3            8
			2      4	  6     10
		1				

*/

//int main()
//{
//	Node* phead = new Node(5);
//	phead->pleft = new Node(3);
//	phead->pleft->pleft = new Node(2);
//	phead->pleft->pRight = new Node(4);
//	phead->pleft->pleft->pleft = new Node(1);
//	phead->pRight = new Node(8);
//	phead->pRight->pleft = new Node(6);
//	phead->pRight->pRight = new Node(10);
//
//
//	CalNodeNum test;
//	cout<<test.Solution(phead)<<endl;
//
//
//	getchar();
//	return 0;
//}