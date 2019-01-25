#include"packet.h"


/*
���������� BST  �������ȸ�С  �������ȸ���
��ȫ������ CBT  	 
�������ΪK�ģ���n�����Ķ�����
���ҽ�����ÿһ����㶼�����ΪK�����������б�Ŵ�1��n�Ľ��һһ��Ӧʱ��֮Ϊ��ȫ������

*/

struct Node{
	int nValue;
	Node* pleft;
	Node* pRight;
	Node(int x):nValue(x),pleft(NULL),pRight(NULL){}
};

class IsBSTAndCBT{
public:
	//�������������  ��������
	bool  IsBST(Node* pTree){
		if(pTree == NULL)
			return false;
		stack<Node*> s;

		Node* pTemp = NULL;
		int Preflag = INT_MIN;
		while(!s.empty() || pTree){
			if(pTree){
				s.push(pTree);
				pTree = pTree->pleft;
			}
			else{
				pTemp = s.top();
				s.pop();
				if(pTemp->nValue > Preflag){  //����
					pTree = pTemp->pRight;
					Preflag = pTemp->nValue;
				}
				else
					return false;
			}

		}
		return true;
	}


	//�������������
	bool IsCBT(Node* pTree){
		if(pTree == NULL)
			return NULL;

		queue<Node*> q;
		q.push(pTree);

		Node* pTemp = NULL;
		Node* l = NULL;
		Node* r = NULL;
		bool leaf = false;	 //������һ��Ҷ�ӽڵ� ���true
		while(!q.empty()){
			pTemp = q.front();
			q.pop();
			l = pTemp->pleft;
			r = pTemp->pRight;
			if(l != NULL)
				q.push(l);
			if(r != NULL)
				q.push(r);

			//���Һ��� û������  ����������ȫ������
			//�������û�� �������Ҷ�û��  ��ô�����������нڵ㶼������Ҷ�ӽڵ�
			//����֮ �������Ҷ�ӽڵ�״̬  �������Ľڵ㲻�������Һ���
			if( (leaf && (l != NULL || r!= NULL)) || (l == NULL && r!= NULL) )
				return false;
			else if(l == NULL && r == NULL)
				leaf = true;			
		}

		return true;
	}




};


/*
                      5
				3            8
			2      4	  6     10
		1					7  9


*/
//
//int main()
//{
//	Node* phead = new Node(5);
//	phead->pleft = new Node(3);
//	phead->pleft->pleft = new Node(2);
//	phead->pleft->pRight = new Node(4);
//	phead->pleft->pleft->pleft = new Node(1);
//	phead->pRight = new Node(8);
//	phead->pRight->pleft = new Node(6);
//	//phead->pRight->pleft->pRight = new Node(7);
//	phead->pRight->pRight = new Node(10);
//	//phead->pRight->pRight->pleft = new Node(9);
//
//	IsBSTAndCBT test;
//	cout<<test.IsBST(phead)<<endl;
//
//	cout<<test.IsCBT(phead)<<endl;
//
//	getchar();
//
//	return 0;
//}