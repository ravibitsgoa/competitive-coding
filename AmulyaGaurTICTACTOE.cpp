/*
Author : Amulya Gaur
Run this code in c++ ide and follow the instructions.
Have fun!
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
char a[3][3];
void print()
{
	cout<<" --- --- --- "<<endl;
	cout<<"| "<<a[0][0]<<" | "<<a[0][1]<<" | "<<a[0][2]<<" |"<<endl;
	cout<<" --- --- --- "<<endl;
	cout<<"| "<<a[1][0]<<" | "<<a[1][1]<<" | "<<a[1][2]<<" |"<<endl;
	cout<<" --- --- --- "<<endl;
	cout<<"| "<<a[2][0]<<" | "<<a[2][1]<<" | "<<a[2][2]<<" |"<<endl;
	cout<<" --- --- --- "<<endl;
}
int main()
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    	a[i][j]=' ';
  cout<<"Welcome to Tic-Tac-Toe Game"<<endl;
  print();
  cout<<endl;
  cout<<"This will be your playground"<<endl<<"Player 1 and 2 will enter the coordinate of the block(0 based indexing) which they want to fill"<<endl;
  cout<<"Character for player 1 is X and for player 2 is O"<<endl;
  cout<<"Initial state is "<<endl;
  print();
  cout<<endl<<"Lets play!"<<endl;
  while(1)
  {
  	int x1,y1,x2,y2,empty1=0,empty2=0,r1,c1,d11,d12,r2,c2,d21,d22;
  	for(int i=0;i<3;i++)
  		for(int j=0;j<3;j++)
  			if(a[i][j]==' ')
  				empty1++;
    if(empty1==0)
    {
    	cout<<"Game Tie! See you again!"<<endl;
    	break;
    }
    else
    {
    	while(1)
    	{
    		cout<<"Player 1"<<endl;
    		cin>>x1>>y1;
    		if(x1>=0 && x1<=2 && y1>=0 && y1<=2 && a[x1][y1]==' ')
    			break;
    		else
    			cout<<"Invalid coordinate! try again"<<endl;
    	}
    	a[x1][y1]='X';
    	cout<<"playground looks like:"<<endl;
    	print();
    	r1=0,c1=0,d11=0,d12=0;
    	for(int i=0;i<3;i++)
    	{
    		if(a[x1][i]=='X')
    			r1++;
    		if(a[i][y1]=='X')
    			c1++;
    	}
    	if(x1==y1)
    	{
    		for(int i=0,j=0;i<3 && j<3;i++,j++)
    			if(a[i][j]=='X')
    				d11++;
    	}
    	if((x1+y1)==2)
    	{
    		if(a[0][2]=='X')
    			d12++;
    		if(a[1][1]=='X')
    			d12++;
    		if(a[2][0]=='X')
    			d12++;
    	}
    }
    if(r1==3 || c1==3 || d11==3 || d12==3)
    {
    	cout<<"Player 1 wins! Thanks for playing!"<<endl;
    	break;
    }
    else
    {
    	empty2=0;
    	for(int i=0;i<3;i++)
    		for(int j=0;j<3;j++)
    			if(a[i][j]==' ')
    				empty2++;
    	if(empty2==0)
    	{
    		cout<<"Game Tie! See you again!"<<endl;
    		break;
    	}
    	else
    	{
    		while(1)
    		{
    			cout<<"Player 2"<<endl;
    			cin>>x2>>y2;
  				if(x2>=0 && x2<=2 && y2>=0 && y2<=2 && a[x2][y2]==' ')
  					break;
	 				else
  					cout<<"Invalid coordinate! try again"<<endl;
    		}
    		a[x2][y2]='O';
    		cout<<"playground looks like:"<<endl;
    		print();
    	 	r2=0,c2=0,d21=0,d22=0;
    		for(int i=0;i<3;i++)
    		{
    			if(a[x2][i]=='O')
    				r2++;
    			if(a[i][y2]=='O')
    				c2++;
    		}
    		if(x2==y2)
    		{
    			for(int i=0,j=0;i<3 && j<3;i++,j++)
    				if(a[i][j]=='O')
    					d21++;
    		}
    		if((x2+y2)==2)
    		{
    			if(a[0][2]=='O')
    				d22++;
    			if(a[1][1]=='O')
    				d22++;
    			if(a[2][0]=='O')
    				d22++;
    		}
			}
    	if(r2==3 || c2==3 || d21==3 || d22==3)
    	{
    		cout<<"Player 2 wins!"<<endl;
    		break;
    	}
    }
    empty2=0;
    for(int i=0;i<3;i++)
    	for(int j=0;j<3;j++)
    		if(a[i][j]==' ')
    			empty2++;
  	if(empty2==0)
		{
			cout<<"Game Tie! See you again!"<<endl;
    	break;
  	}
  }
  return 0;
}
