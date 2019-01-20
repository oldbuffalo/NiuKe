#include"packet.h"
#include"MyList.h"


/*
��������ĳֵ�������С  �м���� �ұߴ�      ����汾�ĺ�����������
*/
class LeftSmallRightBigList{
public:

	//��һ  ����һ������   �����Ž���������  ��ɺ����������� Ȼ���������
	Node* Solution1(Node* phead,int num){
		if(NULL == phead)
			return NULL;
		int nlen = 0; //����ĳ���
		Node* ptemp = phead;
		while(ptemp){
			nlen++;
			ptemp = ptemp->pNext;
		}
		Node** pNode = new Node*[nlen];	  //�ṹ��ָ������
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
			if(node[index]->nValue < num){ //�����λ�õ�����small+1λ�ý���	 
				Swap(node,index++,++small);	
			}
			else if(node[index]->nValue > num){	  //�����λ�õ�����big-1λ�õ�������	 Ȼ���������������������
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

	//��һ ����ʹ����O(N)�Ķ���ռ� ���ұ�֤�����ȶ��ԣ�������֮���������ԭ���������һ��

	Node* Solution2(Node* phead,int num){
		//׼����������		�ֱ�Ƚ�3�������ͷβ
		Node* sH = NULL; // small head
		Node* sT = NULL; // small tail
		Node* eH = NULL; // equal head
		Node* eT = NULL; // equal tail
		Node* bH = NULL; // big head
		Node* bT = NULL; // big tail
		Node* next = NULL; // ���浱ǰ����������һ���ڵ�

		//��ֳ���������
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


		// С���� �� �������� ����
		if (sT != NULL) {
			sT->pNext = eH;
			eT = eT == NULL ? sT : eT;
		}
		// ����ĺ��� �ʹ����� ����
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