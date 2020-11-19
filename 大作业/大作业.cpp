

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student
{
	char name[20];
	int id;
	char sex[10];
	char tel[20];
};
typedef struct linknode {
	 student date;
	linknode* next;

};

//创建结构体表示节点
void menu();//打印交互菜单
void keyDown();//实现交互
void printkinklist(linknode* p);//打印整个链表
void insectlinklist(linknode* head, student date);//头插法插入
void deletelinknode(linknode* p, char *name);
linknode* ncreatlist();//创建链表
linknode* creatnode(student date);//创建链表节点
linknode* seachdatenode(linknode* p, char *name);
linknode* list;
/*主函数开始*/


int main()
{
	list = ncreatlist();
	list->next = NULL;

	while (1)
	{
		menu();
		keyDown();
 
		getchar();
		
	}
	return 0;
}


/*主函数结束*/
void menu()
{
	printf("***********************************\n");
	printf("**       【学生信息管理系统】    **\n");
	printf("***********************************\n");
	printf("**                               **\n");
	printf("**      1.-----录入信息----      **\n");
	printf("**      2.-----浏览信息----      **\n");
	printf("**      3.-----修改信息----      **\n");
	printf("**      4.-----删除信息----      **\n");
	printf("**      5.-----查找信息----      **\n");
	printf("**      6.-----退出程序----      **\n");
	printf("**                               **\n");
	printf("***********************************\n");

}
void keyDown()
{
	int x;
	scanf("%d", &x);
	student date;
	switch (x)
	{
	case 1:printf("**-----------录入信息-----------**\n");				
		printf("请输入学生姓名、学号、性别、电话\n");	
		fflush(stdin);//清空缓存区 
		scanf("%s %d %s %s", date.name, &date.id, date.sex, date.tel);
		insectlinklist(list, date);
		printf("录入成功\n");
		break;
			
	case 2:printf("**-----------浏览信息-----------**\n");
		system("cls");
		printkinklist(list);
		getchar();
		break;
	case 3:printf("**-----------修改信息-----------**\n");
		char ch[20];
		printf("请输入人员姓名\n");
		scanf("%s",ch);
		linknode *tmpx;
		tmpx=seachdatenode(list,ch);
		if(tmpx!=NULL)
		{
			printf("该人员信息：\n姓名\t学号\t性别\t电话\n");
		printf("%s\t%d\t%s\t%s\t\n", tmpx->date.name, tmpx->date.id, tmpx->date.sex, tmpx->date.tel);
	
		printf("请输入修改后信息\n");
			scanf("%s %d %s %s", tmpx->date.name, &tmpx->date.id, tmpx->date.sex, tmpx->date.tel);	
				}
	else 
		printf("查无此人\n");
		break;

	
		break;
	case 4:printf("**-----------删除信息-----------**\n");
		printf("请输入要删除的学生姓名\n");
		char tmp[20];
		scanf("%s",tmp); 
		deletelinknode(list,tmp);
		
		break;
	case 5:printf("**-----------查找信息-----------**\n");
		char tmp1[20];
		scanf("%s",tmp1);
		linknode *tmp2;
		tmp2=seachdatenode(list,tmp1);
		if(tmp2!=NULL)
		{
			printf("姓名\t学号\t性别\t电话\n");
		printf("%s\t%d\t%s\t%s\t\n", tmp2->date.name, tmp2->date.id, tmp2->date.sex, tmp2->date.tel);
		}	
	else 
		printf("查无此人\n");
		break;
	case 6:printf("**-----------查找信息-----------**\n");
		printf("欢迎下次使用");
		exit(0);
		break;
	default:break;
	}



}
linknode* ncreatlist()
{
	linknode* head = (linknode*)malloc(sizeof(linknode));
	head->next = NULL;
	return head;
}

linknode* creatnode(student date)
{
	linknode* current = (linknode*)malloc(sizeof(linknode));
	current->date = date;
	current->next = NULL;
	return current;

}

void printkinklist(linknode*p)
{
	
	linknode* pMove=p->next;
	printf("姓名\t学号\t性别\t电话\n");
	if(pMove==NULL)
	return; 
	while (1)
	{
		if (pMove->next != NULL)
		{
			printf("%s\t %d\t %s\t %s\n", pMove->date.name,pMove->date.id,pMove->date.sex,pMove->date.tel);
			pMove = pMove->next;
		}
		else
		{
			printf("%s\t %d\t %s\t %s\n", pMove->date.name, pMove->date.id, pMove->date.sex, pMove->date.tel);
			break;
		}
	}
	
}

void insectlinklist(linknode* head, student date)
{
	linknode* current = creatnode(date);
	current->next = head->next;
	head->next = current;

}

void deletelinknode(linknode* p, char *name)
{
	linknode* pre=p;
	linknode* current = p->next;
	if (current == NULL)
	{printf("该节点为尾节点\n");
	return ;
	}
		
	while (strcmp(current->date.name,name))
	{
		current = current->next;
		pre = pre->next;
		if (current == NULL)
		{
			printf("未找到该位置\n");
			return;
		}
	}
	pre->next = current->next;
	free(current);
	printf("删除成功！\n");
}

linknode* seachdatenode(linknode* p, char* name)
{
	linknode* current = p->next;
	if (current == NULL)
		return NULL;
	while (current != NULL && strcmp(current->date.name,name))
	{
		current = current->next;
	}
	return current;

}
