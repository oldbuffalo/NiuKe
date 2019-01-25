#include"packet.h"

struct Node{
	int nValue;
	Node* pleft;
	Node* pRight;
	Node(int x):nValue(x),pleft(NULL),pRight(NULL){}
};


/*
已知一颗完成二叉树  求节点个数 不通过遍历的方式  也就是要求时间复杂度小于O(N)
*/

/*
1.先遍历到树的左边界  O(logN)  记录层数
2.然后遍历树的右子树的左边界
  2.1如果 树的右子树的左边界到了最后一层  代表左子树是满二叉树   那么左子树个数能求出来
     继续递归右子树
  2.2如果 树的右子树的左边界没到最后一层，也就是倒数第二层  代表右子树是满二叉树 右子树个数能求出来
     继续递归左子树
*/

class CalNodeNum{
public:
	int Solution(Node* pTree){
		if(pTree == NULL)
			return 0;
		return Process(pTree,1,GetTotalLevel(pTree,1));
	}
	int Process(Node* pTree,int curlevel,int totallevel){
		if(curlevel == totallevel)	
			return 1;

		//判断右子树的左边界的位置
		if(GetTotalLevel(pTree->pRight,curlevel+1) == totallevel)	//计算左子树+根
			return 	(1<<(totallevel-curlevel))+
			        Process(pTree->pRight,curlevel+1,totallevel);
		else
		   	return 	(1<<(totallevel-curlevel-1))+
					Process(pTree->pleft,curlevel+1,totallevel);
	}

	int GetTotalLevel(Node* pTree,int curlevel){
		while(pTree){
			curlevel++;
			pTree = pTree->pleft;
		}

		return 	curlevel-1;
	}




};

/*
                      5
				3            8
			2      4	  6     10
		1				

*/

//int main()
//{
//	Node* phead = new Node(5);
//	phead->pleft = new Node(3);
//	phead->pleft->pleft = new Node(2);
//	phead->pleft->pRight = new Node(4);
//	phead->pleft->pleft->pleft = new Node(1);
//	phead->pRight = new Node(8);
//	phead->pRight->pleft = new Node(6);
//	phead->pRight->pRight = new Node(10);
//
//
//	CalNodeNum test;
//	cout<<test.Solution(phead)<<endl;
//
//
//	getchar();
//	return 0;
//}