#include <bits/stdc++.h>
using namespace std;
bool diag1(vector<string> &board,char ch)
{
	int cnt=0;
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<3;i++)
		{
			if(i==j && board[i][j]==ch)
			{
				cnt++;
			}
		}
	}
	if(cnt==3)
	{
		return 1;
	}
	return 0;
}
bool diag2(vector<string> &board,char ch)
{
	int cnt=0;
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<3;i++)
		{
			if(i+j==2 && board[i][j]==ch)
			{
				cnt++;
			}
		}
	}
	if(cnt==3)
	{
		return 1;
	}
	return 0;
}
bool isWinnerExist(vector<string> &board ,char ch)
{	
	for(int i=0;i<3;i++)
	{
		int cnt=0;
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==ch)
			{
				cnt++;
			}
		}
		if(cnt==3)
		{
			return 1;
		}
	}
	for(int j=0;j<3;j++)
	{
		int cnt=0;
		for(int i=0;i<3;i++)
		{
			if(board[i][j]==ch)
			{
				cnt++;
			}
		}
		if(cnt==3)
		{
			return 1;
		}
	}
	if(diag1(board,ch)==1)
	{
		return 1;
	}
	if(diag2(board,ch)==1)
	{
		return 1;
	}
	return 0;
}
void print(vector<string> &board)
{
	cout<<"*****"<<endl;
	for(int i=0;i<3;i++)
    {
        cout<<board[i]<<endl;
    }
    cout<<"*****"<<endl;
}
bool isValid(int i,int j,vector<string>& board)
{
	if(i>2 ||i<0 || j<0 || j>2 ||board[i][j]!='.')
	{
		return 0;
	}
	return 1;
}
int main() {
	string temp="...";
    vector<string>board(3,temp);
    bool flag=true;
    cout<<"Initial Board"<<endl;
    print(board);
    for(int i=0;i<9;)
    {
    	if(i%2==0)
    	{
    		cout<<"Player 1 turn"<<endl;
    	}
    	else
    	{
    		cout<<"Player 2 turn"<<endl;
    	}
    	cout<<"Please provide input. Example: 1 2"<<endl;
    	int r1,c1;
    	cin>>r1>>c1;
    	if(isValid(r1,c1,board)==0)
    	{
    		cout<<"Invalid input"<<endl;
    	}
    	else 
    	{
    		if(i%2==0)
	    	{
	    		board[r1][c1]='X';
	    		if(isWinnerExist(board,'X')==1)
	    		{
	    			print(board);
	    			cout<<"Player 1 is the winner"<<endl;
	    			flag=false;
	    			break;
	    		}
	    	}
	    	else
	    	{
	    		board[r1][c1]='O';
	    		if(isWinnerExist(board,'O')==1)
	    		{
	    			print(board);
	    			cout<<"Player 2 is the winner"<<endl;
	    			flag=false;
	    			break;
	    		}
	    	}
	    	print(board);
	    	i++;
    	}	
    }
    if(flag ==true)
    {
    	cout<<"Draw"<<endl;
    }
	return 0;
}