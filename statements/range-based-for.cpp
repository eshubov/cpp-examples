// Keep in mind these facts about range-based for:
// - Automatically recognizes arrays.
// - Recognizes containers that have .begin() and .end().

// Which line will produce compilation error?

#include <iostream>
#include <vector>

using namespace std;

class MyVector {
public:
    MyVector(vector<double>& v) : v(v) {}
    vector<double>& v;
};

int main()
{
    // Basic 10-element integer array.
    int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Range-based for loop to iterate through the array.
    for( int y : x ) { // Access by value using a copy declared as a specific type. Not preferred.                       
        cout << y << " ";
    }
    cout << endl;

    // The auto keyword causes type inference to be used. Preferred.

    for( auto y : x ) { // Copy of 'x', almost always undesirable
        cout << y << " ";
    }
    cout << endl;

    for( auto &y : x ) { // Type inference by reference. Preferred.
        cout << y << " ";
    }
    cout << endl;

    vector<double> v = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    // Range-based for loop to iterate through the vector, observing in-place.
    for( const auto &j : v ) {
        cout << j << " ";
    }
    cout << endl;

    // Range-based for loop to iterate custom vector type.
    MyVector mv(v);
    for( auto &j : mv ) {
        cout << j << " ";
    }
    cout << endl;
}

class MyVector1 {
public:
    MyVector(vector<double>& v) : v(v) {}
    vector<double>::iterator begin() { return v.begin(); }
    vector<double>::iterator end() { return v.end(); }
    vector<double>& v;
};
