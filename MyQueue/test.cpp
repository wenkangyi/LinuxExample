#include <iostream>
#include "MyQueue.h"

#include <unistd.h>

using namespace std;
#pragma pack (4)
class A{
	public:
		A(int a){
			this->a = a;
		}
		int GetValue(){return this->a;}
	private:
		int a = 0;
};


int main(){
	
	MyQueue<A> *mq = new MyQueue<A>();
	for(int i=0;i<QueueMaxSize-1;i++){
		mq->InQueue(new A(i));
	}
	
	int total1 = mq->GetEffectiveElements();
	
	std::cout << "有效元素数量：" << total1 << std::endl;
	
	A *n = (A*)mq->OutQueue();
	
	std::cout << "弹出的第一个元素值：" << n->GetValue() << std::endl;
	delete n;
	n = (A*)mq->OutQueue();
	std::cout << "弹出的第二个元素值：" << n->GetValue() << std::endl;
	delete n;
	n = (A*)mq->OutQueue();
	std::cout << "弹出的第三个元素值：" << n->GetValue() << std::endl;
	delete n;
	sleep(3);
	
	total1 = mq->GetEffectiveElements();
	
	std::cout << "有效元素数量：" << total1 << std::endl;
	
	mq->InQueue(new A(11111111));
	mq->InQueue(new A(22222222));
	mq->InQueue(new A(33333333));
	mq->InQueue(new A(88888888));
	std::cout << "准备遍历所有元素" << std::endl;
	for(int i=0;i<QueueMaxSize-1;i++){
		n = (A*)mq->OutQueue();
		std::cout << "弹出的第" << i << "个元素值：" << n->GetValue() << std::endl;
		delete n;
	}
	
	std::cout << "有效元素数量：" << mq->GetEffectiveElements() << std::endl;
	
	return 0;
}


