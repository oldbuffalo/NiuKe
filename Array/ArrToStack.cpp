#include"packet.h"

class ArrToStack{
private:
	int size;	//ջ�����ֵ
	int index; //����Ԫ�ؽ��������λ��
	int* arr;
public:
	ArrToStack():index(0),arr(NULL){}
	~ArrToStack(){
		delete []arr;
		arr = NULL;
	}
	bool InitStack(int n){
		this->size = n;
		arr = new int[n];
		if(arr == NULL)
			return false;
		return true;
	}
	void Push(int x){
		if(index >= size){
			cout<<"ջ�Ѿ�����"<<endl;
			return;
		}
		arr[index++] = x;
	}
	int Pop(){
		if(index == 0){
			cout<<"ջ�Ѿ�����"<<endl;
			return -1;
		}
		return arr[--index];
	}
	int Top(){
		if(index == 0){
			cout<<"ջ�Ѿ�����"<<endl;
			return -1;
		}
		return arr[index-1];
	}

};


//int main()
//{
//	ArrToStack s;
//	s.InitStack(3);
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	cout<<s.Top()<<endl;
//	s.Pop();
//	s.Pop();
//	s.Pop();
//	s.Pop();
//
//	getchar();
//	return 0;
//}