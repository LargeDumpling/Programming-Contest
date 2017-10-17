#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int n;
map<int,int>f;
queue<int>te,m[1050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[10];
	int t,temp,ft;
	for(int k=1;;k++)
	{
		scanf("%d",&n);
		if(!n)
			break;
		printf("Scenario #%d\n",k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			for(int j=1;j<=t;j++)
			{
				scanf("%d",&temp);
				f[temp]=i;
			}
		}
		while(true)
		{
			scanf("%s",tex);
			if(tex[0]=='S')
			{
				f.clear();
				while(te.size())te.pop();
				for(int i=1;i<=n;i++)while(m[i].size())m[i].pop();
				break;
			}
			else if(tex[0]=='E')
			{
				scanf("%d",&t);
				ft=f[t];
				if(!m[ft].size())
					te.push(ft);
				m[ft].push(t);
			}
			else if(tex[0]=='D')
			{
				ft=te.front();
				printf("%d\n",m[ft].front());
				m[ft].pop();
				if(!m[ft].size())
					te.pop();
			}
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

