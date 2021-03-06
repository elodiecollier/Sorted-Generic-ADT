#include "SortedList.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Student::Student() {
  id = -1;
  name = "None";
} //default constructor

Student::Student(int ID, string Name) {
  id = ID;
  name = Name;
} //constructor

int Student::getID() const {
  return id;
} //getID

void Student::setID(int i) {
  id = i;
} //setID

string Student::getName() const {
  return name;
} //getName

void Student::setName(string n) {
  name = n;
} //setName


bool Student::operator==(const Student& s) const{
  if (id == s.getID()) {
    return true;
  } //if
  return false;
} //==

bool Student::operator<(const Student& s) const {
  if (id < s.getID()) {
    return true;
  } //if
  return false;
} //<

bool Student::operator>(const Student& s) const	{
  if (id > s.getID()) {
    return true;
  } //if                                                                                                             
  return false;
} //>

bool Student::operator!=(const Student& s) const	{
  if (id != s.getID()) {
    return true;
  } //if                                                                                                            
  return false;
} //!= 
