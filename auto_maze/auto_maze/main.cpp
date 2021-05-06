#include<iostream>
#include<easyx.h>
#include<stdlib.h>
#include<time.h>
using namespace std;


//递归要做的事情  先分成四块 然后四块打通其中的 三块
//四块继续细分

//left 左   
void part(int myMap[][45], int left, int right, int top, int buttom)
{
	if (left + 2 >= right || top + 2 >= buttom) return;
	//分的时候  取中间值并且 xy必须是偶数  //换成随机值
	int x = (left + right) / 2;
	x += x % 2 != 0 ? 1 : 0;
	int y = (top + buttom) / 2;
	y += y % 2 != 0 ? 1 : 0;
	//随机在四边打通三个位置
	for (int i = left + 1; i < right; ++i) myMap[y][i] = 1;//横着的墙
	for (int j = top + 1; j < buttom; ++j) myMap[j][x] = 1;

	//上方   左边  下方
	myMap[y - 1][x] = myMap[y][x - 1] = myMap[y + 1][x] = 0;
	//换成用随机数控制方向



	part(myMap, left, x, top, y);
	part(myMap, x, right, top, y);
	part(myMap, left, x, y, buttom);
	part(myMap, x, right, y, buttom);
}

int main()
{
	srand((unsigned)time(NULL));
	//递归  先周围先赋值墙
	int myMap[31][45] = { 0 };
	for (int i = 0; i < 31; ++i)
	{
		for (int j = 0; j < 45; ++j)
		{
			if (i == 0 || j == 0 || i == 30 || j == 44) myMap[i][j] = 1;
		}
	}
	myMap[1][0] = myMap[29][44] = 0;//入口和出口

	part(myMap, 0, 44, 0, 30);

	initgraph(45 * 20, 31 * 20);
	setfillcolor(LIGHTGRAY);
	for (int i = 0; i < 31; ++i)
	{
		for (int j = 0; j < 45; ++j)
		{
			if (myMap[i][j] == 1)
			{
				fillrectangle(j * 20, i * 20, j * 20 + 20, i * 20 + 20);
			}
		}
	}



	getchar();
	closegraph();
	return 0;
}


