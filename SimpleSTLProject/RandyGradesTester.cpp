/*
	Name: Tester for Grades class
	Copyright: 2023
	Author: Randy Chauarria
	Date: 12/09/23 17:43
	Description: Lets users enter scores into memory,
	allows users to sort the scores in ascending order, allows
	users to find lowest, min, average scores, and then also
	is able to print the current format that the scores are in.
*/
#include <iostream>
#include <vector>
#include "RandyGrades.h"
using namespace std;

void menu(Grades);

int main(int argc, char** argv) {
	cout << "This program lets you enter grades. Please enter grades below, enter -1 to stop.\n";
	int input;
	Grades gradeVec;
	cin >> input;
	while (input != -1){
		gradeVec.insertData(input);
		cin >> input;
	}
	if (!gradeVec.isEmpty())
		menu(gradeVec);
	return 0;
}

// Manu for calls to functions in the Grades class
// Includes a sort, print, and way to find the highest, lowest, average 
// in a vector of grade scores.
void menu(Grades vec){
	char letter;
	do{
	cout << "Enter 'A' to sort the grades,\n"
		 << "'B' to print out the average, highest, and lowest grades,\n"
		 << "'C' to print the current grades, and 'D' to exit the program.\n";
	cin >> letter;
	letter = toupper(letter);
	while (letter != 'A' && letter != 'B' && letter != 'C' && letter != 'D'){
		cout << "Input invalid. Please enter a valid input.\n";
		cin >> letter; 
		letter = toupper(letter);
	}
	switch (letter){
		case 'A': vec.sortVector();				  
				  break;
		case 'B': vec.findMinMaxAvg();
				  break;
		case 'C': vec.printVector();
	}
	} while (toupper(letter != 'D'));
}
