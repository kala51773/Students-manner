    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>
	typedef struct student
	{
		char name[20];
		
		char sex[10];
		char major[20];
		char brithday[20];
		char address[40];
	
		int eng;
	}student ;
	typedef struct linknode {
		student date;
		linknode* next;
	
	}linknode;

	
	//创建结构体表示节点
	void menu();//打印交互菜单
	void keyDown();//实现交互
	void printkinklist(linknode* p);//打印整个链表
	void insectlinklist(linknode* head, student date);//头插法插入
	void deletelinknode(linknode* p, char* name);
	linknode* ncreatlist();//创建链表
	linknode* creatnode(student date);//创建链表节点
	linknode* seachdatenode(linknode* p, char* name);
	linknode* list;
	void read(linknode* head, char* file);//读取操作
	void write(linknode* head, char* file);
	void Swap(linknode* p, linknode* q)
	{
		linknode temp = *p;
		temp.next = q->next;
		q->next = p->next;
		*p = *q;
		*q = temp;
	}
	//交换指针指向的数据域
	int login();
	
	void  Sort1(linknode* L);
	//升序
	void  Sort2(linknode* L);
	//降序
	
	void stati_major(char* temp,linknode* head);
	void stati_sex(char* temp, linknode* head);
	void stati_age(int age, linknode* head);
	//获得年龄
	int getages(char* date)
	{
		return ((date[0] - 48)*1000 + (date[1] - 48)*100 + (date[2] - 48)*10 + (date[3] - 48)-2020);
	}
	
	
	/*主函数开始*/
	
	
	int main()
	{
		system("color E");
		list = ncreatlist();
		list->next = NULL;
		char a[20] = "ass.txt";
		read(list, a);
		login();//登录 
		while (1)
		{
			
			menu();
			keyDown();
			write(list, a);
			getchar();
			
		}
		
	
		return 0;
	}
	
	
	/*主函数结束*/
	/*读写操作函数*/
	
	void read(linknode* head, char* file)
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
		while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%d\n", &date.name, &date.sex, &date.major, &date.brithday,&date.address,&date.eng) != EOF)
		{
			insectlinklist(head, date);
		}
		//关闭文件
		fclose(fp);
	}
	void write(linknode* head, char* file)
	{
		FILE* fp;
		fp = fopen(file, "w");
		linknode* current = head->next;
		while (current)
		{
			
			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%d\n",current->date.name,current->date.sex,current->date.major,current->date.brithday,current->date.address,current->date.eng );
			current = current->next;
		}
		fclose(fp);
	}
	
	void menu()
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
	void keyDown()
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
			printf("请输入出生日期:\n");
			scanf("%s", &date.brithday);
			printf("请输入家庭住址:\n");
			scanf("%s", &date.address);
			printf("请输入英语入学成绩:\n");
			scanf("%d", &date.eng);
			insectlinklist(list, date);
			printf("录入成功\n");
			system("pause");
			break;
																					   
		case 2:
			system("cls");
			printf("  -----------浏览信息-----------  \n");
			system("cls");
			printkinklist(list);
			getchar();
			break;
		case 3:
			system("cls");
			printf("  -----------修改信息-----------  \n");
			char ch[20];
			printf("请输入人员姓名\n");
			scanf("%s", ch);
			linknode* tmpx;
			tmpx = seachdatenode(list, ch);
			if (tmpx != NULL)
			{
				printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%s\t家庭住址：%s\t英语入学成绩:%d\n", tmpx->date.name, tmpx->date.sex, tmpx->date.major, tmpx->date.brithday, tmpx->date.address, tmpx->date.eng);
				printf("请输入修改后姓名：\n");
				scanf("%s", tmpx->date.name);
				printf("请输入修改后性别：\n");
				scanf("%s", tmpx->date.sex);
				printf("请输入修改后专业：\n");
				scanf("%s", tmpx->date.major);
				printf("请输入修改后出生日期：\n");
				scanf("%s", tmpx->date.brithday);
				printf("请输入修改后家庭住址：\n");
				scanf("%s", tmpx->date.address);
				printf("请输入修改后英语入学成绩：\n");
				scanf("%d", &(tmpx->date.eng));
				
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
			deletelinknode(list, tmp);
			system("pause");
			break;
		case 5:
			system("cls");
			printf("  -----------查找信息-----------  \n");
			char tmp1[20];
			scanf("%s", tmp1);
			linknode* tmp2;
			tmp2 = seachdatenode(list, tmp1);
			if (tmp2 != NULL)
			{
				printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%s\t家庭住址：%s\t英语入学成绩:%d\n", tmp2->date.name, tmp2->date.sex, tmp2->date.major, tmp2->date.brithday, tmp2->date.address, tmp2->date.eng);
			
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
				case 1:Sort1(list);
					system("pause");
					break;
				case 2:Sort2(list);
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
				stati_major(tmp_switch,list);
					system("pause");
					break;
			case 2:
				printf("请输入性别:\n");
				scanf("%s", tmp_switch);
				stati_sex(tmp_switch, list);
					system("pause");
					
					break;
			case 3:
				printf("请输入年龄:\n");
				scanf("%d", &tmp_switch_num);
				stati_age(tmp_switch_num, list);
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
	
	void printkinklist(linknode* p)
	{
	
		linknode* pMove = p->next;
		if (pMove == NULL)
			return;
		while (1)
		{
			if (pMove->next != NULL)
			{
				
				printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%s\t家庭住址：%s\t英语入学成绩:%d\n", pMove->date.name, pMove->date.sex, pMove->date.major, pMove->date.brithday, pMove->date.address, pMove->date.eng);
				pMove = pMove->next;
			}
			else
			{
				printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%s\t家庭住址：%s\t英语入学成绩:%d\n", pMove->date.name, pMove->date.sex, pMove->date.major, pMove->date.brithday, pMove->date.address, pMove->date.eng);
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
	
	void deletelinknode(linknode* p, char* name)
	{
		linknode* pre = p;
		linknode* current = p->next;
		if (current == NULL)
		{
			printf("该节点为尾节点\n");
			return;
		}
	
		while (strcmp(current->date.name, name))
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
		while (current != NULL && strcmp(current->date.name, name))
		{
			current = current->next;
		}
		return current;
	
	}
	/*排序函数的定义*/
	void Sort1(linknode* L)
	{
		linknode* p = L->next;
		linknode* min = p;
	
		while (p)
		{
			min = p;
			linknode* q = p->next;
			while (q)
			{
				if (q->date.eng < min->date.eng)
				{
					min = q;
				}
				q = q->next;
			}
			Swap(p, min); 
			p = p->next;
		}
	}
	void Sort2(linknode *L)
	{
		linknode* p = L->next;
		linknode* min = p;
	
		while (p)
		{
			min = p;
			linknode* q = p->next;
			while (q)
			{
				if (q->date.eng > min->date.eng)
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
	void stati_major(char *temp,linknode* head)
	{
		linknode* p = head->next;
	
			while (p)
			{
				if (strcmp(temp, p->date.major) == 0)
				{
					printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%s\t家庭住址：%s\t英语入学成绩:%d\n", p->date.name, p->date.sex, p->date.major, p->date.brithday, p->date.address, p->date.eng);
				}
				p = p->next;
			}
	}
	void stati_sex(char* temp, linknode* head)
	{
		linknode* p = head->next;
	
		while (p)
		{
			if (strcmp(temp, p->date.sex) == 0)
			{
				printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%s\t家庭住址：%s\t英语入学成绩:%d\n", p->date.name, p->date.sex, p->date.major, p->date.brithday, p->date.address, p->date.eng);
			}
			p = p->next;
		}
	}
	void stati_age(int age, linknode* head)
	{
		linknode* p = head->next;
	
		while (p)
		{
			if  (getages(p->date.brithday)==age)
			{
				printf("姓名：%s\t性别：%s\t专业：%s\t出生日期：%s\t家庭住址：%s\t英语入学成绩:%d\n", p->date.name, p->date.sex, p->date.major, p->date.brithday, p->date.address, p->date.eng);
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
	for (i = 0;i < 5;i++)
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
