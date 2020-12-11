#include "names.hpp"
#include <fstream>
using namespace std;

list<string> GetWriteNames::getNames(string path, int numbers[2])
{
	int i;

	ifstream file(path, ios::in);
	string line;
	list<string> lines;

	while(getline(file, line))
	{
		i++;
		if (i == numbers[0] || i == numbers[1])
		{
			lines.push_back(line);
		}
	}
	file.close();
	return lines;
}

