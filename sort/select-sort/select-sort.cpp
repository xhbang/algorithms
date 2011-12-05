//有问题，一定要去改
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int d[5]={9,7,5,2,1};			//最后一个增量必须是1,相当于直接插入排序,最好没有1以外的公因子
const int times=200000;
const int maxSize=20;
typedef struct Node{
	int key;
	int data;
}Node;

class Order{
	Node my[maxSize];				//0号元素temp
	int size,heapsize;				//增加一个heapsize
	//	clock_t start,finish;		//计算时间
public:
	Order(int i=0):size(i),heapsize(i){}
	void display(ostream &out);
	void init();
	void selectSort();			//简单选择排序
	void heapAdjust(int i,int j);
	void heapSort();						//现在还有问题
	//以下堆算法来自算法导论
	void maxHeap(int i);
	void buildMaxHeap();
	void heapsort();

};

void Order::heapsort(){
	buildMaxHeap();
	int i;
	for(i=heapsize/2;i>1;i--){
		my[0]=my[i];
		my[i]=my[1];
		my[1]=my[0];
		heapsize--;
		maxHeap(1);
	}
}

void Order::maxHeap(int i){
	int largest;
	int left=2*i,right=2*i+1;
	if(left<=heapsize &&my[left].data>my[i].data)
		largest=left;
	else 
		largest=i;
	if(right<=heapsize &&my[right].data>my[largest].data)
		largest=right;
	if(largest!=i){
		my[0]=my[largest];
		my[largest]=my[i];
		my[i]=my[0];
	}
	maxHeap(largest);
}

void Order::buildMaxHeap(){
	for(int i=heapsize/2;i>0;i--)
		maxHeap(i);
}

void Order::heapSort(){
	int i=size/2;
	for(;i>0;i--)
		heapAdjust(i,size);				//从后往前形成大顶堆
	for(i=size;i>1;i--){					//从后向前轮换一次，再调整
		my[0]=my[i];
		my[i]=my[1];
		my[1]=my[0];
		heapAdjust(1,i-1);
	}
}

void Order::heapAdjust(int i,int j){
	int k;
	my[0]=my[i];				//暂存
	for(k=i*2;k<=j;k*=2){						//k<=j
		if(my[k].data<my[k+1].data)
			k++;
		if(my[0].data<my[k].data){				//不是my[i]
			my[i]=my[k];
			i=k;						//再从K开始找
		}
	}
	my[i]=my[0];
}

void Order::selectSort(){
	int i=1,j,min;
	for(;i<size;i++){								//不用等于size
		for(j=i+1,min=i;j<=size;j++)			//选择min
			if(my[j].data<my[min].data)
				min=j;
		if(i!=min){
			my[0]=my[min];
			my[min]=my[i];
			my[i]=my[0];
		}
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
//	order.selectSort();
//	order.heapSort();
	order.heapsort();
	order.display(cout);

	return 0;
}