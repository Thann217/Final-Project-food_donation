#ifndef RECIPIENT_H
#define RECIPIENT_H


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


class recipient{
private:
  string name;
  int id;
  float food_received;


public:
  recipient(string n, int i) : name(n), id(i), food_received(0) {}
  string get_name() const {
      return name;
  }
  int get_id() const {
      return id;
  }
  float get_food_received() const {
      return food_received;
  }
  void set_food_received(float food) {
      food_received=food;
  }
  recipient& operator+=(float food) {
      food_received+=food;
      return *this;
  }
  bool verify(int check_id) const {
      return id==check_id;
  }
  void display(int id, string name, float food_received) const {
      cout<<"ID : "<<id<<endl<<"Name : "<<name<<endl<< "Food donation : "<<setprecision(2)<<food_received<<endl;
      cout<<"--------------------------------"<<endl;
  }
  static void sort_id(vector<recipient>& recipients) {
      int n=recipients.size();
      for (int i=1; i<n; i++) {
          recipient key=recipients[i];
          int j=i-1;
          while(j>=0 && recipients[j].get_id()>key.get_id()){
              recipients[j+1]=recipients[j];
              j=j-1;
          }
          recipients[j+1]=key;
      }
  }
};


#endif
