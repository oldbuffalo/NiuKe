#include"packet.h"


/*
搜索二叉树 BST  左子树比根小  右子树比根大
完全二叉树 CBT  	 
对于深度为K的，有n个结点的二叉树
当且仅当其每一个结点都与深度为K的满二叉树中编号从1至n的结点一一对应时称之为完全二叉树

*/

struct Node{
	int nValue;
	Node* pleft;
	Node* pRight;
	Node(int x):nValue(x),pleft(NULL),pRight(NULL){}
};

class IsBSTAndCBT{
public:
	//二叉树中序遍历  依次升序
	bool  IsBST(Node* pTree){
		if(pTree == NULL)
			return false;
		stack<Node*> s;

		Node* pTemp = NULL;
		int Preflag = INT_MIN;
		while(!s.empty() || pTree){
			if(pTree){
				s.push(pTree);
				pTree = pTree->pleft;
			}
			else{
				pTemp = s.top();
				s.pop();
				if(pTemp->nValue > Preflag){  //升序
					pTree = pTemp->pRight;
					Preflag = pTemp->nValue;
				}
				else
					return false;
			}

		}
		return true;
	}


	//二叉树按层遍历
	bool IsCBT(Node* pTree){
		if(pTree == NULL)
			return NULL;

		queue<Node*> q;
		q.push(pTree);

		Node* pTemp = NULL;
		Node* l = NULL;
		Node* r = NULL;
		bool leaf = false;	 //遇到第一个叶子节点 变成true
		while(!q.empty()){
			pTemp = q.front();
			q.pop();
			l = pTemp->pleft;
			r = pTemp->pRight;
			if(l != NULL)
				q.push(l);
			if(r != NULL)
				q.push(r);

			//有右孩子 没有左孩子  不可能是完全二叉树
			//如果有左没右 或者左右都没有  那么接下来的所有节点都必须是叶子节点
			//换言之 如果打开了叶子节点状态  接下来的节点不能有左右孩子
			if( (leaf && (l != NULL || r!= NULL)) || (l == NULL && r!= NULL) )
				return false;
			else if(l == NULL && r == NULL)
				leaf = true;			
		}

		return true;
	}




};


/*
                      5
				3            8
			2      4	  6     10
		1					7  9


*/
//
//int main()
//{
//	Node* phead = new Node(5);
//	phead->pleft = new Node(3);
//	phead->pleft->pleft = new Node(2);
//	phead->pleft->pRight = new Node(4);
//	phead->pleft->pleft->pleft = new Node(1);
//	phead->pRight = new Node(8);
//	phead->pRight->pleft = new Node(6);
//	//phead->pRight->pleft->pRight = new Node(7);
//	phead->pRight->pRight = new Node(10);
//	//phead->pRight->pRight->pleft = new Node(9);
//
//	IsBSTAndCBT test;
//	cout<<test.IsBST(phead)<<endl;
//
//	cout<<test.IsCBT(phead)<<endl;
//
//	getchar();
//
//	return 0;
//}