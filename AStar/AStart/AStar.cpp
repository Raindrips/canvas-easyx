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
		bool result=false;			//�Ƿ��ҵ��յ�
		this->end = end;			//�յ����긳ֵ
		Node* endNode = nullptr;	//�յ������ڵ�

		//��������close�б�
		closeList.push_back(new Node(start.x, start.y, 0, getH(start)));

		int  length = 0;
		while (length<closeList.size()&&!endNode)
		{
			length = closeList.size();
			addRound(closeList.back());

			Node* minF=nullptr;			//������С��Fֵ
			int minIndex = 0;			//��С���±�ֵ
			for (int i = 0; i < openList.size(); i++)
			{
				Node*n = openList[i];
				//�ж��Ƿ��Ѿ��ҵ����յ���
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
			//����ҵ���С��Fֵ,�����openList��ӵ�closeList��
			if (minF)
			{
				openList.erase(openList.begin()+minIndex);
				closeList.push_back(minF);
			}
			
		}

		//����,�ж��Ƿ��ҵ����յ�
		if (result)
		{
			vector<Pos> tmp;
			//����������յ㵽����·��
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
		//���������ĸ�����
		static Pos dir[] = { 
		  { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }, 
		  //{ 1, 1 }, { -1, -1 }, { 1, -1 }, { -1, 1 },	 //����б����
		};

		for (auto v : dir){
			v.x += n->x;
			v.y += n->y;
			if (inArea(v))
			{
				//�������߹���·�߼���open�б�
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