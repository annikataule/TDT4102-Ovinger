#include "Task1.h"

void cinToFile(string path)
{
	string line;
	ofstream ofs{ path };
	if (!ofs)
		error("Cant open file ", path); // Error handling
	else
	{
		cout << "Enter lines that will be put in " << path << ". End input by typing 'quit'" << endl;
		do
		{
			cin >> line;
			if (line != "quit")
				ofs << line << endl;
		} while (line != "quit");
	}
	ofs.close();
}

void addLineNumber(string inputPath, string outputPath)
{
	string line;
	ifstream ifs{ inputPath };
	if (!ifs)
		error("Cant open file ", inputPath);
	else 
	{
		vector<string> lines;
		while (ifs.eof())
		{
			getline(ifs, line);
			cout << line << endl;
			lines.push_back(line);
		}
		ifs.close();
		ofstream ofs{ outputPath };
		if (!ifs || !ofs)
			error("Cant open file ", outputPath);
		else
		{
			for (int i = 0; i < lines.size(); ++i)
			{
				ofs << setw(lines.size()) << i + 1 << " " << lines[i] << endl;
			}
		}
		
	}
}
