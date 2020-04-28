#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <conio.h> /*���������ȡ*/

bool gameOver;
bool stop = false;
bool hit = false;

/*��Ϸ�ı߿��С*/
const int width = 50;
const int height = 20;

/*�ߵ����꣬ʳ������껹�з���*/
int x,y,fruitX,fruitY,score;

/*��ÿ���������*/
int tailX[200],tailY[200];

/*�ߵ�Ĭ�ϳ���*/
int ntail=3;
typedef enum

{
 
STOP = 0,
LEFT,
RIGHT,
UP,
DOWN
}Direction;

Direction Dir;

/*��ʼ�˵�*/
void menu()

{

int a;
printf("------------------------------------------------------------------\n");
printf("| ̰������Ϸ |\n");
printf("| 1) ����Ϸ |\n");
printf("| 2) ��ʼ�߽� |\n");
printf("| 3) �˳���Ϸ |\n");
printf("------------------------------------------------------------------\n");
printf("---->���������ѡ��:");
scanf("%d", &a);

}

/*��ʼ��״̬*/
void setup()

{

gameOver = false;
/*���ݵ�ǰʱ�����á���������ӡ�*/
srand(time(NULL));
Dir = STOP;
/*̰���ߵ�λ��,�̶����м�*/
x= width/2;
y= height/2;
/*ʳ���λ�ã�λ���������*/
fruitX = rand()%width;
fruitY = rand()%height;
score = 0;

}

/*���ƽ���*/
void draw()

{

if(stop == true)

{

return;

}

system("cls");/*�����Ļ*/
printf("����:%d",score);
printf("\n");

/*��һ��*/
int i;
for(i= 0 ;i<width+1;i++)

{
	
printf("-");

}

printf("\n");

/*���м�Ļ���*/
int p;
for(p= 0 ;p<height;p++)/*�߶�*/

{

int q;
for(q= 0 ;q<width;q++)/*���*/

{

/*��һ������Ѹ��ַ�*/

if(q==0 || q==width-1)

{

printf("|");

}

if(p == fruitY && q == fruitX)/*ʳ����������*/

{

printf("O");

}

else

{

int k=0;

bool print = false;

/*̰���ߵĳ��� Ĭ�ϳ����� 3*/
for(k=0;k<ntail;k++)

{

if(tailX[k]==q && tailY[k]==p)

{

printf("*");

print = true;

}

}

/*������λ�ô�ӡ�� * �Ͳ�Ҫ��ӡ�ո���*/
if(!print)

{

printf(" ");

}

}

}

printf("\n");

}

/*���һ��*/
int j;
for(j= 0 ;j<width+1;j++)

{

printf("-");

}

}

/*�����������*/
void input()

{

if(_kbhit())

{

/*��ȡ���̵������ַ�*/
switch(_getch())

{

case '4':
case 75:/*���*/
Dir = LEFT;
hit= true;
break;
case '8':
case 72:/*�ϼ�*/
Dir = UP;
hit= true;
break;
case '6':
case 77:/*�Ҽ�*/
Dir = RIGHT;
hit= true;
break;
case '2':
case 80:/*���¼��̼� */
Dir = DOWN;
hit= true;
break;
case 'x':
case 27:/*ESE*/
gameOver = true;
break;
case 32:/*�ո� ��ͣ��*/
stop = !stop;
break;

}

}

else if(!hit && stop == false)/*���û�иı䷽��*/

{

x++;

}

}

/*�ж�̰���ߵĳ���*/

void logic()

{

if(stop == true)

{

return;

}

/*����һ��λ�ü���*/
int lastX = tailX[0];
int lastY = tailY[0];
int last2X, last2Y;

/*���»�ȡ��ǰ��λ��*/
tailX[0]=x;
tailY[0]=y;
int i=0;

/*���������ߵĳ��� �� 0 ��λ�ÿճ����������ߵ�λ��������Ŀռ��ƶ�*/
for(i=1; i<ntail;i++)

{

last2X = tailX[i];
last2Y = tailY[i];
tailX[i]=lastX;
tailY[i]=lastY;
lastX = last2X;
lastY = last2Y;

}

/*���ݷ������ı�x y ��ֵ*/
switch(Dir)

{

case UP:
y--;
break;
case DOWN:
y++;
break;
case LEFT:
x--;
break;
case RIGHT:
x++;
break;

}

if(x<0 || width<x || y<0 || height<y)

{

gameOver = true;

/*�����Ļ*/
system("cls");
printf("------------------------------------------------------------------\n");
printf("| |\n");
printf("| |\n");
printf("| ��Ϸ���� |\n");
printf("| |\n");
printf("| |\n");
printf("------------------------------------------------------------------\n");

}

if(x==fruitX && y==fruitY)

{

/*����һ��ʳ��ߵĳ�������1*/
ntail++;
score+=10;

/*������һ��ʳ���λ��*/
fruitX = rand()%width;
fruitY = rand()%height;

}

}

int main()

{

#if 0
while(1)

{

printf("%d\n",_getch());

}

#endif
menu();
setup();
draw();

/*ѭ����̰���ߵĽ���*/
while(!gameOver)

{

draw();
input();
logic();
Sleep(70);

}

return 0;

}
