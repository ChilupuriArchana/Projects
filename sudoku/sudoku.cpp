#include <bits/stdc++.h>
using namespace std;
bool isValidSubMatrices(vector<vector<char>>& board,int sr,int er,int sc,int ec)
{
    set<char>s;
    for(int i=sr;i<er;i++)
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
bool isvalid(vector<vector<char>>& board)
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
    for(int sr=0;sr<9;sr+=3)
    {
        int er=sr+3;
        for(int sc=0;sc<9;sc+=3)
        {
            int ec=sc+3;
            if(isValidSubMatrices(board, sr, er, sc, ec)!=true)
            {
                return false;
            }
        }
    }
    return true;
}
bool cal(vector<vector<char>>& board,int i,int j)
{
    if(i==9)
    {
        return 1;
    }
    else if(j==9)
    {
        return cal(board,i+1,0);
    }
    else if(board[i][j]!='.')
    {
        return cal(board,i,j+1);
    }
    else
    {
        bool ch;
        for(int num=1;num<=9;num++)
        {
            board[i][j]='0'+num;
            if(isvalid(board)==1)
            {
                ch=cal(board,i,j+1);
                if(ch==1)
                {
                    return 1;
                }
            }
            board[i][j]='.';
        }
    }
    return 0;
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
    cal(board,0,0);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}