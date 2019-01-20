#include"packet.h"


/*
链表结点除了正常的指向下一个节点的指针 
还有一个随机指针  随机指向一个节点
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
	//借助哈希表  O(N)的空间复杂度
	Node* Solution1(Node* phead){
		if(NULL == phead)
			return NULL;
		map<Node*,Node*> m;   //原节点和镜像节点的映射

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

	//法一  利用了额外空间  这次进行空间上的优化
	//主要解决的是节点的对应问题  因此把原节点和镜像节点连接成一个新的链表 然后一次取两个
	Node* Solution2(Node* phead){
		if(NULL == phead)
			return NULL;
		Node* ptemp = phead;
		Node* pMark = NULL; //保存下一个节点
		//合成一个链表
		while(ptemp){
			pMark = ptemp->pNext;
			ptemp->pNext = new Node(ptemp->nValue);
			ptemp->pNext->pNext = pMark; //新的镜像节点和下一个相连
			ptemp = pMark;
		}

		ptemp = phead;
		Node* copyNode = NULL;
		//设置随机节点的连接
		while(ptemp){
			copyNode = ptemp->pNext;
			copyNode->pRandom = ptemp->pRandom != NULL ? ptemp->pRandom->pNext : NULL;
			ptemp = ptemp->pNext->pNext;
		}
		
		//链表分离
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