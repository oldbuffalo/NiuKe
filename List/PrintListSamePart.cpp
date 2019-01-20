#include"packet.h"


/*
打印两个有序链表公共部分   外排    像归并排序中merge的过程
用两个指针
*/
struct Node{
	int nValue;
	Node* pNext;
	Node(int x):nValue(x),pNext(NULL){}
};

 class List{
 public:
	 Node* phead;
	 Node* pend;
	 list<Node*> m_list;
 public:
	 List():phead(NULL),pend(NULL){}
	 ~List(){
		 auto ite =  m_list.begin();
		 while(ite != m_list.end()){
		
			 ite++;
		 }

	 }
	 void Push(int x){
		Node* ptemp = new Node(x);
		m_list.push_back(ptemp);
		//尾插法
		if(NULL == phead){
			phead = ptemp;
		}
		else{
			pend->pNext = ptemp;
		}
		pend = ptemp;
	 }
 };

class PrintListSamePart{
public:
	void Solution(Node* phead1,Node* phead2){
		if(NULL == phead1 || NULL == phead2)
			return;
		while(phead1&&phead2){
			if(phead1->nValue < phead2->nValue){
				phead1 = phead1->pNext;
			}
			else if(phead1->nValue > phead2->nValue){
				phead2 = phead2->pNext;
			}
			else{
				cout<<phead1->nValue<<endl;
				phead1 = phead1->pNext;
				phead2 = phead2->pNext;
			}
		}
	}

};


//int main()
//{
//	List l1,l2;
//	l1.Push(1);
//	l1.Push(3);
//	l1.Push(6);
//	l1.Push(7);
//	l1.Push(10);
//
//	l2.Push(1);
//	l2.Push(2);
//	l2.Push(6);
//	l2.Push(8);
//	l2.Push(10);
//
//	PrintListSamePart test;
//	test.Solution(l1.phead,l2.phead);
//
//
//	getchar();
//	return 0;
//}