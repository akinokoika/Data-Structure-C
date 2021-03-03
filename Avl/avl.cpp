#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

struct avlnode;
typedef struct avlnode *position;
typedef struct avlnode *avltree;

struct avlnode
{
	DataType element;
	avltree left;
	avltree right;
	int height;
};

DataType height(position p)
{
	if(p==NULL)
		return -1;
	else
		return p->height;
}

DataType max(position x, position y)
{
    return height(x) > height(y) ? height(x): height(y);
}

position single_left(position k2)
{
	position k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	
	k2->height = max(k2->left, k2->right) + 1;
	k1->height = max(k2, k1->left) + 1;
	
	return k1;
}

position single_right(position k2)
{
	position k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	
	k2->height = max(k2->left, k2->right) + 1;
	k1->height = max(k2, k1->right) + 1;
	
	return k1;
}

position double_left(position k3)
{
	k3->left = single_right(k3->left);
	
	return single_left(k3);
}

position double_right(position k3)
{
	k3->right = single_left(k3->right);
	
	return single_right(k3);
}

avltree insert(DataType x, avltree t)
{
	if(t==NULL)
	{
		t = (avltree)malloc(sizeof(struct avlnode));
		t->element = x;
		t->left = t->right = NULL;
		t->height = 0;
	}
	else if(x < t->element)
	{
		t->left = insert(x,t->left);
		if(height(t->left) - height(t->right) == 2)
		{
			if(x < t->left->element)
				t = single_left(t);
			else
				t = double_left(t);
		}
	}
	else if(x > t->element)
	{
		t->right = insert(x,t->right);
		if(height(t->right) - height(t->left) == 2)
		{
			if(x > t->right->element)
				t = single_right(t);
			else
				t = double_right(t);
		}
	}
	
	t->height = max(t->left, t->right) + 1;
	return t;
}

void preorder(avltree t)
{
	if(t!=NULL)
	{
		printf("data = %d, height = %d\n", t->element, t->height);
		preorder(t->left);
		preorder(t->right);
	}
}

void display(avltree root, int ident, int vec_left[])
{
    if(ident > 0)
    {
    	int i;
        for(i=0; i<ident-1; ++i)
        {
            printf(vec_left[i] ? "|   " : "    ");
        }
        printf(vec_left[ident-1] ? "|------ " : "------ ");
    }

    if(! root)
    {
        printf("(null)\n");
        return;
    }

    printf("%d(%d)\n", root->element, root->height);
    if(!root->left && !root->right)
    {
        return;
    }

    vec_left[ident] = 1;
    display(root->left, ident + 1,vec_left);
    vec_left[ident] = 0;
    display(root->right, ident + 1,vec_left);
}

void set_zero(int vec_left[])
{
	int i;
	for(i=0; i<sizeof(vec_left)/sizeof(vec_left[0]); i++)
		vec_left[i] = 0;
}

int main()
{
	printf("This is adelson velsky and landis tree.\n\n");
	printf("Init from 1 to 9.\n\n");
	avltree t = NULL;
	DataType v;
	/* defaul version */
	int defaul[10] = {1,9,2,8,3,7,6,4,5};
	int i;
	for(i=0; i<9; i++)
	{
		t = insert(defaul[i],t);
		int vec_left[10] = {0};
		display(t,0,vec_left);
		printf("\n");
	}
	printf("input 1 into scanf mode:");
	scanf("%d", &v);
	if(v == 1){
		/* scanf version */
		while(1)
		{
			printf("input -1 quit or other to insert avl:");
			scanf("%d", &v);
			if(v == -1)
				break;
			t = insert(v, t);
			int vec_left[(t->height)+1];
			set_zero(vec_left);
			display(t,0,vec_left);
		}
	}
	
    return 0;

}