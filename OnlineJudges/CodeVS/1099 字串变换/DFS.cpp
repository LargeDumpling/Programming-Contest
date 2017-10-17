#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;//16:47
char A[205],B[205],rule[6][2][25];
int rn,ans=11,Lenth[6][2];
bool query(char *T,int pos,char *tex)
{
	int i;
	for(i=0;tex[i]!='\0'&&T[pos+i]==tex[i];i++);
	if(tex[i]=='\0')
		return true;
	return false;
}
int sTrlen(char *T)
{
	int len=0;
	while(*(T+len)!='\0')len++;
	return len;
}
void sTrmov(char *texa,char t[])
{
	for(int i=0;t[i]!='\0';i++)
		*(texa++)=t[i];
	*(texa++)='\0';
	return;
}
void DFS(char T[],int step)
{
	if(step>=ans)
		return;
	if(query(T,0,B))
		ans=step;
	int Len=sTrlen(T);
	char temp[205];
	for(int i=0;i<Len;i++)
	{//枚举在某一位进行替换
		for(int j=0;j<rn;j++)
		{//枚举在该位是否可能
			if(query(T,i,rule[j][0]))
			{//若匹配则进行替换
				sTrmov(temp,T);
				sTrmov(temp+i,rule[j][1]);
				sTrmov(temp+i+Lenth[j][1],T+i+Lenth[j][0]);
				DFS(temp,step+1);
			}
		}
	}
	return;
}
int main()
{
	scanf("%s%s",A,B);
	for(rn=0;scanf("%s%s",rule[rn][0],rule[rn][1])!=-1;rn++)
	{
		Lenth[rn][0]=sTrlen(rule[rn][0]);
		Lenth[rn][1]=sTrlen(rule[rn][1]);
	}
	DFS(A,0);
	if(ans==11)
		printf("NO ANSWER!");
	else
		printf("%d",ans);
	return 0;
}

