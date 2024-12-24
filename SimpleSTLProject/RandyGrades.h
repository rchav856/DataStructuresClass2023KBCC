/*
	Name: Vector of grade scores
	Copyright: 2023
	Author: Randy Chauarria
	Date: 30/09/23 22:42
	Description: 
*/

#ifndef _GRADEVECTOR_
#define _GRADEVECTOR_
#include <vector>
using namespace std;

class Grades{
	private:
		vector<int> scores;
	public:
		Grades(){}
		~Grades(){}
		void sortVector();
		void findMinMaxAvg();
		void printVector();
		void insertData(int);
		bool isEmpty(){ return scores.empty(); };  
};

#endif