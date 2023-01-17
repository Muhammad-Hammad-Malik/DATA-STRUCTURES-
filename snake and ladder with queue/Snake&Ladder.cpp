#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
int main()
{
	
	bool GameEnd=false;
	string name;
	queue <int> score;
	queue <string> playername;
	queue <int> tempscore;
	queue <string> tempplayername;
	queue <string> results;
	int NumberOfPlayers;
	cout<<"enter number of players"<<endl;
	cin>>NumberOfPlayers;
	srand(time(0));
	int dicevalue=0;
	int points;
	int iteration=0;
	
	for(int a=0;a<NumberOfPlayers;a++)
	{
		cout<<"enter name of player "<<a+1<<endl;
		cin>>name;
		playername.push(name);
		score.push(0);
    }
    int sizef=playername.size();
	while(!GameEnd)
    {
	if(sizef==1)
	{
		GameEnd=true;
		system("cls");
		cout<<" GAME END "<<endl;
	}
	else
	{
	cout<<endl<<endl<<"IT IS "<<playername.front()<<" 's TURN TO PLAY "<<endl;
	system("pause");
	points=score.front();
	dicevalue=rand()%6+1;
	points=points+dicevalue;
	if(points>100)
	{
		cout<<"Value exceeded try next time"<<endl;
		points=points-dicevalue;
	}
	if(points==20)
	{
		cout<<endl<<"ladder activated"<<endl;
		points=40;
	}
	
	if(points==60)
	{
		cout<<endl<<"ladder activated"<<endl;
		points=75;
	}
	if(points==50)
	{
		cout<<endl<<"snake activated"<<endl;
		points=40;
	}
	if(points==90)
	{
		cout<<endl<<"snake activated"<<endl;
		points=79;		
	}
	cout<<" you have gotten a "<<dicevalue<<" total points are"<<points<<endl;
	system("pause");
		if(points<100)
		{
		
		tempplayername.push(playername.front());
		playername.pop();
		tempscore.push(points);
		score.pop();
		}
		else if(points==100)
		{
		sizef--;
		iteration--;
		cout<<playername.front()<<" has reached the target"<<endl<<endl<<endl;
		results.push(playername.front());
		playername.pop();
		
		score.pop();
		}
	iteration++;
	}
	if(iteration==sizef)
	{
		iteration=0;
		playername=tempplayername;
		score=tempscore;
		for(int a=0;a<sizef;a++)
		{
			tempplayername.pop();
			tempscore.pop();
		}
	}
	}
	
	results.push(playername.front());
	playername.pop();
	int resultsize=results.size();
	for(int a=0;a<resultsize;a++)
	{
		cout<<a+1<<" postion is "<<results.front()<<endl;
		results.front();
		results.pop();
	}
	
}