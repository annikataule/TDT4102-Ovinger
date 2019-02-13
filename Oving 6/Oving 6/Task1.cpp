#include "Task1.h"
#include "std_lib_facilities.h"

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
	ifstream ifs{ inputPath }; // Try opening file
	if (!ifs)
		error("Cant open file ", inputPath);
	else 
	{
		vector<string> lines; //Create vector of lines
		while (!ifs.eof()) // Read all the lines
		{
			line.clear();
			getline(ifs, line);
			cout << line << endl;
			lines.push_back(line);
		}
		ifs.close();
		ofstream ofs{ outputPath }; // Prepeare to output to file
		if (!ofs)
			error("Cant open file ", outputPath);
		else
		{
			for (int i = 0; i < lines.size(); ++i)
			{
				ofs << setw(to_string(lines.size()).size()) << i + 1 << " " << lines[i] << endl; // Write all lines with linenumer with a specific width
			}
		}
		
	}
}
