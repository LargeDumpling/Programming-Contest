#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
unsigned long long ans2=0;
class jp
{
	private:
		char key[4000050];
		int next[4000050];
		int head[4000050];
		int num[4000050],num2[4000050];
		int sz;
		unsigned long long ans;
	public:
		void clear()
		{
			ans=head[0]=next[0]=0;
			memset(num,0,sizeof(num));
			memset(num2,0,sizeof(num2)); 
			sz=1;
		}
		void insert(char T[])
		{
			int lenth=strlen(T),u=0;
			for(int i=0,j;i<lenth;i++,u=j)
			{
				for(j=head[u];j&&key[j]!=T[i];j=next[j]);
				if(!j)
				{
					j=sz++;
					key[j]=T[i];
					head[j]=0;
					next[j]=head[u];
					head[u]=j;
				}
				ans+=num[j]++;
			}
			ans2+=num2[u]++;
		}
		unsigned long long sum()
		{
			return ans;
		}
}Tire;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char tex[1005];
	for(int k=1;;k++)
	{
		scanf("%d",&n);
		ans2=0;
		if(!n)
			break;
		Tire.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex);
			Tire.insert(tex);
		}
		printf("Case %d: %lld\n",k,2*Tire.sum()+(unsigned long long)n*(n-1)/2+ans2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

