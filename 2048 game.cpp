#include<bits/stdc++.h>
#define n 6
#define m n
using namespace std;


void upmove(int a[n][m])		    //for upward movement	
{

	for(int j=0;j<m;j++)
	{
		int li=0,ri=j;
		for(int i=1;i<n;i++)
		{
			if(a[i][j]!=0)
			{
				if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[++li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}

void downmove(int a[n][m])          //for downward movement
{

	for(int j=0;j<m;j++)
	{
		int li=n-1,ri=j;
		for(int i=n-2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void leftmove(int a[n][m])                  //for leftmove
{
	for(int i=0;i<n;i++)
	{
		int li=i,ri=0;
		for(int j=1;j<m;j++)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][++ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void rightmove(int a[n][m])                     //for rightmovement
{
	for(int i=0;i<n;i++)
	{
		int li=i,ri=m-1;
		for(int j=m-2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void addblock(int a[n][m])                  // to add new element in the array
{
	srand(time(0));
	/*
	
	srand() - gives the random function a new seed, a starting point (usually random numbers are calculated by taking the 
	previous number (or the seed) and then do many operations on that number to generate the next).
	time(0) - gives the time in seconds since the Unix epoch, which is a pretty good "unpredictable" seed 
	(you're guaranteed your seed will be the same only once, unless you start your program multiple times within the same second).
	
	*/
	while(1)
	{
		int li=rand()%n;
		int ri=rand()%m;
		if(a[li][ri]==0)
		{
			a[li][ri]=pow(2,li%2 + 1);	//	return 2 or 4		if li is even then a[i][j]=2 else a[i][j]=4	
			break;
		}
	}

}

void printdash()
{
		for(int i=0;i<n;i++)
			cout<<"----";
}

void disp(int a[n][m])      //to display the game
{
	cout<<"\n\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\n\n";

	for(int i=0;i<n;i++)
	{
		cout<<"\t\t\t\t";
			printdash();
		cout<<"\n\t\t\t\t";
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t";
	printdash();
	cout<<"\n";
}

bool check(int tmp[n][m],int a[n][m])		//check whether prev array is same as the new one or not 
{
	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		if(tmp[i][j]!=a[i][j])
    			return false;
	return true;
}

bool game_win(int a[n][m])			    //check for the winner
{
		for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		if(a[i][j]==2048)
				return true;
		return false;
}

bool checkover(int a[n][m])									//check whether game is over or not
{
	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		if(a[i][j]==0)
				return true;	
			
	for(int i=0;i<n-1;i++)
    	for(int j=0;j<m-1;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
    				return true;
    		
	return false;
}

int main()
{
	cout<<"\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
	
	int i1,i2,i3,i4,i,j;
	int a[n][m]={0},tmp[n][m]={0};
	srand(time(0));
	i1=rand()%n;
	i2=rand()%m;
	while(1)
	{
		i3=rand()%n;
		i4=rand()%m;
		if(i3!=i1 && i4!=i2) break;
	}
	a[i1][i2]=2;
	a[i3][i4]=2;
	disp(a);
	
	char ch;
	while (1)
    {
    	for(i=0;i<n;i++)
    		for(j=0;j<m;j++)
    			tmp[i][j]=a[i][j];
        cin>>ch;
    	if(ch=='w'||ch=='W') upmove(a);					// W key value of upward move
    	if(ch=='s'||ch=='S') downmove(a);				// S key value of downward move
    	if(ch=='a'||ch=='A') leftmove(a);				// A key value of left move
    	if(ch=='d'||ch=='D') rightmove(a);				// D key value of right move
		if(ch=='x'||ch=='X') break;                     // A
		
		if(!check(tmp,a))						//check where the move by the playes is valid or not
			addblock(a);
		disp(a);
			
		if(!checkover(a))							//check where the game is end or not
		{
			cout<<"\n\n\t\t\tGAME OVER !!!!\n\n\n";
		    cin>>ch;
			exit(0);
		}	
		if(game_win(a))
		{
			cout<<"\n\n\t\t\tYou Won The GAME (^^) (^^) (^^)!!!!\n\n\n";
			cin>>ch;
			exit(0);
		}
	}
	return 0;
}