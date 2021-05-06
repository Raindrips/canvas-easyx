// damaku.cpp: 定义应用程序的入口点。
//

#include "main.h"
#include "Danmaku.h"
using namespace std;
using namespace danmaku;

void test1() {
	Danmaku d(600,600);
	d.start();
	system("pause");
}

int main()
{
	test1();
	
	return 0;
}
