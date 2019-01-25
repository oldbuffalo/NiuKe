#include"packet.h"


struct Node{
	int nValue;
	Node* pLeft;
	Node* pRight;
	Node* pParent;
	Node(int x):nValue(x),pLeft(NULL),pRight(NULL),pParent(NULL){}
};

/*
在二叉树中找一个节点的后继结点

前驱(先驱)结点:中序遍历中当前结点的上一个节点
后继结点:中序遍历中当前结点的下一个节点


最简单的一种方式 用中序遍历的方式遍历一下这颗树
现在需要解决的问题是 访问较少的结点  确定后继结点
*/


/*
寻找后继节点
如果一个节点    
1.有右子树    那么这个节点的后继节点一定是右子树上最左的节点
2.没有右子树  通过该节点的parent指针找到父节点  
              2.1 如果该节点是父节点的左孩子  则父节点是后继节点
			  2.2 如果该节点是父节点的右孩子  则继续往上调整  直到当前结点是父节点的左孩子停止
*/

/*
寻找前驱节点和后继相反
如果有一个节点
1. 有左子树        那么这个节点的前驱节点一定是左子树上最右的节点
2. 没有左子树     通过该节点的parent指针找到父节点  
				  2.1 如果该节点是父节点的右孩子  则父节点是前驱节点
				  2.2 如果该节点是父节点的左孩子  则继续往上调整  直到当前结点是父节点的右孩子停止
*/
class FindSuccessorNode{
public:
	Node* Solution(Node* pTree){
		if(pTree == NULL)
			return NULL;
		if(pTree->pRight){  //有右子树
			Node* ptemp = pTree->pRight;

			while(ptemp->pLeft)
				ptemp = ptemp->pLeft;

			return ptemp;
		}
		else{    //没有右子树
			Node* father = pTree->pParent;
			//if(father == NULL) //根结点  还没有右子树  返回NULL
			//	return NULL;
			while(father != NULL && pTree != father->pLeft){
				pTree = father;
				father = pTree->pParent;
			}

			return father;
		}
	}
	void Print(Node* temp){
		if(temp){
			cout<<temp->nValue<<endl;
		}
		else
			cout<<0<<endl;
	}


};
/*
		  6
	 3		      9
  1	   4	    8	10
   >2	 >5	 7
*/

//  中序  1 2 3 4 5 6 7 8 9 10
//int main()
//{
//	Node* head = new Node(6);
//	head->pParent = NULL;
//	head->pLeft = new Node(3);
//	head->pLeft->pParent = head;
//	head->pLeft->pLeft= new Node(1);
//	head->pLeft->pLeft->pParent = head->pLeft;
//	head->pLeft->pLeft->pRight = new Node(2);
//	head->pLeft->pLeft->pRight->pParent= head->pLeft->pLeft;
//	head->pLeft->pRight = new Node(4);
//	head->pLeft->pRight->pParent =head->pLeft;
//	head->pLeft->pRight->pRight = new Node(5);
//	head->pLeft->pRight->pRight->pParent = head->pLeft->pRight;
//	head->pRight = new Node(9);
//	head->pRight->pParent = head;
//	head->pRight->pLeft = new Node(8);
//	head->pRight->pLeft->pParent = head->pRight;
//	head->pRight->pLeft->pLeft= new Node(7);
//	head->pRight->pLeft->pLeft->pParent = head->pRight->pLeft;
//	head->pRight->pRight= new Node(10);
//	head->pRight->pRight->pParent= head->pRight;
//
//
//	FindSuccessorNode test;
//	Node* t =  head; //后继是7   有右子树	 找右子树最左
//	test.Print(test.Solution(t));
//	t = head->pRight->pLeft;  //后继9  没有右子树 是父节点的左孩子
//	test.Print(test.Solution(t));
//	t = head->pRight->pRight;  //后继NULL  没有右子树 一直往上找不到  
//	test.Print(test.Solution(t));
//	t = head->pLeft->pLeft->pRight;  //后继3  没有右子树 第一次调整不是左孩子
//	test.Print(test.Solution(t));
//
//	
//
//	getchar();
//	return 0;
//	
//}