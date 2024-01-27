#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> cache;
unordered_map<int,int> keyToTime;
map<int,int> timeToKey;
int presentTime=0;
int totalCapacity;

void updateTime(int key)
{
    if(keyToTime.find(key)!=keyToTime.end())
    {
        int del=keyToTime[key];
        keyToTime.erase(key);
        timeToKey.erase(del);
    }
    keyToTime[key]=presentTime;
    timeToKey[presentTime]=key;
}   

void deleteIfRequired(int key)
{
    if(cache.size()<=totalCapacity)
    {
        return;
    }
    int delkey=timeToKey.begin()->second;
    int deltime=timeToKey.begin()->first;
    cache.erase(delkey);
    timeToKey.erase(deltime);
    keyToTime.erase(delkey);    
}

int get(int key) 
{
    presentTime++;
    if(cache.find(key)!=cache.end())
    {
        updateTime(key);
        return cache[key];
    }
    return -1;
}

void put(int key, int value) 
{
    presentTime++;    
    cache[key]=value;
    updateTime(key);
    deleteIfRequired(key);
}

int main() {
	cout<<"Enter capacity"<<endl;
	int c;
	cin>>c;
	totalCapacity=c;
	cout<<"Enter queries"<<endl;
	int qn;
	cin>> qn;
	int presentTime=0;
	for(int i=0;i<qn;i++)
	{
		cout<<"Enter 1 to write or update or Enter 2 to read"<<endl;
		int val;
		cin>>val;
		if(val>2 || val<0)
		{
			cout<<"Provide valid input"<<endl;
		}
		if(val==1)
		{
			int key,value;
			cout<<"Enter key and value pair"<<endl;
			cin>>key>>value;
			put(key,value);
		}
		if(val==2)
		{
			int key;
			cout<<"Enter key "<<endl;
			cin>>key;
			int ans=get(key);
			if(ans==-1)
			{
				cout<<"Key not found"<<endl;
			}
			else
			{
				cout<<"Key"<<"  "<<key<<"  "<<"value"<<"  "<<ans<<endl;
			}
		}
	}
	return 0;
}