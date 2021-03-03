#include <stdio.h>
#include <stdlib.h>

/*	已实现的功能：
/*		链表
/*		{
/*			建立，两种按序查找，按值查找
/*			插入，删除，摧毁，输出，求长度
/*			迭代反转与递归反转
/*			递归反转前n个，递归反转n到m
/*			反转m到n的结点
/*			循环链表测试
/*			数组模拟链表，输出，插入
/*		}
/*
/*	*/

// 结点结构体定义
typedef struct node
{
	int data;
	struct node *next;
}linker;

// 全局返回指针类型定义
typedef linker * king;

// 全局局部指针类型定义
typedef linker * kitchen;

// 全局工作指针声明
// p创建，trv临时，f释放，b传递
linker *head,*p,*t,*r,*v,*f,*b;

// 全局临时变量
int val_num_j;

// 函数接口协议声明
king create_linker(void);
king find_num_linker(king head,int num);
king find_num_head_linker(king head,int num);
king find_val_linker(king head,int val);
int insert_linker(king head,int x,int num);
int remove_linker(king head,int num);
king havoc_linker(king head);
void show_linker(king head);
int length_linker(king head);
king reverse_old_linker(king head);
king reverse_linker(king head);
king reverse_m_n_linker(king head,int m,int n);
king reverse_interval_linker(king head,king interval);
king reverse_group_linker(king head,int k);
king reverse_recursive_linker(king head);
king reverse_recursive_stack_linker(king head);
king reverse_recursive_n_linker(king head,int n);
king reverse_recursive_n_stack_linker(king head,int n);
king reverse_recursive_m_n_linker(king head,int m,int n);
king reverse_recursive_m_n_stack_linker(king head,int m,int n);
king test_linker(king head);
king cycle_linker(king head);
king simulation_linker(king head,int x,int num);
void simulation_show_linker(int data[],int right[]);
int simulation_insert_linker(int data[],int right[],int n,int x,int num);


// 主函数
int main()
{
	int result;
	
	/*scanf("%d",&a);
	t=head;
	while(t!=NULL)
	{
		if(t->next==NULL||t->next->data > a)
		{
			p=(linker *)malloc(sizeof(linker));
			p->data=a;
			p->next=t->next;
			t->next=p;
			break;
		}
		t=t->next;
	}*/
	
	head=create_linker();
	
	printf("创建链表：");
	show_linker(head);
	printf("\n");
	
	//head=test_linker(head);
	
	printf("反转链表：");
	head=reverse_linker(head);
	
	show_linker(head);
	printf("\n");
	
	printf("递归反转链表：");
	head=reverse_recursive_linker(head);
	
	show_linker(head);
	printf("\n");
	
	printf("反转链表前3个：");
	head=reverse_recursive_n_linker(head,3);
	
	show_linker(head);
	printf("\n");
	
	printf("递归反转链表从2到4：");
	head=reverse_recursive_m_n_linker(head,2,4);
	show_linker(head);
	printf("\n");
	
	printf("反转链表从2到4：");
	head=reverse_m_n_linker(head,2,4);
	show_linker(head);
	printf("\n");
	
	/*head->next=reverse_group_linker(head->next,2);
	show_linker(head);
	printf("\n");*/
	
	
	//
	printf("查找链表第1个：");
	t=find_num_linker(head,1);
	if(t!=0)
	{
		printf("找到%d",t->data);
	}
	else
	{
		printf("未找到");
	}
	printf("\n");
	
	//
	printf("查找链表第一个值为3：");
	t=find_val_linker(head,3);
	if(t!=0)
	{
		printf("找到3，序号是%d",val_num_j);
	}
	else
	{
		printf("未找到");
	}
	printf("\n");
	
	//
	printf("插入链表在第1个插入21：");
	result=insert_linker(head,21,1);
	if(result!=0)
	{
		show_linker(head);
	}
	else
	{
		printf("未找到");
	}
	printf("\n");
	
	//
	printf("移除链表第5个：");
	result=remove_linker(head,5);
	if(result!=0)
	{
		show_linker(head);
	}
	else
	{
		printf("未找到");
	}
	printf("\n");
	
	//
	printf("求链表长度：");
	result=length_linker(head);
	printf("%d",result);
	printf("\n");
	
	//
	printf("插入数组模拟链表：");
	simulation_linker(head,33,1);
	printf("\n");
	
	//
	printf("循环链表测试：");
	head=cycle_linker(head);
	
	//
	printf("毁灭链表：");
	head=havoc_linker(head);
	if(head==0)
	{
		printf("已销毁链表");
	}
	printf("\n");
	
	show_linker(head);
	printf("\n");
	
	return 0;
}

// 建立链表
king create_linker()
{
	int i,n,x;
	scanf("%d",&n);
	head=(linker *)malloc(sizeof(linker));
	r=head;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		
		p=(linker *)malloc(sizeof(linker));
		p->data=x;
		p->next=NULL;
		
		r->next=p;
		r=p;
		
		/*
		if(head==NULL){head=p;}
		else{q->next=p;}
		q=p;
		*/
	}
	r->next=NULL;
	return head;
}

// 按序查找 从开始结点 到空
king find_num_linker(king head,int num)
{
	if(head==NULL)
	{
		return 0;
	}
	
	int j;
	t=head->next;
	
	for(j=1;t!=NULL&&j<num;j++)
	{
		t=t->next;
	}
	if(num<=0||t==NULL)
	{
		return 0;
	}
	return t;
}

// 按序查找 从头结点 到尾结点
king find_num_head_linker(king head,int num)
{
	if(head==NULL)
	{
		return 0;
	}
	
	int j;
	t=head;
	
	// 循环条件应为t->next!=NULL
	// 确保指针不会指向链表外面
	for(j=1;t->next!=NULL&&j<num;j++)
	{
		t=t->next;
	}
	if(num<=0||t->next==NULL)
	{
		return 0;
	}
	return t;
}

// 按值查找
king find_val_linker(king head,int val)
{
	if(head==NULL)
	{
		return 0;
	}
	
	int j;
	t=head->next;
	
	for(j=1;t!=NULL&&t->data!=val;j++)
	{
		t=t->next;
	}
	if(t==NULL)
	{
		return 0;
	}
	// 返回所查找值的序号
	val_num_j=j;
	return t;
}

// 链表插入
int insert_linker(king head,int x,int num)
{
	// 调用从头结点开始查找的函数
	// 可以实现对单链表的1号结点的插入
	t=find_num_head_linker(head,num);
	if(t==0)
	{
		return 0;
	}
	
	p=(linker *)malloc(sizeof(linker));
	p->data=x;
	p->next=t->next;
	t->next=p;
	return 1;
}

// 链表删除
int remove_linker(king head,int num)
{
	t=find_num_head_linker(head,num);
	if(t==0)
	{
		return 0;
	}
	
	f=t->next;
	t->next=t->next->next;
	free(f);
	return 1;
}

// 链表毁灭
king havoc_linker(king head)
{
	t=head;
	while(t!=NULL)
	{
		r=t->next;
		free(t);
		t=r;
	}
	head=NULL;
	return head;
}

// 输出链表
void show_linker(king head)
{
	if(head==NULL)
	{
		printf("head");
	}
	else
	{
		t=head->next;
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
	}
}

// 链表长度
int length_linker(king head)
{
	if(head==NULL)
	{
		return 0;
	}
	
	int j=0;
	t=head->next;
	while(t!=NULL)
	{
		t=t->next;
		j++;
	}
	return j;
}

// 旧版链表链表
king reverse_old_linker(king head)
{
	
	if(head==NULL)
	{
		return 0;
	}
	
	t=head->next;
	v=t->next;
	r=v->next;
	t->next=NULL;
	
	while(1)
	{
		v->next=t;
		t=v;
		v=r;
		// 当r指向最后一个结点时
		// 不能执行r=r->next
		if(r->next==NULL)
		{
			v->next=t;
			t=v;
			break;
		}
		r=r->next;
	}
	
	head->next=t;
	return head;
}

// 链表反转
king reverse_linker(king head)
{
	if(head==NULL)
	{
		return 0;
	}
	
	// 处理开始结点的next问题
	t=NULL;
	// 处理带头结点的单链表
	v=head->next;
	r=v;
	
	while(v!=NULL)
	{
		r=v->next;
		v->next=t;
		t=v;
		v=r;
		// 退出循环时v和r为NULL
		// t为反转后的开始结点
	}
	
	head->next=t;
	return head;
}

// 链表反转n到m
king reverse_m_n_linker(king head,int m,int n)
{
	if(head==NULL)
	{
		return 0;
	}
	
	kitchen pre;
	// 以带头结点形式查找m结点，返回m的前驱结点
	pre=find_num_head_linker(head,m);
	// 以不带头结点形式查找n结点，返回n结点
	r=find_num_linker(head,n);
	
	// pre->next传入m结点
	// r->next传入n的后继结点
	// 函数返回链表区间是m到n-1
	t=reverse_interval_linker(pre->next,r->next);
	
	// 原链表前后连接上反转后的链表部分
	pre->next=t;
	b->next=r;
	
	/*printf("pre=%d\n",pre->data);
	printf("b=%d\n",b->data);*/

	return head;
}


// 链表反转从head到interval的前驱结点
king reverse_interval_linker(king head,king interval)
{
	t=NULL;
	// 处理不带头结点的单链表
	v=head;
	r=v;
	
	b=v;
	
	while(v!=interval)
	{
		r=v->next;
		v->next=t;
		t=v;
		v=r;
		// 退出循环时v和r指向interval
		// t为v的前驱结点
	}
	
	// 返回时t为已反转链表部分的开始结点
	// 返回后的链表不包括interval
	return t;
}
/*
// k个一组反转链表
king reverse_group_linker(king head,int k)
{
	if(head==NULL)
	{
		return NULL;
	}
	
	kitchen a,b;
	a=b=head;
	
	for(int i=0;i<k;k++)
	{
		if(b==NULL)
		{
			return head;
		}
		b=b->next;
	}
	
	kitchen head_new=reverse_interval_linker(a,b);
	a->next=reverse_group_linker(b,k);
	return head_new;
}*/

// 链表递归反转
king reverse_recursive_linker(king head)
{
	if(head==NULL)
	{
		return 0;
	}
	
	// 处理带有头结点的单链表
	t=head->next;
	r=reverse_recursive_stack_linker(t);
	head->next=r;
	return head;
}

// 链表递归反转 栈
king reverse_recursive_stack_linker(king head)
{
	if(head->next==NULL)
	{
		// 正常链表此处是最后一个栈，从此处返回
		// 如果链表只有一个结点，直接返回head
		return head;
	}
	r=reverse_recursive_stack_linker(head->next);
	head->next->next=head;
	head->next=NULL;
	return r;
}

// 链表递归反转 反转前n个结点
king reverse_recursive_n_linker(king head,int n)
{
	if(head==NULL)
	{
		return 0;
	}
	if(n>length_linker(head))
	{
		return head;
	}
	
	t=head->next;
	r=reverse_recursive_n_stack_linker(t,n);
	head->next=r;
	return head;
}

// 链表递归反转 反转前n个结点 栈
king reverse_recursive_n_stack_linker(king head,int n)
{
	// 每次入栈递归使n-1
	// 当n==1时，位于最后一个栈，head指向第n个结点
	// 反转前1个结点时，直接返回head
	if(n==1)
	{
		// v为第n个结点的后继节点
		v=head->next;
		return head;
	}
	r=reverse_recursive_n_stack_linker(head->next,n-1);
	head->next->next=head;
	// 反转后的n链表和原链表连接
	head->next=v;
	return r;
}


// 链表递归反转 反转从m到n的结点
king reverse_recursive_m_n_linker(king head,int m,int n)
{
	if(head==NULL)
	{
		return 0;
	}
	// 判断反转区间的有效性
	if(n>length_linker(head)||m>n)
	{
		return head;
	}
	
	t=head->next;
	r=reverse_recursive_m_n_stack_linker(t,m,n);
	head->next=r;
	return head;
}

// 链表递归反转 反转从m到n的结点 栈
king reverse_recursive_m_n_stack_linker(king head,int m,int n)
{
	// 当m==1时，相当于执行反转前n个结点
	if(m==1)
	{
		// 返回反转后的m到n的链表
		return reverse_recursive_n_stack_linker(head,n);
	}
	
	// 使head向后移动，直到指向m所在结点时m==1
	// 返回时使前驱结点head->next指向反转链表
	head->next=reverse_recursive_m_n_stack_linker(head->next,m-1,n-1);
	return head;
}

	
// 输出链表结构测试
king test_linker(king head)
{
	printf("head=%p,head->next=%p,head->data=%d\n",head,head->next,head->data);
	t=head->next;
	printf("t=%p,t->next=%p,t->data=%d\n",t,t->next,t->data);
	v=t->next;
	printf("v=%p,v->next=%p,v->data=%d\n",v,v->next,v->data);
	r=v->next;
	printf("r=%p,r->next=%p,r->data=%d\n",r,r->next,r->data);
	r=r->next;
	printf("rr=%p,rr->next=%p,rr->data=%d\n",r,r->next,r->data);
	
	return head;
}

// 循环链表测试
king cycle_linker(king head)
{
	r=head->next;
	// t指向开始结点
	t=r;
	while(r->next!=NULL)
	{
		r=r->next;
	}
	// r指向尾结点
	// 尾结点的后驱结点指向开始结点
	r->next=t;
	
	//printf("r=%d,r->next=%d",r->data,r->next->data);
	
	kitchen cycle_r;
	int size=1;
	
	cycle_r=r->next;
	// 循环链表的遍历
	while(cycle_r!=r)
	{
		cycle_r=cycle_r->next;
		size++;
	}
	
printf("r=%d,cycle_r=%d,size=%d\n",r->data,cycle_r->data,size);
	
	r->next=NULL;
	return head;
}

// 数组模拟链表
king simulation_linker(king head,int x,int num)
{
	// n保存链表长度，size建立数组下标
	int size=length_linker(head);
	int n=size++;
	// 增加数组最大下标，为插入数据预留位置
	if(x!=0)
	{
		size++;
	}
	// data数组保存数据，right数组保存数组下标
	int data[size],right[size];
	
	// 数组链表初始化
	t=head;
	for(int i=0;i<=n;i++)
	{
			data[i]=t->data;
			t=t->next;
	}
	for(int i=0;i<=n;i++)
	{
		int j=i;
		// right数组最后有效下标的值为0
		// 表示模拟链表的尾指针
		if(i==n)
		{
			right[i]=0;
			break;
		}
		
		// 表示模拟链表的指针指向下一个数据
		right[i]=j+1;
	}
	
	// 插入数据不为0时进行插入	
	if(x!=0)
	{
		simulation_insert_linker(data,right,n,x,num);
		// 对原链表进行同步插入
		insert_linker(head,x,num);
	}
		
	simulation_show_linker(data,right);
	
	return head;
}

// 输出模拟链表
void simulation_show_linker(int data[],int right[])
{
	for(int i=0;right[i]!=0;)
	{
		// right数组从0开始，data数组从1开始
		printf("%d ",data[right[i]]);
		// 表示模拟链表工作指针向后移动
		i=right[i];
	}
}

// 模拟链表插入
int simulation_insert_linker(int data[],int right[],int n,int x,int num)
{
	// 在原模拟链表长度的后面插入数据
	int last=++n;
	data[last]=x;
	// 判断插入位置是否为last
	if(num!=last)
	{
		// 使last的right指向下一个数据
		right[last]=num;
	}
	else
	{
		// 使last的right成为尾指针
		right[last]=0;
	}
	// 使last的前驱right指向last
	right[--num]=last;
	return 1;
}
