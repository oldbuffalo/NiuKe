#include"packet.h"
#include"MyList.h"

/*
�ж�һ�������ǲ��ǻ��Ľṹ
1->2->1   ��
1->2->2->1 ��
1->2->3    ����
*/

class IsPalindromeList{
public:
	//��1  �����ѹջ  ������ʱ���ԭ����Ƚ�   
	//ʱ�临�Ӷ�O(N)    �ռ临�Ӷ�O(N)
	bool Solution1(Node* phead){
		if(NULL == phead)
			return false;
		stack<Node*> s;
		Node* pMark = phead;
		while(pMark){
			s.push(pMark);
			pMark = pMark->pNext;
		}

		while(!s.empty() && phead){
			if(phead->nValue != s.top()->nValue)
				  return false;
			phead = phead->pNext;
			s.pop();		
		}
		
		return true;
	}

	//�ڷ�һ�Ͻ���һЩ�Ż�
	//��������ָ��  ��ָ��һ��������   ��ָ��һ����һ��
	//�����ڿ�ָ���ߵ�β��ʱ�� ��ָ���ߵ��м�  ����ָ��֮��Ĳ���ѹջ 
	//Ȼ��ջ��Ԫ�غ�ԭ�����ǰһ��Ƚ�
	//ʱ�临�Ӷ�O(N)  �ռ临�Ӷ�O(N/2) ���Գ�����Ҳ��O(N)
	bool Solution2(Node* phead){ 
		if(NULL == phead)
			return false;
		Node* pslow = phead;
		Node* pfast = phead;
		/*
		ż����ʱ��  1->2->2->1	    pslowָ��ǰһ��2
		������ʱ��  1->2->2->2->1   pslowָ���м��2
		*/
		while(pfast->pNext && pfast->pNext->pNext){
			pslow = pslow->pNext;
			pfast = pfast->pNext->pNext;
		}
		Node* pMark = pslow->pNext;
		stack<Node*> s;
		while(pMark){
			s.push(pMark);
			pMark = pMark->pNext;
		}

		while(!s.empty() && phead){
			if(s.top()->nValue != phead->nValue)
				  return false;
			phead = phead->pNext;
			s.pop();	
		}

		return true;
	}

	//����  ���ײ��ö���ĸ����ռ�
	//�������ÿ�ָ�����ָ��  ����ָ��ָ���м�λ��
	//Ȼ����ָ��֮�������ת  1->2->2->1       -------->      1->2<-2<-1
	//����ͷ���м���бȽ�   ���ԭ����
	bool Solution3(Node* phead){
		if(NULL == phead)
			return false;
		Node* pslow = phead;
		Node* pfast = phead;
		while(pfast->pNext && pfast->pNext->pNext){
			pslow = pslow->pNext;
			pfast = pfast->pNext->pNext;
		}
		Node* pNewHead = ReverseList(pslow);
		Node* pMark = pNewHead;
		while(phead && pNewHead){
			if(phead->nValue != pNewHead->nValue)
				return false;
			phead =phead->pNext;
			pNewHead = pNewHead->pNext;
		}

		ReverseList(pMark);

		return true;
	}

	Node* ReverseList(Node* start){
		if(NULL == start)
			return NULL;
		Node* p1 = NULL;
		Node* p2 = start;
		Node* p3 = start->pNext;
		while(p2){
			p2->pNext = p1;
			p1 = p2;
			p2 = p3;
			if(p3)
				p3 = p3->pNext;
		}

		return p1;
	}
};


//int main()
//{
//	List l1;
//	l1.Push(1);l1.Push(2);l1.Push(1);l1.Push(2);l1.Push(1);
//	List l2;
//	l2.Push(1);l2.Push(2);l2.Push(2);l2.Push(1);
//	List l3;
//	l3.Push(1);l3.Push(2);l3.Push(3);
//	IsPalindromeList test;
//	cout<<test.Solution1(l1.phead)<<" "<<test.Solution1(l1.phead)<<" "<<test.Solution1(l3.phead)<<endl;
//	cout<<test.Solution2(l1.phead)<<" "<<test.Solution2(l2.phead)<<" "<<test.Solution2(l3.phead)<<endl;
//	cout<<test.Solution3(l1.phead)<<" "<<test.Solution3(l2.phead)<<" "<<test.Solution3(l3.phead)<<endl;
//	getchar();
//	return 0;
//}