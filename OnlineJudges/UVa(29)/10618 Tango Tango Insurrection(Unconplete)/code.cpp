/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
map<char,int>pos;
int lenth,f[80][4][4],pre[80][4][4][2],opt[80][4][4];
char str[80];
int abs(int x){return x<0?-x:x;}
int calc_cost(int a,int b)
{
	int ans=abs(a-b);
	if(ans==3)ans=1;
	ans=((ans+1)<<1)+1;
	return ans;
}
bool sKip(int i,int j,int I,int J,int next)
{
	//if((i!=I&&j!=J)||i==j||I==J)return true;//保证只移动一只脚且两脚分开站
	//if((i==3&&j==1)||(I==3&&J==1))return true;//保证不背对屏幕
	if((!i||i==2)&&j==1&&(I!=i))return true;//保证了特殊情况
	if((!j||j==2)&&i==3&&(J!=j))return true;//同上
	if(next!=4&&I!=next&&J!=next)return true;//保证转移后能踩到音符
	if(next!=4&&((I!=next&&i!=I)||(J!=next&&j!=J)))return true;//保证了转移后能踩到音符
	return false;
}
void updata(int k,int i,int j,int I,int J,int x,int o)
{//(k,i,j)->(k+1,I,J)
	if(x<f[k+1][I][J])
	{
		f[k+1][I][J]=x;
		pre[k+1][I][J][0]=i;
		pre[k+1][I][J][1]=j;
		opt[k+1][I][J]=o;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int fin_ans[80],ansi,ansj;
	pos['U']=0;
	pos['L']=1;
	pos['D']=2;
	pos['R']=3;
	pos['.']=4;
	while(true)
	{
		gets(str+1);
		if(str[1]=='#')break;
		lenth=strlen(str+1);
		memset(f,127,sizeof(f));
		f[0][1][3]=0;
		for(int k=0;k<lenth;k++)
		{
			for(int i=0;i<=3;i++)for(int j=0;j<=3;j++)
			{//(k,i,j)->(k+1,I,J)
				if(i==j||(i==3&&j==1)||f[k][i][j]==f[79][3][3])continue;
				for(int I=0;I<=3&&f[k][i][j]!=f[79][3][3];I++)for(int J=0;J<=3;J++)
				{
					if(I==J||(I==3&&J==1))continue;
					if(sKip(i,j,I,J,pos[str[k+1]])||(i!=I&&j!=J))continue;
					if(i==I&&j==J)//left
					{
						if(str[k+1]=='.')
							updata(k,i,j,I,J,f[k][i][j]+1,0);
						else updata(k,i,j,I,J,f[k][i][j]+3,pos[str[k+1]]==J?1:-1);
					}
					if(i!=I)
						updata(k,i,j,I,J,f[k][i][j]+calc_cost(i,I),-1);
					if(j!=J)
						updata(k,i,j,I,J,f[k][i][j]+calc_cost(j,J),1);
				}
			}
		}
		ansi=0;ansj=1;
		for(int i=0;i<=3;i++)for(int j=0;j<=3;j++)
		{
			if(i==j||(i==3&&j==1))continue;
			if(f[lenth][i][j]<f[lenth][ansi][ansj])ansi=i,ansj=j;
		}
		fin_ans[0]=0;
		for(int i=lenth;i;i--)
		{
			fin_ans[++fin_ans[0]]=opt[i][ansi][ansj];
			ansi=pre[i][ansi][ansj][0];
			ansj=pre[i][ansi][ansj][1];
		}
		for(int i=1;i<=lenth;i++)
			if(!fin_ans[i])putchar('.');
			else if(fin_ans[i]<0)putchar('L');
			else putchar('R');
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

