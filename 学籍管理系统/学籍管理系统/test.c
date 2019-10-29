//	编写一个学生信息管理系统，主要用来管理学生基本信息及成绩信息。
//1、建立学生信息，每个学生的信息包括：学号、姓名、性别、班级、成绩；
//2、求出每个学生的平均分；
//3、排序：分别按平均分排序、按学号排序；
//4、根据学号查询成绩；
//5、输出。

#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define AMOUNT 2//定义一个常量，控制操作学生的数量
struct Student//定义一个学生结构体
{
	int num;//学号
	char name[20];//姓名
	int chinese_grade;//语文成绩
	int English_grade;//英语成绩
	int math_grade;//数学成绩
};
struct Student stu[AMOUNT] = { 0 };//定义学生结构体数组，用于存放多个学生信息
void menu()
{
	printf("*******************************\n");
	printf("******   1.输入信息    ********\n");
	printf("******   2.求平均分    ********\n");
	printf("******   3.排序        ********\n");
	printf("******   4.查询        ********\n");
	printf("******   5.输出        ********\n");
	printf("******   6.退出        ********\n");
	printf("*******************************\n");
}
void sort_menu()//排序菜单
{
	printf("*********************\n");
	printf("*** 1.平均分排序*****\n");
	printf("*** 2.学号排序  *****\n");
	printf("*********************\n");
}
void num_sort()
{
	int tmp = 0;
	int arr2[] = { 0 };
	int i = 0;
	for (i = 0; i < AMOUNT; i++)
	{
		arr2[i] = stu[i].num;
	}
	for (i = 0; i < AMOUNT - 1; i++)
	{
		int j = 0;
		for (j = 0; j < AMOUNT - i - 1; j++)
			if (arr2[i] >arr2[i + 1])
			{
				tmp = arr2[i];
				arr2[i] = arr2[i + 1];
				arr2[i + 1] = tmp;
			}
	}
	for (i = 0; i < AMOUNT; i++)
	{
		printf("%d ", arr2[i]);
	}
}
void grade_sort()//平均分排序
{
	int tmp = 0;
	int arr1[] = { 0 };
	int i = 0;
	for (i = 0; i < AMOUNT; i++)
	{
		arr1[i] = (stu[i].chinese_grade + stu[i].English_grade + stu[i].math_grade) / 3;
	}
	for (i = 0; i < AMOUNT-1; i++)
	{
		int j = 0;
		for (j = 0; j < AMOUNT-i-1;j++)
			if (arr1[i] >arr1[i + 1])
			{
				tmp = arr1[i];
				arr1[i] = arr1[i + 1];
				arr1[i + 1] = tmp;
			}
	}
	for (i = 0; i < AMOUNT; i++)
	{
		printf("%d ", arr1[i]);
	}
}
void input()//输入信息函数
{        
	int i = 0;
	for (i = 0; i < AMOUNT; i++)
	{
		printf("请输入信息\n");
		scanf("%d %s %d %d %d", &stu[i].num,&stu[i].name,&stu[i].chinese_grade,&stu[i].English_grade,&stu[i].math_grade);
		printf("信息确认：\n%d %s %d %d %d\n", stu[i].num, stu[i].name, stu[i].chinese_grade, stu[i].English_grade, stu[i].math_grade);
	}
}
void average()
{
	    int i = 0;
		for(i = 0; i < AMOUNT; i++)
		{
			int ret = (stu[i].chinese_grade + stu[i].English_grade + stu[i].math_grade) / 3;
			printf("平均分为%d：%d\n",ret,i+1);
		}
	
}
void sort()
{
	sort_menu();
	int input2 = 0;
	while (1)
	{
		scanf("%d", &input2);
		if (input2 == 1)
			grade_sort();
		else if (input2 == 2)
		{
			num_sort();
		}
		else
			printf("您的输入有误,请重新输入\n");
	}
}
void inquire()
{
	int i = 0;
	scanf("%d", &i);
	int j = 0;
	for (j = 0; j < AMOUNT; j++)
	{
		if (i == stu[j].num)
		printf("语文成绩：%d", stu[j].chinese_grade);
		printf("数学成绩：%d", stu[j].math_grade);
		printf("英语成绩：%d", stu[j].English_grade);
		printf("平均成绩;%d", (stu[j].chinese_grade + stu[j].English_grade + stu[j].math_grade) / 3);
	}
}
void test()
{
	printf("请输入密码\n");
	int input1 = 0;
	int i = 0;
	scanf("%d", &i);
	if (i == 123456)//secret
	{
		menu();
		while (1)
		{
			printf("请选择->\n");
			scanf("%d", &input1);
			switch (input1)
			{
			case 1://录入信息
				input();
				break;
			case 2://求平均成绩
	     		average();
				break;
			case 3:
				sort();//排序
				break;
			case 4://查询
				inquire();
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
			}
		}
	}
	
}
int main()
{
	test();
	return 0;
}