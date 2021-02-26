#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctype.h>

using namespace std;

const int Size = 20; //The character limitation of your file name
const int MAX_NUM = 5; //Change here to set the number of people you want
const int Name_length = 50; //The character limitation of the data in the file
string name[Name_length];

int read(int x) //Open your file and debug
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

void B_SORT(int arr[], int len) //Sort the time seeds
{
	int i, j;  int temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

int main()
{
	int r_count = read(0);
	cout << "Random drawing is processing......\n";
	srand(time(0));
	int m[MAX_NUM];
	int i = 0;
	cout << "Time seeds creating:\n";
	for (int i =0;i < MAX_NUM; i++) //Creat time seeds
	{
		m[i] = (rand() % r_count);
		int a = 0;
		for (a=0; a < i; a++)
		{
			if (m[i] == m[a])
			{
				m[i] = (rand() % r_count);
				a = 0;
			}
		}
	}
	B_SORT(m, MAX_NUM);

	Sleep(5 * 1000);
	cout << "\a\nGod's kiss falls on:\n";
	for (int i = 0; i < MAX_NUM; i++)
		cout << name[m[i]] << endl;
	cout << "CONGRATULATIONS!\n";
	return 0;
}