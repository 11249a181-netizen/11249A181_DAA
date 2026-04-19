#include <stdio.h>
#include<conio.h>
void tower (int num, char source, char dest, char spare);
int main()
{
	int num;
	printf("enter the number of disks:");
	scanf("%d", &num);
	printf("\n the sequence of moves involved in towers of hanoi:\n");
	towers(num,'A','C','B');
	return 0;
}
void towers(int num,char source,char dest,char spare)
{
	if (num == 1)
	{
		printf("\n move disk 1 from %c to %c", source ,dest);
		return;
	}
	towers(num-1, source, spare,dest);
	printf("\n move disk %d from %c to %c", num,source, dest);
	towers(num-1,spare,dest,source);
	getch();
}
