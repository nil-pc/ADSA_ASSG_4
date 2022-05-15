//dijkstra's algorithm

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	long int key;
	long int label;
	long int wt;
	int vis;
	struct node *par;
	struct node *next;
}node;
node *p,*u,*s;

long int heapsize;

void decrease_key(node* h[],long n,long key)
{
	long i;
	for(i=0;i<heapsize;i++)
	{
		if(h[i]->label==n)
		{
			h[i]->key=key;
			break;
		}
	}
	
	return;
}

void relax(struct node* h[],struct node *p,struct node *q,long w)
{
	if(q->key>(p->key+w))
	{
		q->key=p->key+w;
		decrease_key(h,q->label,p->key+w);
	}
	return;
}

long parent(long i)
{
	if(i%2==1)
	{
		i=(i-1)/2;
	}
	else
	{
		i=(i-2)/2;
	}
	return i;
}


void min_heapify(node* h[],long int n,long int i)
{
	long int l,r,smallest=i;
	l=2*i+1;
	r=2*i+2;
	
	if((l<heapsize) && (h[l]->key<h[i]->key))
		smallest=l;
	else
		smallest=i;
	if((r<heapsize) && (h[r]->key<h[smallest]->key))
		smallest=r;
	if(smallest!=i)
	{
		p=h[i];
		h[i]=h[smallest];
		h[smallest]=p;
		min_heapify(h,n,smallest);
	}
	return;
}


void build_minheap(node* h[],long int n)
{
	long int i;
	for(i=(n-1)/2;i>=0;i--)
	{
		min_heapify(h,n,i);
	}
	
}

void dijkstra(node* a[],long int b,long int n)
{
	long i=0,j=n,z=0;
	node* h[n];
	heapsize=n;
	for(i=0;i<n;i++)
	{
		
		a[i]->key=100000;
		a[i]->vis=0;
		h[i]=a[i];
	}	
	a[b]->key=0;
	h[b]->key=0;
	a[b]->vis=1;
	build_minheap(h,n);
	while(j>0)
	{
		
		u=h[0];
		p=a[u->label]->next;
		while(p!=NULL)
		{
			if(a[p->label]->key>p->wt)
			{
				
				relax(h,a[u->label],a[p->label],p->wt);
			}
			p=p->next;
		}
		h[0]=h[j-1];
		j--;
		heapsize--;
		build_minheap(h,j);
		
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(a[i]->key==100000)
			printf("INF ");
		else
			printf("%ld ",a[i]->key);
	}
	printf("\n");
	return;
}

void dijkstras(node* a[],long int b,long int k,long int n)
{
	long int i=0,j=n,z=0;
	heapsize=n;
	struct node* h[n];
	for(i=0;i<n;i++)
	{
		a[i]->key=100000;
		a[i]->vis=0;
		h[i]=a[i];
	}	
	a[b]->key=0;
	h[b]->key=0;
	a[b]->vis=1;
	build_minheap(h,n);
	while(j>0)
	{
		
		u=h[0];
		p=a[u->label]->next;
		while(p!=NULL)
		{
			if(a[p->label]->key>p->wt)
			{
				relax(h,a[u->label],a[p->label],p->wt);
			}
			p=p->next;
		}
		
		h[0]=h[j-1];
		j--;
		heapsize--;
		build_minheap(h,j);
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(a[i]->label==k)
		{
			if(a[i]->key==100000)
				printf("UNREACHABLE\n");
			else
				printf("%ld\n",a[i]->key);
			return;
		}
	}
	return;
}
	
void main()
{
	long int c,n,k=0,i=0;
	char l;
	scanf("%ld",&n);
	node* a[n];
	heapsize=n;
	for(i=0;i<n;i++)
	{
		p=(node*) malloc(sizeof(node));
		p->label=i;
		p->next=NULL;
		a[i]=p;
	}
	
	scanf("%c",&l);
	for(i=0;i<n;i++)	
	{
		s=a[i];
		scanf("%c",&l);
		while(l!='\n')
		{
			//scanf("%c",&l);
			k=l-48;
			scanf("%c",&l);
			while(l!=32 && l!=10)
			{
				k=k*10+(l-48);
				scanf("%c",&l);
			}
			p=(node*) malloc(sizeof(node));
			p->label=k;
			s->next=p;
			s=p;
			k=0;
			if(l==10)
				break;
			scanf("%c",&l);
		}
		s->next=NULL;
	}
	//scanf("%c",&l);
	for(i=0;i<n;i++)	
	{
		s=a[i]->next;
		scanf("%c",&l);
		while(l!='\n')
		{
			//scanf("%c",&l);
			k=l-48;
			scanf("%c",&l);
			while(l!=32 && l!=10)
			{
				k=k*10+(l-48);
				scanf("%c",&l);
			}
			
			s->wt=k;
			s=s->next;
			k=0;
			if(l==10)
				break;
			scanf("%c",&l);
		}
		
	}
	
	char x[4];
	k=0;
	scanf("%s",x);
	while(strcmp(x,"stop")!=0)
	{
		if(strcmp(x,"apsp")==0)
		{
			
			scanf("%ld",&c);
			dijkstra(a,c,n);
		}
		else if(strcmp(x,"sssp")==0)
		{
			scanf("%ld",&k);
			scanf("%ld",&i);
			dijkstras(a,k,i,n);
		}
		scanf("%s",x);
	}
	return;
}
