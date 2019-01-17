#include"packet.h"

/*����������ʵ��һ�������ջ  ��ʵ��ջ�Ļ������ܵĻ����� ��ʵ�ַ���ջ��
��С��Ԫ��  pop push getMin  ʱ�临�Ӷȶ���O(1)*/


class StackGetMin{
private:
	stack<int> data;
	stack<int> min;
public:
	void push(int x){
		
		//���minջΪ�� ѹ�뵱ǰ������min
		//���minջ��Ϊ�� minջջ��Ԫ�غ͵�ǰ���Ƚ�
		//�����ǰ����С  ѹ��minջ
		//���minջջ����С  �ظ�ѹ��minջ  ��֤data��minͬ������
		if(min.empty())
			min.push(x);
		else{
			min.push(Min(min.top(),x));
		}
		
		//����ѹ��dataջ
		data.push(x);

	}
	void pop(){
		if(data.empty()){
			cout<<"ջ��"<<endl;
			return;
		}
		min.pop();
		data.pop();
	}

	int getMin(){
		if(min.empty()){
			cout<<"ջ��"<<endl;
			return -1;
		}
		return min.top();	
	}

	int Min(int a,int b){
		return a<=b?a:b;
	}

};

//int main(){
//	StackGetMin s;
//	s.push(5);
//	s.push(4);
//	s.push(3);
//	s.push(2);
//	s.push(1);
//
//	cout<<s.getMin()<<endl;
//	s.pop();
//	cout<<s.getMin()<<endl;
//
//	getchar();
//	return 0;
//}