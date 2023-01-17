#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include"graphics.h"
#include <cstring>
//#include <conio.h>
#include <queue>
using namespace std;
template <typename T>
void print(queue <T>& obj)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	int count = obj.size();
	for (int a = 0; a < count; a++)
	{
		string name;
		name = obj.front();
		setfillstyle(SOLID_FILL, YELLOW);
		circle(300, 13 + 25 * a, 10);
		floodfill(300, 13 + 25 * a, WHITE);
		settextstyle(10, 0, 1);
		bgiout << name;
		outstreamxy(5, 5 + 25 * a);
		obj.push(obj.front());
		obj.pop();
	}
	getch();
	cleardevice();
	closegraph();
	cout << endl;
}
int main()
{
	int gd = DETECT, gm; // compiler that what graphics driver to use
	queue <string> obj;
	int players;
	string name;
	cout << "enter the number of players max is 15" << endl;
	cin >> players;
	while (players > 15)
	{
		cout << "wrong input" << endl;
		cin >> players;
	}
	cout << "Set the gap for elimination" << endl;
	int gap;
	cin >> gap;
	for (int a = 0; a < players; a++)
	{
		cout << "enter the name of player" << a + 1 << endl;
		cin >> name;
		obj.push(name);
	}
	srand(time(0));
	int randomstart = rand() % obj.size();
	for (int a = 0; a < randomstart; a++)
	{
		obj.push(obj.front());
		obj.pop();
	}
	initgraph(&gd, &gm, "");
	setcolor(YELLOW);
	string a;
	a = obj.front();
	settextstyle(10, 0, 1);
	bgiout << a; // basically a cout statement but not on console
	outstreamxy(300, 200);
	outtextxy(150, 150, " RANDOMLY SELECTED TO START IS");
	getch();
	closegraph();
	print(obj);
	while (obj.size() != 1)
	{
		for (int a = 0; a < gap; a++)
		{
			obj.push(obj.front());
			obj.pop();
		}

		initgraph(&gd, &gm, "");
		setcolor(MAGENTA);

		a = obj.front();
		settextstyle(10, 0, 1);
		bgiout << a;
		outstreamxy(300, 200);
		outtextxy(240, 150, "ONE IS ELIMINATED");
		obj.pop();
		getch();
		cleardevice();
		outtextxy(180, 200, " THE REMAINING ROSTER IS FOLLOWING");
		getch();

		closegraph();
		initgraph(&gd, &gm, "");
		print(obj);
		//getch();

		closegraph();

	}
	initgraph(&gd, &gm, "");
	setcolor(GREEN);
	string x = obj.front();
	settextstyle(10, 0, 1);
	bgiout << x;
	outstreamxy(300, 200);
	outtextxy(240, 150, "THE WINNER OF GAME IS");
	obj.pop();
	getch();
	closegraph();

	system("pause");
	return 0;

}
