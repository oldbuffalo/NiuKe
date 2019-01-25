#include"packet.h"

/*
ƽ�������  AVL
���������κ�һ���ڵ�  ���������������ĸ߶Ȳ����1
*/


/*
�ݹ���·
����ֽ�  ������->��������
ȷ��ƽ��������Ҫ�Ѽ�����Ϣ
1.�������Ƿ�ƽ��
2.�������Ƿ�ƽ��
3.�������߶�
4.�������߶� 
*/

struct ChildMsg{
	bool isb;
	int height;
};

struct Node{
	int nValue;
	Node* pleft;
	Node* pRight;
	Node(int x):nValue(x),pleft(NULL),pRight(NULL){}
};
class IsBalanceTree{
public:
	bool Solution(Node* pTree){
		return process(pTree).isb;
	}

	ChildMsg process(Node* pTree){
		ChildMsg cmg = {true,0};
		if(pTree == NULL){
			return cmg;
		}

		ChildMsg leftdata =  process(pTree->pleft);
		ChildMsg rightdata =  process(pTree->pRight);

		if(!leftdata.isb  || !rightdata.isb){
			cmg.isb = false;
			return 	cmg;
		}
		
		if(abs(leftdata.height-rightdata.height) > 1){
			cmg.isb = false;
			return cmg;
		}
		
		cmg.height = max(leftdata.height,rightdata.height)+1; 	//�����Լ��ĸ߶�
		return cmg;

	}

	int max(int a,int b){
		return a>b?a:b;
	}

};

//int main(){
//
//	Node* phead = new Node(1);
//	phead->pleft = new Node(2);
//	phead->pleft->pleft = new Node(3);
//	phead->pleft->pRight = new Node(4);
//
//	IsBalanceTree test;
//	cout<<test.Solution(phead)<<endl;
//
//	Node* phead1 = new Node(1);
//	phead1->pleft = new Node(2);
//	phead1->pRight = new Node(3);
//	cout<<test.Solution(phead1)<<endl;
//
//
//	getchar();
//	return 0;
//}