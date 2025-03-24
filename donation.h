#ifndef DONATION_H
#define DONATION_H


#include <iostream>
#include <string>
#include "recipient.h"
#include "donor.h"


using namespace std;


class Donation {
private:
   string donorName;
   int recipientId;
   string foodType;
   int quantity;
   string date;


public:
   Donation() : donorName(""), recipientId(0), foodType(""), quantity(0), date("") {}


   Donation(string dName, int rId, string fType, int qty, string dt)
       : donorName(dName), recipientId(rId), foodType(fType), quantity(qty), date(dt) {}


   int getQuantity() const { return quantity; }
   int getRecipientId() const { return recipientId; }
   string getFoodType() const { return foodType; }
   string getDonorName() const { return donorName; }


   void printDetails() const {
       cout << "Donor: " << donorName
            << " | Recipient ID: " << recipientId
            << " | Food: " << foodType
            << " | Quantity: " << quantity << " kg"
            << " | Date: " << date << endl;
   }
};


void bubbleSort(vector<Donation>& donations) {
   int n = donations.size();
   for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
           if (donations[j].getQuantity() < donations[j + 1].getQuantity()) {
               swap(donations[j], donations[j + 1]);
           }
       }
   }
}


void processDonation(DonorManager& donorManager, recipient recipients[], int recipientCount, Donation& donation) {
   for (int i = 0; i < recipientCount; i++) {
       if (recipients[i].get_id() == donation.getRecipientId()) {
           donorManager.track_donation(donation.getDonorName(), recipients[i], donation.getQuantity());
           return;
       }
   }
   cout << "Recipient not found!" << endl;
}


#endif