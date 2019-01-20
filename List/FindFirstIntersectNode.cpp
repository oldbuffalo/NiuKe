#include"packet.h"

struct Node{
	int nValue;
	Node* pNext;
	Node():pNext(NULL){}
	Node(int x):nValue(x),pNext(NULL){}
};

/*
�����������ཻ������		  �ҵ�һ���ཻ�Ľڵ�
1.�жϵ�������û�л�
2.Ѱ�������޻�������ĵ�һ���ཻ�Ľڵ�       ֻ����Y�͵�
3.Ѱ�������л�������ĵ�һ���ཻ�Ľڵ�        �ܹ������ֽṹ 


�ж������Ƿ��л�
����л�   ����һ���뻷�Ľڵ�   �޻�����NULL
*/

class FindFirstIntersectNode{
public:
	Node* Solution(Node* head1,Node* head2){
		if(head1 == NULL || head2 == NULL)
			return NULL;
		Node* loop1 = GetLoop2(head1);
		Node* loop2 = GetLoop2(head2);
		if(loop1 == NULL && loop2 == NULL)	 //�����޻�����
			return noLoop(head1,head2);
		else if(loop1 && loop2)  //�����л�����
			return 	BothLoop(head1,loop1,head2,loop2);
		else
			return NULL;

	}


	//ʹ��set    �ڼ��뼯���� ����������ظ�  ��һ���ظ��ľ��ǵ�һ���뻷�ڵ�
	Node* GetLoop1(Node* phead){
		if(NULL == phead)
			return NULL;
		set<Node*> NodeSet;
		set<Node*>::iterator ite;
		while(phead){	 
			ite = NodeSet.find(phead);
			if(ite == NodeSet.end()) //û���ظ���
				NodeSet.insert(phead);
			else 
				return phead;
			phead = phead->pNext;
		}

		return NULL;
	}

	//����   ׼������ָ��  ��ָ�����ָ��	   ��һ�������� ��һ����һ��
	//����л�  ����ָ��һ��������    ������ߵ�NULL   �����޻�
	//��������ʱ�� ��ָ��ص���ͷ ���һ����һ�� 
	//Ȼ�����ָ��һ�����ڵ�һ���뻷�ڵ�����   --------->����һ������ ����֤��
	Node* GetLoop2(Node* phead){
		if(phead == NULL|| phead->pNext == NULL || phead->pNext->pNext == NULL)
			return NULL;
		Node* pslow = phead->pNext;
		Node* pfast = phead->pNext->pNext;
		while(pslow != pfast){
			if(pfast->pNext == NULL|| pfast->pNext->pNext == NULL)
				return NULL;
			pslow = pslow->pNext;
			pfast = pfast->pNext->pNext;
		}

		//�ߵ��� ����������  Ҳ�ʹ����л�
		pfast = phead;
		while(pslow != pfast){
			pslow =pslow->pNext;
			pfast = pfast->pNext;
		}

		return pslow; 
	}


	//�����޻��ĵ������ཻ����
	//�ܼ򵥵�һ�ַ�ʽ  ��һ������Ľڵ�װ��һ��set  
	//��������һ�������ѯset���Ƿ���  ��һ���ظ��ľ��ǽ��
	//����  
	//1.�ֱ��������������ȡ����ĳ��Ⱥ����һ���ڵ�  len1,end1,len2,end2
	//2.�ж�end1��end2�Ƿ����  
	//�����  �������ཻ
	//������ �Ƚ�len1��len2  �ó��ȳ��������������߳��Ȳ�ֵ�Ĳ��� 
	//Ȼ����һ���ߣ��ߵ���һ����ͬ�Ľڵ���ǽ����
	Node* noLoop(Node* head1,Node* head2){
		if(head1 == NULL  || head2 == NULL)
			return NULL;
		int n = 0;
		Node* end1 = head1;
		Node* end2 = head2;
		while(end1->pNext){
			n++;
			end1 = end1->pNext;
		}

		while(end2->pNext){
			n--;
			end2 = end2->pNext;
		}

		if(end1 != end2)
			return NULL;

		Node* pShort = NULL;
		Node* pLong = NULL;
		pLong = n > 0 ? head1:head2; //n>0��������1������2 ��n
		pShort = pLong == head1 ? head2 : head1;
		n = abs(n);
		while(n){
			n--;
			pLong = pLong->pNext;
		}
		while(pLong != pShort){
			pLong = pLong->pNext;
			pShort = pShort->pNext;
		}

		return pShort;
	}

	//�����л��������
	//�ṹ1  ���Գɻ�  ���ཻ  6 6
	//�ṹ2  ����һ����������һ��ֱ��        Y����һ��o
	//�ṹ3  ����һ������û��ֱ��            һ�����ų�����������
	Node* BothLoop(Node* head1,Node* loop1,Node* head2,Node* loop2){
		if(loop1 == loop2){ //�ṹ2  ��ͬ���޻������ཻ
			int n = 0;
			Node* end1 = head1;
			Node* end2 = head2;
			while(end1 != loop1){
				n++;
				end1 = end1->pNext;
			}

			while(end2 != loop2){
				n--;
				end2 = end2->pNext;
			}
			Node* pShort = NULL;
			Node* pLong = NULL;
			pLong = n > 0 ? head1:head2; //n>0��������1������2 ��n
			pShort = pLong == head1 ? head2 : head1;
			n = abs(n);
			while(n){
				n--;
				pLong = pLong->pNext;
			}
			while(pLong != pShort){
				pLong = pLong->pNext;
				pShort = pShort->pNext;
			}

			return pShort;	
		}
		else{
			Node* ptemp = loop1->pNext;
			while(ptemp != loop1){
				if(ptemp == loop2)
					return ptemp;    //�ṹ3   ����loop1��loop2 ������
				ptemp = ptemp->pNext;
			}
			return NULL;
		}
			

	}

	void Print(Node* ptemp){
		if(ptemp)
			cout<<ptemp->nValue<<endl;
		else
			cout<<"�޻�"<<endl;
	}

};


//int main()
//{
//	// 1-->2-->3-->4-->NULL
//	Node* head1 = new Node(1);
//	head1->pNext = new Node(2);
//	head1->pNext->pNext = new Node(3);
//	head1->pNext->pNext->pNext = new Node(4);
//
//
//	//1-->2-->3-->4-->5-->3
//	Node* head2 = new Node(1);
//	head2->pNext = new Node(2);
//	head2->pNext->pNext = new Node(3);
//	head2->pNext->pNext->pNext = new Node(4);
//	head2->pNext->pNext->pNext->pNext = new Node(5);
//	head2->pNext->pNext->pNext->pNext->pNext = head2->pNext->pNext;
//
//	//5--->6--->3--->4---->NULL  ����3 4�Ǻ�list1���ཻ����
//	Node* head3 = new Node(5);
//	head3->pNext = new Node(6);
//	head3->pNext->pNext = head1->pNext->pNext;
//	head3->pNext->pNext->pNext = head1->pNext->pNext->pNext ;
//
//
//	//7-->8-->3-->4-->5-->3      �ṹ2  	 3���뻷��
//	Node* head4 = new Node(7);
//	head4->pNext = new Node(8);
//	head4->pNext->pNext = head2->pNext->pNext;
//	head4->pNext->pNext->pNext = head2->pNext->pNext->pNext;
//	head4->pNext->pNext->pNext->pNext = head2->pNext->pNext->pNext->pNext;
//	head4->pNext->pNext->pNext->pNext->pNext = head2->pNext->pNext;
//
//
//	//7-->8-->4-->5-->3--->      �ṹ3 	 3 �� 4���뻷��
//	Node* head5 = new Node(9);
//	head5->pNext = new Node(10);
//	head5->pNext->pNext = head2->pNext->pNext->pNext;
//	head5->pNext->pNext->pNext = head2->pNext->pNext->pNext->pNext;
//	head5->pNext->pNext->pNext->pNext = head2->pNext->pNext;
//	head5->pNext->pNext->pNext->pNext->pNext = head2->pNext->pNext->pNext;
//
//
//	FindFirstIntersectNode test;
//	Node* ptemp;
//	ptemp = test.Solution(head1,head3);
//	test.Print(ptemp);
//
//	ptemp = test.Solution(head2,head4);
//	test.Print(ptemp);
//
//	ptemp = test.Solution(head2,head5);
//	test.Print(ptemp);
//
//	getchar();
//	return 0;
//}