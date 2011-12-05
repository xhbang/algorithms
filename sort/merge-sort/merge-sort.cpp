#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int d[5]={8,6,4,2,1};			//最后一个增量必须是1,相当于直接插入排序
const int times=200000;
const int maxSize=20;
typedef struct Node{
	int key;
	int data;
}Node;

class Order{
	Node my[maxSize];				//0号元素temp
	Node help[maxSize];				//辅助空间
	int size;
	//	clock_t start,finish;		//计算时间
public:
	Order(int i=0):size(i){}
	void display(ostream &out);
	void init();

};

void Order::init(){
	srand(time(NULL));
	for(int i=1;i<=size;i++){
		my[i].data=rand()%100;
		my[i].key=i;
	}
}

void Order::display(ostream &out){
	for(int i=1;i<=size;i++)
		out<<my[i].key<<" ";
	out<<endl;
	for(int i=1;i<=size;i++)
		out<<my[i].data<<" ";
	out<<endl;
}

int main(){
	Order order(19);		//最多19

	order.init();
	order.display(cout);

	return 0;
}
