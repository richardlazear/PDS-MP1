/*
1. In the main, ask the user to enter their name. By name, ask for 2 numbers, add the numbers together, and print the 2 numbers and the sum out.
2. Now send the 2 numbers to a function, multiply the numbers, and return the number back to the main. Print the 2 numbers, the sum, and the product out. Yes, they should print the sum out again.
3. Now send an empty String array of 100 entities to a function and read in a file of words(file contains less than 100 words). In the main, print all the words out and only the words.
4. Call a function and run a sort.You choose the sort to use (I would reuse code). Print the sorted array out in the main.
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
		cout << inWords[i] << "\n";
		i++;
	}
	myFile.close();
	return i;
}

// Method to sort the array (insertion sort)
void arraySort(string inWords[], int arraySize)
{
	for (int i = 1; i < arraySize; i++) {
		string valueToSort = inWords[i];
		int j = i;
		while (j > 0 && inWords[j - 1].compare(valueToSort) > 0) {
			// Swap the two words
			string temp = inWords[j];
			inWords[j] = inWords[j - 1];
			inWords[j - 1] = temp;
			j--;

			// Print the progression line
			for (int l = 0; l < arraySize; l++)
			{
				cout << inWords[l] << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n";
}

void readInVector(vector<string>& inWords)
{
	string line;
	ifstream myFile("myFile.txt");
	int i = 0;
	while (getline(myFile, line))
	{
		inWords.resize(i + 1);
		inWords[i] = line;
		cout << inWords[i] << "\n";
		i++;
	}
	myFile.close();
	cout << "\n";
}

// Method to sort the vector (insertion sort)
void vectorSort(vector<string>& inWords)
{
	for (int i = 1; i < inWords.size(); i++) {
		string valueToSort = inWords[i];
		int j = i;
		while (j > 0 && inWords[j - 1].compare(valueToSort) > 0) {
			// Swap the two words
			string temp = inWords[j];
			inWords[j] = inWords[j - 1];
			inWords[j - 1] = temp;
			j--;

			// Print the progression line
			for (int l = 0; l < inWords.size(); l++)
			{
				cout << inWords[l] << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n";
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
	cout << "\n" << "Sorting the array:\n";
	arraySort(wordsArray, numOfWordsArray);

	cout << "Now we will create a vector and fill it with strings from a text file.\nThis will allow you compare arrays and vectors.\n";
	vector<string> wordsVector(1);
	readInVector(wordsVector);
	cout << "Sorting the vector:\n";
	vectorSort(wordsVector);
	cout << "\n";

	system("PAUSE");
	return 0;
}