//
// Created by Carlos R. Arias on 12/14/22.
//
/**
 * Title:   Integer Set with Class
 * Purpose: Implement C++ method of class that represent integer set operation
 * Author: **<Shadman Shahzahan>
 * Date: February 16, 2024
 */

#include "integer_set.h"

IntegerSet::IntegerSet() { // Initialize all elements in the set to false
    for (int i = 0; i < U; i++) {
        _set[i] = false;
    }
}

// Check if an element belongs to the set
bool IntegerSet::Belongs(unsigned short element) {
    if(element > U){ //Check if the element is within the valid range
        return false;
    }
    return _set[element];
}

// Assign the content of another set to this set
const IntegerSet& IntegerSet::Assign(const IntegerSet &rhs) {
    for (int i = 0; i < U; i++) {
        _set[i] = rhs._set[i];
    }
    return *this;
}

bool IntegerSet::AddElement(unsigned short element) { // Add an element to the set
    // Check if the element is within the valid range
    if (element >= U) {
        return false;
    }
    _set[element] = true;
    return true;
}

bool IntegerSet::Equals(const IntegerSet &rhs) const { // Checks if two sets are equal
    bool isempty = true;
    for (int i = 0; i < U; i++) {
        if (_set[i] != rhs._set[i]) {
            return false;
        }
        // Checks if either set is not empty
        if(_set[i] || rhs._set[i] ){
            isempty = false;
        }
    }
    if(isempty) {
        return false;
    }
    return true;
}

// Performs Intersection with another set
const IntegerSet IntegerSet::Intersection(const IntegerSet &rhs) const {
    IntegerSet result;
    for(int i = 0; i < U; i++){
        result._set[i] = _set[i] && rhs._set[i];
    }
    return result;
}

// Performs Union with another set
const IntegerSet IntegerSet::Union(const IntegerSet& rhs)const{
    IntegerSet result;
    for(int i = 0; i < U; i++){
        result._set[i] = _set[i] || rhs._set[i];
    }
    return result;
}

// Calculate the compliment of the set
const IntegerSet IntegerSet::Complement()const{
    IntegerSet result;
    for(int i = 0; i < U; i++){
        result._set[i] = !_set[i];
    }
    return result;
}

// Get the size of the set
size_t IntegerSet::Size() const {
    int size = 0;
    for (int i = 0; i < U; i++) {
        if (_set[i]) {
            size ++;
        }
    }
    return size;
}

// Clears the set
void IntegerSet::Clear() {
    for (int i = 0; i < U; i++) {
        _set[i] = false;
    }
}

// Convert the set to a string
string IntegerSet::ToString()const{
    string result =  "{";
    bool first = true;
    for (int i = 0; i < U; i++){
        if(_set[i]){
            if(!first){
                result += ", ";
            }
            result += std::to_string(i);
            first = false;
        }
    }
    result += "}";
    // Check if the set is empty
    if (result == "{}"){
        return "{}";
    }
    return result;
}

// Read the set from an input stream
size_t IntegerSet::Read(istream& input){
    this->Clear();
    size_t count = 0;
    int element;
    while (input >> element){
        if (element < U){
            _set[element] = true;
            count++;
        }
    }
    return count;
}

// Write the set to an output stream
void IntegerSet::Write(std::ostream &output) const {
    for (int i = 0; i < U; i++){
        if (_set[i]){
            output << i << " ";
        }
    }
}