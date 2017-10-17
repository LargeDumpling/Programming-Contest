/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,len1,len2;
int num1[62550],num2[62550],m[62550];
int s[62550];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		scanf("%d%d%d",&n,&len1,&len2);
		len1++; len2++;
		memset(m,0,sizeof(m));
		for(int i=1;i<=len1;i++)
		{
			scanf("%d",&num1[i]);
			m[num1[i]]=i;
		}
		s[0]=0;
		for(int i=1;i<=len2;i++)
		{
			scanf("%d",&num2[i]);
			num2[i]=m[num2[i]];
			if(!s[0]||s[s[0]]<num2[i])
				s[++s[0]]=num2[i];
			else if(s[0]&&num2[i]<s[s[0]])
				*lower_bound(s+1,s+s[0]+1,num2[i])=num2[i];
		}
		printf("Case %d: %d\n",cAse,s[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

