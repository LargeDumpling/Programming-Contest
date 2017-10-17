#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n,num[305];
void swap(int &A,int &B)
{
	A^=B;
	B=A^B;
	A^=B;
	return;
}
int calc()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(num[i]>num[j])
				cnt++;	
	return cnt;
}
int main()
{
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int cnt,ans=0;
	srand(time(NULL));
	while(true)
	{
		n=rand()%10+1;
		for(int i=1;i<=n;i++)num[i]=i;
		for(int i=1;i<=n;i++)swap(num[rand()%n+1],num[rand()%n+1]);
		cnt=ans=0;
		cnt=calc();
		while(cnt)
		{
			if(num[1]>num[2])
			{
				swap(num[1],num[2]);
				ans++;
				cnt--;
			}
			if(cnt)
			{
				for(int i=0;i<n;i++)swap(num[i],num[i+1]);
				swap(num[0],num[n]);
				cnt=calc();
				ans++;
			}
			printf("%d\n",cnt);
		}
		if(ans<=((n*n)<<1))
			printf("Yes\n");
		else
			printf("No\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

