#include"packet.h"

/*
保证两个原则
1.pushstack往popstack倒数据的时候  popstack一定要为空
也就是说上次pop完之后 要将数据倒回给pushstack
2.pushstack倒数据的时候一定要倒空
*/

class StackToQueue{
private:
	stack<int> pushstack;
	stack<int> popstack;
public:
	void push(int x){
		pushstack.push(x);
	}
	void pop(){
		//将pushstack中的数据倒进popstack
		if(pushstack.empty()){
			cout<<"队列空"<<endl;
			return;
		}
		dao(pushstack,popstack);
		cout<<"弹出"<<popstack.top()<<endl;
		popstack.pop();

		//然后重新将popstack中的数据倒回给pushstack
	    dao(popstack,pushstack);
	}

	void  dao(stack<int> &res,stack<int> &des){   //源   目标
		while(!res.empty()){
			des.push(res.top());
			res.pop();
		}
	}
};


//int main()
//{
//	StackToQueue q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.pop();
//	q.push(4);
//	q.pop();
//	q.pop();
//	q.pop();
//	q.pop();
//
//	getchar();
//	return 0;
//}