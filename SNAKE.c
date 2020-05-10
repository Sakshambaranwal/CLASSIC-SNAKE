#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int y=4,x=11;
int a,m,n,l,mz,k;
char arr[28][101];
char head=001;
char input;
int sc;
main()
{
	sc=0;
	system("COLOR E1");
	hidecursor();
	int i,j;
	for(i=0;i<28;i++)
	for(j=0;j<101;j++)
	arr[i][j]=NULL;
    for(i=0;i<101;i++)
	{
    arr[0][i]=205;
    arr[27][i]=205;
    if(i<28 && i!=0){
    arr[i][0]=186;
    arr[i][100]=186;
	}
	}
	arr[0][0]=201;
	arr[0][100]=187;
	arr[27][0]=200;
	arr[27][100]=188;
	arr[y][x]=head;
	printf("\t\t\t\t      WELCOME TO  SNAKE\n");
	printf("\t\t\t\t      -----------------\n\n");
	printf("\t\t\t\t\tSELECT LEVEL\n\n");
	printf("\t\t\t\t\t1. Easy\n");
	printf("\t\t\t\t\t2. Moderate\n");
	printf("\t\t\t\t\t3. Pro\n\n\t\t\t\t\t");
	level:scanf("%d",&l);
	if(l==1)
	    l=140;
	else if(l==2)
		l=75;
    else if(l==3)
        l=35;
    else
	{
    printf("Enter valid choice\n");
    goto level;
    }
    system("cls");
    printf("\t\t\t\t      WELCOME TO  SNAKE\n");
	printf("\t\t\t\t      -----------------\n\n");
	printf("\t\t\t\t\tSELECT MAZE\n\n");
	printf("\t\t\t\t\t1. EMPTY\n");
	printf("\t\t\t\t\t2. MAZE-1\n");
	printf("\t\t\t\t\t3. MAZE-2\n\n\t\t\t\t\t");
	maze:scanf("%d",&mz);
	if(mz>=1 && mz<=3)
	    design(mz);
    else
	{
    printf("Enter valid choice\n");
    goto maze;
    }
    system("cls");
    printf("\t\t\t\t\t\tSNAKE\n");
	for(i=0;i<28;i++){
	for(j=0;j<101;j++)
	printf("%c",arr[i][j]);
	printf("\n");}
	gotoxy(105,06);
	printf("SCORE-");
	gotoxy(105,07);
	printf("------");
	gotoxy(80,29);
	printf("-created by-SAKSHAM KUMAR");
//	do{
	control();
//	}while(check());
	getch();
}
print()
{
	/*int i,j;
	gotoxy(1,2);
	for(i=1;i<27;i++){
	for(j=1;j<100;j++)
	printf("%c",arr[i][j]);	
	gotoxy(1,i+1)
	};*/
	gotoxy(x,y+1);
	printf("%c",arr[y][x]);
	if(a==77)//right
	{
		gotoxy(x-1,y+1);
		printf("%c",arr[y][x-1]);		
	}
	else if(a==72)//up
	{
		gotoxy(x,y+2);
		printf("%c",arr[y+1][x]);	
		Sleep(20);	
	}
	else if(a==75)//left
	{
		gotoxy(x+1,y+1);
		printf("%c",arr[y][x+1]);		
	}
	else if(a==80)//down
	{
		gotoxy(x,y);
		printf("%c",arr[y-1][x]);	
		Sleep(20);	
	}
}
control()
{
	int i,j,re;
	y=4;
	x=11;
	arr[y][x]=head;
	food();
//	print();
	move:
	fflush(stdin);
	a=getch();
	/*if(a%2!=k%2)
	{
	   a=temp;
    }*/
    do
    {
    	if(a==77)//right
    	{
        	if(arr[y][x+1]!=NULL && arr[y][x+1]!=arr[m][n])
    		{
    			arr[y][x+1]=head;
    			arr[y][x]=NULL;
    			x++;
    			goto over;
			}	
			arr[y][x+1]=head;
	    	arr[y][x]=NULL;
	    	x++;
		}
		else if(a==72)//up
		{
			if(arr[y-1][x]!=NULL && arr[y-1][x]!=arr[m][n])
    		{
    			arr[y-1][x]=head;
    			arr[y][x]=NULL;
    			y--;
    			goto over;
			}
			arr[y-1][x]=head;
	    	arr[y][x]=NULL;
	    	y--;
		}
	   	else if(a==75)//left
		{
	    	if(arr[y][x-1]!=NULL && arr[y][x-1]!=arr[m][n])
    		{
    			arr[y][x-1]=head;
    			arr[y][x]=NULL;
    			x--;
    			goto over;
			}
			arr[y][x-1]=head;
	    	arr[y][x]=NULL;
	    	x--;
		}
		else if(a==80)//down
		{ 
		    if(arr[y+1][x]!=NULL && arr[y+1][x]!=arr[m][n])
    		{
    			arr[y+1][x]=head;
    			arr[y][x]=NULL;
    			y++;
    			goto over;
			}
	     	arr[y+1][x]=head;
	    	arr[y][x]=NULL;
	    	y++;
		}
		if(y==m && x==n)
		{
		food();
		sc+=160*mz/l;
		gotoxy(105,8);
		printf("%d",sc);
	    }
		print();
		Sleep(l);
	}while(!kbhit());
	//k=a;
	goto move;
	over:
		print();
    	getch();
    	getch();
    	getch();
    	arr[m][n]=NULL;
   		system("cls");
    	printf("\n\n\t\t\t\t\tNEW GAME?\n\n\t\t\t1. YES\n\t\t\t2. NO\n");
    	fflush(stdin);
   		n:scanf("%d",&re);
    	if (re==1)
    	{
		system("cls");
   		main();
     	}
    	else if(re==2)
    	exit(1);
    	else 
    	{
    		printf("Enter valid choice\n");
            goto n;
		}
		
}
design(int n)
{
	int i,j;
	switch(n)
	{
		case 1:	break;
        case 2: for(i=10;i<90;i++)
            	{
	            	if(i>40&&i<60)
		                continue;
	            	arr[9][i]='=';
	            	arr[18][i]='=';
              	}
            	for(i=4;i<23;i++)
            	{
              		if(i>9&&i<18)
	                 	continue;
	            	arr[i][40]='=';
	            	arr[i][60]='=';
             	}
		        break;
        case 3: for(i=10;i<90;i++)
            	{
	            	if(i>40&&i<60)
		                continue;
	            	for(j=6;j<22;j++)
	            	{
	            	    if(j>11&&j<16)
		                continue;
		                arr[j][i]='=';
	                }
              	}
		        break;
    }
}
food()
{
	srand(time(NULL));
	f:
	m=rand()%26+1;
	n=rand()%99+1;
	if(arr[m][n]!=NULL)
	goto f;
	arr[m][n]='*';
	gotoxy(n,m+1);
	printf("%c",arr[m][n]);
}






/*BUGS
 1. SNAKE LENGTH CONSTANT
 2. PREVIOUS SNAKE ON NEW GAME
 3. NO HIGH SCORE
 4. LAGS
 5. MOVES IN REVERSE DIRECTION ALSO*/










void gotoxy(int x1, int y1)
{
 COORD coord;
 coord.X = x1;
 coord.Y = y1;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
