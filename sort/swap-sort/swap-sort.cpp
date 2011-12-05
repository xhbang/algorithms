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
	void bubble_incease();
	void bubble_decrease();
	void quicksort();
	void qsort(int i,int j);		//递归版本
	int part(int i,int j);
	void selectsort();

};

void Order::selectsort(){
	int i,j,min;
	for(i=1;i<size;i++){
		for(j=i+1,min=i;j<=size;j++){		//选择最小的
			if(my[j].data<my[min].data)		//这里是my[min]
				min=j;
		}
		if(i!=min){
			my[0]=my[min];
			my[min]=my[i];
			my[i]=my[0];
		}
	}
}

int Order::part(int i,int j){
	int low=i,high=j;
	my[0]=my[low];
	while(low<high){
		while(low<high && my[high].data>=my[0].data)
			high--;
		if(low<high){
			my[low]=my[high];
			low++;
		}
		while(low<high &&my[low].data<=my[0].data)
			low++;
		if(low<high){
			my[high]=my[low];
			high--;
		}

	}
	my[low]=my[0];
	return low;
}

void Order::qsort(int i,int j){
	int pick;
	if(i<j){
		pick=part(i,j);
		qsort(i,pick-1);
		qsort(pick+1,j);
	}
}

void Order::quicksort(){
	qsort(1,size);
}

void Order::bubble_decrease(){
	int i,j,flag;
	for(i=size-1;i>=1;i--){
		for(j=1;j<=i;j++)
			if(my[j].data<my[j+1].data){
				my[0]=my[j+1];
				my[j+1]=my[j];
				my[j]=my[0];
				flag=1;
			}
		if(!flag)
			break;		//第一次认识到flag的作用
	}	
}

void Order::bubble_incease(){
	int i,j,flag;
	for(i=1;i<size;i++){
		flag=0;
		for(j=size;j>=i+1;j--)
			if(my[j].data<my[j-1].data){
				my[0]=my[j-1];
				my[j-1]=my[j];
				my[j]=my[0];
				flag=1;
			}
		if(!flag)
			break;			//表示其余都排好
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
	clock_t start,finish;
	double duration;
	start=clock();
	for(int i=0;i<times;i++){
		order.init();
//		order.display(cout);
//		order.bubble_decrease();
//		order.display(cout);
//		order.bubble_incease();
		order.quicksort();
//		order.selectsort();
		order.display(cout);
	}
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"using "<<duration<<"secs to finish "<<times<<" times sort"<<endl;
	cout<<"using "<<duration/times<<"sec per time"<<endl;

	return 0;
}
