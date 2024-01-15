#include <bits/stdc++.h>
using namespace std;

bool isValidColumns(vector<vector<char>>& board)
{
    for(int i=0;i<9;i++)
    {
        set<char>s;
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                continue;
            }
            else if(s.find(board[i][j])!=s.end())
            {
                return false;
            }
            s.insert(board[i][j]);
        }
    }
    return true;
}
bool isValidRows(vector<vector<char>>& board)
{
    for(int j=0;j<9;j++)
    {
        set<char>s;
        for(int i=0;i<9;i++)
        {
            if(board[i][j]=='.')
            {
                continue;
            }
            else if(s.find(board[i][j])!=s.end())
            {
                return false;
            }
            s.insert(board[i][j]);
        }
    }
    return true;
}
bool isValidMatrix(vector<vector<char>>& board,int sr,int er,int sc,int ec)
{
    set<char>s;
    for( int i=sr;i<er;i++)
    {
        for(int j=sc;j<ec;j++)
        {
            if(board[i][j]=='.')
            {
                continue;
            }
            else if(s.find(board[i][j])!=s.end())
            {
                return false;
            }
            s.insert(board[i][j]);   
        }
    }
    return true;
}

bool isValidSubMatrices(vector<vector<char>>& board) {
    for(int sr=0;sr<9;sr+=3)
    {
        int er=sr+3;
        for(int sc=0;sc<9;sc+=3)
        {
            int ec=sc+3;
            if(isValidMatrix(board, sr, er, sc, ec)!=true)
            {
                return false;
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board)
{
    return isValidRows(board) 
            && isValidColumns(board) 
            && isValidSubMatrices(board);   
}
int main() {
	vector<char>temp(9);
	vector<vector<char>>board(9,temp);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>board[i][j];
		}
	}
	bool ans=isValidSudoku(board);
    if(ans==true)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
	return 0;
}