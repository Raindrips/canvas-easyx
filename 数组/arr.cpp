#include <iostream>
#include <vector>
#include <algorithm>
#include <easyx.h>
#include <ctime>
#include <string>
#include <graphics.h>
#include <random>
#include <conio.h>
#include <cstdlib>

using namespace std;

class SortGraph {
private:

  int pos;
  long speed = 100;
  vector<int> vec;
  void Rect(int index, int val, COLORREF color) {
	setfillcolor(color);
	fillrectangle(index * pos, hei - val, (index + 1) * pos - 5, hei);
  }

public:
  friend ostream& operator<<(ostream& os, const SortGraph& sg);
  int hei = 600, wid = 800;
  SortGraph(vector<int>& v) {
	this->vec = v;
	pos = wid / v.size();
	initgraph(wid, hei, SHOWCONSOLE);
	srand(time(NULL));
  }

  void drawSelectArr(vector<int>& v, int l, int r, int min) {
	BeginBatchDraw();
	cleardevice();
	for (int i = 0; i < v.size(); i++)
	{
	  if (i < l)
	  {
		Rect(i, v[i], 0xcccccc);
	  }
	  else if (min == r && r == i) {
		Rect(i, v[i], 0x6633ff);
	  }
	  else if (i == r)
	  {
		Rect(i, v[i], 0x33ffff); ;
	  }

	  else if (i == min)
	  {
		Rect(i, v[i], 0xff6633);
	  }
	  else {
		Rect(i, v[i], 0x66ff33);
	  }

	}
	EndBatchDraw();
  }
  void drawBubbleArr(vector<int>& v, int l, int r) {
	BeginBatchDraw();
	cleardevice();
	for (int i = 0; i < v.size(); i++)
	{
	  if (i < l)
	  {
		Rect(i, v[i], 0xcccccc);
	  }
	  else if (i == r)
	  {
		Rect(i, v[i], 0x33ccdd); ;
	  }
	  else if (i == l)
	  {
		Rect(i, v[i], 0xcc6633);
	  }
	  else {
		Rect(i, v[i], 0x66dd33);
	  }
	}
	EndBatchDraw();
  }
  void drawInsertArr(vector<int>& v, int l, int r) {
	BeginBatchDraw();
	cleardevice();
	for (int i = 0; i < v.size(); i++)
	{
	  if (i > l)
	  {
		Rect(i, v[i], 0x3333aa);
	  }
	  else if (i == r)
	  {
		Rect(i, v[i], 0x33ccdd);
	  }
	  else if (i == r - 1)
	  {
		Rect(i, v[i], 0xcc33dd);
	  }
	  else {
		Rect(i, v[i], 0x66dd33);
	  }
	}
	EndBatchDraw();
  }
  void drawArr(vector<int>& v, int l, int mid, int r) {
	  BeginBatchDraw();
	  cleardevice();
	  for (int i = 0; i < v.size(); i++)
	  {
		  if (i < l)
		  {
			  Rect(i, v[i], 0x3333aa);
		  }
		  else if (i > r)
		  {
			  Rect(i, v[i], 0x33ccdd);
		  }
		  else if (i == mid)
		  {
			  Rect(i, v[i], 0xcc33dd);
		  }
		  else {
			  Rect(i, v[i], 0x66dd33);
		  }
	  }
	  EndBatchDraw();
  }

  void random(int l, int r) {
	for (size_t i = 0; i < vec.size(); i++)
	{
	  vec[i] = rand() % r + l;
	}
  }

  void setSpeed(int speed) {
	this->speed = speed;
  }

  void selectSort() {
	int min = 0;

	for (size_t i = 0; i < vec.size(); i++)
	{
	  int min = i;
	  for (size_t j = i + 1; j < vec.size(); j++)
	  {
		if (vec[j] < vec[min]) {
		  min = j;
		}
		drawSelectArr(vec, i, j, min);
		Sleep(speed);
	  }
	  cout << vec[min] << endl;
	  Sleep(speed);
	  swap(vec[i], vec[min]);
	  drawSelectArr(vec, i, i, min);
	}
	drawSelectArr(vec, -1, -1, -1);
  }

  void bubbleSort() {
	for (size_t i = 0; i < vec.size(); i++)
	{
	  for (size_t j = i + 1; j < vec.size(); j++)
	  {
		if (vec[j] < vec[i]) {
		  swap(vec[j], vec[i]);
		}
		drawBubbleArr(vec, i, j);
		Sleep(speed);
	  }
	}
	drawBubbleArr(vec, -1, -1);
	Sleep(speed);
  }
  void insertSort() {
	for (size_t i = 0; i < vec.size(); i++)
	{
	  for (size_t j = i; j > 0; j--)
	  {
		drawInsertArr(vec, i, j);
		Sleep(speed);
		if (vec[j] < vec[j - 1])
		{
		  swap(vec[j], vec[j - 1]);
		}
		else {
		  break;
		}
	  }
	  drawInsertArr(vec, i, i);
	  Sleep(speed);
	}
	drawInsertArr(vec, -1, -1);
  }

  void mergeSort() {
	resolve(0, vec.size() - 1);
  }
  void quickSort() {
	quickSort(0,vec.size()-1);
  }


private:
  void resolve(int l, int r) {
	if (l < r)
	{
	  int mid = (l + r) / 2;
	  resolve(l, mid);
	  resolve(mid + 1, r);
	  merge(l, mid, r);
	}
  }

  void merge(int l, int mid, int r) {
	vector<int> aux(vec.begin() + l, vec.begin() + r + 1);
	size_t lk = l, rk = mid + 1;
	for (int i = l; i <= r; i++)
	{
	  if (lk > mid)
	  {
		vec[i] = aux[rk - l];
		rk++;
	  }
	  else if (rk > r) {
		vec[i] = aux[lk - l];
		lk++;
	  }
	  else if (aux[lk - l] < aux[rk - l]) {
		vec[i] = aux[lk - l];
		lk++;
	  }
	  else {
		vec[i] = aux[rk - l];
		rk++;
	  }
	  drawArr(vec, l, mid, r);
	  Sleep(speed);
	}
  }

  void quickSort(int l, int r) {
	if (l < r)
	{
	  int p = partition(l, r);
	  quickSort(l, p - 1);
	  quickSort(p + 1,r);
	}

  }

  int partition(int l, int r) {
	int p = l;
	int val = vec[l];

	for (int i = l; i <= r; i++)
	{
	  if (vec[i] < val)
	  {
		p++;
		swap(vec[i], vec[p]);
		drawArr(vec, l, p, r);
		Sleep(speed);
	  }	
	}
	swap(vec[l], vec[p]);
	drawArr(vec, l, p, r);
	Sleep(speed);
	return p;
  }

};
ostream& operator<<(ostream& os, const SortGraph& sg)
{
  os << "[";
  for (size_t i = 0; i < sg.vec.size(); i++)
  {
	os << sg.vec[i] << " ";
  }
  os << "\b" << "]";
  return os;
}

//主函数
int main()
{
  vector<int> v(50, 0);
  SortGraph s(v);
  s.setSpeed(100);
  s.random(10, s.hei);
  //选择排序
 // s.selectSort();
  //冒泡排序
  //s.bubbleSort();
  //插入排序
  //s.insertSort();
  //归并排序
  s.mergeSort();
  //快速排序
  //s.quickSort();
  cout << s << endl;
  return getchar();
}
