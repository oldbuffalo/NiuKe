#include"packet.h"

 /*
 ����  ɾ��      �ȸ����������value
 
 */

template<typename T>
class RandomPool{
private:
	map<T,int> KeyIndexMap;
	map<int,T> IndexKeyMap;
	int size;
public:
	RandomPool():size(0){}
	void insert(T key){
		this->KeyIndexMap[key] = size;
		this->IndexKeyMap[size++] = key;
	}


	//���ɾ��֮��Ŀ�ȱ����   �����һ�������
	void Delete(T key){
		int deleteindex =  KeyIndexMap[key];
		int lastindex = --size;
		T lastkey =  IndexKeyMap[lastindex];
		KeyIndexMap[lastkey] = deleteindex;
		IndexKeyMap[deleteindex] = lastkey;
		KeyIndexMap.erase(key);
		IndexKeyMap.erase(lastindex);
	}

	T getRandom(){
		if(size == 0)
			return NULL;
		//[0,size)���������
		int randomindex = rand()%size;
		return this->IndexKeyMap[randomindex];
	}

};

//int main(){
//
//	srand(time(NULL));
//	RandomPool<string> Pool;
//	Pool.insert("gao");
//	Pool.insert("ben");
//	Pool.insert("zui");
//	Pool.insert("shuai");
//
//	cout<<Pool.getRandom()<<endl;
//	cout<<Pool.getRandom()<<endl;
//
//	Pool.Delete("shuai");
//
//   	cout<<Pool.getRandom()<<endl;
//	cout<<Pool.getRandom()<<endl;
//
//
//	getchar();
//	return 0;
//}