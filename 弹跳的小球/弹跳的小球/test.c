#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int i = 0;
	int x = 5;
	int y = 10;

	//int height = 20;//设置边界
	int left = 0;
	int right = 20;
	int top = 0;
	int bottom = 10;//设置边界
	int velocity_x = 1;//设置速度变量
	int velocity_y = 1;
	while (1)
	{
		x += velocity_x;//小球的新位置
		y += velocity_y;
		system("cls");//清屏函数
		for (i = 0; i < x; i++)
		{
			printf("\n");//小球上方的空格
		}
		for (i = 0; i < y; i++)
		{
			printf(" ");
		}
		printf("o");
		printf("\n");
//		sleep(10);
		if (x == top ||x == bottom) 
			velocity_x = -velocity_x;
		if (x == top || x == bottom)
			velocity_y = -velocity_y;
	}
	return 0;
}