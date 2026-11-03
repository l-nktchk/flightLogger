#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//created logFlight function and inserted flight log code
void logFlight() {

    //creates string date and stores last flight date
    string date;
    cout << "Last flight: (mm/dd/yyyy)" << endl;
    cin >> date;
    //simple check so that i dont forget my format
    while ((date.length() != 10) || date[2] != '/' || date[5] != '/') {
        cout << "Date must be mm/dd/yyyy: " << endl;
        cin >> date;
    }

    //creates int packs 280 to track how many 280 mAh packs used
    int packs280;
    cout << "280mAh packs flown: " << endl;
    cin >> packs280;
    //check that i entered a number
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Value must be a whole number: " << endl;
        cin >> packs280;
    } 
    
    //creates int packs 320 to track how many 320 mAh packs used
    int packs320;
    cout << "320mAh packs flown: " << endl;
    cin >> packs320;
    //check that i entered a number
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Value must be a whole number: " << endl;
        cin >> packs320;
    }
    
    //out file for data
    ofstream dataFile("flightPack_data.csv", ios::app);
    dataFile << date << ',' << packs280 << ',' << packs320 << endl;
    dataFile.close();

    //reads in file
    
}

//created showTotals function to store supporting code 
void showTotals() {
    ifstream inFile("flightPack_data.csv");
    //variable line will be used to read through different lines of data
    string line;

    //defined totals
    int total280 = 0;
    int total320 = 0;

    //while function reads through line and outputs
    while (getline(inFile, line)) {
        //if csv starts with an empty line it continues instead of crashing
        if (line.empty()) continue;
        stringstream ss(line);
        string dateStr;
        getline(ss, dateStr, ',');
        string p280Str;
        getline(ss, p280Str, ',');
        total280 += stoi(p280Str);
        string p320Str;
        getline(ss, p320Str, ',');
        total320 += stoi(p320Str);

    }

    //defined total packs
    int packsTotal;
    //calcuates totals (280s + 320s)
    packsTotal = total280 + total320;
    cout << "Total 280mAh packs flown: " << total280 << endl;
    cout << "Total 320mAh packs flown: " << total320 << endl;
    cout << "Total packs flown: " << packsTotal << endl;

    inFile.close();
}

int main() {
    int choice;
    do {
        //mprints the menu selection
        cout << "1) Log flight" << endl;
        cout << "2) Show totals" << endl;
        cout << "3) Quit" << endl;
        cout << "Choice: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Value must be between 1-3 " << endl;
            cin >> choice;
        }
        // Log flight menu and run
        if (choice == 1) {
            logFlight();
        }
        // Show totals menu and run
        else if (choice == 2) {
            showTotals();
        }
        // Quit and run
        else if (choice == 3) {
            cout << "Goodbye" << endl;
        }
        //
        else {
            cout << "Invalid choice" << endl;
        }

    } while (choice != 3);
    return 0;
}
