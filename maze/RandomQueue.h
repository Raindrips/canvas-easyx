#include <vector>
#include <ctime>
using namespace std;
template <typename E>
class RandomQueue {

private:
  vector<E> que;

public:
  RandomQueue() {
	srand(time(nullptr));
  }

  void push_back(E e) {
	que.push_back(e);
  }

  E pop_back() {
	if (que.size() == 0)
	  throw exception("There's no element to remove in Random Qeuue");

	int randIndex = (rand() % que.size());

	E randElement = que.at(randIndex);
	que.at(randIndex) = que.at(que.size() - 1);
	que.pop_back();
	return randElement;
  }
  int size() {
	return que.size();
  }
  boolean empty() {
	return size() == 0;
  }
};