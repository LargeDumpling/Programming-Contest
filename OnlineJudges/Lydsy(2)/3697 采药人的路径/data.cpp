#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int num[100050];
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
//	int n=(1LL*rand()*rand())100000+1;
	int n=100000;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		num[i]=i;
	for(int i=n-1;i;i--)
	{
		swap(num[rand()%i+1],num[i]);
		printf("%d %d %d\n",num[i],num[rand()%(n-i)+i+1],rand()%2);
	}
	fclose(stdout);
	return 0;
}

