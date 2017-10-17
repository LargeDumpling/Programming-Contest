/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	char data;
	jp *next;
}pool[100050],*head,*tail,*inspos,*p;
char tex[100050];
int lenth;
void print()
{
	for(jp *cur=head->next;cur;cur=cur->next) putchar(cur->data);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%s",tex)!=-1)
	{
		lenth=strlen(tex);
		p=pool;
		head=tail=pool;
		head->next=NULL;
		inspos=tail;
		for(int i=0;i<lenth;i++)
		{
			if(tex[i]=='[') inspos=head;
			else if(tex[i]==']') inspos=tail;
			else
			{
				jp* newnode=++p;
				newnode->data=tex[i];
				newnode->next=inspos->next;
				inspos->next=newnode;
				inspos=newnode;
				if(inspos->next==NULL) tail=inspos;
			}
		}
		print();
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

