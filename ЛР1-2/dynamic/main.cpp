#include "names.hpp"
using namespace std;

// ������ �������� ����� ��-81, ���� ³�� �� ������ �����

int main()
{
	GetWriteNames gw;

	int nums[2] = { 17, 25 };
	list<string> students = gw.getNames("groupmates.txt", nums);
	gw.writeNames("selNames.txt", students);
	return 0;
}


