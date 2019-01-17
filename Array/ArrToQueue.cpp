#include"packet.h"


class ArrToQueue{
private:
	int start;
	int end;	//标记将要放入队列的元素的位置 
	int cursize;  //队列当前大小
	int size;   //队列固定大小
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
		//队列中元素没满的时候
		if(cursize == size){
			cout<<"队列已经满了"<<endl;
			return;
		}
		cursize++;
		//arr[end] = x;
		////如果数组最后一个元素被填入数据了，end置0
		//end = end == size-1 ? 0:end+1;

		//上面两句等价于
		arr[end++] = x;
		end = end%size;
	}
	int Pop(){
		// cursize不为空的时候就能取出队首
		if(cursize == 0){
			cout<<"当前队列为空"<<endl;
			return -1;
		}
		int x;
		cursize--;
		x = arr[start];
		start = start == size-1?0:start+1;
		return x;
	}
	int GetFront(){
		// cursize不为空的时候就能取出队首
		if(cursize == 0){
			cout<<"当前队列为空"<<endl;
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