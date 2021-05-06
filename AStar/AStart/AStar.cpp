// AStart.cpp
#include "AStar.h"
#include <iostream>
using namespace std;

namespace CPP37{
	AStar::AStar(function<bool(int,int)>fn)
		:callBack(fn){}

	int AStar::getH(Pos now){
		return abs(end.x - now.x) + abs(end.y - now.y);
	}

	bool AStar::findPath(Pos start, Pos end, vector<Pos>& path)
		
	{
		bool result=false;			//是否找到终点
		this->end = end;			//终点坐标赋值
		Node* endNode = nullptr;	//终点的坐标节点

		//将起点加入close列表
		closeList.push_back(new Node(start.x, start.y, 0, getH(start)));

		int  length = 0;
		while (length<closeList.size()&&!endNode)
		{
			length = closeList.size();
			addRound(closeList.back());

			Node* minF=nullptr;			//储存最小的F值
			int minIndex = 0;			//最小的下标值
			for (int i = 0; i < openList.size(); i++)
			{
				Node*n = openList[i];
				//判断是否已经找到了终点了
				if (n->x==end.x&&n->y==end.y)
				{
					endNode = n;
					result = true;
					break;
				}
				if (!minF||minF->getF()>n->getF())
				{
					minF = n;
					minIndex = i;
				}
			}
			//如果找到最小的F值,则将其从openList添加到closeList上
			if (minF)
			{
				openList.erase(openList.begin()+minIndex);
				closeList.push_back(minF);
			}
			
		}

		//后续,判断是否找到了终点
		if (result)
		{
			vector<Pos> tmp;
			//反向遍历从终点到起点的路线
			while (endNode){
				tmp.push_back(Pos(endNode->x,endNode->y));
				endNode= endNode->parent;
			}
			path.assign(tmp.rbegin(), tmp.rend());
		}
		destory();
		return result;
	}

	void AStar::addRound(Node* n){
		//上下左右四个方向
		static Pos dir[] = { 
		  { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }, 
		  //{ 1, 1 }, { -1, -1 }, { 1, -1 }, { -1, 1 },	 //可以斜着走
		};

		for (auto v : dir){
			v.x += n->x;
			v.y += n->y;
			if (inArea(v))
			{
				//将可以走过的路线加入open列表
				openList.push_back(new Node(v.x, v.y, n->G + 1, getH(v), n));
			}
		}
	}

	bool AStar::inArea(Pos p){
		if (!callBack(p.x,p.y) ||isVisited(openList,p)||isVisited(closeList,p))
		{
			return false;
		}
		return true;
	}

	bool AStar::isVisited(vector<Node*> &ls, Pos s){
		for (auto &e : ls){
			if (e->x==s.x&&e->y==s.y)
			{
				return true;
			}
		}
		return false;
	}

	void  AStar::destory(){
		for (Node *n : openList){
			delete n;
		}

		for (Node *n : closeList){
			delete n;
		}

		openList.clear();
		closeList.clear();
	}
}