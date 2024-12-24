// Randy Chauarria Patient class.
#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include "Patient.h"
#include <fstream>
using namespace std;

void menu(vector<Patient>&);
void getPatientInfo(vector<Patient>&);
void updatePatient(vector<Patient>&, int);
void updateCondition(vector<Patient>&, int);
void printPatientInfo(vector<Patient>&);
int getPatientChoice(vector<Patient>&);
void changeEmergencyInfo(vector<Patient>&, int);
void updateInsurance(vector<Patient>&, int);
void changeReferral(vector<Patient>&, int);
void changePrimary(vector<Patient>&, int);
void updateFinancials(vector<Patient>&, int);
void addToBalance(vector<Patient>&, int);
void setNewBalance(vector<Patient>&, int);
void updateCopay(vector<Patient>&, int);
void writeToFile(vector<Patient>&);

int main(int argc, char** argv){
	cout << fixed << setprecision(2);
	vector<Patient> pVec;
	menu(pVec);
	writeToFile(pVec);
	return 0;
}

/* Simple switch menu to do various tasks.
   Takes a Patient vector in order to keep multiple
   patients kept inside of a data structure for manipulation. */
void menu(vector<Patient>& pVec){
	int num;
	int patient;
	do {
		cout << "\nMENU\n"
		     << "_________\n\n"
		     << "1. Add new patient.\n"
		     << "2. Print patient info.\n"
		     << "3. Update patient condition.\n"
		     << "4. Update emergency contact information.\n"
		     << "5. Update patient's insurance and insured status.\n"
		     << "6. Update patient's referral doctor.\n"
		     << "7. Update patient's primary doctor.\n"
		     << "8. Update patient's financials.\n"
		     << "0. Exit program.\n\n";
		cin >> num;
		cin.ignore();
		cout << endl;
		switch(num) {
			case 1: {
				getPatientInfo(pVec);
				break;
			}
			case 2: {
				printPatientInfo(pVec);
				break;
			}
			case 3: {
				patient = getPatientChoice(pVec);
				updatePatient(pVec, patient);
				break;
			}
			case 4: {
				patient = getPatientChoice(pVec);
				changeEmergencyInfo(pVec, patient);
				break;
			}
			case 5: {
				patient = getPatientChoice(pVec);
				updateInsurance(pVec, patient);
				break;
			}
			case 6: {
				patient = getPatientChoice(pVec);
				changeReferral(pVec, patient);
				break;
			}
			case 7:{
				patient = getPatientChoice(pVec);
				changePrimary(pVec, patient);
				break;
			}
			case 8:{
				patient = getPatientChoice(pVec);
				updateFinancials(pVec, patient);
			}
		}
	} while (num!= 0);
}

/* Creates new Patient object and asks for info to fill in.
   Information is then pushed into the back of a vector. */
void getPatientInfo(vector<Patient>& pVec){
	Patient newPatient;
	string n, b, c;
	int age;
	cout << "Enter name of patient: ";
	getline(cin, n);
	newPatient.setName(n);
	cout << "Enter age of patient: ";
	cin >> age;
	newPatient.setAge(age);
	cin.ignore();
	pVec.push_back(newPatient); 
}

/* Iterates through Patient vector to display information 
   about patients. */
void printPatientInfo(vector<Patient>& pVec){
	cout << "Getting patient information...\n"
		 << "______________________________\n";
	int count = 1;
	for (vector<Patient>::iterator it = pVec.begin(); it != pVec.end(); it++){
		Patient curPatient = *it;
		cout << "Patient " << count++ << ":" <<  endl
			 << "Name: " << curPatient.getName() << endl
			 << "Age: " << curPatient.getAge() << endl
			 << "Condition: " << curPatient.getCondition() << endl
			 << "Emergency Contact Name: " << curPatient.getEmergencyName() << endl
			 << "Emergency Contact Number: " << curPatient.getEmergencyNumber() << endl
			 << "Insured: " << curPatient.getStringInsuredStatus() << endl
			 << "Insurance: " << curPatient.getInsurance() << endl
			 << "Copay: " << curPatient.getCopay() << endl
			 << "Balance: " << curPatient.getBalance() << endl
			 << "Primary Doctor: " << curPatient.getPrimaryDoctor() << endl
			 << "Referral Doctor: " << curPatient.getReferralDoctor() << "\n\n";
	}
	cout << "______________________________\n";
}

// Returns number associated with patient
int getPatientChoice(vector<Patient>& pVec){
	int choice;
	Patient curPatient;
	int patientNumber = 1;
	cout << "Enter number associated with patient you would like to modify:\n";
	for (vector<Patient>::iterator it = pVec.begin(); it != pVec.end(); it++){
		curPatient = *it;
		cout << patientNumber++ << ". " << curPatient.getName() << endl;  
	}
	cin >> choice;
	cin.ignore();
	return choice;
}

// Allows user to change condition of a Patient object
void updatePatient(vector<Patient>& pVec, int choice){
	updateCondition(pVec, choice);
}

/* Implements code on Patient vector to change condition.
   Displays an error message if unable to change condition of patient. */
void updateCondition(vector<Patient>& pVec, int num){
	if (num < 1 || num > (int)pVec.size())
		cout << "Error updating patient!\n";
	else{
		Patient temp = pVec[num - 1];
		string newCondition;
		cout << "Enter new condition for " << temp.getName() << ": ";
		getline(cin, newCondition);
		temp.statusUpdate(newCondition);
		pVec[num - 1] = temp;
		cout << "Successfully updated " << temp.getName() << ".\n";
	}
}

/* Lets program user change emergency name and emergency number
   of a patient's information. */
void changeEmergencyInfo(vector<Patient>& pVec, int choice){
	Patient newPatient = pVec[choice - 1];
	string info;
	cout << "Enter new Emergency Contact Name: ";
	getline(cin, info);
	newPatient.setEmergencyName(info);
	cout << "Enter new Emergency Contact Number: ";
	getline(cin, info);
	newPatient.setEmergencyNumber(info);
	pVec[choice - 1] = newPatient;
	cout << "Successfully updated " << newPatient.getName() 
		 << "'s emergency contact information.\n";  
}

// Updates insured flag and makes changes to insurance 
void updateInsurance(vector<Patient>& pVec, int num){
	Patient temp = pVec[num - 1];
	char c;
	cout << "Does " << temp.getName() << " have insurance?(Y/N) ";
	cin >> c;
	cin.ignore();
	c = toupper(c);
	if (c == 'Y'){
		string comp;
		temp.setInsuredStatus(1);
		cout << "Enter insurance company name: ";
		getline(cin, comp);
		temp.setInsurance(comp); 
	}
	else if (c == 'N'){
		temp.setInsuredStatus(0);
		temp.setInsurance("");
	}
	else{
		cout << "Error reading user input. Exiting.";
		return;
	} 
	pVec[num - 1] = temp;
}

// Changes patient's referral doctor
void changeReferral(vector<Patient>& pVec, int num){
	string newDoctor;
	Patient temp = pVec[num - 1];
	cout << "Enter new name of referral doctor: ";
	getline(cin, newDoctor);
	temp.setReferralDoctor(newDoctor);
	pVec[num - 1] = temp; 
}

// Changes patient's primary doctor
void changePrimary(vector<Patient>& pVec, int num){
	string newDoctor;
	Patient temp = pVec[num - 1];
	cout << "Enter new name of primary doctor: ";
	getline(cin, newDoctor);
	temp.setPrimaryDoctor(newDoctor);
	pVec[num - 1] = temp; 
}

// Gives various choices for updating patient's financials
void updateFinancials(vector<Patient>& pVec, int num){
	Patient temp = pVec[num - 1];
	int choice;
	char askCopay;
	cout << "Would you like to update this patient's copay?(Y/N) ";
	cin >> askCopay;
	askCopay = toupper(askCopay);
	if (askCopay == 'Y')
		updateCopay(pVec, num);
	cout << "1. Add to current patient's balance.\n"
		 << "2. Set up new balance for patient.\n";
	cin >> choice;
	cin.ignore();
	switch(choice){
		case 1:{
			addToBalance(pVec, num);
			break;
		}
		case 2:{
			setNewBalance(pVec, num);
		}
	}
}

// Sets new copay for patient
void updateCopay(vector<Patient>& pVec, int num){
	double newCopay;
	Patient update = pVec[num - 1];
	cout << "Enter new copay for " << update.getName() << ": ";
	cin >> newCopay;
	cin.ignore();
	pVec[num - 1] = update; 
}

// Adds user inputted number to balance of patient
void addToBalance(vector<Patient>& pVec, int num){
	double add;
	Patient p = pVec[num - 1];
	cout << "Enter number to add to balance: ";
	cin >> add;
	cin.ignore();
	p.addToBalance(add);
	pVec[num - 1] = p; 
}

// Rewrites patient's balance
void setNewBalance(vector<Patient>& pVec, int num){
	double newBalance;
	Patient temp = pVec[num - 1];
	cout << "Enter new balance for patient: ";
	cin >> newBalance;
	cin.ignore();
	temp.setBalance(newBalance);
	pVec[num - 1] = temp; 
}

// Makes copy of all records to file labeled "PatientRecords.txt"
void writeToFile(vector<Patient>& pVec){
	Patient curPatient;
	int count = 1;
	ofstream newFile("PatientRecords.txt");
	for (vector<Patient>::iterator it = pVec.begin(); it != pVec.end(); it++){
		curPatient = *it;
		newFile << "Patient " << count++ << ":" <<  endl
			 	<< "Name: " << curPatient.getName() << endl
			 	<< "Age: " << curPatient.getAge() << endl
			 	<< "Condition: " << curPatient.getCondition() << endl
			 	<< "Emergency Contact Name: " << curPatient.getEmergencyName() << endl
			 	<< "Emergency Contact Number: " << curPatient.getEmergencyNumber() << endl
			 	<< "Insured: " << curPatient.getStringInsuredStatus() << endl
			 	<< "Insurance: " << curPatient.getInsurance() << endl
			 	<< "Copay: " << curPatient.getCopay() << endl
			 	<< "Balance: " << curPatient.getBalance() << endl
			 	<< "Primary Doctor: " << curPatient.getPrimaryDoctor() << endl
			 	<< "Referral Doctor: " << curPatient.getReferralDoctor() << "\n\n";
	}
}