#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool hash[3][100009];
int n,m;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int num;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num);
		hash[0][num%100003]=hash[1][num%100007]=hash[2][num%100009]=true;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&num);
		if(hash[0][num%100003]&&hash[1][num%100007]&&hash[2][num%100009])
			printf("YES\n");
		else
			printf("NO\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

