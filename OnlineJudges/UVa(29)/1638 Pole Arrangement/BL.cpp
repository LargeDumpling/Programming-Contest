/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int n,l,r,T,s[25];
	long long ans;
	bool left,right;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&l,&r);
		vector<int>sta;
		for(int i=0;i<n;i++)sta.push_back(i);
		ans=0;
		do
		{
			s[0]=0;
			left=right=false;
			for(int i=0;i<n;i++)if(!s[0]||sta[i]>s[s[0]])s[++s[0]]=sta[i];
			if(s[0]==l)left=true;
			s[0]=0;
			for(int i=n-1;i>=0;i--)if(!s[0]||sta[i]>s[s[0]])s[++s[0]]=sta[i];
			if(s[0]==r)right=true;
			if(left&&right)ans++;
		}while(next_permutation(sta.begin(),sta.end()));
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

