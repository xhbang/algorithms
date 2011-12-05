//sort of arr a and b

#include <iostream>   
using namespace std;   
#define MAX 100
   
typedef struct{  
	int data[MAX];   
	int length;   
}seqlist;   

int insert(seqlist *l,int x,int i){ 
	int j;
	for(j=l->length-1;j>=i;j--)   
		l->data[j+1]=l->data[j];   
	l->data[i]=x;   
	l->length++;   
	return 0;   
}   

void main()
{   
	seqlist *l=new seqlist;
	l->length=1;
	//seqlist *l2=new seqlist;
   
	int  i=0,j=0,n=0;   
	int  data[4]={2,3,5,8};   
	int  b[3]={4,9,10};
	l->length =0;
	
	while(i<4 && j<3){
		if(data[i]<=b[j])
			insert(l,data[i++],n++);
		else
			insert(l,b[j++],n++);
	}
	while(i<4)
		insert(l,data[i++],n++);
	while(j<3)
		insert(l,b[j++],n++);

	for(i=0;i<l->length;i++)   
			cout<<l->data[i];
		
}
