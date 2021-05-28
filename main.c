#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int width = 20, height = 20, gameOver;
int x,y,fruitX,fruitY,score,flag;

void setup()
{
    gameOver = 0;
    x = width/2;
    y = height/2;

    generate_againX:
    fruitX = rand()%20;
    if(fruitX == 0)
    {
        goto generate_againX;
    }
    generate_againY:
    fruitY = rand()%20;
    if(fruitY == 0)
    {
        goto generate_againY;
    }
    score = 0;
}
void draw()
{
    int i,j;
    system("cls");
    for(i = 0;i<width;i++)
    {
    for(j=0;j<height;j++)
        {
            if(i==0 || i==height-1 || j==0 || j==width-1)
            {
                printf("*");
            }
            else
            {
                if(i == x && j ==y)
                {
                    printf("O");
                }
                else if (i==fruitX && j==fruitY)
                {
                    printf("F");
                }
                else
                {
                    printf(" ");
                }
                
            }
            
        }
    printf("\n");
    }
}

void input()
{
    if(kbhit())
    {
        switch (getch())
        {
            case 'a':
                flag = 1;
                break;
            case 's':
                flag = 2;
                break;
            case 'w':
                flag = 3;
                break;
            case 'z':
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
    switch (flag)
    {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            break;
        default:
            break;
    }

}

void game_name()
{
    printf("**The snake game**\n\n");
}

int main()
{
    game_name();
    setup();
    while(1)
    {
        draw();
        input();
        logic();

    }
    return 0;
}