#include<stdio.h>
int a[10][12],b[12][10];
int main()
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			scanf("%d",&a[i][j]);
			b[j][i]=a[i][j];
		}
	return 0;
}

