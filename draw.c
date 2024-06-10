#include <stdio.h>
#include <string.h>

#define ONE '1'
#define TWO '2'
#define THREE '3'
#define FOUR '4'
#define FIVE '5'
#define SIX '6'
#define SEVEN '7'
#define EIGHT '8'
#define NINE '9'
#define ZERO ' '

#define COL 136
#define ROW 35  //declare x-1,y-1

int before_draw();
int drawing(char paper[ROW][COL]);
void print_paper(char paper [ROW][COL]);

int main()
{
	char paper [ROW] [COL];
	memset(paper,ZERO,sizeof(paper)); //ROW*COL);  //init a array

	if ((before_draw() != 0)) return -1;
	char a;

	while(1)
	{
		if ((drawing(paper)) !=0 )
		{
			printf("number is too big,it over paper.\n");
		}

		printf("draw again?You can input ctrl-c to quit.\n\n");
		/*fflush(stdin);
		fflush(stdin);
		scanf("%c",&a);
		if (a != 'y')
		{
			printf("a=%c\n",a);
			return 0;
		}*/
	}	   
	


}

int before_draw()
{
	printf("if you want to start,press \' y \',or not. ");

	int ok;
	ok = getchar();
	return ok == 'y'? 0: -1;
}

int drawing(char paper[ROW][COL])
{
	int x,y;
	printf("input x :");
	scanf("%d",&x);

	printf("input y :");
	scanf("%d",&y);

	if (x>=COL || y>=ROW) return -1;

	int num;
	printf("input you want draw(1~9)");
	scanf("%d",&num);

	if (num<0 || num>9)
	{
		printf("please input agian! if you want to quit,input clrl_c,if you want to print,input p.\n");
		return -1;
	}

	paper[y][x] = num==1 ?ONE:num==2 ?TWO:num==3 ?THREE :num==4 ?FOUR :num==5 ?FIVE :num==6 ?SIX:num==7 ?SEVEN:num==8?EIGHT:NINE;
	if (num == 0)  paper[y][x] = ZERO; //eraser
	print_paper(paper);
	return 0;
}

void print_paper(char paper [ROW][COL])
{
	int i,j;
	for (i=0;i<ROW;i++)
	{
		for (j=0;j<COL;j++)
		{
			printf("%c",paper [i][j]);
		}
	}
}

void find_point(char paper [ROW][COL],int x,int y)
{
	if (paper [y][x] == ONE)  printf("the point is one.\n");
}









