#include <string>
#include <list>
using namespace std;

class GetWriteNames{
	public:
		list<string> getNames(string path, int numbers[2]);
		void writeNames(string path, list<string> students);
};
