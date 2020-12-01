#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<cstring >
#include<stdio.h>
#include<time.h>
#include<fstream>
using namespace std;
typedef class  STUDENT
{
public:
	STUDENT()
	{
		num=0;
		name[20]=0;
		sex[100]=0;
		major[100]=0;
		address[100]=0;
		englishscore=0;
		year=0;
		month=0;
		date=0;
	}
	~STUDENT()
	{
		
	}
	void addstudent(STUDENT* p);
	void printstudent(STUDENT* p);
	void deletestudent(STUDENT* p);
	void search(STUDENT* p);
	void statistical(STUDENT* p);
	void rank(STUDENT* p);
	void storestudent(STUDENT* p);
	int Repeat(int n, STUDENT* p1);
	void readstudent();
	void modifystudent(STUDENT* p);
	STUDENT* next;
private:
	int num;
	char name[20];
	char sex[100];
	char major[100];
	char address[100];
	int  englishscore;
	int year;
	int month;
	int date;
}stu;
stu* createlist()//创链表 
{
	stu* p;
	p = (stu*)malloc(sizeof(stu));
	p->next = NULL;
	return p;
}
int main()
{
	system("color E");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t本地账号登录\n");
	printf("\n\t\t\t\t请输入密码：\n");
	printf("\t\t\t\t");
	char password[20];
	int i;
	for (i = 0;i < 3;i++)
	{
		scanf("%s", password);
		if (strcmp(password, "000000") == 0)
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
		printf("对不起，你已经失败，退出登录系统！！！\n");
		system("pause");
		exit(0);
	}
	system("cls");
	stu t;
	stu* pstu = NULL;
	pstu = createlist();
	while (1)
	{
		system("cls");
		cout << "==============================================欢迎使用学生信息管理系统==================================================\n";
		cout << "\t	          			======请选择功能列表======\n";
		cout << "\t	 		 		    录入学生信息请按1\n";
		cout << "\t	 		 		    显示学生信息请按2\n";
		cout << "\t	 		 		    删除学生信息请按3\n";
		cout << "\t	 		 		    查询学生信息请按4\n";
		cout << "\t	 		 		    统计学生信息请按5\n";
		cout << "\t	 		 	 	    按照英语成绩排序请按6\n";
		cout << "\t	 		 		    修改学生信息请按7\n"; 
		cout << "\t	 		 		    储存信息请按8\n";
		cout << "\t	 		 		    读取文件请按9\n";
		cout << "\t	 		 		    0.退出系统\n";
		cout << "========================================================================================================================\n";
		system("date/t");
		system("time/t");
		char ch = getch();
		switch (ch)
		{
		case '1'://录入信息
			system("CLS");
			t.addstudent(pstu);
			break;
		case '2':
			system("CLS");
			t.printstudent(pstu);
			break;//打印学生信息
		case '3':
			system("CLS");
			t.deletestudent(pstu);
			break;//保存学生信息
		case '4':
			system("CLS");
			t.search(pstu);
			break;//读取学生信息 
		case '5':
			system("CLS");
			t.statistical(pstu);
			break;
		case '6':
			system("CLS");
			t.rank(pstu);
			break;
		case '7':
			system("CLS");
			t.modifystudent(pstu);
			break;
		case '8':
			system("CLS");
			t.storestudent(pstu);
			break;
		case '9':
			t.readstudent();
			break;
		case '0':
			system("CLS");
			cout << "欢迎再次使用!\n";
			return 0;
			break;//退出程序
		default:
			cout << "		                		输入有误，请重新输入\n";
			system("pause");
			break;
		}
	}
}
void stu::addstudent(stu* p)//增加学生信息 
{
	int i, n, t;
	stu* pnew;
	pnew=p->next;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
	cout << "请输入学生的信息\n";
	cout << "请输入添加学生的数量\n";
	cin >> n;
	for (i = 0;i < n;i++)
	{
		
		pnew = new stu;
		cout << "学号:";
		cin >> t;
		t = Repeat(t, p);
		if (t == 0)
		{
			break;
		}
		pnew->num = t;
		cout << "姓名:";
		cin >> pnew->name;
		cout << "性别:";
		cin >> pnew->sex;
		cout << "专业:";
		cin >> pnew->major;
		cout << "出生日期:" << endl;
		cout << "年:";
		cin >> pnew->year;
		cout << "月:";
		cin >> pnew->month;
		cout << "日:";
		cin >> pnew->date;
		cout << "地址:";
		cin >> pnew->address;
		cout << "英语成绩:";
		cin >> pnew->englishscore;
		pnew->next = p->next;
		p->next = pnew;
		cout << "添加成功\n";
	}
	system("pause");
}
void stu::printstudent(stu* p)//显示学生信息 
{
	p = p->next;
	while (p != NULL)
	{
		cout << "学号:" << p->num << "\t";
		cout << "姓名:" << p->name << "\t";
		cout << "性别:" << p->sex << "\t";
		cout << "专业:" << p->major << "\t";
		cout << "出生日期:" << p->year << "." << p->month << "." << p->date << "\t";
		cout << "家庭地址:" << p->address << "\t";
		cout << "英语成绩:" << p->englishscore << endl;
		p = p->next;
	}
	system("pause");
}
//查重 
int stu::Repeat(int n, stu* p1)//出现重复学号无法输入 
{
R:stu* p = p1->next;
	while (p != NULL)
	{
		if (p->num == n)
		{
			cout << "此学号已有 请重新输入！" << endl;
			cout << "请输入学号";
			cin >> n;
			goto R;
		}
		p = p->next;
	}
	return n;
}
void stu::deletestudent(stu* p)//删除学生信息 
{
	stu* temp;
	stu*p1=p;
	temp = p->next;
	string name;
	cout << "输入要删除的姓名";
	cin >> name;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			p1->next = temp->next;
		}
		temp = temp->next;
		p1 = p1->next;
	}
	cout << "删除成功" << endl;
	system("pause");
}
void stu::search(stu* p)//查找学生信息 
{
	string name;
	cout << "请输入查找人的姓名\n";
	cin >> name;
	if (p->next == NULL)
	{
		cout << "抱歉查无此人" << endl;
	}
	while (p != NULL)
	{
		if (name == p->name)
		{
			cout << endl;
			cout << "                               查找人的信息\n";
			cout << "学号:" << p->num << "\t" << "姓名:" << p->name << "\t" << "性别:" << p->sex << "\t" << "专业:" << p->major << "\t" << "出生日期:" << p->year << "年" << p->month << "月" << p->date << "日" << "\t" << "家庭地址:" << p->address << "\t" << "英语成绩:" << p->englishscore << endl;
		}
		p = p->next;
	}
	system("pause");
}
void stu::statistical(stu* p)//统计学生信息数量 
{
	stu* p1 = p->next;
	string a = "专业", b = "性别", c = "年龄";
	string type;
	cout << "请输入统计的类型" << endl;
	cin >> type;
	if (type == a)//统计专业数量 
	{
		char search[100];
		cout << "请输入专业名:";
		cin >> search;
		int sum = 0;
		if (p1 == NULL)
		{
			cout << "无学生信息!";
		}
		else
		{
			while (p1 != NULL)
			{
				if (!strcmp(p1->major, search))
				{
					sum++;
				}
				p1 = p1->next;
			}
		}
		cout << search << "\n" << "总人数：" << sum << endl;
	}
	if (type == b)//统计性别数量 
	{
		int sum = 0;
		char sex[100];
		cout << "请输入性别:";
		cin >> sex;
		if (p1 == NULL)
		{
			cout << "无学生信息" << endl;
		}
		while (p1 != NULL)
		{
			if (!strcmp(p1->sex, sex))
			{
				sum++;
			}
			p1 = p1->next;
		}
		cout << sex << "\n" << "总人数:" << sum << endl;
	}
	else if (type == c)                                          //按年龄统计 
	{
		int age,age1;
		int sum=0;
		cout << "请输入您要统计的年龄：\n";
		cin >> age;
		if (p1 == NULL)
		{
			cout << "无学生信息！\n";
		}
		else
		{
			while(p1!=NULL)
			{
				age1=2020-p1->year;
				if(age==age1)
				{
					sum++;
				}
				p1=p1->next;
			}
			cout<<"总人数:"<<sum<<endl;
		}
	}
	system("pause");
}
void stu::rank(stu* p)//按照英语成绩排序 
{
	stu* p1 = new stu;
	stu* p2 = new stu;
	stu  p3;
	p1 = p->next;
	while (p1 != NULL)
	{
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p1->englishscore > p2->englishscore)
			{
				p3 = *p1;//指针域，数据域交换 
				*p1 = *p2;
				*p2 = p3;
				p3.next = p1->next;//指针域交换 
				p1->next = p2->next;
				p2->next = p3.next;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	cout << "\t\t\t\t\t入门英语成绩从低到高排序已完成" << endl;
	system("pause");
}
void stu::modifystudent(stu* p)//修改学生信息 
{
	int n;
	cout << "请输入要修改学生的学号" << endl;
	cin >> n;
	stu* p1 = new stu;
	p1 = p->next;
	if (p1 == NULL)
	{
		cout << "抱歉,查无此人" << endl;
	}
	while (p1 != NULL)
	{
		if (p1->num == n)
		{
			cout << "请输入修改的学号:" << endl;
			cin >> p1->num;
			cout << "请输入修改的姓名:" << endl;
			cin >> p1->name;
			cout << "请输入修改的性别:" << endl;
			cin >> p1->sex;
			cout << "请输入修改的专业:" << endl;
			cin >> p1->major;
			cout << "请输入修改的地址:" << endl;
			cin >> p1->address;
			cout << "请输入修改的英语成绩:" << endl;
			cin >> p1->englishscore;
			cout << "请输入修改的出生日期:" << endl;
			cout << "请输入修改的年:" << endl;
			cin >> p1->year;
			cout << "请输入修改的月:" << endl;
			cin >> p1->month;
			cout << "请输入修改的日:" << endl;
			cin >> p1->date;
		}
		p1 = p1->next;
	}
	cout << "修改成功!!" << endl;
}
void stu::storestudent(stu* p)//储存学生信息 
{
	stu* p1;
	p1 = p->next;
	ofstream fs;
	fs.open("学生信息.txt", ios::out);
	if (!fs)
	{
		cout << "无法打开学生信息。" << endl;
		exit(0);
	}
	while (p1 != NULL)
	{
		fs << "学号:"<<p1->num << "\t"<<"姓名:" << p1->name << "\t" <<"性别:"<< p1->sex << "\t" <<"专业:"<< p1->major << "\t" <<"出生日期"<< p1->year << "." << p1->month << "." << p1->date << "\t" <<"地址"<< p1->address << "\t"<<"英语成绩" << p1->englishscore << endl;
		p1 = p1->next;
	}
	cout << "存入学生信息已完成。" << endl;
	fs.close();
	system("pause");
}
void stu::readstudent()//读取学生信息 
{
	ifstream ifs;
	ifs.open("学生信息.txt",ios::in);
	if(!ifs.is_open())
	{
		cout<<"文件打开失败"<<endl;
		return;
	}
	string buf;
	while(getline(ifs,buf))
	{
		cout<<buf<<endl;
	}
	ifs.close();
	system("pause");
} 
/*else if (type == c)                                          //按年龄统计 
	{
		int age;
		cout << "请输入您要统计的年龄：\n";
		cin >> age;
		if (p1 == NULL)
		{
			cout << "无学生信息！\n";
		}
		else
		{
			int total = 0;
			time_t tt = time(NULL);                                        //这句返回的只是一个时间cuo
			tm* t = localtime(&tt);
			while (p1 != NULL)
			{
				int agenow = 0;
				if (t->tm_year + 1900 >= p1->year && t->tm_mon + 1 >= p1->month && t->tm_mday >= p1->date)
				{
					agenow = t->tm_year + 1900 - p1->year;
				}
				else
				{
					agenow = t->tm_year + 1900 - p1->year - 1;
				}
				if (agenow == age)
				{
					total++;
				}
				p1 = p1->next;
			}
			cout << "年龄为" << age << "的学生人数为：\t" << total << endl;
		}
	}
	system("pause");
}*/
