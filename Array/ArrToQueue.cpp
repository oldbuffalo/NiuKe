#include"packet.h"


class ArrToQueue{
private:
	int start;
	int end;	//��ǽ�Ҫ������е�Ԫ�ص�λ�� 
	int cursize;  //���е�ǰ��С
	int size;   //���й̶���С
	int* arr;
public:
	ArrToQueue(int n):start(0),end(0),cursize(0),arr(NULL){
		arr = new int[n];
		size = n;
	}
	~ArrToQueue(){
		delete []arr;
		arr = NULL; 
	}
	void Push(int x){
		//������Ԫ��û����ʱ��
		if(cursize == size){
			cout<<"�����Ѿ�����"<<endl;
			return;
		}
		cursize++;
		//arr[end] = x;
		////����������һ��Ԫ�ر����������ˣ�end��0
		//end = end == size-1 ? 0:end+1;

		//��������ȼ���
		arr[end++] = x;
		end = end%size;
	}
	int Pop(){
		// cursize��Ϊ�յ�ʱ�����ȡ������
		if(cursize == 0){
			cout<<"��ǰ����Ϊ��"<<endl;
			return -1;
		}
		int x;
		cursize--;
		x = arr[start];
		start = start == size-1?0:start+1;
		return x;
	}
	int GetFront(){
		// cursize��Ϊ�յ�ʱ�����ȡ������
		if(cursize == 0){
			cout<<"��ǰ����Ϊ��"<<endl;
			return -1;
		}

		return arr[start];
	}



};

//int main()
//{
//	ArrToQueue q(3);
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	cout<<q.GetFront()<<endl;
//	cout<<q.Pop()<<endl;
//	cout<<q.Pop()<<endl;
//	cout<<q.Pop()<<endl;
//	cout<<q.Pop()<<endl;
//	getchar();
//	return 0;
//}