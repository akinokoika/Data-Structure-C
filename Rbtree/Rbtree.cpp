#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum colortype {red, black} colortype;
typedef enum rotatetype {ll, rr} rotatetype;

typedef struct node
{
	int data;
	struct node * left;
	struct node * right;
	struct node * parent;
	colortype color;
}rbnode;

typedef rbnode * rbtree;

rbnode *root;

rbtree nullnode = NULL;

rbtree init()
{	
	root = (rbnode *)malloc(sizeof(rbnode));
	root->data = -1;
	root->parent = root->left = root->right = nullnode;
	root->color = black;
	return root;
}

rbtree rotate(rbnode *kg, rotatetype direction)
{
	rbnode *kf, *kgf;
	
	if(direction == ll)
	{
		kf = kg->right;
		kg->right = kf->left;
		if(kf->left != nullnode)
		{
			kf->left->parent = kg;
		}
		kf->left = kg;
	}
	if(direction == rr)
	{
		kf = kg->left;
		kg->left = kf->right;
		if(kf->right != nullnode)
		{
			kf->right->parent = kg;
		}
		kf->right = kg;
	}
	
	if(kg->parent == kg)
	{
		kf->parent = kf;
		kg->parent = kf;	
	}
	else
	{
		kgf = kg->parent;
		if(kgf->left == kg)
		{
			kgf->left = kf;
		}
		if(kgf->right == kg)
		{
			kgf->right = kf;
			
		}
		kf->parent = kgf;
		kg->parent = kf;
		
		while(kf->parent != kf)
		{
			kf = kf->parent; 
		}
	}
	
	return kf;
}

rbtree insert(int x, rbtree root)
{
	rbnode *h, *f, *g, *u, *p;
	
	if(root->parent == nullnode)
	{
		root->data = x;
		root->parent = root;
		return root;
	}
	
	h = (rbnode *)malloc(sizeof(rbnode));
	h->data = x;
	h->left = h->right = nullnode;
	h->color = red;
	
	p = root;
	while(1)
	{
		if(x < p->data)
		{
			if(p->left == nullnode)
			{
				p->left = h;
				h->parent = p;
				break;
			}
			else
			{
				p = p->left;
			}
		}
		if(x > p->data)
		{
			if(p->right == nullnode)
			{
				p->right = h;
				h->parent = p;
				break;
			}
			else
			{
				p = p->right;
			}
		}
		if(x == p->data)
		{
			free(h);
			return root;
		}
	}
	
	while(1)
	{
		f = h->parent;
		if(f == h)
		{
			h->color = black;
		}
		if(f->color == black)
		{
			break;
		}
		if(f->color == red)
		{
			g = h->parent->parent;
			if(g->left == f)
			{
				u = g->right;
			}
			if(g->right == f)
			{
				u = g->left;
			}
			
			if(u == nullnode || u->color == black)
			{
				if(g->right == f && f->right == h)
				{
					root = rotate(g, ll);
					f->color = black;
					g->color = red;
					break;
				}
				if(g->left == f && f->left == h)
				{
					root = rotate(g, rr);
					f->color = black;
					g->color = red;
					break;
				}
				if(g->right == f && f->left == h)
				{
					root = rotate(f, rr);
					root = rotate(g, ll);
					h->color = black;
					g->color = red;
					break;
				}
				if(g->left == f && f->right == h)
				{
					root = rotate(f, ll);
					root = rotate(g, rr);
					h->color = black;
					g->color = red;
					break;
				} 
			}
			
			if(u->color == red)
			{
				f->color = u->color = black;
				g->color = red;
				h = g;
			}
		}
	}

	return root;
}

rbtree findnode(int x, rbnode *ft)
{
	rbnode *fn = ft;
	while(1)
	{
		if(fn == nullnode)
		{
			return fn;
		}
		if(x > fn->data)
		{
			fn = fn->right;
		}
		if(x < fn->data)
		{
			fn = fn->left;
		}
		if(x == fn->data)
		{
			break;
		}
	}
	return fn;
}

rbtree nextnode(rbnode *r)
{
	if(r->right == nullnode)
	{
		while(r != r->parent->left)
		{
			r = r->parent;
		}
		r = r->parent;
	}
	else
	{
		r = r->right;
		while(r->left != nullnode)
		{
			r = r->left;
		}
	}
	return r;
}

rbtree del(int x, rbtree root)
{
	rbnode *p, *r, *f, *b, *c;
	
	p = findnode(x, root);
	if(p == nullnode)
	{
		return root;
	}
	if(p->left != nullnode && p->right != nullnode)
	{
		r = nextnode(p);
		p->data = r->data;
		p = r;
	}
	else if(p->left != nullnode || p->right !=nullnode)
	{
		if(p->left != nullnode)
		{
			p->data = p->left->data;
			p = p->left;
		}
		else if(p->right != nullnode)
		{
			p->data = p->right->data;
			p = p->right;
		}
	}
	if(p->color == black)
	{
		f = p->parent;
		if(f->left == p)
		{
			b = f->right;
			if(b->color == red)
			{
				b->color = black;
				b->left->color = red;
				root = rotate(f, ll);
			}
			if(b->color == black)
			{
				if(b->left != nullnode && b->right == nullnode)
				{
					b->left->color = black;
					b->color = red;
					root = rotate(b, rr);
					b = f->right;
				}
				if((b->left != nullnode && b->right != nullnode) || (b->right != nullnode))
				{
					b->color = f->color;
					f->color = b->right->color = black;
					root = rotate(f, ll);
				}
				if(b->left == nullnode && b->right == nullnode)
				{
					if(f->color == red)
					{
						f->color = black;
						b->color = red;
					}
					else if(f->color == black)
					{
						b->color = red;
						if(f->parent->left == f)
						{
							b = f->parent->right;
						}
						if(f->parent->right == f)
						{
							b = f->parent->left;
						}
						b->color = red;
					}
				}
			}
		}
		if(f->right == p)
		{
			b = f->left;
			if(b->color == red)
			{
				b->color = black;
				b->right->color = red;
				root = rotate(f, rr);
			}
			if(b->color == black)
			{
				if(b->right != nullnode && b->left == nullnode)
				{
					b->right->color = black;
					b->color = red;
					root = rotate(b, ll);
					b = f->left;
				}
				if((b->left != nullnode && b->right != nullnode) || (b->left != nullnode))
				{
					b->color = f->color;
					f->color = b->left->color = black;
					root = rotate(f, rr);
				}
				if(b->left == nullnode && b->right == nullnode)
				{
					if(f->color == red)
					{
						f->color = black;
						b->color = red;
					}
					else if(f->color == black)
					{
						b->color = red;
						if(f->parent->left == f)
						{
							b = f->parent->right;
						}
						if(f->parent->right == f)
						{
							b = f->parent->left;
						}
						b->color = red;
					}
				}
			}
		}
	}
	if(p->parent->left == p)
	{
		p->parent->left = nullnode;
	}
	if(p->parent->right == p)
	{
		p->parent->right = nullnode;
	}
	free(p);
	
	return root; 
}

int vec[22] = {0};
void treeprint(rbtree t, int layer)
{
	if(layer > 0)
	{
		int i;
		for(i=0;i<layer-1;i++)
		{
			printf(vec[i] ? "|   " : "    ");
		}
		printf(vec[layer-1] ? "|----- " : "------ ");
	}
	
	if(!t)
	{
		printf("\n");
		return;
	}
	
	printf("%d(%d)\n",t->data,t->color);
	
	if(!t->left && !t->right)
	{
		return;
	}
	
	vec[layer] = 1;
	treeprint(t->left, layer+1);
	vec[layer] = 0;
	treeprint(t->right, layer+1);
}

int pick = 0;
int dfs(rbnode *n, int arr[])
{
	if(n->color == black && n->parent != n)
	{
		arr[pick]++;
	}
	if(n->left == nullnode && n->right == nullnode)
	{
		pick++;
		return 1;
	}
	if(n->left != nullnode)
	{
		dfs(n->left, arr);
	}
	if(n->right != nullnode)
	{
		dfs(n->right, arr);
	}
}

int m = 0;
int dfspro(rbnode *n, int count[])
{
	if(n->left == nullnode && n->right == nullnode)
	{
		return 1;
	}
	
	int arr[22] = {0};
	pick = 0;
	dfs(n, arr);
	int i, max, min;
	max = min = arr[0];
	for(i=0; arr[i]!=0 ; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
		if(arr[i] < min)
		{
			min = arr[i];
		}
	}
	if(max == min)
	{
		count[m] = arr[0];
	}
	m++;
	
	if(n->left != nullnode)
	{
		dfspro(n->left, count);
	}
	if(n->right != nullnode)
	{
		dfspro(n->right, count);
	}
}

void rbtest(rbtree t)
{
	pick = 0, m = 0;
	int c[22] = {0};
	dfspro(t, c);
	int i, sum = 0;
	printf("\nrbtest : ");
	for(i=0; c[i]!=0 ; i++)
	{
		sum++;
		printf("%d ",c[i]);
	}
	printf("\n\n");
}

int main()
{
	printf("This is red black tree.\n1 is black, 0 is red.\n");
	printf("If the rbtest output is all 1, five characteristics are met.\n\n");
	printf("r b tree init : 1, 2, 3, 4, 5, 6, 7, 8, 9\n");
	rbtree t = init();
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	int i;
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		t = insert(arr[i], t);
	}
	treeprint(t,0);
	
	rbtest(t);
	
	printf("r b tree del : 6\n");
	del(6,t);
	treeprint(t,0);
	rbtest(t);
	
	return 0;
}