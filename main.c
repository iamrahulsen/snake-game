#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>

int width = 20, height = 20, gameOver;
int x,y,fruitX,fruitY,score,flag;
int tailX[100], tailY[100];
int countTail = 0;

// setting up the random food postion and snake
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

// drawing the game grid
void draw()
{
    int i,j,k;
    system("cls");
    printf("**The snake game**\n\n");
    for(i = 0;i<width;i++)
    {
    for(j=0;j<height;j++)
        {
            if(i==0 || i==height-1 || j==0 || j==width-1)
            {
                printf("#");
            }
            else
            {
                if(i == x && j ==y)
                {
                    printf("O");
                }
                else if (i==fruitX && j==fruitY)
                {
                    printf("*");
                }
                else
                {
                    int ch = 0; // increasing the tail
                    for(k = 0; k<countTail;k++)
                    {
                        if(i == tailX[k] && j==tailY[k])
                        {
                            printf("o");
                            ch = 1;
                        }
                    }
                    if(ch == 0)
                    {
                        printf(" ");
                    }
                }
            }
        }
    printf("\n");
    }
    printf("Score: %d\n\n", score); // displaying live score
    printf("INSTRUCTION\n");
    printf("Press \nw for up\na for left\nd for right\ns for down\nand \nPress x to exit: ");
}

// taking input from the user
void input()
{
    if(kbhit())
    {
        switch (getch())
        {
            case 'a':
                flag = 1;
                break;
            case 'd':
                flag = 2;
                break;
            case 'w':
                flag = 3;
                break;
            case 's':
                flag = 4;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

// collison and movement of the snake inside the grid
void logic()
{
    int i;
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(i = 1; i < countTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
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
    if(x <= 0 || x >= width || y <= 0 || y >= height)
    {
        gameOver = 1;

    }
    for(i = 0; i<countTail; i++) {
        if ( x == tailX[i] && y==tailY[i]) {
            gameOver = 1;
            
        }
        
    }    
    
    if(x == fruitX && y == fruitY)
    {
        generate_againX1:
        fruitX = rand()%20;
        if(fruitX == 0)
        {
            goto generate_againX1;
        }
        generate_againY1:
        fruitY = rand()%20;
        if(fruitY == 0)
        {
            goto generate_againY1;
        }
        score+=10; // calculation of the score
        countTail++; // increasing the tail

    }

}

// driver program
int main()
{
    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
        for(int i = 0; i < 6000; i++)
        {
            for(int j = 0; j < 6000; j++)
            {
            }
        }
    }
    printf("\n\n Game Over!\n");
    printf("Your final Score: %d\n", score);
    getch();
    return 0;
}



