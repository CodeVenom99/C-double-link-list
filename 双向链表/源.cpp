#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct DulNODE
{
	int data;
	struct DulNODE* prior;
	struct DulNODE* next;
}DulNODE;
DulNODE* creat_DulNODE(void);//创建头结点
bool push_DulNODE(DulNODE* p, int num);//尾部加入
bool insert_DulNODE(DulNODE* p, int pos, int num);//插入指定位置
bool pop_DulNODE(DulNODE* p);//尾部删除
bool delete_DulNODE(DulNODE* p,int pos);//删除指定位置
int len_DulNODE(DulNODE* p);//长度
bool sort_DulNODE(DulNODE* p, int L, int H);//排序
void show_DulNODE(DulNODE* p);//显示双向链表
void test01()
{
	DulNODE* p = creat_DulNODE();
	for (int i = 0; i < 5; i++)
	{
		push_DulNODE(p, 5-i);
	}
	insert_DulNODE(p, 2, 300);
	sort_DulNODE(p,1, len_DulNODE(p));
	//printf("长度为：%d\r\n",len_DulNODE(p)) ;
	show_DulNODE(p);
}
int main()
{
	test01();
	return 0;
}
DulNODE* creat_DulNODE()
{
	DulNODE* temp = (DulNODE*)malloc(sizeof(DulNODE));
	if (temp == NULL)
		exit(-1);
	temp->data = 0;
	temp->prior = temp;
	temp->next = temp;
	return temp;
}
int len_DulNODE(DulNODE* p)
{
	int i = 0;
	DulNODE* temp = p;
	while (temp->next != p)
	{
		temp = temp->next;
		i++;
	}
	return i;
}
bool insert_DulNODE(DulNODE* p, int pos, int num)
{
	DulNODE* temp = p;
	for (int i = 0; i < pos - 1; i++)
	{
		temp = temp->next;
		if (temp->next == p)
		{
			printf("没有这么多元素");
			exit(-1);
		}
	}
	DulNODE* new_temp = (DulNODE*)malloc(sizeof(DulNODE));
	if (new_temp == NULL)
		exit(-1);
	new_temp->next = temp->next;
	new_temp->prior = temp;
	new_temp->data = num;
	temp->next->prior = new_temp;
	temp->next = new_temp;
	
	return 1;
}
bool push_DulNODE(DulNODE* p,int num)
{
	DulNODE* temp = p;
	while (temp->next != p)
		temp = temp->next;
	DulNODE* new_temp = (DulNODE*)malloc(sizeof(DulNODE));//创建新节点
	if (new_temp == NULL)
		exit(-1);
	new_temp->data = num;
	new_temp->next = p;
	new_temp->prior = temp;
	temp->next = new_temp;
	p->prior = new_temp;
	return 1;
}
bool delete_DulNODE(DulNODE* p, int pos)
{
	DulNODE* temp = p;
	for (int i = 0; i < pos - 1; i++)
	{
		temp = temp->next;
		if (temp->next == p)
		{
			printf("没有这么多元素");
			exit(-1);
		}
	}
	DulNODE* temp1 = temp->next;
	temp->next = temp1->next;
	temp1->next->prior = temp;
	free(temp1);
	temp1 = NULL;
	return 1;
}
bool pop_DulNODE(DulNODE* p)
{
	DulNODE* temp = p;
	while (temp->next!=p)
	{
		temp = temp->next;
	}
	DulNODE* last_temp = temp;
	temp = temp->prior;
	temp->next = p;
	p->prior = temp;
	free(last_temp);
	last_temp = NULL;
	return 1;
}
void show_DulNODE(DulNODE* p)
{
	DulNODE* temp = p;
	while (temp->next != p)
	{
		temp = temp->next;
		printf("%d \r\n",temp->data);
		
	}
}
int find_pos(DulNODE* p, int L, int H)
{
	DulNODE* temp_L = p, * temp_H = p;
	for (int i = 0; i < L; i++)
	{
		temp_L = temp_L->next;
	}
	int val = temp_L->data;
	for (int i = 0; i < H; i++)
	{
		temp_H = temp_H->next;
	}
	while (L < H)
	{
		while (L < H && val < temp_H->data)
		{
			--H;
			temp_H = temp_H->prior;
		}
		temp_L->data = temp_H->data;
		while (L < H && val > temp_L->data)
		{
			++L;
			temp_L = temp_L->next;
		}
		temp_H->data = temp_L->data;
	}
	temp_H->data = val;
	return H;
}
bool sort_DulNODE(DulNODE* p,int L,int H)
{
	if (L < H)
	{
		int i, j,pos;
		DulNODE* temp = p,*temp1;
		pos = find_pos(temp, L, H);
		sort_DulNODE(temp, L, pos - 1);
		sort_DulNODE(temp, pos + 1, H);
		return 1;
	}

}

//for (i = 0; i < len_DulNODE(p) - 1; i++)
//{
//	temp = temp->next;
//	for (j = i + 1, temp1 = temp->next; j < len_DulNODE(p); j++, temp1 = temp1->next)
//	{
//
//		if (temp->data < temp1->data)
//		{
//			change_num = temp1->data;
//			temp1->data = temp->data;
//			temp->data = change_num;
//		}
//	}
//}



