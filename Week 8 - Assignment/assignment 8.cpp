#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; //set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoxy(int column, int line)
{
	COORD coord; //set the coordinate
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void freqCharacter(int fbin[128], char fc)
{
	ShowConsoleCursor(false); // to hide the cursor
	int x = 20, y = 0, color;
	
	color = rand() % 13 + 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //set the color randomly.

	gotoxy(x, y);
	cout << "THE FREQUENCY of CHARACTERS ARE IN THE DOCUMENT" << endl;
	gotoxy(x, y+1);
	cout << "===============================================" << endl;
	cout << "        " << endl;
	
	for (int i = 0; i < 26; i++) // counting the frequencies of 26 letters from A to Z
	{
		color = rand() % 14 + 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << char(65 + i) << " : " << "[" << fbin[65 + i] << "]";
		fbin[65 + i] = fbin[65 + i] / 50; //the character will be counted by groups of 50.
		for (int j = 0; j < fbin[65 + i]; j++)
			cout << "*";
		cout << endl;
	}

	for (int i = 0; i < 32; i++) //32 to 64 is the range of ascii code table for regular characters.
	{
		if (fbin[32 + i] == 0); //if the frequency of the character is zero, don't print it out.
		else
		{
			color = rand() % 14 + 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			cout << char(32 + i) << " : " << "[" << fbin[32 + i] << "]";

			fbin[32 + i] = fbin[32 + i] / 50;//the character will be counted by groups of 50.
			for (int j = 0; j < fbin[32 + i]; j++)
				cout << "*";
			cout << endl;
		}
	}
	for (int i = 0; i < 6; i++) //91 to 96 is the range of ascii code table for regular characters.
	{
		if (fbin[91 + i] == 0); //if the frequency of the character is zero, don't print it out.
		else
		{
			color = rand() % 14 + 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
			cout << char(91 + i) << " : " << "[" << fbin[91 + i] << "]";
			fbin[91 + i] = fbin[91 + i] / 50; //the character will be counted by groups of 50.
			for (int j = 0; j < fbin[91 + i]; j++)
				cout << "*";
			cout << endl;
		}
	}
	for (int i = 0; i < 4; i++) //123 to 127 is the range of ascii code table for regular characters.
	{
		if (fbin[123 + i] == 0); //if the frequency of the character is zero, don't print it out.
		else
		{
			cout << char(123 + i) << " : " << "[" << fbin[123 + i] << "]";

			fbin[91 + i] = fbin[123 + i] / 50;
			for (int j = 0; j < fbin[123 + i]; j++)
				cout << "*";
			cout << endl;
		}
	}
	while (1);
}
/*Some innovations: use function called, set randomly color, set the coordinates, hide the cursor, 
and hide the sentence "Press any key to continue..." */
void main()
{	
	int bin[128];    // frequencies of the characters
	char c;          //characters in the document
	
	ShowConsoleCursor(false); // to hide the cursor
	
	// initialize frequency counts for each possible character
	for (int i = 0; i < 128; i++)
		bin[i] = 0;
	ifstream infile("C:\\Users\\faqua\\Documents\\TEMP\\INPUT\\const.txt");// input file
	//check for the error
	if (infile.fail())
		cout << "Cannot open the file" << endl;

	// Read the file, tracking the frequency of the characters to the end of file
	infile >> c;	
	while (!infile.eof())
	{
		c = toupper(c); //convert lowercase letters into uppercase letters to count
		bin[c]++;
		infile >> c;
	}
	infile.close();

	freqCharacter(bin, c);
	
	system("pause");
	
}