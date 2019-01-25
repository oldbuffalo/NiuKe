#include"packet.h"

/*
二叉树的先序 中序 后序遍历
分成递归和非递归
*/


/*
        5
	3        8
  2  4	   7     10
1		 6>    9>   <11
*/

/*
先序  5 3 2 1 4 8 7 6 10 9 11
中序  1 2 3 4 5 6 7 8 9 10 11
后序  1 2 4 3 6 7 9 11 10 8 5
*/
struct Node
{
	int nValue;
	Node* pleft;
	Node* pRight;
	Node(int x):nValue(x),pleft(NULL),pRight(NULL){}
};

class TraversalTree{
public:
	/*
	递归法遍历  本质上访问节点的次序是一样的   并且每个结点都访问了三次
	第一次访问到该节点就打印   -------先序
	第二次访问到该节点就打印   -------中序
	第三次访问到该节点就打印   -------后序
	*/
	void PreOrderRecur(Node* pTree){
		if(pTree){
			cout<<pTree->nValue<<" ";
			PreOrderRecur(pTree->pleft);
			PreOrderRecur(pTree->pRight);
		}
	}
	void InOrderRecur(Node* pTree){
		if(pTree){
			InOrderRecur(pTree->pleft);
			cout<<pTree->nValue<<" ";
			InOrderRecur(pTree->pRight);
		}
	}
	void PosOrderRecur(Node* pTree){
		if(pTree){
			PosOrderRecur(pTree->pleft);
			PosOrderRecur(pTree->pRight);
			cout<<pTree->nValue<<" ";
		}
	}



	void PreOrderUnRecur(Node* pTree){
		if(pTree == NULL)
			return;
		cout<<"PreOrderUnRecur:";
		stack<Node*> s;
		s.push(pTree);

		Node* ptemp = NULL;
		while(!s.empty()){
			
			//弹出打印
			ptemp = s.top();
			cout<<ptemp->nValue<<" ";
			s.pop();

			//右子树先进栈
			if(ptemp->pRight)
				s.push(ptemp->pRight);
			if(ptemp->pleft)
				s.push(ptemp->pleft);
		}
		cout<<endl;
	}

	void InOrderUnRecur(Node* pTree){
		if(pTree == NULL)
			return;
		cout<<"InOrderUnRecur:";
		stack<Node*> s;
		while(!s.empty()|| pTree){
			if(pTree){	  //一直向左压栈 
				s.push(pTree);
				pTree = pTree->pleft;
			}
			else{
				//弹出打印  向右走
				cout<<s.top()->nValue<<" ";
				pTree = s.top()->pRight;
				s.pop();
			}
		}

		cout<<endl;
	}


	//比较简单的方式借助两个栈	  后序是左右根   逆序过来就是根右左   和先序相比就是左右顺序颠倒了
	void PosOrderUnRecur1(Node* pTree){
		if(pTree == NULL)
			return;
		cout<<"PosOrderUnRecur:";
		stack<Node*>  s1;
		stack<Node*>  s2;
		Node* ptemp = NULL;
		s1.push(pTree);
		while(!s1.empty()){
			ptemp = s1.top();
			s1.pop();
			s2.push(ptemp);
			//左子树先进栈
			if(ptemp->pleft)
				s1.push(ptemp->pleft);
			if(ptemp->pRight)
				s1.push(ptemp->pRight);	
		}

		while(!s2.empty()){
			cout<<s2.top()->nValue<<" ";
			s2.pop();
		}
		
		cout<<endl;
	}

	//只借助一个栈
	void PosOrderUnRecur2(Node* pTree){
		if(pTree == NULL)
			return;
		cout<<"PosOrderUnRecur:";
		stack<Node*> s;

		Node* ptemp = NULL;
		Node* pMark = NULL;		  //标记处理过的节点
		while(!s.empty()|| pTree){
			if(pTree){
				s.push(pTree);
				pTree = pTree->pleft;
			}
			else{
				ptemp = s.top();

				if(ptemp->pRight  == NULL || ptemp->pRight == pMark){
					//当前节点没有右子树 或者右子树已经处理过了
					//弹出打印
					s.pop();
					pMark = ptemp;
					cout<<ptemp->nValue<<" ";
				}
				else{
					pTree = ptemp->pRight;	
				}
			}
		}
	}
};

//int  main(){
//	Node* head = new Node(5);
//	head->pleft = new Node(3);
//	head->pRight = new Node(8);
//	head->pleft->pleft = new Node(2);
//	head->pleft->pRight = new Node(4);
//	head->pleft->pleft->pleft = new Node(1);
//	head->pRight->pleft = new Node(7);
//	head->pRight->pleft->pleft = new Node(6);
//	head->pRight->pRight = new Node(10);
//	head->pRight->pRight->pleft = new Node(9);
//	head->pRight->pRight->pRight = new Node(11);
//
//
//	TraversalTree test;
//	cout<<"PreOrderRecur:";
//	test.PreOrderRecur(head);
//	cout<<endl;
//	cout<<"InOrderRecur:";
//	test.InOrderRecur(head);
//	cout<<endl;
//	cout<<"PosOrderRecur:";
//	test.PosOrderRecur(head);
//	cout<<endl;
//	test.PreOrderUnRecur(head);
//	test.InOrderUnRecur(head);
//	test.PosOrderUnRecur1(head);
//	test.PosOrderUnRecur2(head);
//
//
//	getchar();
//	return 0;
//
//}