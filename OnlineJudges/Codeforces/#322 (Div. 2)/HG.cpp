#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<ctime>
using namespace std;
int n,a[100010],b[100010],sum,s,k;
int main()
{
	freopen("code.in","r",stdin);
	freopen("HG.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=10-(a[i]%10);
		sum+=a[i]/10;
		a[i]/=10;
	}
	sort(b+1,b+n+1);
	bool bo=1;
	while(bo)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<10)
			{
				k-=b[i],b[i]=10,a[i]++;
				if(k==0)
				{
					sum++;
					bo=0;
					break;
				}
				else if(k<0)
				{
					bo=0;
					break;
				}
				else if(k>0)
				{
					sum++;
					continue;
				}
			}
			else if(sum==n*10)
			{
				bo=0;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}

