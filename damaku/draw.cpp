#include "draw.h"
#include <easyx.h>
#include <ctime>
namespace danmaku {
	Draw::Draw(int wid, int hei)
		:wid(wid),hei(hei)
	{
		srand(time(nullptr));
		initgraph(wid, hei);
	}
	Draw::~Draw()
	{
		closegraph();
	}

}