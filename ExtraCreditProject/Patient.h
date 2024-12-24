// Randy Chauarria Patient class header
#ifndef __PATIENT__
#define __PATIENT__
#include <iostream>
#include <string>
using namespace std;

class Patient{
	private:
		string name;
		int age;
		string condition;
	public:
		Patient() { condition = "Healthy"; }
		Patient(const Patient &right);
		void setName(string name) { this->name = name; }
		string getName() { return this->name; }
		void setAge(int num) { this->age = num; }
		int getAge() { return this->age; }
		void statusUpdate(string condition) { this->condition = condition; }
		string getCondition() { return this->condition; }
};

#endif