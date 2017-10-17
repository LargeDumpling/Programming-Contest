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
struct jp *null;
struct jp
{
	char data;
	jp* next;
}*head,*tail,*inspos;
void clear()
{
	for(jp *cur=head->next,*t;cur!=NULL;cur=t)
	{
		t=cur->next;
		delete cur;
	}
	return;
}
void print()
{
	for(jp *cur=head->next,*t;cur!=NULL;cur=t)
	{
		t=cur->next;
		putchar(cur->data);
		delete cur;
	}
	putchar('\n');
	head=new jp;
	head->data=0;
	head->next=NULL;
	inspos=tail=head;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("again.out","w",stdout);
	head=new jp;
	head->data=0;
	head->next=NULL;
	inspos=tail=head;
	char ch;
	while(true)
	{
		ch=getchar();
		if(ch=='\n') print();
		else if(ch==-1) break;
		else if(ch=='[') inspos=head;
		else if(ch==']') inspos=tail;
		else
		{
			jp *newnode=new jp;
			newnode->data=ch;
			newnode->next=inspos->next;
			inspos->next=newnode;
			if((inspos=newnode)->next==NULL) tail=inspos;
		}
	}
	if(head->next!=NULL) print();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

