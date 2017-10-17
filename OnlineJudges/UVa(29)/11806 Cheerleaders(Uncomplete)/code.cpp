#include<iostream>
#define min(a,b) (a<b?a:b)
using namespace std;
const int mod=1000007;
int T,n,m,k,ans,C[550][550],r,c,now;
int main()
{
	scanf("%d",&T);
	C[0][0]=1;
	for(int i=1;i<=450;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(long long)(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int t=1;t<=T;t++)
	{
		ans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<16;i++)
		{
			r=n;
			c=m;
			now=0;
			if(i&1)
				r--,now++;
			if(i&2)
				r--,now++;
			if(i&4)
				c--,now++;
			if(i&8)
				c--,now++;
			if(now&1)
				ans=(long long)(ans+mod-C[r*c][k])%mod;
//				ans=(long long)(ans+mod-C[r*c][min(r*c,k)]);
			else
				ans=(long long)(ans+C[r*c][k])%mod;
//				ans=(long long)(ans+C[r*c][min(r*c,k)]);
		}
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}

