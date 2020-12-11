#include "names.hpp"
#include <fstream>
using namespace std;

void GetWriteNames::writeNames(string path, list<string> students)
{
	ofstream file(path, ios::out);

	for(string s : students /*int i=0; i<students.size(); i++*/)
	{
		file << s/*students[i]*/ << endl;
	}
	file.close();
}

