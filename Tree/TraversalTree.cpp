#include"packet.h"

/*
������������ ���� �������
�ֳɵݹ�ͷǵݹ�
*/


/*
        5
	3        8
  2  4	   7     10
1		 6>    9>   <11
*/

/*
����  5 3 2 1 4 8 7 6 10 9 11
����  1 2 3 4 5 6 7 8 9 10 11
����  1 2 4 3 6 7 9 11 10 8 5
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
	�ݹ鷨����  �����Ϸ��ʽڵ�Ĵ�����һ����   ����ÿ����㶼����������
	��һ�η��ʵ��ýڵ�ʹ�ӡ   -------����
	�ڶ��η��ʵ��ýڵ�ʹ�ӡ   -------����
	�����η��ʵ��ýڵ�ʹ�ӡ   -------����
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
			
			//������ӡ
			ptemp = s.top();
			cout<<ptemp->nValue<<" ";
			s.pop();

			//�������Ƚ�ջ
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
			if(pTree){	  //һֱ����ѹջ 
				s.push(pTree);
				pTree = pTree->pleft;
			}
			else{
				//������ӡ  ������
				cout<<s.top()->nValue<<" ";
				pTree = s.top()->pRight;
				s.pop();
			}
		}

		cout<<endl;
	}


	//�Ƚϼ򵥵ķ�ʽ��������ջ	  ���������Ҹ�   ����������Ǹ�����   ��������Ⱦ�������˳��ߵ���
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
			//�������Ƚ�ջ
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

	//ֻ����һ��ջ
	void PosOrderUnRecur2(Node* pTree){
		if(pTree == NULL)
			return;
		cout<<"PosOrderUnRecur:";
		stack<Node*> s;

		Node* ptemp = NULL;
		Node* pMark = NULL;		  //��Ǵ�����Ľڵ�
		while(!s.empty()|| pTree){
			if(pTree){
				s.push(pTree);
				pTree = pTree->pleft;
			}
			else{
				ptemp = s.top();

				if(ptemp->pRight  == NULL || ptemp->pRight == pMark){
					//��ǰ�ڵ�û�������� �����������Ѿ��������
					//������ӡ
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