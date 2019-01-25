#include"packet.h"

/*
平衡二叉树  AVL
对于树中任何一个节点  左子树和右子树的高度差不超过1
*/


/*
递归套路
问题分解  整棵树->左右子树
确定平衡条件需要搜集的信息
1.左子树是否平衡
2.右子树是否平衡
3.左子树高度
4.右子树高度 
*/

struct ChildMsg{
	bool isb;
	int height;
};

struct Node{
	int nValue;
	Node* pleft;
	Node* pRight;
	Node(int x):nValue(x),pleft(NULL),pRight(NULL){}
};
class IsBalanceTree{
public:
	bool Solution(Node* pTree){
		return process(pTree).isb;
	}

	ChildMsg process(Node* pTree){
		ChildMsg cmg = {true,0};
		if(pTree == NULL){
			return cmg;
		}

		ChildMsg leftdata =  process(pTree->pleft);
		ChildMsg rightdata =  process(pTree->pRight);

		if(!leftdata.isb  || !rightdata.isb){
			cmg.isb = false;
			return 	cmg;
		}
		
		if(abs(leftdata.height-rightdata.height) > 1){
			cmg.isb = false;
			return cmg;
		}
		
		cmg.height = max(leftdata.height,rightdata.height)+1; 	//返回自己的高度
		return cmg;

	}

	int max(int a,int b){
		return a>b?a:b;
	}

};

//int main(){
//
//	Node* phead = new Node(1);
//	phead->pleft = new Node(2);
//	phead->pleft->pleft = new Node(3);
//	phead->pleft->pRight = new Node(4);
//
//	IsBalanceTree test;
//	cout<<test.Solution(phead)<<endl;
//
//	Node* phead1 = new Node(1);
//	phead1->pleft = new Node(2);
//	phead1->pRight = new Node(3);
//	cout<<test.Solution(phead1)<<endl;
//
//
//	getchar();
//	return 0;
//}