#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

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
    ifstream inFile("flightPack_data.csv");
    //variable line will be used to read through different lines of data
    string line;

    //while function reads through line and outputs
    while (getline(inFile, line)) {
        cout << line << endl; 
    }

    inFile.close();
 
    return 0;
}
