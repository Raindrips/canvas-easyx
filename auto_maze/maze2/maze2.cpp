/*
本次课内容  迷宫生成
下次课内容  迷宫寻路

================================================
C/C++区别   面向过程和面向对象/有类/有新的输入输出格式/有封装好的模板库

项目课的区别   使用不同的方式来写项目

迷宫生成的思路

	1. 递归方法生成迷宫
			先把大的地图分割成四块   随意打通其中的三块
			  把四块小地图继续拆分  拆到不能再拆为止
	2. 深度寻路法生成迷宫
		  将地图上的关键结点  全部打通 形成一条能够遍历所有结点的方式
		  从一个点出发  打通相邻的结点 (每次打通的新的结点 随机性不是很强)
	3. Prim生成迷宫
		从其中的一个结点出发  把能够打通的位置放入数组  随机从中取出一条边打通
		将新的结点可以打通的位置  放入数组


	行和列 一定是奇数

	int map[13][15]
	数组里面的下标  下标是0   第一行/列  外墙
					行下标12   外墙  列下标14  外圈

		如果行下标和列下标都是偶数(一定不能打通的)
		行下标和列下标都是奇数(关键结点  一定是空的)
		其余的位置都是可以打通的


		打通所有的关键结点



*/

#include<iostream>
#include<vector>//vector<vector<int>> arr;//相当于二维数组
#include<stdlib.h>
#include<time.h>
using namespace std;

struct COOR
{
	int x, y;
};
class map
{
	int m_map[13][15];//改成动态数组也可以
	//墙 1  空地 0
public:
	map()//初始化一个随机的地图数组
	{
		//第一步  所有的结点先准备好  同时其余地方全部都视为墙
		vector<COOR> key;//相当于结构体数组  存放还没有访问过的结点
		int len = 0;
		memset(m_map, 0, sizeof(m_map));
		for (int i = 0; i < 13; ++i)
		{
			for (int j = 0; j < 15; ++j)
			{
				if (i % 2 != 0 && j % 2 != 0)
				{
					//关键结点
					key.push_back({ i,j });//尾插
				}
				else//墙
				{
					m_map[i][j] = 1;
				}
			}
		}
		//打通 是两个关键结点的位置
		vector<COOR> node;//存放已经访问过的节点
		vector<COOR> wall;//存放可以打通的墙
		//先选中其中的一个关键结点  然后把周围的所有能够打通的位置全部放入容器中
		int m;
		COOR temp;
		//先从key中随便取出一个节点
		m = rand() % key.size();
		node.push_back(key[m]);//放到已经访问的结点当中
		//周围的能够打通的墙 全部都放到这个wall里面
		//判断上下左右能不能放进去  如果可以放到wall里面 那么就放
		//如果放不了 那么就算了
		if (key[m].x - 1 != 0 && m_map[key[m].x - 1][key[m].y] == 1)//上
		{//key[m].x-1!= 0 判断是不是外墙 
		 //m_map[key[m].x - 1][key[m].y] == 1 判断这个边是不是打通过
			wall.push_back({ key[m].x - 1, key[m].y });//把这条边放进去
		}
		if (key[m].x + 1 != 12 && m_map[key[m].x + 1][key[m].y] == 1)//下
		{
			wall.push_back({ key[m].x + 1, key[m].y });//把这条边放进去
		}
		if (key[m].y - 1 != 0 && m_map[key[m].x][key[m].y - 1] == 1)//左
		{
			wall.push_back({ key[m].x, key[m].y - 1 });//把这条边放进去
		}
		if (key[m].y + 1 != 14 && m_map[key[m].x][key[m].y + 1] == 1)
		{
			wall.push_back({ key[m].x, key[m].y + 1 });//把这条边放进去
		}
		key.erase(key.begin() + m);//在key中删除这个元素
		//随机从wall里面选择一堵墙  打通
		//这个墙  打通的另外一边是否已经访问过  如果访问过 这个墙直接去掉
		//否则 打通这个墙  同时墙另外一边的结点作为下一个要访问的结点

		m = rand() % wall.size();//得到随机的一堵墙
		//wall[m].x  wall[m].y(墙的位置)
		//坐标 x是奇数还是偶数 判断  上下  左右
		//两个节点是否都访问过
		//一个访问过  一个没访问过 ---->打通
		//将没有访问的结点 作为下一个要访问的位置
		if (wall[m].x % 2 != 0)
		{
			//x是奇数 说明 判断上下两边是否都访问过  如果都访问过的话  换一堵墙
			//wall[m].x-1,y
			//wall[m].x+1,y
			temp = { wall[m].x - 1, wall[m].y };
			//循环判断node里面有没有temp相同的元素
		}

		//重复上面的步骤   直到所有的结点全部访问为止


		//key还没有访问的结点
		//node 访问过的结点
		// wall 存放可以打通的墙

	}
};
int main()
{
	srand((unsigned)time(NULL));

	//递归  先周围先赋值墙
	int myMap[13][15];
	map m;
	return 0;
}





/*

动态数组+模板  ====  vector






*/