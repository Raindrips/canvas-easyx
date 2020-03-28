#pragma once
#ifndef ASTAR_H
#define ASTAR_H
#include <vector>
#include <functional>

/*
	@公司:潭州教育
	@版期:C++37期项目
	@作者:小雨滴老师
	@版本:1.0
*/
namespace CPP37{
	using std::vector;

	//坐标节点
	struct Pos{
		int x;
		int y;
		Pos(int x = 0, int y = 0) :x(x), y(y){}
	};

	//路径的节点
	class Node{
	public:
		int x;				//横坐标
		int y;				//纵坐标
		int G;				//已经走过的路径
		int H;				//预估的路径
		int getF(){ return G + H; }		//和值
		Node *parent;					//指向上一条走到路线
		Node(int x, int y, int G, int H, Node* parent = nullptr)
			:x(x), y(y), G(G), H(H), parent(parent){}
	};

	//A星寻路算法
	class AStar{
	protected:
		vector<Node*> openList;				//准备要走的路径
		vector<Node*> closeList;			//正准备要走的路径和已经走过的路径

		Pos end;							//终点

		std::function<bool(int, int)> callBack;		//回调函数,判断数据是否合法

		/*
			计算当前位置到终点位置预估的值
			now[in] 当前的位置
			return 计算出H的值
		*/
		int getH(Pos now);

		/*
			开始寻找附近的路径,将周围可以移动的路径加入open列表
			n [in]	表示当前路径的位置
		*/
		void addRound(Node* n);

		/*
			判断数据是否合法
			p 判断的坐标
			return 合法的返回1  非法返回 0
		*/
		bool inArea(Pos p);

		/*
		判断这调路径是否已经走过了
		ls		列表(openList,closeList)
		s		要判断的坐标
		return  判断,已经走过了,返回true,没走过返回false
		*/
		bool isVisited(vector<Node*> &ls, Pos s);

		/*
			销毁new出来的节点数据,一切都进行初始化
		*/
		void destory();

	public:
		//fn 传入外部判断的接口
		AStar(std::function<bool(int, int)>fn);
		/*
		A星寻路算法
			start[in]	起点坐标
			end	[in]	终点坐标
			path[out]	最短的路径,如果不存在,则返回一个空的容器
			return		找到路线了,返回ture,没有找到返回false
		*/
		bool findPath(Pos start, Pos end, vector<Pos>& path);

		

	};
}


#endif //ASTAR_H