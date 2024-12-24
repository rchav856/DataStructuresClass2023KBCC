// Randy Chauarria test program for Patient class.
#include <iostream>
#include <vector>
#include "Patient.h"
using namespace std;

void menu(vector<Patient>&);
void getPatientInfo(vector<Patient>&);
void updatePatient(vector<Patient>&);
void updateCondition(int, vector<Patient>&);
void printPatientInfo(vector<Patient>);

int main(int argc, char** argv){
	vector<Patient> pVec;
	menu(pVec);
	return 0;
}

/* Simple switch menu to do various tasks.
   Takes a Patient vector in order to keep multiple
   patients kept inside of a data structure for manipulation. */
void menu(vector<Patient>& pVec){
	int num;
	do {
		cout << "\nMENU\n"
		     << "_________\n\n"
		     << "1. Add new patient.\n"
		     << "2. Print patient info.\n"
		     << "3. Update patient condition.\n"
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
				updatePatient(pVec);
				break;
			}
		}
	} while (num!= 0);
}

/* Creates new Patient object and asks for info to fill in.
   Information is then pushed into the back of a vector. */
void getPatientInfo(vector<Patient>& pVec){
	Patient newPatient;
	string name;
	int age;
	cout << "Enter name of patient: ";
	getline(cin, name);
	newPatient.setName(name);
	cout << "Enter age of patient: ";
	cin >> age;
	cin.ignore();
	newPatient.setAge(age);
	cout << endl;
	pVec.push_back(newPatient);
}

/* Iterates through Patient vector to display information 
   about patients. */
void printPatientInfo(vector<Patient> pVec){
	cout << "Getting patient information...\n"
		 << "______________________________\n";
	int count = 1;
	for (vector<Patient>::iterator it = pVec.begin(); it != pVec.end(); it++){
		Patient curPatient = *it;
		cout << "Patient " << count++ << ":" <<  endl
			 << "Name: " << curPatient.getName() << endl
			 << "Age: " << curPatient.getAge() << endl
			 << "Condition: " << curPatient.getCondition() << "\n\n";
	}
	cout << "______________________________\n";
}

// Allows user to change condition of a Patient object
void updatePatient(vector<Patient>& pVec){
	int choice;
	string newCondition;
	Patient curPatient;
	int patientNumber = 1;
	cout << "Enter number associated with patient you would like to modify:\n";
	for (vector<Patient>::iterator it = pVec.begin(); it != pVec.end(); it++){
		curPatient = *it;
		cout << patientNumber++ << ". " << curPatient.getName() << endl;  
		}
	cin >> choice;
	cin.ignore();
	updateCondition(choice, pVec);
}

/* Implements code on Patient vector to change condition.
   Displays an error message if unable to change condition of patient. */
void updateCondition(int num, vector<Patient>& pVec){
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