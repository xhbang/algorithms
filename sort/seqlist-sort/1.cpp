#include<iostream.h>   
#include   "cSeqList.h"   
//函数模板把两个有序线性表合并成一张有序表   
template   <class   Type>                       
cSeqList<Type>     SeqMerge   (   cSeqList<Type>   A,   cSeqList<Type>   B   )     
{   
	//计算合并后的长度   
	int   Clength=A.Length()+B.Length();   
	cSeqList<Type>   C(Clength);     //模板类     对象       
	int   j=0,ia=0,ib=0;   
	//取两个表头的元素比较，小者插入C表   
	while(ia<A.Length()&&ib<B.Length())   {   
		(A.GetElement(ia)<B.GetElement(ib))?   
			C.Insert(A.GetElement(ia++),j++):   
		C.Insert(B.GetElement(ib++),j++);   
		//在Insert函数中要允许元素重复   
	}   
	//剩余的部分顺序加入C表   
	for(;ia<A.Length();)     
		C.Insert(A.GetElement(ia++),j++);   
	for(;ib<B.Length();)     
		C.Insert(B.GetElement(ib++),j++);   
	return   C;   
}   
//主函数   
void   main()   
{   
	cSeqList   <int>   s1(5),s2(4);   //模板类     对象   
	int   v;   
	for(int   i=0;i<s1.getMaxSize();i++)   {   
		cout<<"请输入第"<<i+1<<"个元素：";   
		cin>>v;   
		s1.Insert(v,i);   
	}   
	for(   i=0;i<s2.getMaxSize();i++)   {   
		cout<<"请输入第"<<i+1<<"个元素：";   
		cin>>v;   
		s2.Insert(v,i);   
	}   
	//两个有序表的合并   
	cSeqList   <int>   s3=SeqMerge(s1,s2);   
	//这里隐式地调用了“缺省拷贝构造函数”   
	s1.display();s2.display();   
	s3.display   (   );   
}
