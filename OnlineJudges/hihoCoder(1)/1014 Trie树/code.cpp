#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ch[1000050][26],sum[1000050],sz=0;
struct jp *null;
struct jp
{
	int data,cnt;
	jp *son,*next;
	jp()
	{
		data=cnt=0;
		son=next=null;
	}
}*root;
/*
void insert(char tex[])
{
    int lenth=strlen(tex),u=0;
    for(int i=0;i<lenth;sum[u]++,u=ch[u][tex[i++]-97])
        if(!ch[u][tex[i]-97])
            ch[u][tex[i]-97]=++sz;
    return;
}
*/
void insert(char *tex)
{
	int lenth=strlen(tex);
	jp* u=root,*temp;
	for(int i=0;i<lenth;i++)
	{
		temp=null;
		for(temp=u->son;temp!=null;temp=temp->next)
			if(temp->data==tex[i]-97)
				break;
		if(temp==null)
		{
			temp=new jp();
			temp->data=tex[i]-97;
			temp->next=u->son;
			u->son=temp;
		}
		u->cnt++;
		u=temp;
	}
	u->cnt++;
	return;
}
/*	
int query(char tex[])
{
    int lenth=strlen(tex),u=0;
    for(int i=0;i<lenth;u=ch[u][tex[i++]-97])
        if(!ch[u][tex[i]-97])
            return 0;
    return sum[u];
}
*/
int query(char *tex)
{
	int lenth=strlen(tex);
	jp *u=root,*temp;
	for(int i=0;i<lenth;i++)
	{
		temp=null;
		for(temp=u->son;temp!=null;temp=temp->next)
			if(temp->data==tex[i]-97)
				break;
		if(temp==null)
			return 0;
		u=temp;
	}
	return u->cnt;
}
int main()
{
	null=new jp();
	null->son=null->next=null;
	root=new jp();
    int n;
    char tex[15];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",tex);
        insert(tex);
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",tex);
        printf("%d\n",query(tex));
    }
    return 0;
}

