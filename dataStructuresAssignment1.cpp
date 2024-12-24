/*
	Name: iterative and recursive binary search testing
	Copyright: 2023
	Author: Randy Chauarria
	Date: 25/09/23 16:28
	Description: Has timers for both iterative and recursive binary search algorithms.,
	Allows you to read numbers from a file, sort into an array, and then search for
	a number through both iterative and recursive binary search.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

void menu(fstream&, bool&, int*, bool&);
void loadData(fstream&, int*, bool&);
void sortData(fstream&, int*, bool& data);
int iterativeBinarySearch(int*, int);
int recursiveBinarySearch(int*, int, int, int);

// Used for size of array and number of integers in file.
const int SIZE = 10000;
// Holding clock time and when timer ends
clock_t startTime;
clock_t endTime;
// Holding result of time elapsed
double timeElapsed;

// Menu for doing various tasks with file
void menu(fstream& file, bool& dataLoaded, int *array, bool& sorted){
	int input;
	int num;
	cout << "1. Load data from file into array.\n"
		 << "2. Sort the data.\n"
		 << "3. Conduct an iterative Binary Search for a value.\n"
		 << "4. Conduct a recursive Binary Search for a value.\n"
		 << "5. Exit program.\n";
	cin >> input;
	switch (input){
		case 1: loadData(file, array, sorted);
				dataLoaded = true;
				break;
		case 2: if (dataLoaded == false){
					cout << "Must load data first. (Option 1)\n";
					menu(file, dataLoaded, array, sorted);
				}		
				else
					sortData(file, array, dataLoaded);
				break;
		case 3: if (dataLoaded == false || sorted == false){
					cout << "Must load and sort data first. (Option 1 and 2)\n";
					menu(file, dataLoaded, array, sorted);
				}
				else{
					cout << "Enter a number you wish to search for: ";
					cin >> num;
					startTime = clock();
					cout << "Your number was found in position " << iterativeBinarySearch(array, num)
						 << ".\n";
					endTime = clock();
					timeElapsed = ((double)(endTime - startTime))/CLOCKS_PER_SEC;
					cout << "The iterative binary search took " << timeElapsed << " seconds.\n";
					menu(file, dataLoaded, array, sorted);
				}
				break;
		case 4: if (dataLoaded == false || sorted == false){
					cout << "Must load and sort data first. (Option 1 and 2)\n";
					menu(file, dataLoaded, array, sorted);
				}		
				else{
					cout << "Enter a number you wish to search for: ";
					cin >> num;
					startTime = clock();
					cout << "Your number was found in position " << recursiveBinarySearch(array, num, 0, SIZE - 1)
						 << ".\n";
					endTime = clock();
					timeElapsed = ((double)(endTime - startTime))/CLOCKS_PER_SEC;
					cout << "The recursive binary search took " << timeElapsed << " seconds.\n";
					menu(file, dataLoaded, array, sorted);
				}
				break;
		case 5: cout << "Program terminated.\n";
				break;
		default: cout << "Bad Input, try again.\n";
				 menu(file, dataLoaded, array, sorted);
	}	 
}

// Searches for a number iteratively through binary search 
int iterativeBinarySearch(int* array, int num){
	int left = 0;
	int right = SIZE - 1;
	while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == num) 
            return mid; 
        else if (array[mid] < num)
            left = mid + 1; 
        else 
            right = mid - 1; 
    }
    return -1;
}

// Searches for a number recursively through binary search
int recursiveBinarySearch(int* array, int num, int left, int right){
	if (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == num)
            return mid;
        else if (array[mid] < num)
            return recursiveBinarySearch(array, num, mid + 1, right);
        else
            return recursiveBinarySearch(array, num, left, mid - 1);
    }
	return -1; 
}

// Sorts data from array into ascending order
void sortData(fstream& file, int *array, bool& data){
	bool sorted = true;
	int minIndex;
	int minVal;
	for (int i = 0; i < SIZE - 1; i++){
		minIndex = i;
		minVal = array[i];
		for (int j = i + 1; j < SIZE; j++){
			if (array[j] < array[minIndex]){
				minIndex = j;
				minVal = array[j];
			}
		}
		array[minIndex] = array[i];
		array[i] = minVal;	
	}
	menu(file, data, array, sorted);
}

// Loading data from file into an array
void loadData(fstream& file, int *array, bool& sorted){
	bool data = true;
	file.open("newFile", ios::in);
	for (int i = 0; i < SIZE; i++){
		file >> array[i];
	}
	file.close();
	menu(file, data, array, sorted);
}

int main(){
	int array[SIZE];
	fstream file;
	bool dataLoaded = false, sorted = false;
	cout << fixed << setprecision(10);
	file.open("newFile", ios::out | ios::in);
	srand(time(0));
	for (int i = 0; i < SIZE; i++){
		file << rand() << " ";
	}
	file.close();
	menu(file, dataLoaded, array, sorted);
	return 0;
}
