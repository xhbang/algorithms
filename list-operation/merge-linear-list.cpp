//******************************************************************************************************************************
//
//             合并有序线性表
//
//            张明烁编写于2008年6月7日
//					谢行2009年来此一游,张明烁我觉得你写的很麻烦，所以我给你改了
//
//******************************************************************************************************************************

#include <stdio.h>
#define lla 5//宏定义lla为la数组的大小为5.
#define llb 8//宏定义llb为lb数组的大小为8.
#define llc lla+llb//宏定义llc为lc数组的大小为la数组和lb数组大小之和.
void main()
{
//定义并初始化两个数组la，lb。
int la[lla]={3,5,8,11,13};
int lb[llb]={2,6,8,9,11,15,20,26};
int lc[llc];//定义一个数组lc，用于存放la、lb合并后的新数组。
int *pa=la,*pb=lb,*pc=lc,*p;
while(pa<la+lla && pb<lb+llb)//la,lb均有数字的时候的情况。
{
   if(*pa>*pb)
		*pc++=*pb++;

   else if(*pa<*pb)
		*pc++=*pa++;
   else{		//(*pa==*pb),如果la、lb中的元素相等，则保留一个相等的值在lc中。
    *pc++=*pa++;
    pb++;
   }
}
while(pb<lb+llb)
   *pc++=*pb++;

while(pa<la+lla)
   *pc++=*pa++;

printf("需要合并的两组线性表分别为：\n");
for(p=la;p<pa;p++)//输出la中的数据。
   printf("%6d",*p);
printf("\n\n");

for(p=lb;p<pb;p++)//输出lb中的数据。
   printf("%6d",*p);
printf("\n\n");

printf("将两组线性表合并后的线性表为：\n");

for(p=lc;p<pc;p++)//输出lc中的数据。
   printf("%6d",*p);
printf("\n\n");

}

