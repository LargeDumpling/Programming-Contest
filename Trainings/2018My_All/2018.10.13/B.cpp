/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ch[256];
int T_T,B[3][24],R[7][24];
//fro[24],bac[24],lef[24],rig[24],top[24],bot[24];
#define I   R[0]
#define fro R[1]
#define bac R[2]
#define lef R[3]
#define rig R[4]
#define top R[5]
#define bot R[6]
void multi(int M0[],int M1[],int M2[])
{
	int ans[24];
	for(int i=0;i<24;i++)
		ans[i]=M0[M1[i]];
	memcpy(M2,ans,sizeof(ans));
	return;
}
void pre_calc()
{
	for(int i=0;i<24;i++)
	{
		I[i]=i;
		ch['a'+i]=i;
	}
	memcpy(fro,I,sizeof(I));
	memcpy(bac,I,sizeof(I));
	memcpy(lef,I,sizeof(I));
	memcpy(rig,I,sizeof(I));
	memcpy(top,I,sizeof(I));
	memcpy(bot,I,sizeof(I));
	//turn the front face ninety degree clockwise
	B[0][ch['a']]=ch['d'];
	B[0][ch['b']]=ch['a'];
	B[0][ch['c']]=ch['c'];
	B[0][ch['d']]=ch['b'];
	B[0][ch['e']]=ch['w'];
	B[0][ch['f']]=ch['u'];
	B[0][ch['g']]=ch['g'];
	B[0][ch['h']]=ch['h'];
	B[0][ch['i']]=ch['i'];
	B[0][ch['j']]=ch['j'];
	B[0][ch['k']]=ch['k'];
	B[0][ch['l']]=ch['l'];
	B[0][ch['m']]=ch['m'];
	B[0][ch['n']]=ch['n'];
	B[0][ch['o']]=ch['t'];
	B[0][ch['p']]=ch['r'];
	B[0][ch['q']]=ch['q'];
	B[0][ch['r']]=ch['e'];
	B[0][ch['s']]=ch['s'];
	B[0][ch['t']]=ch['f'];
	B[0][ch['u']]=ch['o'];
	B[0][ch['v']]=ch['v'];
	B[0][ch['w']]=ch['p'];
	B[0][ch['x']]=ch['x'];
	//rotate the left face to be the front face
	B[1][ch['a']]=ch['q'];
	B[1][ch['b']]=ch['r'];
	B[1][ch['c']]=ch['s'];
	B[1][ch['d']]=ch['t'];
	B[1][ch['e']]=ch['g'];
	B[1][ch['f']]=ch['e'];
	B[1][ch['g']]=ch['h'];
	B[1][ch['h']]=ch['f'];
	B[1][ch['i']]=ch['x'];
	B[1][ch['j']]=ch['w'];
	B[1][ch['k']]=ch['v'];
	B[1][ch['l']]=ch['u'];
	B[1][ch['m']]=ch['n'];
	B[1][ch['n']]=ch['p'];
	B[1][ch['o']]=ch['m'];
	B[1][ch['p']]=ch['o'];
	B[1][ch['q']]=ch['l'];
	B[1][ch['r']]=ch['k'];
	B[1][ch['s']]=ch['j'];
	B[1][ch['t']]=ch['i'];
	B[1][ch['u']]=ch['a'];
	B[1][ch['v']]=ch['b'];
	B[1][ch['w']]=ch['c'];
	B[1][ch['x']]=ch['d'];
	//rotate the bottom face to be the front face
	B[2][ch['a']]=ch['e'];
	B[2][ch['b']]=ch['f'];
	B[2][ch['c']]=ch['g'];
	B[2][ch['d']]=ch['h'];
	B[2][ch['e']]=ch['i'];
	B[2][ch['f']]=ch['j'];
	B[2][ch['g']]=ch['k'];
	B[2][ch['h']]=ch['l'];
	B[2][ch['i']]=ch['m'];
	B[2][ch['j']]=ch['n'];
	B[2][ch['k']]=ch['o'];
	B[2][ch['l']]=ch['p'];
	B[2][ch['m']]=ch['a'];
	B[2][ch['n']]=ch['b'];
	B[2][ch['o']]=ch['c'];
	B[2][ch['p']]=ch['d'];
	B[2][ch['q']]=ch['r'];
	B[2][ch['r']]=ch['t'];
	B[2][ch['s']]=ch['q'];
	B[2][ch['t']]=ch['s'];
	B[2][ch['u']]=ch['w'];
	B[2][ch['v']]=ch['u'];
	B[2][ch['w']]=ch['x'];
	B[2][ch['x']]=ch['v'];
	multi(fro,B[0],fro);

	multi(bac,B[1],bac); multi(bac,B[1],bac);
	multi(bac,B[0],bac);
	multi(bac,B[1],bac); multi(bac,B[1],bac);

	multi(lef,B[1],lef);
	multi(lef,B[0],lef);
	multi(lef,B[1],lef); multi(lef,B[1],lef); multi(lef,B[1],lef);

	multi(rig,B[1],rig); multi(rig,B[1],rig); multi(rig,B[1],rig);
	multi(rig,B[0],rig);
	multi(rig,B[1],rig);

	multi(bot,B[2],bot);
	multi(bot,B[0],bot);
	multi(bot,B[2],bot); multi(bot,B[2],bot); multi(bot,B[2],bot);

	multi(top,B[2],top); multi(top,B[2],top); multi(top,B[2],top);
	multi(top,B[0],top);
	multi(top,B[2],top);
	return;
}
bool check(int X[])
{
	for(int i=0;i<24;i+=4)
	{
		if(X[i]==X[i+1]&&X[i+1]==X[i+2]&&X[i+2]==X[i+3]);
		else return false;
	}
	return true;
}
int main()
{
	int st[24],tes[24];
	bool flag;
	pre_calc();
	scanf("%d",&T_T);
	while(T_T--)
	{
		flag=false;
		for(int i=0;i<24;i++)
			scanf("%d",&st[i]);
		for(int i=0;i<7&&!flag;i++)
		{
			multi(st,R[i],tes);
			if(check(tes))
				flag=true;
			multi(tes,R[i],tes);
			multi(tes,R[i],tes);
			if(check(tes))
				flag=true;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

