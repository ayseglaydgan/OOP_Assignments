#include <iostream>
#include <vector>
#include <fstream>
#include "DayOfYearSet.h"

using namespace std;
// use own namespace
using namespace Aysegul_DayOfYearSet;

// test call by value
void test_call_by_value(DayOfYearSet d1, DayOfYearSet d2) {
    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;
    cout << "d1 == d2: " << (d1 == d2) << endl;
    cout << "d1 != d2: " << (d1 != d2) << endl;

}

// test call by reference
void test_call_by_reference(DayOfYearSet& d1, DayOfYearSet& d2) {
    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;
    cout << "d1 == d2: " << (d1 == d2) << endl;
    cout << "d1 != d2: " << (d1 != d2) << endl;
}

void deMorganRule(DayOfYearSet& set1, DayOfYearSet& set2)
{
    // write result to file
    ofstream outfile;
    outfile.open("deMorganRule.txt");
    outfile << "set1: " << set1 << endl;
    outfile << "set2: " << set2 << endl;

    DayOfYearSet set5 = set1 + set2;
    outfile << "(set1 + set2) " << set5 << endl;
    DayOfYearSet set6 = !set5;
    outfile << "!(set1 + set2) " << set6 << endl;

    // deMorgan rule
    DayOfYearSet set3 = !set1;
    DayOfYearSet set4 = !set2;
    DayOfYearSet ndSet = set3 ^ set4;
    outfile << "!set1: " << set3 << endl; 
    outfile << "!set2: " << set4 << endl;

    outfile << "!set1 ^ !set2 " << ndSet << endl;

    outfile << "Left side size: " << set6.size() << endl;
    outfile << "Right side size: " << ndSet.size() << endl;
    outfile << "As you can see they are equal" << endl;

    outfile.close();


}

int main()
{
    cout << "--------------------- Welcome to DayOfYearSet Test File ---------------------" << endl;

    // Test 1 - Constructors
    cout << "Test 1 - Constructors" << endl;
    DayOfYearSet set1;
    cout << "Test default constructor print result set1: " << set1 << endl;
    cout << "Add some days and print" << endl;
    set1.add(DayOfYearSet::DayOfYear(1,5));
    set1.add(DayOfYearSet::DayOfYear(15,10));
    set1.add(DayOfYearSet::DayOfYear(25,5));
    set1.add(DayOfYearSet::DayOfYear(3,8));
    set1.add(DayOfYearSet::DayOfYear(27,8));
    set1.add(DayOfYearSet::DayOfYear(6,5));
    cout << set1 << endl;

    DayOfYearSet set2(set1);
    cout << "Test copy constructor print result set2: " << set2 << endl;

    cout << "Create a vector and use it with constructor" << endl;
    vector<DayOfYearSet::DayOfYear> vec;
    vec.push_back(DayOfYearSet::DayOfYear(1,5));
    vec.push_back(DayOfYearSet::DayOfYear(15,10));
    vec.push_back(DayOfYearSet::DayOfYear(25,5));
    vec.push_back(DayOfYearSet::DayOfYear(3,8));
    vec.push_back(DayOfYearSet::DayOfYear(27,8));

    DayOfYearSet set3(vec);
    cout << "Test vector constructor print result: set3: " << set3 << endl;

    // test copy assignment operator
    DayOfYearSet set4 = set1;
    cout << "Test copy assignment operator print result set4: " << set4 << endl;

    cout << "Test add remove methods" << endl;
    cout << "Use first set. First print set1 again. After remove some days and print" << endl;
    cout << "Before remove" << endl;
    cout << set1 << endl;
    set1.remove(DayOfYearSet::DayOfYear(1,5));
    set1.remove(DayOfYearSet::DayOfYear(15,10));
    set1.remove(DayOfYearSet::DayOfYear(25,5));
    set1.remove(DayOfYearSet::DayOfYear(3,8));

    cout << "After remove" << endl;
    cout << set1 << endl;

    cout << "Test add method. Add new days" << endl;
    set1.add(DayOfYearSet::DayOfYear(23,5));
    set1.add(DayOfYearSet::DayOfYear(19,12));

    cout << "After add" << endl;
    cout << set1 << endl;

    cout << "Use index operator" << endl;
    cout << "set1[0] = " << set1[0].getDay() << "/" << set1[0].getMonth() << endl;
    cout << "set1[1] = " << set1[1].getDay() << "/" << set1[1].getMonth() << endl;

    cout << "Test + - ^ ! operators on set1 and set2" << endl << "set1:" << set1 << endl << "set2:" << set2 << endl;

    cout << "Test + operator" << endl;
    DayOfYearSet set5 = set1 + set2;
    cout << "set1 + set2 = " << set5 << endl;

    cout << "Test - operator " << endl;
    DayOfYearSet set6 = set1 - set2;
    cout << "set1 - set2 = " << set6 << endl;

    cout << "Test ^ operator" << endl;
    DayOfYearSet set7 = set1 ^ set2;
    cout << "set1 ^ set2 = " << set7 << endl;

    cout << "Test unary ! operator" << endl;
    //DayOfYearSet set8 = !set1;
    cout << "!set1 (I prefer dont print because it is too long) = " << endl;

    cout << "Show active DayOfYear Count" << endl;
    cout << "Active DayCount = " << DayOfYearSet::DayOfYear::getActiveDaysOfYear() << endl;

    cout << "Show active DayOfYear Count with some changes" << endl;

    cout << "Active DaysCount = " << DayOfYearSet::DayOfYear::getActiveDaysOfYear() << endl;
    
    // test call by value and call by reference functions
    cout << "Test call by value and call by reference functions" << endl;
    cout << "set1: " << set1 << endl;
    cout << "set2: " << set2 << endl;
    test_call_by_value(set1, set2);
    test_call_by_reference(set1, set2);

    cout << "De Morgan Rule" << endl;
    cout << "Those tests are too long, so I write results to deMorganRule.txt" << endl;

    deMorganRule(set1, set2);

    cout << "--------------------- End of DayOfYearSet Test File ---------------------" << endl;

    return 0;
}