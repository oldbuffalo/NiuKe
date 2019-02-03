#include"packet.h"


/*
并查集
快速检查两个元素是否属于一个集合
合并两个元素所在的集合
*/

/*
该结构需要给定所有样本
1.每个样本各自成为一个集合，并且成为该集合的代表元素
判断两个元素是否在同一集合？  只要看代表元素是否相同
如何合并两个集合？  
元素少的集合合并到元素多的集合上  并且直接挂到代表元素下面

查询元素所在集合的代表节点的过程中的优化：
因为此结构存在长挂链，影响查询效率，因此每次查询完毕之后都将开始查询之后的节点直接挂到代表节点上去
*/

class Node{
	//封装什么都行
	int val;
};



class UnionFind{
private:
	map<Node*,Node*> fathermap; //子节点对应父节点
	map<Node*,int>  sizemap;  //集合中的元素所在集合的元素个数
public:
	UnionFind(list<Node*> nodes){  //初始化给定样本
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
		//}		  这种方式需要将之前的节点记录下来  重新连到代表节点(优化)

		if(father != n){
			father = FindHead(father);
		}	

		fathermap[n] = father;// 优化
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

		if(head1 != head2){ //不是同一集合
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