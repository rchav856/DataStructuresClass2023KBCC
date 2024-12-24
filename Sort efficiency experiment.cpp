#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

int menu();
int* doInput(int);
void generateData(fstream&, int);
void bubbleSort(int*, const int);
int *bestArray = nullptr;
int *worstArray = nullptr;
int *averageArray = nullptr;
int BEST_SIZE = 0;
int WORST_SIZE = 0;
int AVERAGE_SIZE = 0;
double bubbleTime = 0;
double efficientBubbleTime = 0;
double selectionTime = 0;


int menu(){
	int choice;
	cout << "SORT EFFICIENCY TESTS\n"
	     << "_______________________\n"
	     << "1. Generate new data set(s).\n"
	     << "2. Run a sort.\n"
	     << "3. Report statistics so far.\n"
	     << "4. Exit.\n";
	cin >> choice;
	if (choice != 1 && choice != 2 && choice !=3 && choice != 4){
		cout << "Invalid choice.\n";
		menu();
	}
	return choice;
}

void generateData(fstream& dataFile, int size){
	srand(time(0));
	for (int i = 0; i < size; i++)
		dataFile << rand()%100+1 << " ";
}

void putDataInArray(fstream& file, int size, int* arr){
	for (int i = 0;  i < size; i++){
		file >> arr[i];
	}
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++){
    	for (int j = 0; j < size; j++){
    		if (arr[j] > arr[j+1]){
    			int temp = arr[j];
    			arr[j] = arr[j + 1];
    			arr[j + 1] = temp;
			}
		}
	}
}

void efficientBubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size){
	int minValue;
	int minElement;
	for (int i = 0; i < size - 1; i++){
		minValue = arr[i];
		minElement = i;
		for (int j = i + 1; j < size; j++){
			if (arr[j] < minValue){
				minValue = arr[j];
				minElement = j;
			}
		}
		arr[minElement] = arr[i];
		arr[i] = minValue;		
	}
}

int main(){
	int input;
	fstream best, average, worst;
	cout << fixed << setprecision(10);
	do{
		input = menu();
		switch(input){
			case 1:	{
				string whichData;
				int dataSize;
				cout << "Do you want best, worst, or average? ";
				cin >> whichData;
				if (whichData == "best"){
					cout << "How many items do you wish to generate? ";
					cin >> dataSize;
					BEST_SIZE = dataSize;
					best.open("best.txt", ios::out);
					if (best.is_open()){
						generateData(best, dataSize);
						best.close();
						best.open("best.txt", ios::in);
						bestArray = new int [dataSize];
						putDataInArray(best, dataSize, bestArray);
						best.close();
					}
					else 
						cout << "Error opening file best.txt.\n";
				}
				else if (whichData == "worst"){
					cout << "How many items do you wish to generate? ";
					cin >> dataSize;
					WORST_SIZE = dataSize;
					worst.open("worst.txt", ios::out);
					if (worst.is_open()){
						generateData(worst, dataSize);
						worst.close();
						worst.open("worst.txt", ios::in);
						worstArray = new int [dataSize];
						putDataInArray(best, dataSize, worstArray);
						worst.close();
					}
					else
						cout << "Error opening file worst.txt.\n";
				}
				else if (whichData == "average"){
					cout << "How many items do you wish to generate? ";
					cin >> dataSize;
					AVERAGE_SIZE = dataSize;
					average.open("average.txt", ios::out);
					if (average.is_open()){
						generateData(average, dataSize);
						average.close();
						average.open("average.txt", ios::in);
						averageArray = new int [dataSize];
						putDataInArray(best, dataSize, averageArray);
						average.close();
					}
					else 
						cout << "Error opening file average.txt.\n";
				}
				else
					cout << "Invalid input.\n";
				break;
			}
			case 2:{
				int whichSort;
				cout << "Enter '1' for bubble sort, '2' for efficient bubble sort,"
					 << " or '3' for selection sort.\n";
				cin >> whichSort;
				if (whichSort == 1){
					clock_t startTime = clock();
					bubbleSort(bestArray, BEST_SIZE);
					bubbleSort(worstArray, WORST_SIZE);
					bubbleSort(averageArray, AVERAGE_SIZE);
					clock_t endTime = clock();
					bubbleTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
					cout << "That took " << bubbleTime << " seconds.\n";
					}
				else if (whichSort == 2){
					clock_t startTime = clock();
					efficientBubbleSort(bestArray, BEST_SIZE);
					efficientBubbleSort(worstArray, WORST_SIZE);
					efficientBubbleSort(averageArray, AVERAGE_SIZE);
					clock_t endTime = clock();
					efficientBubbleTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
					cout << "That took " << efficientBubbleTime << " seconds.\n";
					}
				else if (whichSort == 3){
					clock_t startTime = clock();
					selectionSort(bestArray, BEST_SIZE);
					selectionSort(worstArray, WORST_SIZE);
					selectionSort(averageArray, AVERAGE_SIZE);
					clock_t endTime = clock();
					selectionTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
					cout << "That took " << selectionTime << " seconds.\n";
				}
				else
					cout << "Invalid input.\n";
				break;
				}
			case 3:
					cout << "Bubble sort took " << bubbleTime << " seconds, "
						 << "efficient bubble sort took " << efficientBubbleTime << " seconds, "
						 << "and selection sort took " << selectionTime << " seconds.\n";
					break;
		}		
	}while (input != 4);
	best.close();
	average.close();
	worst.close();
	delete [] bestArray;
	delete [] worstArray;
	delete [] averageArray;
	return 0;
}
