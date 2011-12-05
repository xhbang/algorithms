#include <iostream>

using namespace std;

//typedef int DataType
const int maxsize=100;

template <typename T>
class SeqList{
private:
	T data[maxsize];
	int size;
public:
	void init();
	int insert(int pos,T item);
	int length();
	int deleteat(int pos);
	T get_item(int pos);
	int locate(T item);
};

template <typename T>
void SeqList<T>::init(){
	size=0;
}

template <typename T>
int SeqList<T>::insert(int pos,T item){
	if(pos<1 || pos >(size+1))
		return 0;
	if(size>=maxsize)
		return 0;
	for(int i=size;i>=pos;i--)
		data[i]=data[i-1];
	data[pos-1]=item;
	size++;
	return 1;
}

template <typename T>
int SeqList<T>::length(){
	return size;
}

template <typename T>
int SeqList<T>::deleteat(int pos){
	if(pos<1 || pos >size){
		cout<<"A WRONG RANGE OF DATA"<<endl;
		return 0;
	}
	for(int i=pos;i<size;i++)
		data[i-1]=data[i];
	size--;
	return 1;
}

template <typename T>
T SeqList<T>::get_item(int pos){
	if(pos<1 || pos >size){
		cout<<"A WRONG RANGE OF DATA"<<endl;
	}
	return data[pos-1];
}

template <typename T>
int SeqList<T>::locate(T item){
	int found=0,i=0;
	while(i<size && !found){
		if(data[i]==item)
			found=1;
		else i++;
	}
	if(i<size)
		return i+1;
	else 
		return -1;
}


//for test
int main(){
	SeqList<int> clist;
	clist.init();
	for(int i=0;i<7;i++)
		clist.insert(1,i);
	for(i=0;i<clist.length();i++)
		cout<<clist.get_item(i+1)<<endl;
	clist.deleteat(4);
	for(i=0;i<clist.length();i++)
		cout<<clist.get_item(i+1)<<endl;

	cout<<"cin a char to find"<<endl;
	int ch;
	cin>>ch;
	cout<<clist.locate(ch)<<endl;

	return 0;
}
