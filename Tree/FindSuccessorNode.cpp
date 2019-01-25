#include"packet.h"


struct Node{
	int nValue;
	Node* pLeft;
	Node* pRight;
	Node* pParent;
	Node(int x):nValue(x),pLeft(NULL),pRight(NULL),pParent(NULL){}
};

/*
�ڶ���������һ���ڵ�ĺ�̽��

ǰ��(����)���:��������е�ǰ������һ���ڵ�
��̽��:��������е�ǰ������һ���ڵ�


��򵥵�һ�ַ�ʽ ����������ķ�ʽ����һ�������
������Ҫ����������� ���ʽ��ٵĽ��  ȷ����̽��
*/


/*
Ѱ�Һ�̽ڵ�
���һ���ڵ�    
1.��������    ��ô����ڵ�ĺ�̽ڵ�һ����������������Ľڵ�
2.û��������  ͨ���ýڵ��parentָ���ҵ����ڵ�  
              2.1 ����ýڵ��Ǹ��ڵ������  �򸸽ڵ��Ǻ�̽ڵ�
			  2.2 ����ýڵ��Ǹ��ڵ���Һ���  ��������ϵ���  ֱ����ǰ����Ǹ��ڵ������ֹͣ
*/

/*
Ѱ��ǰ���ڵ�ͺ���෴
�����һ���ڵ�
1. ��������        ��ô����ڵ��ǰ���ڵ�һ���������������ҵĽڵ�
2. û��������     ͨ���ýڵ��parentָ���ҵ����ڵ�  
				  2.1 ����ýڵ��Ǹ��ڵ���Һ���  �򸸽ڵ���ǰ���ڵ�
				  2.2 ����ýڵ��Ǹ��ڵ������  ��������ϵ���  ֱ����ǰ����Ǹ��ڵ���Һ���ֹͣ
*/
class FindSuccessorNode{
public:
	Node* Solution(Node* pTree){
		if(pTree == NULL)
			return NULL;
		if(pTree->pRight){  //��������
			Node* ptemp = pTree->pRight;

			while(ptemp->pLeft)
				ptemp = ptemp->pLeft;

			return ptemp;
		}
		else{    //û��������
			Node* father = pTree->pParent;
			//if(father == NULL) //�����  ��û��������  ����NULL
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

//  ����  1 2 3 4 5 6 7 8 9 10
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
//	Node* t =  head; //�����7   ��������	 ������������
//	test.Print(test.Solution(t));
//	t = head->pRight->pLeft;  //���9  û�������� �Ǹ��ڵ������
//	test.Print(test.Solution(t));
//	t = head->pRight->pRight;  //���NULL  û�������� һֱ�����Ҳ���  
//	test.Print(test.Solution(t));
//	t = head->pLeft->pLeft->pRight;  //���3  û�������� ��һ�ε�����������
//	test.Print(test.Solution(t));
//
//	
//
//	getchar();
//	return 0;
//	
//}