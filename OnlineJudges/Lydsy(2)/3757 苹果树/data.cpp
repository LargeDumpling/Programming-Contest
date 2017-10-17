/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit Question() () () () () () () () () () () () () () () () () () () () () () () () () () () () () () () () () () ():
	2016-02-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int Rand()
{
	return 1LL*rand()*rand()%100000000;
}
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x,n,m,cn,num[100050],a,b; sscanf(argv[1],"%d",&x);
	srand(x);
	//n=Rand()%50000+1;
	//m=Rand()%100000+1;
	n=50000;
	m=100000;
	cn=n;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) printf("%d ",rand()%cn+1);
	//num[0]=rand()%n+1;
	//printf("\n0 %d\n",num[0]);
	//for(int i=1;i<=n;i++) num[i]=i;
	for(int i=1;i<=n;i++) printf("%d %d\n",i-1,i);
	/*for(int i=n-1;i;i--)
	{
		swap(num[i],num[rand()%i+1]);
		swap(num[i+1],num[i+rand()%(n-i)+1]);
		printf("%d %d\n",num[i],num[i+1]);
	}*/
	for(int i=1;i<=m;i++)
	{
		if(rand()&2)
			a=b=0;
		else
		{
			do
			{
				a=rand()%cn+1;
				b=rand()%cn+1;
			}while(a==b);
		}
		printf("%d %d %d %d\n",rand()%n+1,rand()%n+1,a,b);
	}
	fclose(stdout);
	return 0;
}

