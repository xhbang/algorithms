#include <stdio.h>
#include <stdlib.h>

#define INITSIZE 50

void sort(int a[],int n){
	for(int i=0;i<n;i++)
		for(int j=i+1;i<n;i++)
			if(a[i]>a[j]){
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[j]=a[i]-a[j];
			}
}

void print(int a[],int n){
	for(int i=0;i<n;i++)
		printf("3d",a[i]);
	printf("\n");
}

int main(){
	int a[INITSIZE];
	srand(time(NULL));
	for(int i=0;i<INITSIZE;i++)
		a[i]=srand();
	sort(a,INITSIZE);
	print(a,INITSIZE);

	return 0;
}
