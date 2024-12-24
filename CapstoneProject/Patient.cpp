// Randy Chauarria Patient class implementation file.
#include "Patient.h"

// Default Constructor
Patient::Patient(){
	this->condition = "Healthy"; 
	this->balance = 0.00; 
	this->insured = false;
	this->insurance = "";
	this->copay = 0.00;
	this->emergencyName = "";
	this->emergencyNumber = ""; 
}

// Copy constructor 
Patient::Patient(const Patient &right){
	this->name = right.name;
	this->age = right.age;
	this->condition = right.condition;
	this->balance = right.balance;
	this->copay = right.copay;
	this->emergencyName = right.emergencyName;
	this->emergencyNumber = right.emergencyNumber;
	this->insurance = right.insurance;
	this->insured = right.insured;
	this->PrimaryDoctor = right.PrimaryDoctor;
	this->ReferralDoctor = right.ReferralDoctor;
}

// Sets primary doctor to string in parameter
void Patient::setPrimaryDoctor(string name){
	this->PrimaryDoctor = name;
}

// Sets referral doctor to string in parameter
void Patient::setReferralDoctor(string name){
	this->ReferralDoctor = name;
}

// Adds an insurance name to a patient's record
void Patient::setInsurance(string insurName){
	this->insurance = insurName;
}

// Sets a patient's insurance status to true or false
void Patient::setInsuredStatus(bool status){
	this->insured = status;
}

// Takes in string name of patient's emergency contact
void Patient::setEmergencyName(string name){
	this->emergencyName = name;
}

// Takes in string number of patient's emergency contact
void Patient::setEmergencyNumber(string num){
	this->emergencyNumber = num;
}

// Sets balance owed by patient
void Patient::setBalance(double num){
	this->balance = num;
}

// Adds to preexisting balance of patient
void Patient::addToBalance(double val){
	this->balance += val;
}

// Updates patient health status
void Patient::statusUpdate(string condition){
	this->condition = condition; 
}

// Sets patient age
void Patient::setAge(int num){
	this->age = num; 
}

// Sets patient name
void Patient::setName(string name){ 
	this->name = name; 
}

// Returns string version of insured status.
string Patient::getStringInsuredStatus(){
	if (this->getInsuredStatus() == 1)
		return "True";
	return "False";
}