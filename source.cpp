#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
const int Size = 60;
const int MAX_NUM = 50;
string name[MAX_NUM];

int read(int x)
{
	const int size = Size;
	char filename[size];
	int count = 0;

	ifstream inFile;
	cout << "Enter name of data file: ";
	cin.getline(filename, size);
	cout << "File opening......\n";
	inFile.open(filename);
	Sleep(3 * 1000);

	if (!inFile.is_open())
	{
		cout << "\aCould not open the file \"" << filename << "\"\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	inFile >> name[count];
	while (inFile.good())
	{
		++count;
		inFile >> name[count];
	}
	if (inFile.eof())
	{
		cout << "\aEnd of file reached.\n";
	}
	else if (inFile.fail())
	{
		cout << "\aInput terminated by data mismatch.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "\aInput terminated by unknown reason.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	if (count == 0)
	{
		cout << "\aNo data processed.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "There are " << count + 1 << " data in total.\n";
	}
	inFile.close();

	return count;
}

int main()
{
	int r_count = read(0);
	cout << "Random drawing is processing......\n";
	srand(time(0));
	int(n) = (rand() % r_count);
	Sleep(5 * 1000);

	cout << "\aGod's kiss falls on " << name[n] << ", CONGRATULATIONS!\n";

	system("pause");
	return 0;
}