#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string getInfoForFile();
fstream openFile(string);
void voterMenu();
void checkContentOfFile(string, ofstream&);
void copyToFile(string, ofstream&);
void updateTally(int);
void askTally();
void printTally();
void getTally();

struct Candidate{
		int tally;
		Candidate(){
			this->tally = 0;
		}
};

class Voter{
	public:
		string id;
		string name;
		string status;	
		Voter(){
			this->id = "";
			this->name = "";
			this->status = "";
		}
};

/* Candidates we are using */
Candidate mickeyC, donaldC, bugsC;

int main(int argc, char** argv){
	string fileName, fileLine;
	fstream voterFile;
	ofstream auditFile;
	auditFile.open("auditrail.txt");
	getTally();
	cout << "Enter name of file containing voter info below.\n"
		 << "File should be in the format [ID] [Name] [Status]\n"
		 << "Status is: (P) for proceed to vote, (A) for already voted, (N) for not registered.\n";
	fileName = getInfoForFile();
	try{
		voterFile = openFile(fileName);
	}
	catch(string error){
		cout << error;
		return 0;
	}
	while (getline(voterFile, fileLine, '\n')){
		checkContentOfFile(fileLine, auditFile);
	}
	auditFile.close();
	voterFile.close();
	return 0;
}

/* Gets user input for string name and returns the string */
string getInfoForFile(){
	string file;
	cout << "Enter file name: ";
	getline(cin, file); 
	return file;
}

/* Gets input for name of a file, opens it, and does exception handling 
	if error found */
fstream openFile(string fileName){
	fstream file;
	file.open(fileName, ios::out | ios::in);
	if (!file){
		string error = "Error opening file ";
		error.append(fileName);
		error.append(". Terminating program.\n");
		throw error;
	}
	else
		return file;
}

/* Simple menu holding candidates */
void voterMenu(){
	cout << "************************\n"
		 << "*  	Voter Menu     *\n"
		 << "************************\n"
		 << "1. Mickey Mouse        *\n"
		 << "2. Donald Duck         *\n"
		 << "3. Bugs Bunny          *\n"
		 << "************************\n";
}

/* This function only asks for a vote if voter.status equals 'P'
	in file holding voter information. Else, all other voters are 
	ignored until end of file or until a voter with voter.status with
	value 'P' is found. (Loop is done in main function) */
void checkContentOfFile(string fileLine, ofstream& outputFile){
	Voter voter;
	voter.id = fileLine.substr(0, 5);
	voter.status = fileLine.substr(fileLine.size() - 1, 1);
	voter.name = fileLine.substr(6, fileLine.size() - 8);
	if (voter.status == "P"){
		int choice;
		voterMenu();
		cout << "Hello, " << voter.name << ".\nPlease select a candidate.\n"
			 << "Enter Number: ";
		cin >> choice;
		switch (choice){
			case 1: cout << "You voted for Mickey Mouse.\n";
					updateTally(1);
					askTally();
					break;
			case 2: cout << "You voted for Donald Duck.\n";
					updateTally(2);
					askTally();
					break;
			case 3: cout << "You voted for Bugs Bunny.\n";
					updateTally(3);
				  	askTally();
		}
		voter.status = "A";
	}
	string appendedString = voter.id + " " + voter.name +" " + voter.status;
	copyToFile(appendedString, outputFile);
}

/* Copies line to file in main titled auditFile */
void copyToFile(string line, ofstream &file){
	file << line << endl;
}

/* Asks user whether they would like to check poll results. This is coupled
	with printTally to achieve this and reduce clutter */
void askTally(){
	char choice;
	cout << "Thank you for your vote.\n"
		 << "Would you like to see the results? (Y/N) : ";
	cin >> choice;
	choice = toupper(choice);
	if (choice == 'Y')
		printTally();
	else
		return;
}

/* Updates file containing total tally of candidates. Three 
	seperate files are for the three candidates. These files only hold an integer.
	Integer holding candidate to update passed to update that specific candidate's tally only. */
void updateTally(int choice){
	string tally;
	switch (choice){
		case 1: {
					ofstream mickey("mickeyTally.txt");
					mickey << ++mickeyC.tally;
					mickey.close();
					break;
					}
		case 2: {
					ofstream donald("donaldTally.txt");
					donald << ++donaldC.tally;
					donald.close();
					break;
				}
		case 3: {
					ofstream bugs("mickeyTally.txt");
					bugs << ++bugsC.tally;
					bugs.close();
					break;
				}
	}
}

/* Reads tally variable from each candidate */
void printTally(){
	cout << "Mickey: " << mickeyC.tally << endl
		 << "Donald Duck: " << donaldC.tally << endl
		 << "Bugs Bunny: " << bugsC.tally << endl;
}

/* Makes sure tally files exist, and updates each candidate to hold
   the integer in each file to their tally member variable */
void getTally(){
	string tally;
	ifstream mickey("mickeyTally.txt");
	if(!mickey){
		ofstream mickey1;
		mickey1.open("mickeyTally.txt");
		mickey1 << "0";
		mickey1.close();
		mickey.open("mickeyTally.txt");   
	}
	getline(mickey, tally);
	const char* mickeyCStr = tally.c_str();
	mickeyC.tally = atoi(mickeyCStr);
	mickey.close();
	ifstream donald("donaldTally.txt");
	if(!donald){
		ofstream donald1;
		donald1.open("donaldTally.txt");
		donald1 << "0";
		donald1.close();
		donald.open("donaldTally.txt");   
	}
	getline(donald, tally);
	const char* donaldCStr = tally.c_str();
	donaldC.tally = atoi(donaldCStr);
	donald.close();
	ifstream bugs("bugsTally.txt");
	if(!bugs){
		ofstream bugs1;
		bugs1.open("bugsTally.txt");
		bugs1 << "0";
		bugs1.close();
		bugs.open("bugsTally.txt");   
	}
	getline(bugs, tally);
	const char* bugsCStr = tally.c_str();
	bugsC.tally = atoi(bugsCStr);
	bugs.close();
}