#include "names.hpp"
using namespace std;

// Робота студентів групи ІТ-81, Пиріг Віри та Федчук Олени

int main()
{
	GetWriteNames gw;

	int nums[2] = { 17, 25 };
	list<string> students = gw.getNames("groupmates.txt", nums);
	gw.writeNames("selNames.txt", students);
	return 0;
}


