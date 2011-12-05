#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int times=200000;
const int maxSize=20;
typedef struct Node{
	int key;
	int data;
}Node;

class Order{
	Node my[maxSize];				//0号元素temp
	int size;
//	clock_t start,finish;		//计算时间
public:
	Order(int i=0):size(i){}
	void display(ostream &out);
	void init();
	void insertSort();
	int binSearch(int key);
	void binInsertSort();		//我还是不太明白

};

void Order::binInsertSort(){
	int mid,pos;
	for(int i=2;i<=size;i++){
		my[0]=my[i];
		int low=1,high=i-1;
		while(low<=high){				//我就是不明白插入点的值等于my[0]了是多少,再仔细想想
			mid=(low+high)/2;
			if(my[0].data>my[mid].data)
				low=mid+1;
			else
				high=mid-1;
		}
		for(pos=i-1;pos>=low;pos--)
			my[pos+1]=my[pos];
		my[low]=my[0];
	}
}

int Order::binSearch(int key){
	int i=1,j=size,mid;
	while(i<=j){
		mid=(i+j)/2;
		if(my[mid].data==key)
			return mid;
		else if(my[mid].data>key)
			j=mid-1;
		else
			i=mid+1;
	}
	return 0;
}

void Order::insertSort(){
	for(int i=2;i<=size;i++){
		my[0]=my[i];
		int j=i-1;
		while(my[j-1].data>my[0].data){		//总会减到0号，不用担心越界
			my[j+1]=my[j];
			j--;		//放后面
		}
		my[j]=my[0];
	}
}

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
//	order.insertSort();
	order.binInsertSort();
	order.display(cout);
//	cout<<order.binSearch(87);
	return 0;
}
