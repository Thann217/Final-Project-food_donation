#ifndef DONOR_H
#define DONOR_H


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "recipient.h"


using namespace std;


class Donor {
private:
   string name;
   string contactDetails;
   int donationFrequency;
   int id;


public:
   Donor(string n, string contact, int id) : name(n), contactDetails(contact),id(0), donationFrequency(0) {}


   string get_name() {
       return name;
   }


   string get_contact_details() {
       return contactDetails;
   }


   int get_donation_frequency() {
       return donationFrequency;
   }


   void update_contact_details(string newContact) {
       contactDetails = newContact;
   }


   void increment_donation_frequency() {
       donationFrequency++;
   }


   void display() {
       cout << "Name: " << name << endl
            << "Contact: " << contactDetails << endl
            << "Donation Frequency: " << donationFrequency << endl;
       cout << "--------------------------------" << endl;
   }
};


class DonorManager {
private:
   vector<Donor> donors;


public:
   void register_donor(string name, string contact, int id) {
       Donor newDonor(name, contact, id);
       donors.push_back(newDonor);
   }


   void update_donor_contact(string name, string newContact) {
       for (auto& donor : donors) {
           if (donor.get_name() == name) {
               donor.update_contact_details(newContact);
               return;
           }
       }
       cout << "Donor not found!" << endl;
   }


   void track_donation(string name, recipient &rec, int foodAmount) {
       for (auto& donor : donors) {
           if (donor.get_name() == name) {
               donor.increment_donation_frequency();
               rec += foodAmount; // Add food to recipient
               return;
           }
       }
       cout << "Donor not found!" << endl;
   }


   void display_all_donors() {
       for (auto& donor : donors) {
           donor.display();
       }
   }
};


#endif
