//
// Created by Carlos R. Arias on 12/14/22.
//

#ifndef INTEGERSET_CLASS_ASSIGNMENT_INTEGER_SET_H
#define INTEGERSET_CLASS_ASSIGNMENT_INTEGER_SET_H


#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;

const unsigned short U = 10;

class IntegerSet {
private:
    bool _set[U];
public:
    IntegerSet();
    const IntegerSet& Assign(const IntegerSet& rhs);
    bool AddElement(unsigned short element);
    bool Belongs(unsigned short element);
    const IntegerSet Intersection(const IntegerSet& rhs)const;
    const IntegerSet Union(const IntegerSet& rhs)const;
    const IntegerSet Complement()const;
    bool Equals(const IntegerSet& rhs)const;
    size_t Size()const;
    void Write(ostream& output)const;
    size_t Read(istream& input);
    string ToString()const;
    void Clear();
};



#endif //INTEGERSET_CLASS_ASSIGNMENT_INTEGER_SET_H
