/*
1. In the main, ask the user to enter their name. By name, ask for 2 numbers, add the numbers together, and print the 2 numbers and the sum out.
2. Now send the 2 numbers to a function, multiply the numbers, and return the number back to the main. Print the 2 numbers, the sum, and the product out. Yes, they should print the sum out again.
3. Now send an empty String array of 100 entities to a function and read in a file of words(file contains less than 100 words). In the main, print all the words out and only the words.
4. Call a function and run a sort.You choose the sort to use(I would reuse code). Print the sorted array out in the main.
5. Have them then create a vector and do the same thing as 3 and 4 above. Tell them this allows them to compare Vector to regular arrays.
*/

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int multiplication(int inFirstNum, int inSecondNum)
{
	int product = inFirstNum * inSecondNum;
	return product;
}

// http://www.cplusplus.com/forum/beginner/107573/
int readInArray(string inWords[])
{
	string line;
	ifstream myFile("myFile.txt");
	int i = 0;
	while (getline(myFile, line))
	{
		inWords[i] = line;
		i++;
	}
	myFile.close();
	return i;
}

void readInVector(vector<string> inWords)
{
	string line;
	ifstream myFile("myFile.txt");
	int i = 0;
	while (getline(myFile, line))
	{
		inWords[i] = line;
		i++;
	}
	myFile.close();
}

int main()
{
	cout << ("Please enter your first name: ");
	string name;
	cin >> name;
	
	cout << (name + ", please enter a number: ");
	int firstNum;
	cin >> firstNum;
	cout << (name + ", please enter another number: ");
	int secondNum;
	cin >> secondNum;

	int sum = firstNum + secondNum;
	cout << firstNum << " + " << secondNum << " = " << sum << "\n";
	cout << firstNum << " * " << secondNum << " = " << multiplication(firstNum, secondNum);
	cout << "\n" << "\n";

	cout << "Now we will create an array and fill it with strings from a text file.\n";
	string wordsArray[100];
	int numOfWordsArray = readInArray(wordsArray);
	for (int i = 0; i < numOfWordsArray; i++)
	{
		cout << wordsArray[i] << "\n";
	}
	cout << "\n";

	cout << "Now we will create a vector and fill it with strings from a text file.\nThis will allow you compare arrays and vectors.\n";
	vector<string> wordsVector;
	wordsVector.reserve(100);
	readInVector(wordsVector);
	cout << wordsVector.size();
	for (int i = 0; i < wordsVector.size(); i++)
	{
		cout << wordsArray[i] << "\n";
	}
	cout << "\n";

	system("PAUSE");
	return 0;
}