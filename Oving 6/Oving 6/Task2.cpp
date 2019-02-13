#include "Task2.h"
#include "std_lib_facilities.h"

void countCharInTxt(string path)
{
	ifstream ifs{ path };
	if (!ifs)
	{
		error("Cant open file ", path);
		return;
	}
	string text, line;
	while (!ifs.eof()) // Read all the lines
	{
		line.clear();
		getline(ifs, line);
		text += line;
	}

	vector<int> chars(26);

	for (const auto c : text) 
	{
		if ((c <= 255 && c > -1) && isalpha(c))
			chars[tolower(c) - 'a'] += 1;
	}

	for (int i = 0; i < chars.size(); i += 3)
	{
		for (int j = i; j < i + 3 && j < chars.size(); ++j)
		{
			cout << (char)((j)+(int)'a') << ":\t" << chars[j] << "\t\t";
		}
		cout << endl;
	}

}
