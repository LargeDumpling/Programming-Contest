#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,num[100050],ans=0;
bool cnmp(int a,int b){return (10-(a%10))<(10-(b%10));}
int main()
{
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	int st;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		ans+=num[i]/10;
	}
	sort(num+1,num+n+1,cnmp);
	for(int i=1;i<=n&&k>0;i++)
		if(k>=(10-num[i]%10)&&num[i]!=100)
		{
			ans++;
			k-=(10-num[i]%10);
			num[i]+=(10-num[i]%10);
		}
	for(int i=1;i<=n&&k>0;i++)
		if(num[i]!=100)
		{
			if(k/10<=(100-num[i])/10)
			{
				ans+=k/10;
				k=0;
			}
			else if(k/10>(100-num[i])/10)
			{
				ans+=(100-num[i])/10;
				k-=(100-num[i]);
			}
		}
	printf("%d",ans);
    return 0;
}

