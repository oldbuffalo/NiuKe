#include"packet.h"

/*
�����������л��ͷ����л�
1.ע���ֵ��λ
2.ע��ֵ������־
3.���л��ͷ����л���ʽһ��
   
        1
    2	    3
 4    5   6   7
 
����ķ�ʽ���л�   1!2!4!#!#!5!#!#!3!6!#!#!7!#!#!
����/����  ����
*/
struct Node
{
	int nValue;
	Node* pleft;
	Node* pRight;
	Node(int x):nValue(x),pleft(NULL),pRight(NULL){}
};	

class SerializeAndReconstructTree{
public:
	string SerializeByPre(Node* pTree){
		if(NULL == pTree)
			return "#!";

  	    //ostringstream   ss;
		//ss<<pTree->nValue;
		//string res = ss.str()+"!";
		//string res = std::to_string(pTree->nValue)+"!";
		//res += 	SerializeByPre(pTree->pleft);
		//res += 	SerializeByPre(pTree->pRight);

		string  res = std::to_string(pTree->nValue)+"!";
		res += 	SerializeByPre(pTree->pleft);
		res += 	SerializeByPre(pTree->pRight);

		return res;
	}

	Node* ReconstructTreeByPre(string preStr){
		if(preStr.empty())
			return NULL;
		vector<string> v;	///����ڵ��ֵ
		SplitString(preStr,v,"!");
		queue<string> q;	 //ǰ���ö���  ������ջ
		for(int i = 0;i<v.size();i++)
			q.push(v[i]);

		return reconPreOrder(q); 
	}

	Node* reconPreOrder(queue<string> &q){
		string	value = q.front();
		q.pop(); 
		if(value == "#")
			return NULL;
		Node* ptemp = new Node(atoi(value.c_str()));
		ptemp->pleft = reconPreOrder(q);
		ptemp->pRight = reconPreOrder(q);

		return ptemp;
	}

	void SplitString(const string& s, vector<string>& v, const string& c)	// �ַ����ָ�
	{
		string::size_type pos1, pos2;
		pos2 = s.find(c);
		pos1 = 0;
		//npos ��ʾ�����ڵ�λ��	   -1
		while(string::npos != pos2)
		{
			v.push_back(s.substr(pos1, pos2-pos1));//��pos1��ʼ����ȡpos2-pos1λ
			pos1 = pos2 + c.size();
			pos2 = s.find(c, pos1);  // ��pos1��ʼ���� �����Ӵ������±�  ����������npos
		}
		if(pos1 != s.length())
			v.push_back(s.substr(pos1));
	}

	void PreOrder(Node* pTree){
		if(pTree == NULL)
			return;

		stack<Node*> s;
		s.push(pTree);

		Node* ptemp = NULL;
		while(!s.empty()){
			ptemp = s.top();
			s.pop();
			cout<<ptemp->nValue<<" ";
			if(ptemp->pRight)
				s.push(ptemp->pRight);
			if(ptemp->pleft)
				s.push(ptemp->pleft);
		}

		cout<<endl;
	}

	void LevelPrint(Node* pTree){
		if(pTree == NULL)
			return;

		queue<Node*> q;
		q.push(pTree);
		Node* pTemp = NULL;
		while(!q.empty()){
			pTemp = q.front();
			q.pop();
			cout<<pTemp->nValue<<" ";
			if(pTemp->pleft)
				q.push(pTemp->pleft);
			if(pTemp->pRight)
				q.push(pTemp->pRight);
		}

		cout<<endl;

	}

	string serialByLevel(Node* pTree){
		if(pTree == NULL)
			return NULL;
		string res;
		queue<Node*> q;
		q.push(pTree);
		res += std::to_string(pTree->nValue) + "!";
		Node* pTemp = NULL;
		while(!q.empty()){
			pTemp = q.front();	  //ȡ�����������Һ��ӵ�ֵ
			q.pop();
			if(pTemp->pleft){
				res += std::to_string(pTemp->pleft->nValue) + "!";
				q.push(pTemp->pleft);
			}
			else
				res += "#!";
			if(pTemp->pRight){
				res += std::to_string(pTemp->pRight->nValue) + "!";
				q.push(pTemp->pRight);
			}
			else
				res += "#!";
		}

		return res;
	}

	Node* reconByLevelString(string str){
		if(str.empty())
			return NULL;
		vector<string> v;	//����ڵ��ֵ
		SplitString(str,v,"!");
		queue<Node*> q;		// ��¼�ڵ�    ����ȡ���� �������Һ���
		int index = 0;
		Node* phead = generateNodeByString(v[index++]);
		if(phead == NULL)
			return NULL;
		else
			q.push(phead);

		Node* pTemp = NULL;
		while(!q.empty()){
			pTemp = q.front();
			q.pop();
			pTemp->pleft = generateNodeByString(v[index++]);
			pTemp->pRight = generateNodeByString(v[index++]);
			if(pTemp->pleft)
				q.push(pTemp->pleft);
			if(pTemp->pRight)
				q.push(pTemp->pRight);
		}

		return phead;
	}

	Node* generateNodeByString(string str){	 //����ڵ㺯��
		if(str == "#")
			return NULL;
		else
			return new Node(atoi(str.c_str()));
	}


};



//int main()
//{
//	Node* pHead = new Node(1);
//	pHead->pleft = new Node(2);
//	pHead->pleft->pleft = new Node(4);
//	pHead->pleft->pRight = new Node(5);
//	pHead->pRight = new Node(3);
//	pHead->pRight->pleft = new Node(6);
//	pHead->pRight->pRight = new Node(7);
//
//	SerializeAndReconstructTree test;
//	string str;
//	str = test.SerializeByPre(pHead);
//	cout<<str<<endl;
//	Node* ptemp  = test.ReconstructTreeByPre(str);
//	test.PreOrder(ptemp);
//
//
//	str = test.serialByLevel(pHead);
//	cout<<str<<endl;
//	ptemp = test.reconByLevelString(str);
//	test.LevelPrint(ptemp);
//
//	getchar();
//
//	return 0;
//}