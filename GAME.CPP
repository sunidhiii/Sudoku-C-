#include<iostream.h>
#include<conio.h>
#include<fstream.h>
void main()
{	clrscr();
	int e[4][4]={ 2, 0, 4, 0,
		      0, 4, 0, 3,
		      3, 0, 0, 4,
		      0, 1, 3, 0 };

	int m[6][6]= { 5, 0, 0, 0, 6, 0,
		       0, 4, 0, 1, 0, 3,
		       1, 0, 3, 0, 4, 0,
		       0, 0, 2, 0, 1, 0,
		       0, 1, 4, 6, 0, 5,
		       0, 6, 0, 4, 0, 0 } ;

	int d[9][9]= { 0, 2, 0, 5, 0, 1, 0, 9, 0,
		       8, 0, 0, 2, 0, 3, 0, 0, 6,
		       0, 3, 0, 0, 6, 0, 0, 7, 0,
		       0, 0, 1, 3, 0, 0, 6, 0, 0,
		       5, 4, 0, 0, 2, 6, 0, 1, 9,
		       0, 0, 2, 1, 0, 0, 7, 0, 0,
		       0, 9, 0, 0, 3, 0, 0, 8, 0,
		       2, 0, 0, 8, 0, 4, 0, 0, 7,
		       0, 1, 0, 9, 0, 7, 0, 6, };

	ofstream fout("game.txt");

	cout<<"\nEASY\n";
	for(int i=0; i<4; i++)
	{	for(int j=0; j<4; j++)
		{	cout<<e[i][j]<<" ";
			fout<<e[i][j]<<" ";
		}
		cout<<endl;
	}
	fout<<endl;

	cout<<"\nMEDIUM\n";
	for(int x=0; x<6; x++)
	{	for(int y=0; y<6; y++)
		{	cout<<m[x][y]<<" ";
			fout<<m[x][y]<<" ";
		}
		cout<<endl;
	}
	fout<<endl;

	cout<<"\nDIFFICULT\n";
	for(int a=0; a<9; a++)
	{	for(int b=0; b<9; b++)
		{	cout<<d[a][b]<<" ";
			fout<<d[a][b]<<" ";
		}
		cout<<endl;
	}
	getch();
}
