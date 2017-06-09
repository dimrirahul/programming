#include <iostream>
#include <array>

using namespace std;

struct Intersection {
	array<int, 4> lights;
	void readIntersection() {
		for (auto &it : lights) {
			cin >> it;			
		}
	}
};

using Iarray = array<Intersection, 4>;

bool bothOn(const Iarray& iArray, int myIndex, int myLightIndex, int otherIndex) {
	return (iArray[myIndex].lights[myLightIndex] == 1) &&
	 (iArray[otherIndex].lights[3] == 1 || iArray[myIndex].lights[3] == 1);
}

bool checkLeft(const Iarray& iArray, int index) {
	return bothOn(iArray, index, 0, (index + 3) % 4);
}

bool checkStraight(const Iarray& iArray, int index) {
	return bothOn(iArray, index, 1, (index + 2) % 4);
}

bool checkRight(const Iarray& iArray, int index) {
	return bothOn(iArray, index, 2, (index + 1) % 4);
}

bool isCollision(const Iarray& iArray, int index) {
	if (checkLeft(iArray, index)) return true;
	if (checkStraight(iArray, index)) return true;
	if (checkRight(iArray, index)) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	Iarray iArray;
	for (auto &it : iArray)
		it.readIntersection();
	bool res = false;
	for (int i = 0; i < iArray.size(); i++) {
		res = isCollision(iArray, i);
		if (res) break;
	}
	cout << (res ? "YES" : "NO") << "\n";
	return 0;
}