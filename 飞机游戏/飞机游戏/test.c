#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x = 5;
	int y = 10;
	int i, j;
	char input;
	//int isfire = 0;
	while (1)
	{
		system("cls");//«Â∆¡
		for (i = 0; i < x; i++)
		{
			printf("\n");
		}
		for (j = 0; j < y; j++)
		
			printf(" ");
		printf("  *  ");
		printf("\n");
		for (j = 0; j < y; j++)

			printf(" ");
		printf("*****");
		printf("\n");
		for (j = 0; j < y; j++)

			printf(" ");
		printf(" * * ");
		printf("\n");
		//øÿ÷∆∑…ª˙
		scanf_s("%c", &input);
		if (input == 'a')//
			y--;
		if (input == 'd')
			y++;
		if (input == 's')
			x--;
		if (input == 'w')
			x++;
		if (input == ' ')
	}
	return 0;
}