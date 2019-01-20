#include"packet.h"
#include"MyList.h"


/*
单向链表按某值划分左边小  中间相等 右边大      链表版本的荷兰国旗问题
*/
class LeftSmallRightBigList{
public:

	//法一  开辟一个数组   将结点放进数组里面  变成荷兰国旗问题 然后重连结点
	Node* Solution1(Node* phead,int num){
		if(NULL == phead)
			return NULL;
		int nlen = 0; //链表的长度
		Node* ptemp = phead;
		while(ptemp){
			nlen++;
			ptemp = ptemp->pNext;
		}
		Node** pNode = new Node*[nlen];	  //结构体指针数组
		ptemp = phead;;
		for(int i = 0;i<nlen;i++){
			pNode[i] = ptemp;
			ptemp = ptemp->pNext;
		}

		arrPartition(pNode,nlen,num);

		int i = 0;
		for(i = 0;i<nlen-1;i++){
			pNode[i]->pNext = pNode[i+1];
		}
		pNode[i]->pNext = NULL;

		phead = pNode[0];
		delete []pNode;
		pNode = NULL;

		return 	phead;
	}

	void arrPartition(Node* node[] ,int nlen,int num){
		if(NULL == node || nlen <= 1)
			return;
		int small = -1;
		int big = nlen;
		int index = 0;
		while(index != big){
			if(node[index]->nValue < num){ //把这个位置的数和small+1位置交换	 
				Swap(node,index++,++small);	
			}
			else if(node[index]->nValue > num){	  //把这个位置的数和big-1位置的数交换	 然后继续调整交换过来的数
				Swap(node,index,--big);				
			}
			else
				index++;
		}
	}

	void Swap(Node* node[],int a,int b){
		if(a == b)
			return;
		int temp = node[a]->nValue;
		node[a]->nValue = node[b]->nValue;
		node[b]->nValue = temp;
	}

	//法一 不仅使用了O(N)的额外空间 而且保证不了稳定性，即调整之后的链表与原链表结点次序一样

	Node* Solution2(Node* phead,int num){
		//准备六个变量		分别比较3个链表的头尾
		Node* sH = NULL; // small head
		Node* sT = NULL; // small tail
		Node* eH = NULL; // equal head
		Node* eT = NULL; // equal tail
		Node* bH = NULL; // big head
		Node* bT = NULL; // big tail
		Node* next = NULL; // 保存当前遍历结点的下一个节点

		//拆分成三个链表
		while(phead){
			next = phead->pNext;
			phead->pNext = NULL;
			if(phead->nValue < num)
				ConnectNode(sH,sT,phead);
			else if(phead->nValue == num)
				ConnectNode(eH,eT,phead);	
			else
				ConnectNode(bH,bT,phead);
			phead = next;
		}


		// 小链表 和 等于链表 连接
		if (sT != NULL) {
			sT->pNext = eH;
			eT = eT == NULL ? sT : eT;
		}
		// 上面的合体 和大连接 连接
		if (eT != NULL) {
			eT->pNext = bH;
		}
		
		return 	sH!=NULL ? sH :	eH != NULL ? eH :bH;
	}

	void ConnectNode(Node* &head,Node* &tail,Node* &temp){
		if(NULL == head)
			head =	temp;
		else
			tail->pNext = temp;
		tail = temp;
	}

	
};

//int main(){
//	
//
//	List l1;
//	for(int i = 10;i>=0;i--)
//		l1.Push(i);
//	List l2;
//	l2.Push(1);	l2.Push(2);l2.Push(2);l2.Push(1);l2.Push(3);l2.Push(3);
//	LeftSmallRightBigList test;
//	Node* phead = test.Solution1(l1.phead,5);
//	//Node* phead = test.Solution2(l1.phead,5);
//	l1.printLinkedList(phead);
//	phead = test.Solution1(l2.phead,2);
//	//phead = test.Solution2(l2.phead,2);
//	l2.printLinkedList(phead);
//
//
//
//
//	getchar();
//	return 0;
//}								   