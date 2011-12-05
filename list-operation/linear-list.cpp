#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define INITSIZE 100
#define INCRESE 10
#define OVERFLOW 2		//此处应用多少作为返回值我还有疑虑
#define ERROR 0
#define OK 1

typedef int Status;
typedef char ElemType;
//typedef int ElemType;

typedef struct Sqlist{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;

//函数声明部分
Status Initlist(Sqlist* L);
Status Insertlist(Sqlist* L,int i,ElemType e);
Status Mergelist(Sqlist La,Sqlist Lb,Sqlist* Lc);
Status Showlist(Sqlist* L);
Status Sortlist(Sqlist* L);			//bubble sort
Status Deletelist(Sqlist* L,int i);
Status Clearlist(Sqlist* L);
Status Travellist(Sqlist* L);
Status Emptylist(Sqlist* L);
Status Deletevaluelist(Sqlist* L,ElemType e); 
ElemType Deletelastlist(Sqlist* L);
ElemType Deletefirstlist(Sqlist* L);
Status Insertorderlist(Sqlist* L,ElemType e);

Status Insertorderlist(Sqlist* L,ElemType e){
	for(int i=0;i<L->length;i++)
		if(e < L->elem[i])
			break;
/*典型的错误写法，要从后面开始
	for(int j=i;j<L->length;i++)
		L->elem[j+1]=L->elem[j];
*/
	for(int j=L->length;j>=i;j--)
		L->elem[j+1]=L->elem[j];
	L->elem[i]=e;
	return OK;
}

ElemType Deletefirstlist(Sqlist* L){
	ElemType e;
	if(L->length == 0)
		return ERROR;
	e = L->elem[0];	
	for(int i=1;i<L->length;i++)
		L->elem[i-1]=L->elem[i];
	--L->length;
	return e;
}

ElemType Deletelastlist(Sqlist* L){
	if(L->length == 0){
		printf("LIST NULL,NO OPERATION");
		return ERROR;
	}
	--L->length;
	return L->elem[L->length];
}

Status Deletevaluelist(Sqlist* L,ElemType e){
	for(int i=0;i<L->length;i++)
		if(L->elem[i] == e)
			break;
	if(i == L->listsize)
		return ERROR;
	for(int j=i+1;j<L->length;j++)
		L->elem[j-1]=L->elem[j];
	--L->length;
	return OK;
}

Status Emptylist(Sqlist* L){
	if(L->length == 0)
		return 1;
	else
		return 0;
}

Status Travellist(Sqlist* L){
	ElemType *p;
	p = L->elem;
	for(int i=0;i<L->length;i++){
		printf("3c",*p++);
	}
	printf("\n");
	return OK;
}

Status Clearlist(Sqlist *L){
	if(L->elem){
		free(L->elem);
		L->length = 0;
		L->listsize = 0;
	}
	return OK;
}

Status Deletelist(Sqlist* L,int i){
	if(i<1 || i>L->length)
		return ERROR;
	ElemType *q,*p;
	ElemType e;
	p = &(L->elem[i-1]);
	e = *p;
	q = L->elem+L->length-1;
	for(++p;p<=q;++p)
		*(p-1)=*p;
	--L->length;
	return OK;

}
Status Sortlist(Sqlist* L){
	ElemType *p = NULL;
	int i,j;
	for(i=0;i<L->length-1;++i)
		for(j=L->length-i-1,p=&(L->elem[0]);j>0;--j){
/*			if(L->elem[j] < L->elem[j-1]){
				ElemType temp;
				temp = L->elem[j-1];
				L->elem[j-1] = L->elem[j];
				L->elem[j] = temp;
			}
*/			
			if(*p >*(p+1)){
				ElemType temp;
				temp = *p;
				*p = *(p+1);
				*(p+1) = temp;
			}
			p++;
		}

	return OK;
}


Status Mergelist(Sqlist La,Sqlist Lb,Sqlist* Lc){
	ElemType *pa=La.elem,*pb=Lb.elem,*pc;
	ElemType *pa_last=La.elem+La.length-1,*pb_last=Lb.elem+Lb.length-1;
	Lc->listsize=Lc->length=La.length + Lb.length;
	pc=Lc->elem=(ElemType *)malloc(Lc->listsize*sizeof(ElemType));
	if(!pc)
		return OVERFLOW;
	while(pa<=pa_last && pb<=pb_last)
//		*pc++ = (*pa<=*pb?*pa++:*pb++);
//another choice

/*problem here:the length of lc is fixed to la+lb,how to do it??????
	if(*pa<*pb)
		*pc++=*pa++;
	else if(*pa>*pb)
		*pc++=*pb++;
	else{
		*pc++=*pa++;
		pb++;
	}
*/
	if(*pa<*pb)
		*pc++ = *pa++;
	else
		*pc++ = *pb++;

	while(pa<=pa_last)
		*pc++=*pa++;
	while(pb<=pb_last)
		*pc++=*pb++;

	return OK;
}

Status Initlist(Sqlist* L){
	L->elem = (ElemType*)malloc(INITSIZE*sizeof(ElemType));
	if(!L->elem)
		return OVERFLOW;
	L->length = 0;
	L->listsize = INITSIZE;
	return OK;
}

Status Showlist(Sqlist* L){
	int i=0;
//	ElemType num=0;
	ElemType num='0';
	for(;i<L->length;i++){
		num = L->elem[i];
//		printf("%d",num);
		printf("%c",num);
	}
	printf("\n");

	return OK;
}

Status Insertlist(Sqlist* L,int i,ElemType e){
	if(i<1 ||i>L->length+1)
		return ERROR;
	if(L->length >L->listsize){
		ElemType *newbase;
		newbase = (ElemType*)realloc(L->elem,(L->listsize+INCRESE)*sizeof(ElemType));
		L->elem = newbase;
		L->listsize += INCRESE;
	}
	ElemType *p,*q;
	q = &(L->elem[i-1]);
	for(p=&(L->elem[L->length-1]);p>=q;--p)
		*(p+1)=*p;
	*q = e;
	++L->length;
	return OK;
}




int main(){
	Sqlist La,Lb,Lc;
	int i=1;
//	ElemType num = 0;
	ElemType num = '0';		//if it misunderstand you,rename it char

	Initlist(&La);
	Initlist(&Lb);
	
	printf("plsase input LIST A,q to end\n");
	while(1){
		scanf("%c",&num);
		if(num == 'q' ||num =='Q')
			break;
		Insertlist(&La,i,num);
		i++;
	}
//	Sortlist(&La);
	Showlist(&La);

	i = 1;
	printf("please input LIST B,q to end\n");
	while(1){
//		scanf("%d",&num);
		scanf("%c",&num);
		if(num == 'q' ||num =='Q')
			break;
		Insertlist(&Lb,i,num);
		i++;
	}
//	Sortlist(&Lb);
	Showlist(&Lb);
/*
	printf("IS THERE any element you want to delete from list b,enter the positon,0 means no action\n");
	int n;
	scanf("%d",&n);
	if(n=0)
		return 0;
	else
		Deletelist(&Lb,n);
	Showlist(&Lb);
*/

	Mergelist(La,Lb,&Lc);
//	printf("MERGE DONE!\n");
//	Showlist(&Lc);
	return 0;
}
