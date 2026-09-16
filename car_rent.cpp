#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream.h>
#include <dos.h>
#include <process.h>

class CarRental {
    char customerName[50];
    char contactNo[15];
    char carName[30];
    int days;
    float ratePerDay;
    float totalAmount;

public:
    void inputCustomer();
    void selectCar();
    void generateInvoice();
    void showRecord();
};

void CarRental::inputCustomer() {
    clrscr();
    cout << "\n\t=======================================";
    cout << "\n\t       CUSTOMER DETAILS ENTRY          ";
    cout << "\n\t=======================================\n";
    cout << "\n\tEnter Customer Name : ";
    gets(customerName);
    cout << "\tEnter Contact No.   : ";
    gets(contactNo);
}

void CarRental::selectCar() {
    int choice;
    clrscr();
    cout << "\n\t=======================================";
    cout << "\n\t            CAR SELECTION              ";
    cout << "\n\t=======================================\n";
    cout << "\n\t1. Hatchback  (Maruti Swift)   - Rs. 1000/day";
    cout << "\n\t2. Sedan      (Honda City)     - Rs. 1800/day";
    cout << "\n\t3. SUV        (Mahindra Thar)  - Rs. 2500/day";
    cout << "\n\t4. Luxury     (Audi A4)        - Rs. 5000/day";
    
    cout << "\n\n\tSelect Car Type (1-4): ";
    cin >> choice;

    switch(choice) {
        case 1: strcpy(carName, "Maruti Swift"); ratePerDay = 1000; break;
        case 2: strcpy(carName, "Honda City"); ratePerDay = 1800; break;
        case 3: strcpy(carName, "Mahindra Thar"); ratePerDay = 2500; break;
        case 4: strcpy(carName, "Audi A4"); ratePerDay = 5000; break;
        default: strcpy(carName, "Basic Car"); ratePerDay = 800; break;
    }

    cout << "\n\tEnter Number of Days to Rent: ";
    cin >> days;
    
    totalAmount = days * ratePerDay;
}

void CarRental::generateInvoice() {
    clrscr();
    cout << "\n\n\t===================================================";
    cout << "\n\t                  OFFICIAL INVOICE                   ";
    cout << "\n\t===================================================";
    cout << "\n\n\t Customer Name  : " << customerName;
    cout << "\n\t Contact Number : " << contactNo;
    cout << "\n\t Car Allocated  : " << carName;
    cout << "\n\t Rental Period  : " << days << " Days";
    cout << "\n\t Rate per Day   : Rs. " << ratePerDay;
    cout << "\n\t---------------------------------------------------";
    cout << "\n\t TOTAL PAYABLE  : Rs. " << totalAmount;
    cout << "\n\t===================================================";
    cout << "\n\n\t -> Press any key to return to Main Menu...";
    getch();
}

void CarRental::showRecord() {
    cout << "\n  " << customerName << "\t\t" << contactNo << "\t" << carName << "\t" << totalAmount;
}

// Global functions for project flow
void login() {
    char pass[20];
    char ch;
    int i = 0;
    
    clrscr();
    cout << "\n\n\n\n\t\t\t============================";
    cout << "\n\t\t\t  CAR RENTAL LOGIN SYSTEM";
    cout << "\n\t\t\t============================\n";
    cout << "\n\t\t\tEnter Password: ";
    
    // Hiding password with asterisks (*)
    while(1) {
        ch = getch();
        if(ch == 13) { // 13 is ASCII for Enter key
            pass[i] = '\0';
            break;
        }
        else if(ch == 8) { // 8 is ASCII for Backspace
            if(i > 0) {
                i--;
                cout << "\b \b"; // Erases character from screen
            }
        }
        else {
            pass[i++] = ch;
            cout << "*";
        }
    }
    
    if(strcmp(pass, "admin") == 0) {
        cout << "\n\n\t\t\tAccess Granted! Loading";
        for(int j=0; j<3; j++) {
            delay(400); 
            cout << ".";
        }
    } else {
        cout << "\n\n\t\t\tAccess Denied! Incorrect Password.";
        delay(1500);
        exit(0);
    }
}

void writeToFile() {
    ofstream outFile;
    outFile.open("RENTAL.DAT", ios::app | ios::binary);
    
    CarRental C;
    C.inputCustomer();
    C.selectCar();
    C.generateInvoice();
    
    outFile.write((char*)&C, sizeof(C));
    outFile.close();
}

void readFromFile() {
    ifstream inFile;
    inFile.open("RENTAL.DAT", ios::in | ios::binary);
    
    if(!inFile) {
        clrscr();
        cout << "\n\tError: No records found! File does not exist.";
        getch();
        return;
    }
    
    clrscr();
    cout << "\n\t================================================================";
    cout << "\n\t                       ALL RENTAL RECORDS                       ";
    cout << "\n\t================================================================\n";
    cout << "\n  CUSTOMER NAME\t\tCONTACT\t\tCAR MODEL\tTOTAL BILL";
    cout << "\n----------------------------------------------------------------------";
    
    CarRental C;
    while(inFile.read((char*)&C, sizeof(C))) {
        C.showRecord();
    }
    
    inFile.close();
    cout << "\n\n----------------------------------------------------------------------";
    cout << "\n\n\tPress any key to return to Main Menu...";
    getch();
}

void main() {
    int choice;
    login(); // Call login screen first
    
    do {
        clrscr();
        cout << "\n\n\t=======================================";
        cout << "\n\t       CAR RENTAL SYSTEM MAIN MENU     ";
        cout << "\n\t=======================================\n";
        cout << "\n\t 1. Rent a New Car";
        cout << "\n\t 2. View All Past Records (Admin)";
        cout << "\n\t 3. Exit Program";
        cout << "\n\n\t Enter your choice (1-3): ";
        cin >> choice;
        
        switch(choice) {
            case 1: 
                writeToFile();
                break;
            case 2: 
                readFromFile();
                break;
            case 3: 
                clrscr();
                cout << "\n\n\t\tExiting System. Have a great day!";
                delay(1000);
                exit(0);
            default: 
                cout << "\n\tInvalid choice. Press any key to try again.";
                getch();
        }
    } while(choice != 3);
}
