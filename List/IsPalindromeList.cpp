#include"packet.h"
#include"MyList.h"

/*
判断一个链表是不是回文结构
1->2->1   是
1->2->2->1 是
1->2->3    不是
*/

class IsPalindromeList{
public:
	//法1  将结点压栈  弹出的时候和原链表比较   
	//时间复杂度O(N)    空间复杂度O(N)
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

	//在法一上进行一些优化
	//利用两根指针  快指针一次走两步   慢指针一次走一步
	//这样在快指针走到尾的时候 慢指针走到中间  将慢指针之后的部分压栈 
	//然后将栈的元素和原链表的前一半比较
	//时间复杂度O(N)  空间复杂度O(N/2) 忽略常数的也是O(N)
	bool Solution2(Node* phead){ 
		if(NULL == phead)
			return false;
		Node* pslow = phead;
		Node* pfast = phead;
		/*
		偶数的时候  1->2->2->1	    pslow指向前一个2
		奇数的时候  1->2->2->2->1   pslow指向中间的2
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

	//法三  彻底不用额外的辅助空间
	//还是利用快指针和慢指针  将慢指针指向中间位置
	//然后将慢指针之后的链表反转  1->2->2->1       -------->      1->2<-2<-1
	//从两头向中间进行比较   最后还原链表
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