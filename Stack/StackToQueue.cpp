#include"packet.h"

/*
��֤����ԭ��
1.pushstack��popstack�����ݵ�ʱ��  popstackһ��ҪΪ��
Ҳ����˵�ϴ�pop��֮�� Ҫ�����ݵ��ظ�pushstack
2.pushstack�����ݵ�ʱ��һ��Ҫ����
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
		//��pushstack�е����ݵ���popstack
		if(pushstack.empty()){
			cout<<"���п�"<<endl;
			return;
		}
		dao(pushstack,popstack);
		cout<<"����"<<popstack.top()<<endl;
		popstack.pop();

		//Ȼ�����½�popstack�е����ݵ��ظ�pushstack
	    dao(popstack,pushstack);
	}

	void  dao(stack<int> &res,stack<int> &des){   //Դ   Ŀ��
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