#pragma once
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<string>
#include<array>
#include<algorithm>
#include<limits>
#include<cstdio>
#include<cctype>
#include<fstream>
#include<vector>

using namespace std;

namespace std
{
	int RandomNumber(int From, int To)
	{
		int RandNumber = rand() % (To - From + 1) + From;

		return RandNumber;

	}

	long double ReadNumber(string Message)
	{
		cout << Message << "\n";
		long double Number;
		cin >> Number;

		while (cin.fail() == 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "INVALID NUMBER , " << Message << "\n";
			cin >> Number;
		}

		return Number;
	}

	long double ReadPositiveNumber(string Message)
	{
		int Number;
		do {

			Number = ReadNumber(Message);

		} while (Number <= 0);

		return Number;
	}

	long double ValidateNumberInRange(int From, int To)
	{
		int Number;
		do
		{
			Number = ReadNumber("ENTER A NUMBER BETWEEN " + to_string(From) + " & " + to_string(To));

		} while (Number < From || Number > To);

		return Number;
	}

	void PrintArray(int Array[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			cout << Array[i] << ' ';
		}

		cout << "\n";
	}

	void FillArrayWithRandomNumber(int Array[100], int& ArraySize)
	{
		ArraySize = ReadPositiveNumber("ENTER SIZE OF ARRAY");

		for (int i = 0; i < ArraySize; i++)
		{
			Array[i] = RandomNumber(1, 100);
		}
	}

	void CopyArray(int CopiedArray[], int ArrayCopy[], int CopiedArraySize)
	{
		for (int i = 0; i < CopiedArraySize; i++)
		{
			ArrayCopy[i] = CopiedArray[i];
		}

	}

	void AddArrayELement(int Number, int Array[], int& ArraySize)
	{
		Array[ArraySize++] = Number;
	}

	void ReadArray(int Array[100], int& ArraySize)
	{
		ArraySize = ReadPositiveNumber("ENTER SIZE OF ARRAY");

		cout << "ENTER ARRAY ELEMENT" << endl;

		for (int i = 0; i < ArraySize; i++)
		{
			cout << "ELEMENT [" << (i + 1) << "] : ";
			cin >> Array[i];
		}
	}

	bool IsArrayPalindrome(int Array[100], int ArraySize)
	{
		for (int i = 0; i < (ArraySize / 2); i++)
		{
			if (Array[i] != Array[ArraySize - i - 1])
				return 0;
		}

		return 1;
	}

	int CheckFoundOrNot(int NumberToCheck, int Array[100], int ArraySize)
	{

		for (int i = 0; i < ArraySize; i++)
		{
			if (NumberToCheck == Array[i])
			{
				return i;
			}
		}
		return -1;
	}

	bool IsFoundInArray(int NumberToCheck, int Array[100], int ArraySize)
	{
		return (CheckFoundOrNot(NumberToCheck, Array, ArraySize) != -1);
	}

	bool AreArraysEqual(int Array1[100], int Array2[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			if (Array1[i] != Array2[i])
			{
				return 0;
			}
		}

		return 1;
	}

	void CopyArrayInReversedOrder(int CopiedArray[], int ArrayCopy[], int CopiedArraySize)
	{
		for (int i = 0; i < CopiedArraySize; i++)
		{
			ArrayCopy[i] = CopiedArray[CopiedArraySize - 1 - i];
		}

	}

	long double GetFloatingPoint(float Number)
	{
		return Number - (int)Number;
	}

	void SwapNumbers(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	bool DoYouWantToPlayAgain()
	{
		string Choice;
		do
		{
			cout << "DO YOU WANT TO PLAY AGAIN[Y/N]\n";
			cin >> Choice;
		} while (Choice != "Y" && Choice != "y" && Choice != "N" && Choice != "n");

		if (Choice == "Y" || Choice == "y")
		{
			system("cls");
			system("color 0F");
			return 1;
		}

		else
		{
			cout << "\nGOOD BYE :)\n";
			return 0;
		}
	}

	bool DoYouWantToContinue()
	{
		string Choice;
		do
		{
			cout << "DO YOU WANT TO CONTINUE[Y/N]\n";
			cin >> Choice;
		} while (Choice != "Y" && Choice != "y" && Choice != "N" && Choice != "n");

		if (Choice == "Y" || Choice == "y")
		{
			system("cls");
			system("color 0F");
			return 1;
		}

		else
		{
			cout << "\n\nGOOD BYE :)\n\n";
			return 0;
		}
	}

	string ReadLineString(string Message)
	{
		string String;
		cout << Message << "\n";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, String);

		return String;
	}

	long double ValidateNumberInRange(int From, int To, string Message)
	{
		int Number;
		do
		{
			Number = ReadNumber(Message);

		} while (Number < From || Number > To);

		return Number;
	}

	long double ReadDoublePositiveNumber(string Message)
	{
		long double Number;
		do {

			Number = ReadNumber(Message);

		} while (Number <= 0);

		return Number;
	}

	string ReadString(string Message)
	{
		string String;
		cout << Message << "\n";
		cin >> String;

		return String;
	}

	bool DoYouWantToReadAgain()
	{
		string ReadAgain;
		do
		{

			ReadAgain = ReadString("DO YOU WANT TO READ AGAIN [Y/N]");

		}while(ReadAgain != "Y" && ReadAgain != "y" && ReadAgain != "N" && ReadAgain != "n");
		
		if (ReadAgain == "Y" || ReadAgain == "y")
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	int GetIntegerPart(float Number)
	{
		return (int)Number;
	}

	void PrintFileContent(string FileName)
	{
		fstream File;
		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				if (Line != "")
				{
					cout << Line << "\n";
				}

			}

			File.close();
		}
	}

	void LoadDataFromFileToVector(string FileName, vector<string>& FileContent)
	{
		fstream File;
		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				if (Line != "")
				{
					FileContent.push_back(Line);
				}

			}

			File.close();
		}
	}

	void SaveVectorDataToFile(string FileName, vector<string>& VectorContent)
	{
		fstream File;
		File.open(FileName, ios::out);

		if (File.is_open())
		{
			for (string& Line : VectorContent)
			{
				if (Line != "")
				{
					File << Line << "\n";
				}

			}

			File.close();
		}
	}

	void DeleteRecordFromFile(string FileName, string Record)
	{
		// ALWAYS WE USE VECTOR IN FILES AS A MEDIUM
		vector<string>FileContent;

		LoadDataFromFileToVector(FileName, FileContent);

		for (string& Line : FileContent)
		{
			if (Line == Record)
			{
				Line = "";
			}
		}

		SaveVectorDataToFile(FileName, FileContent);

	}

	void UpdateRecordFromFile(string FileName, string Record, string Update)
	{
		//ALWAYS WE USE VECTORS IN FILES AS A MEDIUM
		vector<string>FileContent;

		LoadDataFromFileToVector(FileName, FileContent);

		for (string& Line : FileContent)
		{
			if (Line == Record)
			{
				Line = Update;
			}
		}

		SaveVectorDataToFile(FileName, FileContent);
	}

	bool IsPrime(long long Number)
	{
		for (long long i = 2; i <= sqrt(Number); i++)
		{
			if (Number % i == 0)
			{
				return 0;
			}
		}

		if (Number != 1)
		{
			return 1;
		}

		return 0;

	}

	bool IsPerfect(long long Number)
	{
		long long DivisorsSum = 0;

		for (long long i = 1; i < Number; i++)
		{
			if (Number % i == 0)
			{
				DivisorsSum += i;
			}
		}

		if (Number == DivisorsSum)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	char ReadArithmeticOperation(string Message)
	{
		char Operation = ' ';

		bool RepeatingCondition = 1;

		do
		{
			cout << Message << "\n";
			cin >> Operation;

			RepeatingCondition = (
				(Operation != '+') &&
				(Operation != '-') &&
				(Operation != '*') &&
				(Operation != '/') &&
				(Operation != '%'));

		} while (RepeatingCondition == true);

		return Operation;
	}

	string Tab(short Number)
	{
		string Tab = "";
		while (Number--)
		{
			Tab += "\t";
		}

		return Tab;
	}

	string ReadSentence(string Message)
	{
		string Sentence;
		cout << Message << "\n";
		cin.ignore(1, '\n');
		getline(cin, Sentence);

		return Sentence;
	}

}
