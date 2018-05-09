#include<stdio.h>
int main()
{
	int x,num[3]={2,3,5},flag[3]={0,0,0};
	int i;
	scanf("%d",&x);
	for(i=0;i<3;i++)
		flag[i]=x%num[i];
	for(i=0;i<3;i++) if(flag[i])
		printf("Can't be divided by %d\n",num[i]);
	return 0;
}

