// Randy Chauarria Patient class
#include <iostream>
#include <string>
using namespace std;

class Patient{
	private:
		string name;
		int age;
		string condition;
	public:
		Patient(){
			condition = "Healthy";
		}
		void setName(string name){
			this->name = name;
		}
		string getName(){
			return this->name;
		}
		void setAge(int num){
			this->age = num;
		}
		int getAge(){
			return this->age;
		}
		void statusUpdate(string condition){
			this->condition = condition;
		}
		string getCondition(){
			return this->condition;
		}
};

void menu(Patient*);

// Test driver
int main(){
	Patient *Current_Patient = new Patient;
	menu(Current_Patient);
	delete Current_Patient;
	system("pause");
	return 0;
}

// Menu that takes a Patient pointer and adds information about patient
void menu(Patient* patient){
	int num;
	do{
		cout << "MENU\n"
			 << "_________\n\n"
			 << "1. Add new patient.\n"
			 << "2. Print patient info.\n"
			 << "3. Update patient condition.\n"
			 << "0. Exit program.\n\n";
		cin >> num;
		cin.ignore();
		cout << endl;
		switch(num){
			case 1:{
				string name;
				int age;
				cout << "Enter name of patient: ";
				getline(cin, name);
				patient->setName(name);
				cout << "\nEnter age of patient: ";
				cin >> age;
				cin.ignore();
				patient->setAge(age);
				cout << endl;
				break;
			} 
			case 2:{
				cout << "Getting patient information...\n"
					 << "Name: " << patient->getName() << endl
					 << "Age: "  << patient->getAge() << endl
					 << "Condition: " << patient->getCondition() << "\n\n";
				break;
			}
			case 3:{
				string condition;
				cout << "What is the condition of this patient? ";
				getline(cin, condition); 
				patient->statusUpdate(condition);
				cout << endl; 
				break;
			}
				
		}
	}while (num!= 0);
}