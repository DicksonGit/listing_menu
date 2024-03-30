
 //HOMEWORK 4
//AGHOMI DICKSON 
//CSE 1040
//FEBRUARY 2024
//This C++ program manages a list of numbers, offering operations like addition, removal, and computation of statistics


#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void displayMenu();
void displayList(const double numbers[], int size);
void addNumberToList(double number, double *&numberList, int &listSize);
void removeNumberFromList(double numberToRemove, double *&numberList, int &listSize);
double computeAverage(const double numbers[], int size);
double findMinimum(const double numbers[], int size);
double findMaximum(const double numbers[], int size);

int main() {
    // Student information
    cout << "Student Name: Aghomi Dickson" << endl;
    cout << "EUID: 11642501" << endl;
    cout << "Email: dicksonaghomi@my.unt.edu" << endl;
    cout << "Department: Computer Science" << endl;
    cout << "Course Number: CSCE 1040" << endl;

    // Dynamic array to store numbers
    double *numberList = nullptr;
    int listSize = 0;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                displayList(numberList, listSize);
                break;
            case 2: {
                double number;
                cout << "Enter a number to add: ";
                cin >> number;
                addNumberToList(number, numberList, listSize);
                cout << "Number added to the list." << endl;
                break;
            }
            case 3: {
                if (listSize == 0) {
                    cout << "Error: The list is empty. No removal done." << endl;
                } else {
                    double numberToRemove;
                    cout << "Enter a number to remove: ";
                    cin >> numberToRemove;
                    removeNumberFromList(numberToRemove, numberList, listSize);
                }
                break;
            }
            case 4:
                if (listSize == 0) {
                    cout << "Error: The list is empty. No average computed." << endl;
                } else {
                    cout << "Average of the list: " << fixed << setprecision(2) << computeAverage(numberList, listSize) << endl;
                }
                break;
            case 5:
                if (listSize == 0) {
                    cout << "Error: The list is empty. No minimum found." << endl;
                } else {
                    cout << "Minimum of the list: " << findMinimum(numberList, listSize) << endl;
                }
                break;
            case 6:
                if (listSize == 0) {
                    cout << "Error: The list is empty. No maximum found." << endl;
                } else {
                    cout << "Maximum of the list: " << findMaximum(numberList, listSize) << endl;
                }
                break;
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                // Deallocate memory
                delete[] numberList;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (true);

    // Deallocate memory
    delete[] numberList;
    return 0;
}

// Function to display the menu options
void displayMenu() {
    cout << "\n***************** M E N U *****************" << endl;
    cout << "| 1. Display list of numbers              |" << endl;
    cout << "| 2. Add number to list of numbers        |" << endl;
    cout << "| 3. Remove number from list of numbers   |" << endl;
    cout << "| 4. Compute average of list of numbers  |" << endl;
    cout << "| 5. Compute minimum of list of numbers  |" << endl;
    cout << "| 6. Compute maximum of list of numbers  |" << endl;
    cout << "| 7. Exit program                         |" << endl;
    cout << "*******************************************" << endl;
}

// Function to display the list of numbers
void displayList(const double numbers[], int size) {
    cout << "List of numbers: ";
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

// Function to add a number to the list
void addNumberToList(double number, double *&numberList, int &listSize) {
    double *tempList = new double[listSize + 1];
    for (int i = 0; i < listSize; ++i) {
        tempList[i] = numberList[i];
    }
    tempList[listSize++] = number;
    delete[] numberList;
    numberList = tempList;
}

// Function to remove a number from the list
void removeNumberFromList(double numberToRemove, double *&numberList, int &listSize) {
    bool found = false;
    for (int i = 0; i < listSize; ++i) {
        if (numberList[i] == numberToRemove) {
            for (int j = i; j < listSize - 1; ++j) {
                numberList[j] = numberList[j + 1];
            }
            found = true;
            break;
        }
    }
    if (found) {
        listSize--;
        cout << "Number removed from the list." << endl;
    } else {
        cout << "Number not found. No removal done." << endl;
    }
}

// Function to compute the average of the numbers in the list
double computeAverage(const double numbers[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    return sum / size;
}

// Function to find the minimum number in the list
double findMinimum(const double numbers[], int size) {
    double min = numbers[0];
    for (int i = 1; i < size; ++i) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

// Function to find the maximum number in the list
double findMaximum(const double numbers[], int size) {
    double max = numbers[0];
    for (int i = 1; i < size; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}
