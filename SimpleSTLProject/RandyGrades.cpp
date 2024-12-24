/*
	Name: RandyGrades function implementation
	Copyright: 2023
	Author: Randy Chauarria
	Date: 30/09/23 22:59
	Description: Implementation file for RandyGrades.h
*/

#include "RandyGrades.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Sorts vector
void Grades::sortVector(){
	sort(scores.begin(), scores.end());
}
	
// Finds min, max, and average grade in vector
void Grades::findMinMaxAvg(){
	int min = scores[0], max = scores[0], avg = 0;
	for (vector<int>::iterator it = scores.begin();
		it != scores.end(); it++){
			if (min > *it)
				min = *it;
			if (max < *it)
				max = *it;
			avg += *it;
		}
	cout << "The min score is " << min << " and the "
		 << "highest score is " << max << ". "
		 << "The average score is " << (double)(avg / scores.size())
		 << ".\n"; 
}
	
// Prints vector as is, from start to end
void Grades::printVector(){
	for (vector<int>::iterator it = scores.begin(); 
		it != scores.end(); it++){
			cout << *it << " ";
		}
		cout << endl;
}
	
// Inserts grades to end of vector
void Grades::insertData(int num){
	scores.push_back(num);
}
