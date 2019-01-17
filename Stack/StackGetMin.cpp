#include"packet.h"

/*问题描述：实现一个特殊的栈  在实现栈的基本功能的基础上 再实现返回栈中
最小的元素  pop push getMin  时间复杂度都是O(1)*/


class StackGetMin{
private:
	stack<int> data;
	stack<int> min;
public:
	void push(int x){
		
		//如果min栈为空 压入当前数进入min
		//如果min栈不为空 min栈栈顶元素和当前数比较
		//如果当前数更小  压入min栈
		//如果min栈栈顶更小  重复压入min栈  保证data和min同步生长
		if(min.empty())
			min.push(x);
		else{
			min.push(Min(min.top(),x));
		}
		
		//数据压入data栈
		data.push(x);

	}
	void pop(){
		if(data.empty()){
			cout<<"栈空"<<endl;
			return;
		}
		min.pop();
		data.pop();
	}

	int getMin(){
		if(min.empty()){
			cout<<"栈空"<<endl;
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