#pragma once
#ifndef ASTAR_H
#define ASTAR_H
#include <vector>
#include <functional>

/*
	@��˾:̶�ݽ���
	@����:C++37����Ŀ
	@����:С�����ʦ
	@�汾:1.0
*/
namespace CPP37{
	using std::vector;

	//����ڵ�
	struct Pos{
		int x;
		int y;
		Pos(int x = 0, int y = 0) :x(x), y(y){}
	};

	//·���Ľڵ�
	class Node{
	public:
		int x;				//������
		int y;				//������
		int G;				//�Ѿ��߹���·��
		int H;				//Ԥ����·��
		int getF(){ return G + H; }		//��ֵ
		Node *parent;					//ָ����һ���ߵ�·��
		Node(int x, int y, int G, int H, Node* parent = nullptr)
			:x(x), y(y), G(G), H(H), parent(parent){}
	};

	//A��Ѱ·�㷨
	class AStar{
	protected:
		vector<Node*> openList;				//׼��Ҫ�ߵ�·��
		vector<Node*> closeList;			//��׼��Ҫ�ߵ�·�����Ѿ��߹���·��

		Pos end;							//�յ�

		std::function<bool(int, int)> callBack;		//�ص�����,�ж������Ƿ�Ϸ�

		/*
			���㵱ǰλ�õ��յ�λ��Ԥ����ֵ
			now[in] ��ǰ��λ��
			return �����H��ֵ
		*/
		int getH(Pos now);

		/*
			��ʼѰ�Ҹ�����·��,����Χ�����ƶ���·������open�б�
			n [in]	��ʾ��ǰ·����λ��
		*/
		void addRound(Node* n);

		/*
			�ж������Ƿ�Ϸ�
			p �жϵ�����
			return �Ϸ��ķ���1  �Ƿ����� 0
		*/
		bool inArea(Pos p);

		/*
		�ж����·���Ƿ��Ѿ��߹���
		ls		�б�(openList,closeList)
		s		Ҫ�жϵ�����
		return  �ж�,�Ѿ��߹���,����true,û�߹�����false
		*/
		bool isVisited(vector<Node*> &ls, Pos s);

		/*
			����new�����Ľڵ�����,һ�ж����г�ʼ��
		*/
		void destory();

	public:
		//fn �����ⲿ�жϵĽӿ�
		AStar(std::function<bool(int, int)>fn);
		/*
		A��Ѱ·�㷨
			start[in]	�������
			end	[in]	�յ�����
			path[out]	��̵�·��,���������,�򷵻�һ���յ�����
			return		�ҵ�·����,����ture,û���ҵ�����false
		*/
		bool findPath(Pos start, Pos end, vector<Pos>& path);

		

	};
}


#endif //ASTAR_H