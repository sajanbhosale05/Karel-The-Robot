#include<stdio.h>
#include<stdlib.h>
char arr[4][8]= {
        {'0','0','0','0','0','0','0','#'},
        {'0','0','#','0','0','0','0','#'},
        {'0','#','#','#','0','0','0','#'},
        {'0','0','0','0','0','#','#','#'}};
int posr = 0, posc = 0; //current position of the robot
char dir = 'e'; // current head direction of the robot
void movf(int,int); // function for moveforward
void movb(int,int); // function for movrbackward
void tleft(char); // function for turn left
void tright(char); // function for turn right
void curp(); // function for get current position of the robot
void curh(); //function for get current head direction of the robot
int r = 4,c=8;
void main()
{
    int ch;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%c ",arr[i][j]);
        }
		printf("\n");
    }
    while(1)
    {
        printf("MENU\n");
        printf("1. MOVE F \n2. MOVE B\n3. TURN RIGHT\n4. TURN LEFT\n5. CURRENT POSITION\n6. CURRENT HEAD DIRECTION\n7. EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                movf(posr, posc);
                break;
            case 2:
                movb(posr, posc);
                break;
            case 3:
                tright(dir);
                break;
            case 4:
                tleft(dir);
                break;
            case 5:
                curp();
				break;
			case 6:
				curh();
				break;
			case 7:
				exit(0);
        }
    }
}
void movf(int r, int c)
{
	if(dir == 'e')
	{
		if(posc<=7 && posr<=3 && posc>=0 && posr >=0)
		{
			if(arr[posr][posc+1]!='#')
			{
				printf("MOVED\n");
				posc++;
			}
			else
			{
				printf("MOVE NOT POSSIBLE");
			}
		}
		else
		{
			printf("MOVE NOT POSSIBLE");
		}
	}
	else if(dir == 's')
	{
		if(posc<=7 && posr<=3 && posc>=0 && posr >=0)
		{
			if(arr[posr+1][posc]!='#')
			{
				printf("MOVED\n");
				posr++;
			}
			else
			{
				printf("MOVE NOT POSSIBLE");
			}
		}
		else
		{
			printf("MOVE NOT POSSIBLE");
		}
	}
	else if(dir == 'w')
	{
		if(posc<=7 && posr<=3 && posc>=0 && posr >=0)
		{
			if(arr[posr][posc-1]!='#' && posc!=0)
			{
				printf("MOVED\n");
				posc--;
			}
			else
			{
				printf("MOVE NOT POSSIBLE");
			}
		}
		else
		{
			printf("MOVE NOT POSSIBLE");
		}
	}
	else if(dir == 'n')
	{
		if(posc<=7 && posr<=3 && posc>=0 && posr >=0)
		{
			if(arr[posr-1][posc]!='#' && posr!=0)
			{
				printf("MOVED\n");
				posr--;
			}
			else
			{
				printf("MOVE NOT POSSIBLE");
			}
		}
		else
		{
			printf("MOVE NOT POSSIBLE");
		}
	}
}
void movb(int r, int c)
{
	if(dir == 'e')
	{
		if(posc<=7 && posr<=3 && posc>=0 && posr >=0)
		{
			if(arr[posr][posc-1]!='#' && posc != 0)
			{
				printf("MOVED\n");
				posc--;
			}
			else
			{
				printf("MOVE NOT POSSIBLE\n");
			}
		}
		else
		{
			printf("MOVE NOT POSSIBLE\n");
		}
	}
	else if(dir == 's')
	{
		if(posc<=7 && posr<=3 && posc>=0 && posr >=0)
		{
			if(arr[posr-1][posc]!='#' && posr!=0)
			{
				printf("MOVED\n");
				posr--;
			}
			else
			{
				printf("MOVE NOT POSSIBLE\n");
			}
		}
		else
		{
			printf("MOVE NOT POSSIBLE\n");
		}
	}
	else if(dir == 'w')
	{
		if(posc<=7 && posr<=3 && posc>=0 && posr >=0)
		{
			if(arr[posr][posc+1]!='#')
			{
				printf("MOVED\n");
				posc++;
			}
			else
			{
				printf("MOVE NOT POSSIBLE\n");
			}
		}
		else
		{
			printf("MOVE NOT POSSIBLE\n");
		}
	}
	else if(dir == 'n')
	{
		if(posc<=7 && posr<=3 && posc>=0 && posr >=0)
		{
			if(arr[posr+1][posc]!='#')
			{
				printf("MOVED\n");
				posr++;
			}
			else
			{
				printf("MOVE NOT POSSIBLE\n");
			}
		}
		else
		{
			printf("MOVE NOT POSSIBLE\n");
		}
	}
}
void tright(char d)
{
	if(d=='n')
	{
		dir = 'e';
	}
	else if(d=='e')
	{
		dir = 's';
	}
	else if(d=='s')
	{
		dir = 'w';
	}
	else if(d=='w')
	{
		dir = 'n';
	}
}
void tleft(char d)
{
	if(d=='n')
	{
		dir = 'w';
	}
	else if(d=='w')
	{
		dir = 's';
	}
	else if(d=='s')
	{
		dir = 'e';
	}
	else if(d=='e')
	{
		dir = 'n';
	}
}
void curp()
{
	printf("CURRENT POSITION : [%d %d]\n",posr,posc);
}
void curh()
{
	printf("CURRENT HEAD DIRECTION : %c\n",dir);
}