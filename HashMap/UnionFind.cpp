#include"packet.h"


/*
���鼯
���ټ������Ԫ���Ƿ�����һ������
�ϲ�����Ԫ�����ڵļ���
*/

/*
�ýṹ��Ҫ������������
1.ÿ���������Գ�Ϊһ�����ϣ����ҳ�Ϊ�ü��ϵĴ���Ԫ��
�ж�����Ԫ���Ƿ���ͬһ���ϣ�  ֻҪ������Ԫ���Ƿ���ͬ
��κϲ��������ϣ�  
Ԫ���ٵļ��Ϻϲ���Ԫ�ض�ļ�����  ����ֱ�ӹҵ�����Ԫ������

��ѯԪ�����ڼ��ϵĴ���ڵ�Ĺ����е��Ż���
��Ϊ�˽ṹ���ڳ�������Ӱ���ѯЧ�ʣ����ÿ�β�ѯ���֮�󶼽���ʼ��ѯ֮��Ľڵ�ֱ�ӹҵ�����ڵ���ȥ
*/

class Node{
	//��װʲô����
	int val;
};



class UnionFind{
private:
	map<Node*,Node*> fathermap; //�ӽڵ��Ӧ���ڵ�
	map<Node*,int>  sizemap;  //�����е�Ԫ�����ڼ��ϵ�Ԫ�ظ���
public:
	UnionFind(list<Node*> nodes){  //��ʼ����������
		for(auto node : nodes){
			fathermap[node] = node;
			sizemap[node] = 1;
		}
	}


	Node* FindHead(Node* n){

		Node* father = fathermap[n]; 
		//while(father != n){
		//	n = father;
		//	father = fathermap[n];
		//}		  ���ַ�ʽ��Ҫ��֮ǰ�Ľڵ��¼����  ������������ڵ�(�Ż�)

		if(father != n){
			father = FindHead(father);
		}	

		fathermap[n] = father;// �Ż�
		return father;
	}

	bool isSameSet(Node* n1,Node* n2){
		return  FindHead(n1) == FindHead(n2);
	}

	void Union(Node* n1,Node* n2){
		if(n1 == NULL || n2 == NULL)
			return;
		Node* head1 = FindHead(n1);
		Node* head2 = FindHead(n2);

		if(head1 != head2){ //����ͬһ����
			int size1 =  sizemap[head1];
			int size2 =  sizemap[head2];
			if(size1 < size2){
				fathermap[head1] = head2;
				sizemap[head2] = size1+size2;
			}
			else{
			   	fathermap[head2] = head1;
				sizemap[head1] = size1+size2;
			}
		}

	}


};