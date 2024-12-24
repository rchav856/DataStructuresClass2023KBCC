// Randy Chauarria Patient class header
#ifndef __PATIENT__
#define __PATIENT__
#include <iostream>
#include <string>
using namespace std;

class Patient{
	private:
		string name, condition, insurance, PrimaryDoctor, 
			   ReferralDoctor, emergencyName, emergencyNumber;
		int age;
		bool insured;
		double copay, balance;
	public:
		Patient();
		Patient(const Patient &right);
		
		// Mutators
		void setName(string);
		void statusUpdate(string);
		void setPrimaryDoctor(string);
		void setReferralDoctor(string);
		void setInsurance(string);
		void setEmergencyName(string);
		void setEmergencyNumber(string);
		void setAge(int);
		void setInsuredStatus(bool);
		void setCopay(double);
		void setBalance(double);
		void addToBalance(double);
		
		// Accessors
		double getCopay() { return this->copay; }
		double getBalance() { return this->balance; }
		bool getInsuredStatus() { return this->insured; }
		int getAge() { return this->age; }
		string getName() { return this->name; }
		string getCondition() { return this->condition; }
		string getInsurance() { return this->insurance; }
		string getPrimaryDoctor() { return this->PrimaryDoctor; }
		string getReferralDoctor() { return this->ReferralDoctor; }
		string getEmergencyName() {	return this->emergencyName; }
		string getEmergencyNumber() { return this->emergencyNumber; }
		string getStringInsuredStatus();
};

#endif