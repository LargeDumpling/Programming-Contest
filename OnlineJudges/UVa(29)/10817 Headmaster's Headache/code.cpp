/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
struct jp
{
	int salary,sour;
	jp(int A=0,int B=0):salary(A),sour(B){}
}tea[125];
const int INF=2147483647>>1;
int S,M,N,f[125][256][256];
int dp(int x,int s0,int s1,int s2)
{
	if(x==M+N)return f[x][s1][s2]=(s2==(1<<S)-1?0:INF);
	if(f[x][s1][s2]!=-1)return f[x][s1][s2];
	int &ans=f[x][s1][s2]=INF;
	if(x>=M)ans=dp(x+1,s0,s1,s2);
	int m0=s0&tea[x+1].sour,m1=s1&tea[x+1].sour;
	s0^=m0;s1=(s1^m1)|m0;s2|=m1;
	ans=min(ans,dp(x+1,s0,s1,s2)+tea[x+1].salary);
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int temp;
	string line;
	stringstream in;
	while(getline(cin,line))
	{
		in.clear();
		in.str(line);
		in>>S>>M>>N;
		if(!S&&!M&&!N)break;
		memset(f,-1,sizeof(f));
		for(int i=1;i<=M+N;i++)
		{
			getline(cin,line);
			in.clear();
			in.str(line);
			in>>tea[i].salary;
			tea[i].sour=0;
			while(in>>temp)
				tea[i].sour|=(1<<(temp-1));
		}
		printf("%d\n",dp(0,(1<<S)-1,0,0));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

