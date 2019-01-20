#include"packet.h"


/*
���������������ָ����һ���ڵ��ָ�� 
����һ�����ָ��  ���ָ��һ���ڵ�
*/
struct Node{
	int nValue;
	Node* pNext;
	Node* pRandom;
	Node():pNext(NULL),pRandom(NULL){}
	Node(int x):nValue(x),pNext(NULL),pRandom(NULL){}
};

class CopyListWithRandom{
public:
	//������ϣ��  O(N)�Ŀռ临�Ӷ�
	Node* Solution1(Node* phead){
		if(NULL == phead)
			return NULL;
		map<Node*,Node*> m;   //ԭ�ڵ�;���ڵ��ӳ��

		Node* ptemp = phead;
		while(ptemp){
			m[ptemp] = new Node(ptemp->nValue);
			ptemp = ptemp->pNext;
		}
		
		ptemp = phead;
		while(ptemp){
			m[ptemp]->pNext = m[ptemp->pNext];
			m[ptemp]->pRandom = m[ptemp->pRandom];

			ptemp = ptemp->pNext;
		}
		
		return m[phead];
	}

	//��һ  �����˶���ռ�  ��ν��пռ��ϵ��Ż�
	//��Ҫ������ǽڵ�Ķ�Ӧ����  ��˰�ԭ�ڵ�;���ڵ����ӳ�һ���µ����� Ȼ��һ��ȡ����
	Node* Solution2(Node* phead){
		if(NULL == phead)
			return NULL;
		Node* ptemp = phead;
		Node* pMark = NULL; //������һ���ڵ�
		//�ϳ�һ������
		while(ptemp){
			pMark = ptemp->pNext;
			ptemp->pNext = new Node(ptemp->nValue);
			ptemp->pNext->pNext = pMark; //�µľ���ڵ����һ������
			ptemp = pMark;
		}

		ptemp = phead;
		Node* copyNode = NULL;
		//��������ڵ������
		while(ptemp){
			copyNode = ptemp->pNext;
			copyNode->pRandom = ptemp->pRandom != NULL ? ptemp->pRandom->pNext : NULL;
			ptemp = ptemp->pNext->pNext;
		}
		
		//�������
		ptemp = phead;
		Node* res = ptemp->pNext;

		while(ptemp){
			pMark = ptemp->pNext->pNext;
			copyNode = ptemp->pNext;
			ptemp->pNext = pMark;
			copyNode->pNext = pMark ? pMark->pNext : NULL;
			ptemp = pMark;
		}

		return res;
	}

	
	void TraversalList(Node* phead){
		if(phead == NULL)
			return;
		while(phead){
			cout<<"Curval:"<<phead->nValue<<" ";
			if(phead->pNext)
				cout<<"Nextval:"<<phead->pNext->nValue<<" ";
			else
				cout<<"Nextval:"<<"NULL"<<" ";
			if(phead->pRandom)
				cout<<"Randomval:"<<phead->pRandom->nValue<<endl;
			else
				cout<<"Randomval:"<<"NULL"<<endl;

			phead = phead->pNext;
		}

		cout<<endl;
	}
};


//int main()
//{
//	Node* n1 = new Node(1);
//	Node* n2 = new Node(2);
//	Node* n3 = new Node(3);
//	n1->pNext = n2;
//	n1->pRandom = n3;
//	n2->pNext = n3;
//	n2->pRandom = n1;
//	n3->pNext = NULL;
//	n3->pRandom = NULL;
//
//	Node* phead;
//    CopyListWithRandom	test;
//	phead = test.Solution1(n1);
//	test.TraversalList(phead);
//
//	phead = test.Solution2(n1);
//	test.TraversalList(phead);
//
//	getchar();
//	return 0;
//}