#include"packet.h"

class ArrToStack{
private:
	int size;	//栈的最大值
	int index; //新来元素将入填入的位置
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
			cout<<"栈已经满了"<<endl;
			return;
		}
		arr[index++] = x;
	}
	int Pop(){
		if(index == 0){
			cout<<"栈已经空了"<<endl;
			return -1;
		}
		return arr[--index];
	}
	int Top(){
		if(index == 0){
			cout<<"栈已经空了"<<endl;
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