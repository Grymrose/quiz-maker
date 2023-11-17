#include <string>
#include <vector>
#include <lib/json.hpp>


class FileIO{
private:
	std::string Path;
public:
	FileIO();
	~FileIO();
	void SaveData(vector <Question>);
	vecotr <Question> LoadData();
}

/*
======== ISSUES ========
The vector <String> Data will not be used.
It cannot logically do an complete store of all question objects and its data into JSON.
It has been replaced with vector <Question> instead.

It is recommended to use serialization instead of JSON parsing.
See: https://www.boost.org/doc/libs/1_36_0/libs/serialization/doc/index.html
*/
