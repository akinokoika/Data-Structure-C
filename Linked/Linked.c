#include <stdio.h>
#include <stdlib.h>

/*	��ʵ�ֵĹ��ܣ�
/*		����
/*		{
/*			���������ְ�����ң���ֵ����
/*			���룬ɾ�����ݻ٣�������󳤶�
/*			������ת��ݹ鷴ת
/*			�ݹ鷴תǰn�����ݹ鷴תn��m
/*			��תm��n�Ľ��
/*			ѭ���������
/*			����ģ���������������
/*		}
/*
/*	*/

// ���ṹ�嶨��
typedef struct node
{
	int data;
	struct node *next;
}linker;

// ȫ�ַ���ָ�����Ͷ���
typedef linker * king;

// ȫ�־ֲ�ָ�����Ͷ���
typedef linker * kitchen;

// ȫ�ֹ���ָ������
// p������trv��ʱ��f�ͷţ�b����
linker *head,*p,*t,*r,*v,*f,*b;

// ȫ����ʱ����
int val_num_j;

// �����ӿ�Э������
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


// ������
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
	
	printf("��������");
	show_linker(head);
	printf("\n");
	
	//head=test_linker(head);
	
	printf("��ת����");
	head=reverse_linker(head);
	
	show_linker(head);
	printf("\n");
	
	printf("�ݹ鷴ת����");
	head=reverse_recursive_linker(head);
	
	show_linker(head);
	printf("\n");
	
	printf("��ת����ǰ3����");
	head=reverse_recursive_n_linker(head,3);
	
	show_linker(head);
	printf("\n");
	
	printf("�ݹ鷴ת�����2��4��");
	head=reverse_recursive_m_n_linker(head,2,4);
	show_linker(head);
	printf("\n");
	
	printf("��ת�����2��4��");
	head=reverse_m_n_linker(head,2,4);
	show_linker(head);
	printf("\n");
	
	/*head->next=reverse_group_linker(head->next,2);
	show_linker(head);
	printf("\n");*/
	
	
	//
	printf("���������1����");
	t=find_num_linker(head,1);
	if(t!=0)
	{
		printf("�ҵ�%d",t->data);
	}
	else
	{
		printf("δ�ҵ�");
	}
	printf("\n");
	
	//
	printf("���������һ��ֵΪ3��");
	t=find_val_linker(head,3);
	if(t!=0)
	{
		printf("�ҵ�3�������%d",val_num_j);
	}
	else
	{
		printf("δ�ҵ�");
	}
	printf("\n");
	
	//
	printf("���������ڵ�1������21��");
	result=insert_linker(head,21,1);
	if(result!=0)
	{
		show_linker(head);
	}
	else
	{
		printf("δ�ҵ�");
	}
	printf("\n");
	
	//
	printf("�Ƴ������5����");
	result=remove_linker(head,5);
	if(result!=0)
	{
		show_linker(head);
	}
	else
	{
		printf("δ�ҵ�");
	}
	printf("\n");
	
	//
	printf("�������ȣ�");
	result=length_linker(head);
	printf("%d",result);
	printf("\n");
	
	//
	printf("��������ģ������");
	simulation_linker(head,33,1);
	printf("\n");
	
	//
	printf("ѭ��������ԣ�");
	head=cycle_linker(head);
	
	//
	printf("��������");
	head=havoc_linker(head);
	if(head==0)
	{
		printf("����������");
	}
	printf("\n");
	
	show_linker(head);
	printf("\n");
	
	return 0;
}

// ��������
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

// ������� �ӿ�ʼ��� ����
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

// ������� ��ͷ��� ��β���
king find_num_head_linker(king head,int num)
{
	if(head==NULL)
	{
		return 0;
	}
	
	int j;
	t=head;
	
	// ѭ������ӦΪt->next!=NULL
	// ȷ��ָ�벻��ָ����������
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

// ��ֵ����
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
	// ����������ֵ�����
	val_num_j=j;
	return t;
}

// �������
int insert_linker(king head,int x,int num)
{
	// ���ô�ͷ��㿪ʼ���ҵĺ���
	// ����ʵ�ֶԵ������1�Ž��Ĳ���
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

// ����ɾ��
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

// �������
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

// �������
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

// ������
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

// �ɰ���������
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
		// ��rָ�����һ�����ʱ
		// ����ִ��r=r->next
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

// ����ת
king reverse_linker(king head)
{
	if(head==NULL)
	{
		return 0;
	}
	
	// ����ʼ����next����
	t=NULL;
	// �����ͷ���ĵ�����
	v=head->next;
	r=v;
	
	while(v!=NULL)
	{
		r=v->next;
		v->next=t;
		t=v;
		v=r;
		// �˳�ѭ��ʱv��rΪNULL
		// tΪ��ת��Ŀ�ʼ���
	}
	
	head->next=t;
	return head;
}

// ����תn��m
king reverse_m_n_linker(king head,int m,int n)
{
	if(head==NULL)
	{
		return 0;
	}
	
	kitchen pre;
	// �Դ�ͷ�����ʽ����m��㣬����m��ǰ�����
	pre=find_num_head_linker(head,m);
	// �Բ���ͷ�����ʽ����n��㣬����n���
	r=find_num_linker(head,n);
	
	// pre->next����m���
	// r->next����n�ĺ�̽��
	// ������������������m��n-1
	t=reverse_interval_linker(pre->next,r->next);
	
	// ԭ����ǰ�������Ϸ�ת���������
	pre->next=t;
	b->next=r;
	
	/*printf("pre=%d\n",pre->data);
	printf("b=%d\n",b->data);*/

	return head;
}


// ����ת��head��interval��ǰ�����
king reverse_interval_linker(king head,king interval)
{
	t=NULL;
	// ������ͷ���ĵ�����
	v=head;
	r=v;
	
	b=v;
	
	while(v!=interval)
	{
		r=v->next;
		v->next=t;
		t=v;
		v=r;
		// �˳�ѭ��ʱv��rָ��interval
		// tΪv��ǰ�����
	}
	
	// ����ʱtΪ�ѷ�ת�����ֵĿ�ʼ���
	// ���غ����������interval
	return t;
}
/*
// k��һ�鷴ת����
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

// ����ݹ鷴ת
king reverse_recursive_linker(king head)
{
	if(head==NULL)
	{
		return 0;
	}
	
	// �������ͷ���ĵ�����
	t=head->next;
	r=reverse_recursive_stack_linker(t);
	head->next=r;
	return head;
}

// ����ݹ鷴ת ջ
king reverse_recursive_stack_linker(king head)
{
	if(head->next==NULL)
	{
		// ��������˴������һ��ջ���Ӵ˴�����
		// �������ֻ��һ����㣬ֱ�ӷ���head
		return head;
	}
	r=reverse_recursive_stack_linker(head->next);
	head->next->next=head;
	head->next=NULL;
	return r;
}

// ����ݹ鷴ת ��תǰn�����
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

// ����ݹ鷴ת ��תǰn����� ջ
king reverse_recursive_n_stack_linker(king head,int n)
{
	// ÿ����ջ�ݹ�ʹn-1
	// ��n==1ʱ��λ�����һ��ջ��headָ���n�����
	// ��תǰ1�����ʱ��ֱ�ӷ���head
	if(n==1)
	{
		// vΪ��n�����ĺ�̽ڵ�
		v=head->next;
		return head;
	}
	r=reverse_recursive_n_stack_linker(head->next,n-1);
	head->next->next=head;
	// ��ת���n�����ԭ��������
	head->next=v;
	return r;
}


// ����ݹ鷴ת ��ת��m��n�Ľ��
king reverse_recursive_m_n_linker(king head,int m,int n)
{
	if(head==NULL)
	{
		return 0;
	}
	// �жϷ�ת�������Ч��
	if(n>length_linker(head)||m>n)
	{
		return head;
	}
	
	t=head->next;
	r=reverse_recursive_m_n_stack_linker(t,m,n);
	head->next=r;
	return head;
}

// ����ݹ鷴ת ��ת��m��n�Ľ�� ջ
king reverse_recursive_m_n_stack_linker(king head,int m,int n)
{
	// ��m==1ʱ���൱��ִ�з�תǰn�����
	if(m==1)
	{
		// ���ط�ת���m��n������
		return reverse_recursive_n_stack_linker(head,n);
	}
	
	// ʹhead����ƶ���ֱ��ָ��m���ڽ��ʱm==1
	// ����ʱʹǰ�����head->nextָ��ת����
	head->next=reverse_recursive_m_n_stack_linker(head->next,m-1,n-1);
	return head;
}

	
// �������ṹ����
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

// ѭ���������
king cycle_linker(king head)
{
	r=head->next;
	// tָ��ʼ���
	t=r;
	while(r->next!=NULL)
	{
		r=r->next;
	}
	// rָ��β���
	// β���ĺ������ָ��ʼ���
	r->next=t;
	
	//printf("r=%d,r->next=%d",r->data,r->next->data);
	
	kitchen cycle_r;
	int size=1;
	
	cycle_r=r->next;
	// ѭ������ı���
	while(cycle_r!=r)
	{
		cycle_r=cycle_r->next;
		size++;
	}
	
printf("r=%d,cycle_r=%d,size=%d\n",r->data,cycle_r->data,size);
	
	r->next=NULL;
	return head;
}

// ����ģ������
king simulation_linker(king head,int x,int num)
{
	// n���������ȣ�size���������±�
	int size=length_linker(head);
	int n=size++;
	// ������������±꣬Ϊ��������Ԥ��λ��
	if(x!=0)
	{
		size++;
	}
	// data���鱣�����ݣ�right���鱣�������±�
	int data[size],right[size];
	
	// ���������ʼ��
	t=head;
	for(int i=0;i<=n;i++)
	{
			data[i]=t->data;
			t=t->next;
	}
	for(int i=0;i<=n;i++)
	{
		int j=i;
		// right���������Ч�±��ֵΪ0
		// ��ʾģ�������βָ��
		if(i==n)
		{
			right[i]=0;
			break;
		}
		
		// ��ʾģ�������ָ��ָ����һ������
		right[i]=j+1;
	}
	
	// �������ݲ�Ϊ0ʱ���в���	
	if(x!=0)
	{
		simulation_insert_linker(data,right,n,x,num);
		// ��ԭ�������ͬ������
		insert_linker(head,x,num);
	}
		
	simulation_show_linker(data,right);
	
	return head;
}

// ���ģ������
void simulation_show_linker(int data[],int right[])
{
	for(int i=0;right[i]!=0;)
	{
		// right�����0��ʼ��data�����1��ʼ
		printf("%d ",data[right[i]]);
		// ��ʾģ��������ָ������ƶ�
		i=right[i];
	}
}

// ģ���������
int simulation_insert_linker(int data[],int right[],int n,int x,int num)
{
	// ��ԭģ�������ȵĺ����������
	int last=++n;
	data[last]=x;
	// �жϲ���λ���Ƿ�Ϊlast
	if(num!=last)
	{
		// ʹlast��rightָ����һ������
		right[last]=num;
	}
	else
	{
		// ʹlast��right��Ϊβָ��
		right[last]=0;
	}
	// ʹlast��ǰ��rightָ��last
	right[--num]=last;
	return 1;
}
