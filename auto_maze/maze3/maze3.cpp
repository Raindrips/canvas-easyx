#include<iostream>
#include<easyx.h>
#include<vector>//可以访问的边
#include<stdlib.h>
#include<time.h>
using namespace std;

struct node
{	//flag==0  表示没有访问过   flag==1  表示已经访问过
	//flag==2  表示待访问 ---->放到map里面
	int flag;//表示关键结点是否访问过
	bool left, right, top, buttom;//表示这个节点周围的四堵墙
};

struct coor
{
	int x, y;
};
void drawMap(node arr[][25])
{
	//打通的墙  不画 
	//没有打通的墙  画一条边
	BeginBatchDraw();
	cleardevice();//清屏操作
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			if (arr[i][j].flag == 0)//没有访问过这个节点
			{
				setfillcolor(WHITE);
			}
			else if (arr[i][j].flag == 1)
			{
				setfillcolor(RGB(255, 193, 193));//访问过
			}
			else//待访问
			{
				setfillcolor(BLUE);
			}
			solidrectangle(j * 40, i * 40, j * 40 + 39, i * 40 + 39);
			if (arr[i][j].top == 0)//没有打通
			{
				line(j * 40, i * 40, j * 40 + 39, i * 40);
			}
			if (arr[i][j].buttom == 0)
			{
				line(j * 40, i * 40 + 39, j * 40 + 39, i * 40 + 39);
			}
			if (arr[i][j].left == 0)
			{
				line(j * 40, i * 40, j * 40, i * 40 + 39);
			}
			if (arr[i][j].right == 0)
			{
				line(j * 40 + 39, i * 40, j * 40 + 39, i * 40 + 39);
			}
		}
	}
	EndBatchDraw();
}

void getThrough1(node arr[][25], const coor n)//打通这个节点
{
	//判断周围的结点 有哪些是可以打通的   可以打通就打通
	if ((n.x + 1 < 20) && arr[n.x + 1][n.y].flag == 1)//下
	{
		arr[n.x + 1][n.y].top = 1;//打通两堵墙
		arr[n.x][n.y].buttom = 1;
	}
	else if ((n.y - 1 >= 0) && arr[n.x][n.y - 1].flag == 1)//左
	{
		arr[n.x][n.y - 1].right = 1;//打通两堵墙
		arr[n.x][n.y].left = 1;
	}
	else if (n.y + 1 < 25 && arr[n.x][n.y + 1].flag == 1)//右
	{
		arr[n.x][n.y + 1].left = 1;//打通两堵墙
		arr[n.x][n.y].right = 1;
	}
	else if ((n.x - 1 >= 0) && arr[n.x - 1][n.y].flag == 1)//上
	{
		//打通
		arr[n.x - 1][n.y].buttom = 1;
		arr[n.x][n.y].top = 1;
	}
}
void getThrough2(node arr[][25], const coor n)//打通这个节点
{
	//判断周围的结点 有哪些是可以打通的   可以打通就打通
	if ((n.x - 1 >= 0) && arr[n.x - 1][n.y].flag == 1)//上
	{
		//打通
		arr[n.x - 1][n.y].buttom = 1;
		arr[n.x][n.y].top = 1;
	}
	else if ((n.x + 1 < 20) && arr[n.x + 1][n.y].flag == 1)//下
	{
		arr[n.x + 1][n.y].top = 1;//打通两堵墙
		arr[n.x][n.y].buttom = 1;
	}
	else if ((n.y - 1 >= 0) && arr[n.x][n.y - 1].flag == 1)//左
	{
		arr[n.x][n.y - 1].right = 1;//打通两堵墙
		arr[n.x][n.y].left = 1;
	}
	else if (n.y + 1 < 25)//右
	{
		arr[n.x][n.y + 1].left = 1;//打通两堵墙
		arr[n.x][n.y].right = 1;
	}
}
void getThrough3(node arr[][25], const coor n)//打通这个节点
{
	//判断周围的结点 有哪些是可以打通的   可以打通就打通
	if ((n.y - 1 >= 0) && arr[n.x][n.y - 1].flag == 1)//左
	{
		arr[n.x][n.y - 1].right = 1;//打通两堵墙
		arr[n.x][n.y].left = 1;
	}
	else if (n.y + 1 < 25 && arr[n.x][n.y + 1].flag == 1)//右
	{
		arr[n.x][n.y + 1].left = 1;//打通两堵墙
		arr[n.x][n.y].right = 1;
	}
	else if ((n.x - 1 >= 0) && arr[n.x - 1][n.y].flag == 1)//上
	{
		//打通
		arr[n.x - 1][n.y].buttom = 1;
		arr[n.x][n.y].top = 1;
	}
	else if ((n.x + 1 < 20) && arr[n.x + 1][n.y].flag == 1)//下
	{
		arr[n.x + 1][n.y].top = 1;//打通两堵墙
		arr[n.x][n.y].buttom = 1;
	}

}
void getThrough4(node arr[][25], const coor n)//打通这个节点
{
	//判断周围的结点 有哪些是可以打通的   可以打通就打通
	if (n.y + 1 < 25 && arr[n.x][n.y + 1].flag == 1)//右
	{
		arr[n.x][n.y + 1].left = 1;//打通两堵墙
		arr[n.x][n.y].right = 1;
	}
	else if ((n.x - 1 >= 0) && arr[n.x - 1][n.y].flag == 1)//上
	{
		//打通
		arr[n.x - 1][n.y].buttom = 1;
		arr[n.x][n.y].top = 1;
	}
	else if ((n.x + 1 < 20) && arr[n.x + 1][n.y].flag == 1)//下
	{
		arr[n.x + 1][n.y].top = 1;//打通两堵墙
		arr[n.x][n.y].buttom = 1;
	}
	else if ((n.y - 1 >= 0) && arr[n.x][n.y - 1].flag == 1)//左
	{
		arr[n.x][n.y - 1].right = 1;//打通两堵墙
		arr[n.x][n.y].left = 1;
	}
}



int main()
{
	initgraph(25 * 40, 20 * 40);
	setfillcolor(WHITE);//填充颜色 白色
	setlinecolor(BLACK);//线条颜色  红色
	setlinestyle(PS_SOLID, 2);

	node arr[20][25] = { 0 };//每个墙 都没打通的  每个结点 都是没有访问过
	//flag=0 表示结点没有访问过   如果left   等于0  说明没有打通

	//先选中一个结点  最左上角  arr[0][0]
	arr[0][0].flag = 1;//这个节点已经访问过

	coor map[20 * 25];//存放可以访问的结点
	int len = 0;//map里面的坐标的个数

	map[len++] = { 1, 0 };//下方的结点 可以访问
	arr[1][0].flag = 2;//待访问
	map[len++] = { 0, 1 };//右边的结点 可以访问
	arr[0][1].flag = 2;//待访问
	drawMap(arr);

	srand((unsigned)time(NULL));
	int m;
	typedef void(*PFUN)(node arr[][25], const coor n);
	PFUN pfun[4] = { getThrough1, getThrough2, getThrough3, getThrough4 };
	while (len > 0)
	{
		//随机选取其中的一个结点  进行访问
		m = rand() % len;//从可以访问的结点中随机取一个
		//考虑打通这个节点  把这个节点相邻的结点放到map里面

		pfun[rand() % 4](arr, map[m]);
		arr[map[m].x][map[m].y].flag = 1;//已经访问过这个节点

		//周围的四个节点 全部放到map里面
		if (map[m].x - 1 >= 0 && arr[map[m].x - 1][map[m].y].flag == 0)
		{
			//如果上方的结点没有访问过   设置为待访问 并且把这个位置放到map里面
			arr[map[m].x - 1][map[m].y].flag = 2;
			map[len++] = { map[m].x - 1, map[m].y };
		}
		if (map[m].x + 1 < 20 && arr[map[m].x + 1][map[m].y].flag == 0)
		{
			//下
			arr[map[m].x + 1][map[m].y].flag = 2;
			map[len++] = { map[m].x + 1, map[m].y };
		}
		if (map[m].y - 1 >= 0 && arr[map[m].x][map[m].y - 1].flag == 0)
		{
			//左
			arr[map[m].x][map[m].y - 1].flag = 2;
			map[len++] = { map[m].x, map[m].y - 1 };
		}
		if (map[m].y + 1 < 25 && arr[map[m].x][map[m].y + 1].flag == 0)
		{
			//右
			arr[map[m].x][map[m].y + 1].flag = 2;
			map[len++] = { map[m].x, map[m].y + 1 };
		}
		//map[m]已经访问过  从map里面删掉就可以
		map[m] = map[len - 1];
		len--;
		drawMap(arr);
		//Sleep(1000);

	}






	drawMap(arr);
	getchar();
	closegraph();
	return 0;
}