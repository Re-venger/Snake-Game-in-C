/*
Built-in functions that i used
kbhit() - 
rand() - 
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>

int width = 20;
int height = 20;
int i, j, flag, gameOver;
int x, y, fruitx, fruity;
int gameScore;



void setup(){

	gameOver = 0;

	x = height/2;
	y = width / 2;

	label3:
		fruitx = rand()%20;
		if(fruitx == 0)
			goto label3;

	label4:
		fruity = rand()%20;
		if(fruity == 0)
			goto label4;
		gameScore = 0;
}			




// function to draw the grid
void Draw(){

	system("cls");
	for(int i = 0; i < height;i++)
	{
		for(int j = 0; j < width; j++)
		{
			if(i == 0 || i == width-1 || j == 0 || j == height-1)
			{
				printf("#");
			}
			else{
				if(i == x && j == y)			//this checks if the current position is eaqual to position of snake
				{
					printf("0");
				}
				else if(i == fruitx && j == fruity)			//this checks if the current position is eaqual to position of fruit
				{
					printf("^");
				}else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	printf("Score: %d", gameScore);
	printf("\n");
	printf("Press x to quit the game\n");
}


void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				flag = 1;
				break;
			case 's':
				flag = 2;
				break;
			case 'd':
				flag = 3;
				break;
			case 'w':
				flag = 4;
				break;
			case 'x':
				gameOver = 1;
				break;
		}
	}
}

void logic()
{
	sleep(0.998);
	switch(flag){
		case 1:
			y--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y++;
			break;
		case 4:
			x--;
			break;
		default:
			break;
	}

	if(x < 0 || x > height || y < 0 || y > width)
	{
		printf("x: %d, y: %d",x, y);
		gameOver = 1;
	}

	// set the location of the fruit
	if(x == fruitx && y == fruity){
		label1:
			fruitx = rand()%20;
			if(fruitx == 0)
				goto label1;

		label2:
			fruity = rand()%20;
			if(fruity == 0)
				goto label2;
			gameScore += 10;
	}
}

int main(){

	setup();

	while(!gameOver)
	{
		Draw();
		input();
		logic();
	}
	return 0;
}