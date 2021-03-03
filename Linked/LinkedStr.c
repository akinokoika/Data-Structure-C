#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  */

// 结点结构体定义
typedef struct node
{
  char data[255];
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
king find_val_linker(king head,char val[]);
int insert_linker(king head,char x[],int num);
int remove_linker(king head,int num);
king havoc_linker(king head);
void show_linker(king head);
int length_linker(king head);
king reverse_interval_linker(king head,king interval);
king reverse_recursive_linker(king head);
king reverse_recursive_stack_linker(king head);
king reverse_recursive_n_linker(king head,int n);
king reverse_recursive_n_stack_linker(king head,int n);
king reverse_recursive_m_n_linker(king head,int m,int n);
king reverse_recursive_m_n_stack_linker(king head,int m,int n);
king test_linker(king head);
int sub(char s[],char x[]);

char *built[] = {"这是","一个","测 试","3","的"};


// 主函数
int main()
{
  int result;
  
  head=create_linker();
  
  printf("创建链表：");
  show_linker(head);
  printf("\n");
  
  head=test_linker(head);
  
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
  
  
  //
  printf("查找链表第1个：");
  t=find_num_linker(head,1);
  if(t!=0)
  {
    printf("找到%s",t->data);
  }
  else
  {
    printf("未找到");
  }
  printf("\n");
  
  //
  printf("查找链表第一个值为3：");
  t=find_val_linker(head,"3");
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
  result=insert_linker(head,"21",1);
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
  int i,n;
  char x[255];
  //scanf("%d",&n);
  // 获得内置字符串数组长度
  n=strlen(built);
  n--;
  
  head=(linker *)malloc(sizeof(linker));
  r=head;
  for(i=1;i<=n;i++)
  {
    //scanf("%s",x);
    // 将内置字符串数组的每个元素复制到x
    strcpy(x,built[i-1]);
    
    p=(linker *)malloc(sizeof(linker));
    strcpy(p->data,x);
    p->next=NULL;
    
    r->next=p;
    r=p;
    
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
king find_val_linker(king head,char val[])
{
  if(head==NULL)
  {
    return 0;
  }
  
  int j;
  t=head->next;
  
  for(j=1;t!=NULL&&(!sub(t->data,val));j++)
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
int insert_linker(king head,char x[],int num)
{
  // 调用从头结点开始查找的函数
  // 可以实现对单链表的1号结点的插入
  t=find_num_head_linker(head,num);
  if(t==0)
  {
    return 0;
  }
  
  p=(linker *)malloc(sizeof(linker));
  strcpy(p->data,x);
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
      printf("%s,",t->data);
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
  }
  
  // 返回时t为已反转链表部分的开始结点
  // 返回后的链表不包括interval
  return t;
}

// 链表反转
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

// 链表反转 递归
king reverse_recursive_stack_linker(king head)
{
  if(head->next==NULL)
  {
    // 如果链表只有一个结点，直接返回head
    return head;
  }
  r=reverse_recursive_stack_linker(head->next);
  head->next->next=head;
  head->next=NULL;
  return r;
}

// 链表反转 反转前n个结点
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

// 链表反转 反转前n个结点 递归
king reverse_recursive_n_stack_linker(king head,int n)
{
  // 每次递归使n-1直到n==1
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


// 链表反转 反转从m到n的结点
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

// 链表反转 反转从m到n的结点 递归
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
  printf("head=%p,head->next=%p,head->data=%s\n",head,head->next,head->data);
  t=head->next;
  printf("t=%p,t->next=%p,t->data=%s\n",t,t->next,t->data);
  v=t->next;
  printf("v=%p,v->next=%p,v->data=%s\n",v,v->next,v->data);
  r=v->next;
  printf("r=%p,r->next=%p,r->data=%s\n",r,r->next,r->data);
  r=r->next;
  printf("rr=%p,rr->next=%p,rr->data=%s\n",r,r->next,r->data);
  
  return head;
}

// 判断字符串s是否包含子串x
int sub(char s[],char x[])
{
    if(strstr(s,x))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}