#ifndef REPORTING_H
#define REPORTING_H


#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include "donation.h"
#include "recipient.h"
#include "donor.h"


using namespace std;


class Reporting {
private:
   vector<Donation> donations;
   vector<recipient> recipients;
   DonorManager* donorManager;


public:
   Reporting(DonorManager* dm) : donorManager(dm) {}


   void addDonation(Donation donation) {
       donations.push_back(donation);
   }


   void addRecipient(const recipient& rec) {
       recipients.push_back(rec);
   }


   void generateDonationReport() {
       if (donations.empty()) {
           cout << "No donations available for reporting." << endl;
           return;
       }


       cout << "Donation Report (Sorted by Quantity):" << endl;
       bubbleSort(donations);
       for (const auto& donation : donations) {
           donation.printDetails();
       }
   }


   void generateDistributionReport() {
       if (recipients.empty()) {
           cout << "No recipients available for reporting." << endl;
           return;
       }


       cout << "Recipient Distribution Report:" << endl;
       for (const auto& rec : recipients) {
           cout << "ID : " << rec.get_id() << endl;
           cout << "Name : " << rec.get_name() << endl;
           cout << "Food donation : " << fixed << setprecision(2) << rec.get_food_received() << " kg" << endl;
           cout << "--------------------------------" << endl;
       }
   }


   void generateDonorReport() {
       if (!donorManager) {
           cout << "No donor manager available for reporting." << endl;
           return;
       }


       cout << "Donor Report:" << endl;
       donorManager->display_all_donors();
   }


   void generateOverallSummary() {
       int totalDonations = donations.size();
       int totalQuantity = accumulate(donations.begin(), donations.end(), 0,
                                      [](int sum, const Donation& donation) {
                                          return sum + donation.getQuantity();
                                      });


       cout << "Overall Summary of Donations:" << endl;
       cout << "Total Donations: " << totalDonations << endl;
       cout << "Total Quantity Donated: " << totalQuantity << " kg" << endl;
       cout << "----------------------------------" << endl;
   }


   void generateDistributionSummary() {
       int totalRecipients = recipients.size();
       int totalDistributedFood = accumulate(recipients.begin(), recipients.end(), 0,
                                             [](int sum, const recipient& rec) {
                                                 return sum + rec.get_food_received();
                                             });


       cout << "Overall Summary of Distributions:" << endl;
       cout << "Total Recipients: " << totalRecipients << endl;
       cout << "Total Food Distributed: " << totalDistributedFood << " kg" << endl;
       cout << "----------------------------------" << endl;
   }
};


#endif
