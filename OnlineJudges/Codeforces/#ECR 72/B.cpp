/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-09-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=105;
int T_T,n,ans;
long long x,flo[MAXN];
long long besC,besS;
struct blow
{
	long long d,h;
	bool operator<(const blow &X)const
	{
		return (d-h)>(X.d-X.h);
	}
}b[105];
int main()
{
	cin>>T_T;
	while(T_T--)
	{
		cin>>n>>x;
		for(int i=1;i<=n;i++)
		{
			cin>>b[i].d>>b[i].h;
			if(i==1)
			{
				besC=b[i].d-b[i].h;
				besS=b[i].d;
			}
			else
			{
				besC=max(besC,b[i].d-b[i].h);
				besS=max(besS,b[i].d);
			}
		}
		if(x<=besS) ans=1;
		else if(besC<=0) ans=-1;
		else ans=((x-besS)%besC?(x-besS)/besC+1:(x-besS)/besC)+1;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

