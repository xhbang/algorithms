#include <iostream>
using namespace std;
//合并有序数组a,b；其中m,n分别为两数组的长度
int merge(int a[],int b[],int m,int n)
{
	int i,j,t;
	for(i=0;i<m;i++) //把数组b中的元素插到数组a中去
		for(j=0;j<n;j++)
		{
			if(b[j]>a[i])
			{
				i++;
				t=i+1;//记录数字要插入的位置
			}
			else
			{
				for(i=m-1;i>t;i--)///实现插入操作
					a[i+1]=a[i];
				a[t]=b[j];
				m++;//a数组长度加1
			}
		}
		for(i=0;i<m;i++)
			cout<<a[i]<<" ";
		return 0;
}
void main()
{
	int a[]={2,3,5,8},m=4;
	int b[]={4,7,9},n=3;
	merge(a,b,m,n);
}
