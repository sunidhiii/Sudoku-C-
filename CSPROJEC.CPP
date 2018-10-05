#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<time.h>
int easy[9][9], medium[9][9], difficult[9][9];
int r=0,c=0,v, value,size,t=0; char l;
ifstream fin("game.txt");
class level  //to select sudoku of chosen level
{	public:
	void geteasy()
	{	fin.seekg(0);
		while(fin.tellg()<=16)
		{	for(int i=0; i<4; i++)
			{	for(int j=0; j<4; j++)
					fin>>easy[i][j];
			}
		}
		size=4;
	}
	void getmed()
	{	fin.seekg(32);
		while(fin.tellg()<=68)
		{       for(int x=0; x<6; x++)
			{	for(int y=0; y<6; y++)
					fin>>medium[x][y];
			}
		}
		size=6;
	}
	void getdiff()
	{	fin.seekg(105);
		while(fin.tellg()<=186)
		{       for(int a=0; a<9; a++)
			{	for(int b=0; b<9; b++)
					fin>>difficult[a][b];
			}
		}
		size=9;
	}
}lev;
ofstream fout ("Player.txt");
class player    //to store the details of the player
{	public:
	char name[50];
	int age;
	void input()
	{	cout<<"Welcome....Let's play Sudoku";
		cout<<"\nEnter your name : ";
		gets(name);
		fout<<name<<endl;
		cout<<"\nEnter your age : ";
		cin>>age;
		fout<<age<<endl;
	}
}p;
class sudoku
{	public:
	void enter_val()    //to take input
	{	cout<<"Enter Row no.: ";
		cin>>r;
		cout<<"Enter col no.: ";
		cin>>c;
		cout<<"Enter Value : ";
		cin>>v;
	}
	int check_condn(int arr[9][9], int x, int y, int val, int s1)//to check if entered value is correct
	{       if(s1==4)
		{	for(int i=0; i<4; i++)
			{	if(val==arr[x-1][i] || val==arr[i][y-1])
					return 0;
			}
			for(i=((x-1)/2)*2; i<=(((x-1)/2)*2)+1; i++)
			{	for(int j=((y-1)/2)*2; j<=(((y-1)/2)*2)+1; j++)
				{	if(arr[i][j]==val)
						return 0;
				}
			}
			return val;
		}
		else if(s1==6)
		{	for(int i=0; i<6; i++)
			{	if(val==arr[x-1][i] || val==arr[i][y-1])
					return 0;
			}
			for(i=((x-1)/2)*2; i<=(((x-1)/2)*2)+1; i++)
			{	for(int j=((y-1)/2)*2; j<=(((y-1)/2)*2)+1; j++)
				{	if(arr[i][j]==val)
						return 0;
				}
			}
			return val;
		}
		else if(s1==9)
		{	for(int i=0; i<9; i++)
			{	if(val==arr[x-1][i] || val==arr[i][y-1])
					return 0;
			}
			for(i=((x-1)/3)*3; i<=(((x-1)/3)*3)+2; i++)
			{	for(int j=((y-1)/3)*3; j<=(((y-1)/3)*3)+2; j++)
				{	if(arr[i][j]==val)
						return 0;
				}
			}
			return val;
		}
	}
	void fill_value(int arr[9][9]) //to fill the given value in sudoku
	{	if(arr[r-1][c-1]==0)
		{      	if(value>0 && value<=9)
			{	arr[r-1][c-1]=value;
				clrscr();
			}
			else
			{	cout<<"\nInvalid value!!\n"
				    <<"\nPress ENTER to continue\n";
				getch();
			}
		}
		else
		{	cout<<"\nPlace filled!!\n"
			    <<"\nPress ENTER to continue\n";
			getch();
		}
	}
	int check(int arr[9][9],int s) //to check whether the sudoku is completely filled or not
	{	int d=0, i, j;
		for(i=0; i<size; i++)
		{	for(j=0; j<size; j++)
			{	if(arr[i][j]==0)
					d++;
			}
		}
		if(d==0)
			return 1;
		else
			return 0;
	}
void disp_easy()   //to display sudoku of easy level
{       clrscr();
	textcolor(LIGHTRED);
	cout<<"\t+---+---+ +---+---+"<<endl;
	for(int i=0; i<4; i++)
	{	cout<<"\t| ";
		for(int j=0; j<4; j++)
		{	if(j==1)
			{	if(easy[i][j]==0)
					cout<<"  | | ";
				else
				{	cprintf("%d",easy[i][j]);
					cout<<" | | ";
				}
			}
			else
			{       if(easy[i][j]==0)
					cout<<"  | ";
				else
				{	cprintf("%d",easy[i][j]);
					cout<<" | ";
				}
			}
		}
		cout<<endl;
		cout<<"\t+---+---+ +---+---+"<<endl;
		if(i==1)
			cout<<"\t+---+---+ +---+---+"<<endl;
	}
}
void disp_med()  //to display sudoku of medium level
{       clrscr();
	textcolor(LIGHTBLUE);
	cout<<"\t+---+---+ +---+---+ +---+---+"<<endl;
	for(int x=0; x<6; x++)
	{	cout<<"\t| ";
		for(int y=0; y<6; y++)
		{	if(y==1 || y==3)
			{	if(medium[x][y]==0)
					cout<<"  | | ";
				else
				{	cprintf("%d",medium[x][y]);
					cout<<" | | ";
				}
			}
			else
			{       if(medium[x][y]==0)
					cout<<"  | ";
				else
				{	cprintf("%d",medium[x][y]);
					cout<<" | ";
				}
			}
		}
		cout<<endl;
		cout<<"\t+---+---+ +---+---+ +---+---+"<<endl;
		if(x==1 || x==3)
			cout<<"\t+---+---+ +---+---+ +---+---+"<<endl;
	}
}
void disp_diff()  //to display sudoku of difficult level
{       clrscr();
	textcolor(YELLOW);
	cout<<"\t+---+---+---+ +---+---+---+ +---+---+---+"<<endl;
	for (int a=0; a<9; a++)
	{	cout<<"\t| ";
		for (int b=0; b<9; b++)
		{	if(b==2 || b==5)
			{	if(difficult[a][b]==0)
					cout<<"  | | ";
				else
				{	cprintf("%d",difficult[a][b]);
					cout<<" | | ";
				}
			}
			else
			{       if(difficult[a][b]==0)
					cout<<"  | ";
				else
				{	cprintf("%d",difficult[a][b]);
					cout<<" | ";
				}
			}
		}
		cout<<endl;
		cout<<"\t+---+---+---+ +---+---+---+ +---+---+---+"<<endl;
		if(a==2 || a==5)
			cout<<"\t+---+---+---+ +---+---+---+ +---+---+---+"<<endl;
	}
}
void result(int res) //to display player's result
{       clrscr();
	ifstream filin("Player.txt");
	if(res==1)
	{	gotoxy(28,10);
		cout<<"Congrats...You WIN!!";
		gotoxy(32, 12);
		cout<<"Well Played!";
		gotoxy(24, 14);
		cout<<"Press ENTER to see your result";
		getch();
		clrscr();
		filin.read((char*)&p, sizeof(p));
		cout<<"\nName : "<<p.name
		    <<"\n\n\Age : "<<p.age
		    <<"\n\nLevel Played : ";
		    switch(l)
		    {	  case 'e':
			  case 'E': cout<<"Easy";
				    break;
			  case 'm':
			  case 'M': cout<<"Medium";
				    break;
			  case 'd':
			  case 'D': cout<<"Difficult";
				    break;
		    }
		cout<<"\n\nTime Taken : "<<int(t/CLK_TCK)<<" seconds";
	}
	else
	{	gotoxy(34, 10);
		cout<<"Time up!!";
		gotoxy(34,12);
		cout<<"You Lose!.";
		gotoxy(28, 14);
		cout<<"Better Luck Next Time!";
	}
	filin.close();
}
}s;
void main()
{	int res;
	clrscr();
	p.input();
	cout<<endl;
	cout<<p.name<<", select your level...";
	cout<<"\nE for Easy"<<"\nM for Medium"<<"\nD for Difficult"<<endl;
	cin>>l;
	fout<<l;
	switch(l)
	{       case 'e' :
		case 'E' : clrscr();
			   cout<<"\nYou chose level : Easy";
			   cout<<"\nYou will be given 5 mins to complete this level.\n";
			   cout<<"\nPress ENTER to start\n";
			   getch();
			   lev.geteasy();
			   s.disp_easy();
			   do
			   {    t=clock();
				s.enter_val();
				value=s.check_condn(easy,r,c,v,size);
				s.fill_value(easy);
				s.disp_easy();
			   }while(s.check(easy,size)==0&&(t/CLK_TCK)<=300);
			   res=s.check(easy,size);
			   s.result(res);
			   break;
		case 'm' :
		case 'M' : clrscr();
			   cout<<"\nYou chose level : Medium";
			   cout<<"\nYou will be given 10 mins to complete this level.\n";
			   cout<<"\nPress ENTER to start\n";
			   getch();
			   lev.getmed();
			   s.disp_med();
			   do
			   {	t=clock();
				s.enter_val();
				value=s.check_condn(medium,r,c,v,size);
				s.fill_value(medium);
				s.disp_med();
			   }while(s.check(medium,size)==0&&(t/CLK_TCK)<=600);
			   res=s.check(medium,size);
			   s.result(res);
			   break;
		case 'd' :
		case 'D' : clrscr();
			   cout<<"\nYou chose level : Difficult";
			   cout<<"\nYou will be given 20 mins to complete this level.\n";
			   cout<<"\nPress ENTER to start\n";
			   getch();
			   lev.getdiff();
			   s.disp_diff();
			   do
			   {    t=clock();
				s.enter_val();
				value=s.check_condn(difficult,r,c,v,size);
				s.fill_value(difficult);
				s.disp_diff();
			   }while(s.check(difficult,size)==0&&(t/CLK_TCK)<=1200);
			   res=s.check(difficult,size);
			   s.result(res);
			   break;
		default  : cout<<"\n Wrong choice!!";
	}
	getch();
}
