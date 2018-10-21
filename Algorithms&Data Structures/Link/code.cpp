/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Node
{
	int data;
	Node *nxt,*pre;
	Node()
	{
		data=0;
	}
	Node(int D,Node *N)
	{
		data=D;
		nxt=N;
	}
}*head,*tail;
int size;
void init()
{
	head=new Node();
	tail=new Node();
	head->pre=head;
	size=0;
	return;
}
void print()
{// output the elements in the link
	puts("\nLink:");
	for(Node *u=head;u!=NULL;u=u->nxt)
		if(u!=head)
			printf("%d ",u->data);
	putchar('\n');
	return;
}
void insert(const int &x)
{// insert interger x at the end of the link
	tail->nxt=new Node(x,NULL);
	tail=tail->nxt;
	size++;
	return;
}
void insert(const int &x,int rk)
{// insert interger x into the link and let it be the (rk)th element
	if(rk==0||size+1<rk)
	{
		puts("\nInvalid insert position!");
		return;
	}
	Node *u=head;
	while(rk)
	{
		rk--;
		if(!rk) u->nxt=new Node(x,u->nxt);
		u=u->nxt;
	}
	size++;
	return;
}
void del(int rk)
{
	if(rk==0||size<rk)
	{
		puts("\nInvalid insert position!");
		return;
	}
	Node *u=head;
	while(rk)
	{
		rk--;
		if(!rk)
		{
			Node *tem=u->nxt;
			u->nxt=tem->nxt;
			delete tem;
		}
		u=u->nxt;
	}
	size--;
	return;
}
void delx(int x)
{
	for(Node *u=&head;u->nxt!=NULL;u=u->nxt)
		if((u->nxt)->data==x)
		{
			Node *tem=u->nxt;
			u->nxt=tem->nxt;
			delete tem;
			break;
		}
	return;
}
bool exist(int &x)
{
	for(Node *u=head;u!=NULL;u=u->nxt)
		if(u!=head&&u->data==x)
			return true;
	return false;
}
/*
 * For ex2_1
 * 		(1)
 * 			int x;
 * 			init();
 * 			for(int i=1;i<=5;i++)
 * 			{
 * 				scanf("%d",&x);
 * 				insert(x);
 * 			}
 * 			print();
 * 		(2) **You should make sure you have read the node I write after
 * 		the definition of the funtion insert().
 * 			int x,p;
 *			puts("\nPlease input the element x and the position");
 * 			scanf("%d%d",&x,&p);
 * 			insert(x,p);
 * 			print();
 * 		(3) **You should make sure you have read the node I write after
 * 		the definition of the funtion insert().
 * 			int p;
 *			puts("\nPlease input the position of the element you want to delete");
 * 			scanf("%d",&p)
 * 			del(p);
 * 			print();
 * For ex2_2	
 * 		(1)
 * 			init();
 * 			int x;
 * 			while(true)
 * 			{
 * 				scanf("%d",&x);
 * 				if(!x) break;
 * 				insert(x);
 * 			}
 * 			print();
 * 		(2)
 * 			int x;
 * 			puts("\nBefore");
 * 			print();
 * 			if(exist(x)) del(x);
 * 			else insert(x);
 * 			puts("\nAfter");
 * 			print();
 */
int main()
{
	init();
 	int x;
  	while(true)
  	{
  		scanf("%d",&x);
  		if(!x) break;
  		insert(x);
  	}
	print();
	while(true)
	{
		scanf("%d",&x);
		puts("\nBefore");
		print();
		if(exist(x)) delx(x);
		else insert(x);
		puts("\nAfter");
		print();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

