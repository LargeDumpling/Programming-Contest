#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int num[200000],n,k;
void swap(int &a,int &b)
{
	if(a==b)
		return;
	a+=b;
	b=a-b;
	a=a-b;
	return;
}
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	n=rand()%10+1;
//	n=200000;
	k=(1LL*rand()*rand())%20+1;
//	k=1000000;
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;i++)
		num[i]=i-1;
	for(int i=n-1;i;i--)
	{
		swap(num[i],num[(rand()%i)+1]);
		printf("%d %d %d\n",num[i],num[rand()%(n-i)+i+1],rand()%k);
	}
	fclose(stdout);
	return 0;
}

