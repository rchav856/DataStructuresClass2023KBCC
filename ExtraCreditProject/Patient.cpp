// Randy Chauarria Patient class implementation file.
// Rest of member functions were only one line long.
#include "Patient.h"

// Copy constructor 
Patient::Patient(const Patient &right){
	this->name = right.name;
	this->age = right.age;
	this->condition = right.condition;
}