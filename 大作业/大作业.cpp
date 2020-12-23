#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




typedef struct student
{
	char name[20];
	char sex[10];
	char major[20];
	int year, month, day;
	char address[40];
	int eng;
}student;

class linknode
{



public:
	void menu();//打印交互菜单
	void keyDown();//实现交互
	void printkinklist(linknode* p);//打印整个链表
	void insectlinklist(linknode* p, student date);//头插法插入
	void deletelinknode(linknode* p, char* name);
	//linknode* ncreatlist();//创建链表
	linknode* creatnode(student date);//创建链表节点
	linknode* seachdatenode(linknode* p, char* name);

	void read(linknode* p, char* file);//读取操作
	void write(linknode* p, char* file);
	void setheadNULL()
	{
		next = NULL;
	}
	void Swap(linknode* p, linknode* q)
	{
		linknode temp = *p;
		temp.next = q->next;
		q->next = p->next;
		*p = *q;
		*q = temp;
	}
	//交换指针指向的数据域


	void  Sort1(linknode* L);
	//升序
	void  Sort2(linknode* L);
	//降序
	void stati_major(char* temp, linknode* head);
	void stati_sex(char* temp, linknode* head);
	void stati_age(int y, int m, int d, linknode* head);
private:
	student data;
	linknode* next;

};
int login();
//创建结构体表示节点




/*主函数开始*/


int main()
{


	
	linknode* list;
	system("color E");
	list = new linknode;
	char a[20] = "ass.txt";
	list->setheadNULL();
	list->read(list, a);
	login();//登录 
	while (1)
	{

		list->menu();
		list->keyDown();
		list->write(list, a);
		getchar();

	}


	return 0;
}


/*主函数结束*/
/*读写操作函数*/

void linknode::read(linknode* head, char* file)
{
	//打开
	FILE* fp;
	student date;
	fp = fopen(file, "r");

	if (fp == NULL)
	{
		fp = fopen(file, "w+");//不存在文件就创建文件
	}
	//读文件
	while (fscanf(fp, "%s\t%s\t%s\t%d-%d-%d\t%s\t%d\n", &date.name, &date.sex, &date.major, &date.year, &date.month, &date.day, &date.address, &date.eng) != EOF)
	{
		insectlinklist(head, date);
	}
	//关闭文件
	fclose(fp);
}
void linknode::write(linknode* head, char* file)
{
	FILE* fp;
	fp = fopen(file, "w");
	linknode* current = head->next;
	while (current)
	{

		fprintf(fp, "%s\t%s\t%s\t%d-%d-%d\t%s\t%d\n", current->data.name, current->data.sex, current->data.major, current->data.year, current->data.month, current->data.day, current->data.address, current->data.eng);
		current = current->next;
	}
	fclose(fp);
}

void linknode::menu()
{


	system("cls");
	printf("\n\n\n================================================================================");
	printf("\t                                                         \n");
	printf("\t                  【学生信息管理系统】                   \n");
	printf("\t                                                         \n");
	printf("--------------------------------------------------------------------------------  \n");
	printf("\t\t                        1.-----录入信息----                    \n");
	printf("\t\t                        2.-----浏览信息----                    \n");
	printf("\t\t                        3.-----修改信息----                    \n");
	printf("\t\t                        4.-----删除信息----                    \n");
	printf("\t\t                        5.-----查找信息----                    \n");
	printf("\t\t                        6.-----成绩排序----                    \n");
	printf("\t\t                        7.-----信息统计----                    \n");
	printf("\t\t                        8.-----退出程序----                    \n");
	printf("\t\t                                                            \n");;
	printf("================================================================================\n");
	system("date/t");
	system("time/t");
}
void linknode::keyDown()
{
	int x;
	scanf("%d", &x);
	student date;
	switch (x)
	{
	case 1:
		system("cls");
		printf("  -----------录入信息-----------  \n");

		fflush(stdin);//清空缓存区 

		printf("请输入姓名:\n");
		scanf("%s", &date.name);
		printf("请输入性别:\n");
		scanf("%s", &date.sex);
		printf("请输入专业:\n");
		scanf("%s", &date.major);
		printf("请输入出生年份:\n");
		scanf("%d", &date.year);
		printf("请输入出生月份:\n");
		scanf("%d", &date.month);
		printf("请输入出生日期:\n");
		scanf("%d", &date.day);
	
		printf("请输入家庭住址:\n");
		scanf("%s", &date.address);
		printf("请输入英语入学成绩:\n");
		scanf("%d", &date.eng);
		insectlinklist(this, date);
		printf("录入成功\n");
		system("pause");
		break;

	case 2:
		system("cls");
		printf("  -----------浏览信息-----------  \n");
		system("cls");
		printkinklist(this);
		getchar();
		break;
	case 3:
		system("cls");
		printf("  -----------修改信息-----------  \n");
		char ch[20];
		printf("请输入人员姓名\n");
		scanf("%s", ch);
		linknode* tmpx;
		tmpx = seachdatenode(this, ch);
		if (tmpx != NULL)
		{
			printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%d-%d-%d\t家庭住址：%s\t英语入学成绩:%d\n", tmpx->data.name, tmpx->data.sex, tmpx->data.major, tmpx->data.year, tmpx->data.month, tmpx->data.day, tmpx->data.address, tmpx->data.eng);
			printf("请输入修改后姓名：\n");
			scanf("%s", tmpx->data.name);
			printf("请输入修改后性别：\n");
			scanf("%s", tmpx->data.sex);
			printf("请输入修改后专业：\n");
			scanf("%s", tmpx->data.major);
			printf("请输入修改后出生日期：\n");
			printf("请输入修改后出生年份：\n");
			scanf("%d", &tmpx->data.year);
			printf("请输入修改后出生月份：\n");
			scanf("%d", &tmpx->data.month);
			printf("请输入修改后出生日期：\n");
			scanf("%d", &tmpx->data.day);
			printf("请输入修改后家庭住址：\n");
			scanf("%s", tmpx->data.address);
			printf("请输入修改后英语入学成绩：\n");
			scanf("%d", &(tmpx->data.eng));

		}
		else
			printf("查无此人\n");
		system("pause");

		break;
	case 4:
		system("cls");
		printf("  -----------删除信息-----------  \n");
		printf("请输入要删除的学生姓名\n");
		char tmp[20];
		scanf("%s", tmp);
		deletelinknode(this, tmp);
		system("pause");
		break;
	case 5:
		system("cls");
		printf("  -----------查找信息-----------  \n");
		char tmp1[20];
		scanf("%s", tmp1);
		linknode* tmp2;
		tmp2 = seachdatenode(this, tmp1);
		if (tmp2 != NULL)
		{
			printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%d-%d-%d\t家庭住址：%s\t英语入学成绩:%d\n", tmp2->data.name, tmp2->data.sex, tmp2->data.major, tmp2->data.year, tmp2->data.month, tmp2->data.day, tmp2->data.address, tmp2->data.eng);

			getchar();
			printf("按任意键继续.....");
		}
		else
			printf("查无此人\n");
		break;
	case 6:
		system("cls");
		printf("按英文成绩排序\n");
		printf("1.升序\n");
		printf("2.降序\n");
		printf("3.输入其他值返回上一级\n");
		int tmpx1;
		scanf("%d", &tmpx1);

		switch (tmpx1)
		{
		case 1:Sort1(this);
			system("pause");
			break;
		case 2:Sort2(this);
			system("pause");
			break;
		default: break;

		}
		break;
	case 7:
		system("cls");
		char tmp_char[20];
		int tmp_sqe;
		printf("1.按照专业统计\n");
		printf("2.按照性别统计\n");
		printf("3.按照年龄统计\n");
		printf("4.输入其他数字返回上一级\n");
		scanf("%d", &tmp_sqe);
		char tmp_switch[20];
		int tmp_switch_num;
		switch (tmp_sqe)
		{
		case 1:
			printf("请输入专业名称:\n");
			scanf("%s", tmp_switch);
			stati_major(tmp_switch, this);
			system("pause");
			break;
		case 2:
			printf("请输入性别:\n");
			scanf("%s", tmp_switch);
			stati_sex(tmp_switch, this);
			system("pause");

			break;
		case 3:
			printf("请输入年龄:\n");
			int m_y, m_m, m_d;
			
			scanf("%d%d%d", &m_y, &m_m, &m_d);
			stati_age(m_y, m_m, m_d, this);
			printf("按任意键继续.....\n");
			getchar();
			break;
		default:
			break;
		}
		break;
	case 8:
		system("cls");
		printf("欢迎下次使用");
		exit(0);
		break;
	default:break;
	}



}

linknode* linknode::creatnode(student date)
{
	linknode* current = (linknode*)malloc(sizeof(linknode));
	current->data = date;
	current->next = NULL;
	return current;

}

void linknode::printkinklist(linknode* p)
{

	linknode* pMove = p->next;
	if (pMove == NULL)
		return;
	while (1)
	{
		if (pMove->next != NULL)
		{
			printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%d-%d-%d\t家庭住址：s\t英语入学成绩:%d\n", pMove->data.name, pMove->data.sex, pMove->data.major, pMove->data.year, pMove->data.month, pMove->data.day,pMove->data.eng);
			//printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%d-%d-%d\t家庭住址：%s\t英语入学成绩:%s\n", pMove->data.name, pMove->data.sex, pMove->data.major, pMove->data.year, pMove->data.month, pMove->data.day, pMove->data.address, pMove->data.eng);
			pMove = pMove->next;
		}
		else
		{
			printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%d-%d-%d\t家庭住址：s\t英语入学成绩:%d\n", pMove->data.name, pMove->data.sex, pMove->data.major, pMove->data.year, pMove->data.month, pMove->data.day, pMove->data.eng);
			break;
		}
	}

}

void linknode::insectlinklist(linknode* head, student date)
{
	linknode* current = creatnode(date);
	current->next = head->next;
	head->next = current;
}

void linknode::deletelinknode(linknode* p, char* name)
{
	linknode* pre = p;
	linknode* current = p->next;
	if (current == NULL)
	{
		printf("该节点为尾节点\n");
		return;
	}

	while (strcmp(current->data.name, name))
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

linknode* linknode::seachdatenode(linknode* p, char* name)
{
	linknode* current = p->next;
	if (current == NULL)
		return NULL;
	while (current != NULL && strcmp(current->data.name, name))
	{
		current = current->next;
	}
	return current;

}
/*排序函数的定义*/
void linknode::Sort1(linknode* L)
{
	linknode* p = L->next;
	linknode* min = p;

	while (p)
	{
		min = p;
		linknode* q = p->next;
		while (q)
		{
			if (q->data.eng < min->data.eng)
			{
				min = q;
			}
			q = q->next;
		}
		Swap(p, min);
		p = p->next;
	}
}
void linknode::Sort2(linknode* L)
{
	linknode* p = L->next;
	linknode* min = p;

	while (p)
	{
		min = p;
		linknode* q = p->next;
		while (q)
		{
			if (q->data.eng > min->data.eng)
			{
				min = q;
			}
			q = q->next;
		}
		Swap(p, min);
		p = p->next;
	}
}
/*统计函数的定义*/
void linknode::stati_major(char* temp, linknode* head)
{
	linknode* p = head->next;

	while (p)
	{
		if (strcmp(temp, p->data.major) == 0)
		{
			printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%d-%d-%d\t家庭住址：%s\t英语入学成绩:%d\n", p->data.name, p->data.sex, p->data.major, p->data.year, p->data.month, p->data.day, p->data.address, p->data.eng);
		}
		p = p->next;
	}
}
void linknode::stati_sex(char* temp, linknode* head)
{
	linknode* p = head->next;

	while (p)
	{
		if (strcmp(temp, p->data.sex) == 0)
		{
			printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%d-%d-%d\t家庭住址：%s\t英语入学成绩:%d\n", p->data.name, p->data.sex, p->data.major, p->data.year, p->data.month, p->data.day, p->data.address, p->data.eng);
		}
		p = p->next;
	}
}
void linknode::stati_age(int y, int m, int d, linknode* head)
{
	linknode* p = head->next;

	while (p)
	{
		if (y == head->data.year && y == head->data.month && y == head->data.day);
		{
			printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%d-%d-%d\t家庭住址：%s\t英语入学成绩:%d\n", p->data.name, p->data.sex, p->data.major, p->data.year, p->data.month, p->data.day, p->data.address, p->data.eng);
		}

		p = p->next;
	}
}
int login()
{

	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t学生信息管理系统登录\n");
	printf("\n\t\t\t\t请输入密码：\n");
	printf("================================================================================\n");
	printf("\t\t\t");
	char password[20];
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)
		{
			printf("登陆成功！！！\n");
			system("pause");
			break;
		}
		else
		{
			printf("密码输入错误，请重新输入：\n");
			printf("你还有%d次机会！！！\n", 2 - i);
		}
	}
	if (i == 3)
	{
		printf("密码尝试次数用尽，已退出系统\n");
		system("pause");
		exit(0);
	}
	system("cls");
}
