#include <iostream>
#include <fstream>
#include <string>
#include "SortedList.h"
#include <utility>
#include <tuple>
#include "Student.h"

using namespace std;

template <class ItemType>
SortedList<ItemType>::SortedList() {
  head = new Node<ItemType>;
  head -> next = nullptr;
  length = 0;
} //constructor

template <class ItemType>
SortedList<ItemType>::~SortedList() {
  makeEmpty();
} //destructor

template <class ItemType>
bool SortedList<ItemType>::isEmpty() const{
  if (length == 0) {
    return true;
  } //if
  return false;
} //isEmpty

template <class ItemType>
int SortedList<ItemType>::getLength() const{
  return length;
} //getLength

template <class ItemType>
void SortedList<ItemType>::makeEmpty() {
  Node<ItemType>* tempPtr;
  Node<ItemType>* listData = head -> next;
  while (listData != NULL) {
    tempPtr = listData;
    listData = listData -> next;
    delete tempPtr;
  } //while
  head -> next = NULL;
  length = 0;
} //makeEmpty

template <class ItemType>
ItemType SortedList<ItemType>::getAt(int index) {
  Node<ItemType>* tempPtr = head -> next;
  if (index > length || index < 1) {
    throw OutOfBound();
  } //if
  for (int i = 1; i < index; i++) {
    tempPtr = tempPtr -> next;
  } //for
  return tempPtr -> info;
} //getAt

template <class ItemType>
void SortedList<ItemType>::putItem(ItemType newItem) {
  bool boolVal;
  Node<ItemType>* preNode = nullptr;
  tie(boolVal, preNode) = findItem(newItem);
  if (boolVal == true) {
    throw DuplicateItem();
  } // if
  Node<ItemType>* newNode = new Node<ItemType>;
  newNode -> info = newItem;
  Node<ItemType>* nextNode;
  nextNode = preNode -> next;
  newNode -> next = nextNode;
  preNode -> next = newNode;
  length++;
} //putItem

template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item) {
  bool boolVal;
  Node<ItemType>* preNode = nullptr;
  tie(boolVal, preNode) = findItem(item);
  if (boolVal == false) {
    throw DeletingMissingItem();
    cout << "delete tested";
  } //if
  Node<ItemType>* temp= preNode -> next;
  preNode -> next = temp -> next;
  delete temp;
   length--;
} //deleteItem

template <class ItemType>
void SortedList<ItemType>::printList(ofstream& outFile) {
  Node<ItemType>* temp = head ->next;
  outFile << "List Items : ";
  while (temp != nullptr) {
    outFile << temp-> info;
    outFile << "->";
    temp = temp -> next;
  } //while
  outFile << "NULL \n";
} //printList

template <class ItemType>
void SortedList<ItemType>::merge(SortedList& otherList) {
  Node<ItemType>* myNode = head -> next;
  Node<ItemType>* otherNode = (otherList.getHead()) -> next;
  Node<ItemType>* newList = new Node<ItemType>;
  newList -> next = NULL;
  Node<ItemType>* newListCurr = NULL;
  int counter = 0;
  if(otherNode != NULL || myNode != NULL) {
    if (otherNode == NULL) {
      newListCurr = myNode;
      myNode = myNode -> next;
      counter++;
    } //if
    else if (myNode == NULL) {
      newListCurr = otherNode;
      otherNode = otherNode -> next;
      counter++;
    } //elseif
    else if (myNode -> info < otherNode -> info) {
      newListCurr -> next = myNode;
      myNode = myNode -> next;
      counter++;
    } //elseif
    else if (myNode -> info > otherNode -> info) {
      newListCurr = otherNode;
      otherNode = otherNode -> next;
      counter++;
    } //elseif
    else if (myNode -> info == otherNode -> info) {
      newListCurr = myNode;
      myNode = myNode -> next;
      otherNode = otherNode -> next;
      counter++;
    } //elseif
    newList -> next = newListCurr;
  } //if
  while (otherNode != NULL || myNode != NULL) {
    if (otherNode == NULL) {  
      newListCurr -> next = myNode;
      myNode = myNode -> next;
      newListCurr = newListCurr -> next;
      counter++;
    } //if
    else if (myNode == NULL) {
      newListCurr -> next = otherNode;
      otherNode = otherNode -> next;
      newListCurr = newListCurr -> next;
      counter++;
    } //elseif
    else if (myNode -> info < otherNode -> info) {
      newListCurr -> next = myNode;
      myNode = myNode -> next;
      newListCurr = newListCurr -> next;
      counter++;
    } //elseif
    else if (myNode -> info > otherNode -> info) {
      newListCurr -> next = otherNode;
      otherNode = otherNode -> next;
      newListCurr = newListCurr -> next;
      counter++;
    } //elseif
    
    else if (myNode -> info == otherNode -> info) {
      newListCurr -> next = myNode;
      myNode = myNode -> next;
      otherNode = otherNode -> next;
      newListCurr = newListCurr -> next;
      counter++;
    } //elseif
  } //while
  //  otherList.makeEmpty();
  head = newList;
  length = counter;
  otherList.head -> next = NULL;
} //merge

template <class ItemType>
std::pair<bool, Node<ItemType>*> SortedList<ItemType>::findItem(ItemType item) {
  Node<ItemType>* tempPred = head;
  Node<ItemType>* temp = head -> next;
  bool val = false;
  while (temp != nullptr && (val == false) && (((temp -> info) < item) || ((temp -> info) == item))) {
      if (temp -> info == item) {
	val = true;
      } //if
      else {
	tempPred = temp;
	temp = temp -> next;
      } //else
    } //while
   return std::make_pair(val, tempPred);
} //findItem

template <class ItemType>
Node<ItemType>* SortedList<ItemType>::getHead() {
  return head;
} //getHead
