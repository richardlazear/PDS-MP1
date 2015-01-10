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
// http://www.cplusplus.com/forum/beginner/107573/
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
	cout << "\n";

	int sum = firstNum + secondNum;
	cout << firstNum << " + " << secondNum << " = " << sum << "\n";
	cout << "Number 1: " << firstNum << "\n";
	cout << "Number 2: " << secondNum << "\n";
	cout << "Sum: " << sum << "\n";
	cout << "Product: " << multiplication(firstNum, secondNum) << "\n\n";

	cout << "Now we will create an array and fill it with strings from a text file.\n";
	string wordsArray[100];
	int numOfWordsArray = readInArray(wordsArray);
	for (int i = 0; i < numOfWordsArray; i++)
	{
		cout << wordsArray[i] << "\n";
	}
	cout << "\n" << "Sorting the array:";
	arraySort(wordsArray, numOfWordsArray);
	for (int i = 0; i < numOfWordsArray; i++)
	{
		cout << wordsArray[i] << " ";
	}
	cout << "\n";

	cout << "-------------------------------------------------\n";

	cout << "Now we will create a vector and fill it with strings from a text file.\nThis will allow you compare arrays and vectors.";
	vector<string> wordsVector(1);
	readInVector(wordsVector);
	for (unsigned int i = 0; i < wordsVector.size(); i++)
	{
		cout << wordsVector[i] << "\n";
	}
	cout << "\nSorting the vector:";
	vectorSort(wordsVector);
	for (int i = 0; i < wordsVector.size(); i++)
	{
		cout << wordsVector[i] << " ";
	}
	cout << "\n\n";

	system("PAUSE");
	return 0;
}