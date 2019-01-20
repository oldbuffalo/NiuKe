#include"packet.h"

struct Node{
	int nValue;
	Node* pNext;
	Node(){}
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
		//β�巨
		if(NULL == phead){
			phead = ptemp;
		}
		else{
			pend->pNext = ptemp;
		}
		pend = ptemp;
	 }

	 void  Traversal(){
		Node* ptemp = this->phead;
		while(ptemp){
			cout<<ptemp->nValue<<" ";
			ptemp = ptemp->pNext;
		}
		cout<<endl;
	 }

	 void printLinkedList(Node* ptemp){
		while(ptemp){
			cout<<ptemp->nValue<<" ";
			ptemp = ptemp->pNext;
		}
		cout<<endl;	
	 }
 };