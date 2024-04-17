#include "integer_set.h"

#include <iostream>
#include <sstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::stringstream;



void Test(bool condition, const char* message);

int main(int argc, char* argv[]) {
    bool flag;

    IntegerSet a, b, c, d, e;

    Test(a.Size() == 0, "Constructor size set correctly");
    Test(a.ToString() == "{}", "ToString on empty set");
    Test(!a.Equals(b), "Equals on empty set");

    flag = a.AddElement(3);
    Test(flag, "Adding 3 to set a, returned correct value");
    flag = a.AddElement(5);
    flag = a.AddElement(1);
    Test(a.Size() == 3, "A size is 3 after adding 3 elements");
    flag = a.AddElement(1);
    Test(a.Size() == 3, "A size is 3 after adding an existing element");
    flag = a.AddElement(10);
    Test(!flag, "Adding invalid element to set a detected");
    Test(a.Size() == 3, "A size is 3 after adding invalid element");
    Test(a.ToString() == "{1, 3, 5}", "ToString on set a");

    Test(!a.Belongs(2), "2 does not belong to a");
    Test(a.Belongs(5), "5 does belong to a");

    b.Assign(a);
    Test(b.ToString() == "{1, 3, 5}", "ToString after assigning a to b");
    c.Assign(b.Complement());
    Test(c.ToString() == "{0, 2, 4, 6, 7, 8, 9}", "ToString after b complement");

    d.Assign(a.Intersection(c));
    Test(d.ToString() == "{}", "ToString Intersection of disjoint sets");

    d.AddElement(0);
    d.AddElement(1);
    d.AddElement(2);
    e.Assign(d.Intersection(a));
    Test(e.ToString() == "{1}", "ToString Intersection Result");

    d.Clear();
    Test(d.ToString() == "{}", "ToString empty after Clear");

    d.AddElement(2);
    d.AddElement(0);
    d.AddElement(4);
    e.Assign(a.Union(d));
    Test(e.ToString() == "{0, 1, 2, 3, 4, 5}", "ToString Union Result");

    // Read and Write Tests
    stringstream stream;
    size_t count;
    a.Clear();
    b.Clear();
    stream.str("4 3 0 1");
    count = a.Read(stream);
    Test(count == 4, "Count after reading correct");
    Test(a.Size() == 4, "Size after reading correct");
    Test(a.ToString() == "{0, 1, 3, 4}", "ToString after reading correct");

    stream.clear();
    stream.str("14 3 10 1");
    count = a.Read(stream);
    Test(count == 2, "Count after reading correct (2)");
    Test(a.Size() == 2, "Size after reading correct (2)");
    Test(a.ToString() == "{1, 3}", "ToString after reading correct (2)");

    stream.clear();
    stream.str("");
    b.Write(stream);
    Test(stream.str() == "", "Write empty set correct");

    stream.clear();
    stream.str("");
    a.Write(stream);
    Test(stream.str() == "1 3 ", "Write non-empty set correct");

    return 0;
}

void Test(bool condition, const char* message){
    static auto passedTests = 0;
    if (condition){
        cout << "TEST PASSED (" << left << setw(50) << message << ") Total Passed: " << ++passedTests << endl;
    }else{
        cout << "TEST FAILED (" << left << setw(50) << message << ") **************" << endl;
    }
}