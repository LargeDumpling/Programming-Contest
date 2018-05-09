#include<stdio.h>
int num[21];
void swap(int *a,int *b)
{
	*a^=*b;
	*b=*a^*b;
	*a=*a^*b;
	return;
}
int main()
{
	int i,j;
	for(i=0;i<20;i++)
		scanf("%d",&num[i]);
	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
			if(num[j+1]<num[j])
				swap(&num[j],&num[j+1]);
	scanf("%d",&num[20]);
	for(i=20;i;i--)
		if(num[i]<num[i-1])
			swap(&num[i],&num[i-1]);
	for(i=0;i<21;i++)
		printf("%d ",num[i]);
	return 0;
}

