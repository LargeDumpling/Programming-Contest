#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
int n,root,op,x,ed;
int ch[100010][2],w[100010],s[100010],c[100010],r[100010];
void maintain(int k)
{
    if(k)s[k]=c[k]+s[ch[k][0]]+s[ch[k][1]];
}
void rotate(int &k,int d)
{
    int p=ch[k][d^1];
    ch[k][d^1]=ch[p][d];
    ch[p][d]=k;
    s[p]=s[k];
    maintain(k),k=p;
}
void add(int &k,const int &x)
{
    if(!k)
    {
        k=++ed,w[k]=x,r[k]=rand(),s[k]=c[k]=1,ch[k][0]=ch[k][1]=0;
        return;
    }
    s[k]++;
    if(x==w[k]){c[k]++;return ;}
    int d=x>w[k];
    add(ch[k][d],x);
    if(r[ch[k][d]]<r[k])rotate(k,d^1);
}
bool del(int &k,const int &x)
{
    if(!k)return 0;
    if(x==w[k])
    {
        if(c[k]>1){c[k]--,s[k]--;return 1;}
        if(!ch[k][0]){k=ch[k][1];return 1;}
        if(!ch[k][1]){k=ch[k][0];return 1;}
        if(r[ch[k][0]]<r[ch[k][1]])rotate(k,1);
        else rotate(k,0);
        return del(k,x);
    }
    int d=x>w[k];
    if(del(ch[k][d],x))
    {
        s[k]--;
        return 1;
    }
    else return 0;
}
int findrank(int k,const int &x)
{
    if(!k)return 0;
    int pp=(ch[k][0]?s[ch[k][0]]:0);
    if(x==w[k])return pp+1;
    if(x>w[k])return pp+c[k]+findrank(ch[k][1],x);
    return findrank(ch[k][0],x);
}
int findwei(int k,const int &x)
{
    if(!k)return 0;
    int pp=(ch[k][0]?s[ch[k][0]]:0);
    if(x<=pp)return findwei(ch[k][0],x);
    if(x>pp+c[k])return findwei(ch[k][1],x-pp-c[k]);
    return w[k];
}
void findqian(int k,const int &x,int &ans)
{
    if(!k)return ;
    if(x>w[k])ans=w[k],findqian(ch[k][1],x,ans);
    else findqian(ch[k][0],x,ans);
}
void findhou(int k,const int &x,int &ans)
{
    if(!k)return ;
    if(x<w[k])ans=w[k],findhou(ch[k][0],x,ans);
    else findhou(ch[k][1],x,ans);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("HG.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&op,&x);
        if(op==1)add(root,x);
        else if(op==2)del(root,x);
        else if(op==3)printf("%d\n",findrank(root,x));
        else if(op==4)printf("%d\n",findwei(root,x));
        else if(op==5)
        {
            int pp=0;
            findqian(root,x,pp);
            printf("%d\n",pp);
        }
        else
        {
            int pp=0;
            findhou(root,x,pp);
            printf("%d\n",pp);
        }
    }
    return 0;
}
