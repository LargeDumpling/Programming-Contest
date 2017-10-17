#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int n=rand()%30000+1,num[300050],m;
	for(int i=1;i<=n;i++)num[i]=i;
	printf("%d\n",n);
	for(int i=n-1;i;i--)
	{
		swap(num[rand()%i+1],num[i]);
		swap(num[rand()%(n-i)+i+1],num[i+1]);
		printf("%d %d\n",num[i],num[i+1]);
	}
	for(int i=1;i<=n;i++)printf("%d ",rand());
	printf("\n");
	printf("%d\n",m=rand()%30000+1);
	for(int i=1,t;i<=m;i++)
	{
		t=rand()%3;
		if(t==0)
			printf("CHANGE %d %d\n",rand()%n+1,rand());
		else if(t==1)
			printf("QMAX %d %d\n",rand()%n+1,rand()%n+1);
		else if(t==2)
			printf("QSUM %d %d\n",rand()%n+1,rand()%n+1);
	}
	fclose(stdout);
	return 0;
}

