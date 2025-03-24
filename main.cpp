#include <iostream>
#include "donor.h"
#include "recipient.h"
#include "donation.h"
#include "reporting.h"




using namespace std;




void displayMenu() {
   cout << "1. Register Donor\n";
   cout << "2. Create Donation\n";
   cout << "3. Generate Donation Report\n";
   cout << "4. Generate Distribution Report\n";
   cout << "5. Generate Donor Report\n";
   cout << "6. Generate Overall Summary\n";
   cout << "7. Generate Distribution Summary\n";
   cout << "8. Exit\n";
   cout << "Choose an option: ";
}




int main() {
   DonorManager donorManager;
   vector<recipient> recipients; // Use a vector instead of an array for dynamic management
   Reporting report(&donorManager);




   // Add some initial recipients
   recipients.push_back(recipient("John", 101));
   recipients.push_back(recipient("Jane", 102));




   int choice;
   do {
       displayMenu();
       cin >> choice;
       cin.ignore(); // To ignore the newline character after the integer input




       switch (choice) {
           case 1: {
               string name, contact;
               cout << "Enter donor name: ";
               getline(cin, name);
               cout << "Enter donor contact details: ";
               getline(cin, contact);
               int id = rand() % 900 + 100;
              donorManager.register_donor(name, contact, id);
              cout<<"Your ID is "<<id<<endl;
               cout << "Donor registered successfully!\n";
               recipients.push_back(recipient(name, id));
               break;
           }
           case 2: {
               string donorName, foodType, date;
               int recipientId, quantity;
               cout << "Enter donor name: ";
               getline(cin, donorName);
               cout << "Enter recipient ID: ";
               cin >> recipientId;
               cin.ignore();
               cout << "Enter food type: ";
               getline(cin, foodType);
               cout << "Enter quantity (in kg): ";
               cin >> quantity;
               cin.ignore();




               Donation donation(donorName, recipientId, foodType, quantity, date);
               processDonation(donorManager, recipients.data(), recipients.size(), donation);
               report.addDonation(donation);
               cout << "Donation created successfully!\n";
               break;
           }
           case 3:
               report.generateDonationReport();
               break;
           case 4:
               // Ensure recipients are added to the Reporting class
               for (const auto& rec : recipients) {
                   report.addRecipient(rec);
               }
               report.generateDistributionReport();
               break;
           case 5:
               report.generateDonorReport();
               break;
           case 6:
               report.generateOverallSummary();
               break;
           case 7:
               report.generateDistributionSummary();
               break;
           case 8:
               cout << "Exiting...\n";
               break;
           default:
               cout << "Invalid choice. Please try again.\n";
       }
   } while (choice != 8);




   return 0;
}