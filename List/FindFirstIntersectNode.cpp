#include"packet.h"

struct Node{
	int nValue;
	Node* pNext;
	Node():pNext(NULL){}
	Node(int x):nValue(x),pNext(NULL){}
};

/*
两个单链表相交的问题		  找第一个相交的节点
1.判断单链表有没有环
2.寻找两个无环单链表的第一个相交的节点       只能是Y型的
3.寻找两个有环单链表的第一个相交的节点        总共有三种结构 


判断链表是否有环
如果有环   返回一个入环的节点   无环返回NULL
*/

class FindFirstIntersectNode{
public:
	Node* Solution(Node* head1,Node* head2){
		if(head1 == NULL || head2 == NULL)
			return NULL;
		Node* loop1 = GetLoop2(head1);
		Node* loop2 = GetLoop2(head2);
		if(loop1 == NULL && loop2 == NULL)	 //两个无环链表
			return noLoop(head1,head2);
		else if(loop1 && loop2)  //两个有环链表
			return 	BothLoop(head1,loop1,head2,loop2);
		else
			return NULL;

	}


	//使用set    在加入集合中 如果发现有重复  第一个重复的就是第一个入环节点
	Node* GetLoop1(Node* phead){
		if(NULL == phead)
			return NULL;
		set<Node*> NodeSet;
		set<Node*>::iterator ite;
		while(phead){	 
			ite = NodeSet.find(phead);
			if(ite == NodeSet.end()) //没有重复的
				NodeSet.insert(phead);
			else 
				return phead;
			phead = phead->pNext;
		}

		return NULL;
	}

	//法二   准备两个指针  快指针和慢指针	   快一次走两步 慢一次走一步
	//如果有环  快慢指针一定会相遇    如果快走到NULL   代表无环
	//在相遇的时刻 快指针回到开头 变成一次走一步 
	//然后快慢指针一定会在第一个入环节点相遇   --------->这是一个结论 可以证明
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

		//走到这 代表能相遇  也就代表有环
		pfast = phead;
		while(pslow != pfast){
			pslow =pslow->pNext;
			pfast = pfast->pNext;
		}

		return pslow; 
	}


	//两个无环的单链表相交问题
	//很简单的一种方式  把一个链表的节点装进一个set  
	//遍历另外一个链表查询set中是否有  第一个重复的就是结果
	//法二  
	//1.分别遍历两个链表，获取链表的长度和最后一个节点  len1,end1,len2,end2
	//2.判断end1和end2是否相等  
	//不相等  不可能相交
	//如果相等 比较len1和len2  让长度长的链表先走两者长度差值的步数 
	//然后再一起走，走到第一个相同的节点就是结果。
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
		pLong = n > 0 ? head1:head2; //n>0代表链表1比链表2 长n
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

	//两个有环链表相加
	//结构1  各自成环  不相交  6 6
	//结构2  共享一个环，但有一条直线        Y下面一个o
	//结构3  共享一个环，没有直线            一个环放出来两根天线
	Node* BothLoop(Node* head1,Node* loop1,Node* head2,Node* loop2){
		if(loop1 == loop2){ //结构2  等同于无环链表相交
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
			pLong = n > 0 ? head1:head2; //n>0代表链表1比链表2 长n
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
					return ptemp;    //结构3   返回loop1和loop2 都可以
				ptemp = ptemp->pNext;
			}
			return NULL;
		}
			

	}

	void Print(Node* ptemp){
		if(ptemp)
			cout<<ptemp->nValue<<endl;
		else
			cout<<"无环"<<endl;
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
//	//5--->6--->3--->4---->NULL  其中3 4是和list1的相交部分
//	Node* head3 = new Node(5);
//	head3->pNext = new Node(6);
//	head3->pNext->pNext = head1->pNext->pNext;
//	head3->pNext->pNext->pNext = head1->pNext->pNext->pNext ;
//
//
//	//7-->8-->3-->4-->5-->3      结构2  	 3个入环点
//	Node* head4 = new Node(7);
//	head4->pNext = new Node(8);
//	head4->pNext->pNext = head2->pNext->pNext;
//	head4->pNext->pNext->pNext = head2->pNext->pNext->pNext;
//	head4->pNext->pNext->pNext->pNext = head2->pNext->pNext->pNext->pNext;
//	head4->pNext->pNext->pNext->pNext->pNext = head2->pNext->pNext;
//
//
//	//7-->8-->4-->5-->3--->      结构3 	 3 和 4是入环点
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