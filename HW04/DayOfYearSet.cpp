#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "DayOfYearSet.h"

using namespace std;
using namespace Aysegul_DayOfYearSet;

// nicely initialized
int DayOfYearSet::DayOfYear::activeCount = 0;

// implement DayOfYearSet
// default constructor
DayOfYearSet::DayOfYearSet()
{
    // create 10 size of array as default
    dayOfYearArray = new DayOfYear[10];
    this->sizeArray = 0;
    this->capacity = 10;
    
}

DayOfYearSet::DayOfYearSet(int size)
{
    // initialize the dynamic array
    dayOfYearArray = new DayOfYear[size];
    this->sizeArray = 0;
    this->capacity = size;
}

// vector constructor
DayOfYearSet::DayOfYearSet(vector<DayOfYear>& days)
{
    // initialize the dynamic array
    dayOfYearArray = new DayOfYear[days.size()];
    this->sizeArray = days.size();
    this->capacity = days.size();

    // copy the vector to the array
    for (int i = 0; i < days.size(); i++)
    {
        dayOfYearArray[i] = days[i];
    }
}

// big three implementation
// copy constructor
DayOfYearSet::DayOfYearSet(const DayOfYearSet& other)
{
    // initialize the dynamic array
    dayOfYearArray = new DayOfYear[other.sizeArray];
    this->sizeArray = other.sizeArray;
    this->capacity = other.capacity;

    // copy the array
    for (int i = 0; i < other.sizeArray; i++)
    {
        dayOfYearArray[i] = other.dayOfYearArray[i];
    }
}

// overload assignemnt operator
DayOfYearSet& DayOfYearSet::operator=(const DayOfYearSet& other)
{
    // check if the object is not the same
    if (this != &other)
    {
        // delete the old array
        delete[] dayOfYearArray;

        // initialize the dynamic array
        dayOfYearArray = new DayOfYear[other.sizeArray];
        this->sizeArray = other.sizeArray;
        this->capacity = other.capacity;

        // copy the array
        for (int i = 0; i < other.sizeArray; i++)
        {
            dayOfYearArray[i] = other.dayOfYearArray[i];
        }
    }
    return *this;
}

// destructor
DayOfYearSet::~DayOfYearSet()
{
    // delete the array
    delete[] dayOfYearArray;
}

// add function
void DayOfYearSet::add(const DayOfYear& day)
{
    // check if contains return
    if (contains(day))
    {
        cerr << "Day already exists" << endl;
        return;
    }

    // check if the array is full
    if (sizeArray == capacity)
    {
        // create a new array with double the size
        DayOfYear* tempArray = new DayOfYear[capacity * 2];

        // copy the old array to the new array
        for (int i = 0; i < sizeArray; i++)
        {
            tempArray[i] = dayOfYearArray[i];
        }

        // delete the old array
        delete[] dayOfYearArray;

        // assign the new array to the old array
        dayOfYearArray = tempArray;

        // increase the capacity
        capacity *= 2;
    }

    // add the day to the array
    dayOfYearArray[sizeArray] = day;

    // increase the size
    sizeArray++;
}

// remove
void DayOfYearSet::remove(const DayOfYear& day)
{
    // check if the array is empty
    if (sizeArray == 0)
    {
        // do nothing
        return;
    }

    // find the day in the array
    int index = find(day);

    // check if the day is found
    if (index == -1)
    {
        // do nothing
        return;
    }

    // shift the array
    for (int i = index; i < sizeArray - 1; i++)
    {
        dayOfYearArray[i] = dayOfYearArray[i + 1];
    }

    // decrease the size
    sizeArray--;
}

// big five implementation
// ostream overload
ostream& operator<<(ostream& os, const DayOfYearSet& set)
{
    // print the array
    for (int i = 0; i < set.size(); i++)
    {
        const DayOfYearSet::DayOfYear temp = set[i];
       os << temp.getDay() << "/" << temp.getMonth() << endl;
    }
    return os;
}

// istream overload
istream& operator>>(istream& is, DayOfYearSet& set)
{
    // read the array
    for (int i = 0; i < set.size(); i++)
    {
        DayOfYearSet::DayOfYear temp = set[i];
        int day, month;
        is >> day >> month;
        temp.setDay(day);
        temp.setMonth(month);
        set[i] = temp;
    }
    return is;
}

// overload ==
bool DayOfYearSet::operator==(const DayOfYearSet& other) const
{
    // check if the size is the same
    if (this->sizeArray != other.sizeArray)
    {
        return false;
    }

    // check if the array is the same
    for (int i = 0; i < this->sizeArray; i++)
    {
        if (this->dayOfYearArray[i] != other.dayOfYearArray[i])
        {
            return false;
        }
    }
    return true;
}

// overload !=
bool DayOfYearSet::operator!=(const DayOfYearSet& other) const
{
    // check if the size is the same
    if (this->sizeArray != other.sizeArray)
    {
        return true;
    }

    // check if the array is the same
    for (int i = 0; i < this->sizeArray; i++)
    {
        if (this->dayOfYearArray[i] != other.dayOfYearArray[i])
        {
            return true;
        }
    }
    return false;
}

// overload binary + opeator
DayOfYearSet DayOfYearSet::operator+(const DayOfYearSet& other) const
{
    // create a new array
    DayOfYearSet newSet(this->sizeArray + other.sizeArray);

    // copy the array
    for (int i = 0; i < this->sizeArray; i++)
    {
        newSet.add(this->dayOfYearArray[i]);
    }

    // copy the other array
    for (int i = 0; i < other.sizeArray; i++)
    {
        newSet.add(other.dayOfYearArray[i]);
    }


    // return the new set
    return newSet;
}

// overload binary - operator
DayOfYearSet DayOfYearSet::operator-(const DayOfYearSet& other) const
{
    // create a new array
    DayOfYearSet newSet(this->sizeArray);

    // copy the array
    for (int i = 0; i < this->sizeArray; i++)
    {
        newSet.add(this->dayOfYearArray[i]);
    }

    // remove the other array
    for (int i = 0; i < other.sizeArray; i++)
    {
        newSet.remove(other.dayOfYearArray[i]);
    }

    // return the new set
    return newSet;
}

// overload binary ^ operator
DayOfYearSet DayOfYearSet::operator^(const DayOfYearSet& other) const
{
    // create a new array
    DayOfYearSet newSet(this->sizeArray);

    // check if they have same element
    for (int i = 0; i < this->sizeArray; i++)
    {
        for (int j = 0; j < other.sizeArray; j++)
        {
            if (this->dayOfYearArray[i] == other.dayOfYearArray[j])
            {
                newSet.add(this->dayOfYearArray[i]);
            }
        }
    }

    return newSet;
}

// overload unary ! operator
DayOfYearSet DayOfYearSet::operator!() const
{
    // create a new array
    DayOfYearSet newSet(this->sizeArray);

    // copy the array
    for (int i = 0; i < this->sizeArray; i++)
    {
        DayOfYearSet::DayOfYear temp = !this->dayOfYearArray[i];
        newSet.add(temp);
    }

    // return the new set
    return newSet;
}

// overload binary [] operator
DayOfYearSet::DayOfYear DayOfYearSet::operator[](int index) const
{
    // check if the index is valid
    if (index < 0 || index >= this->sizeArray)
    {
        cerr << "Invalid index" << endl;
        return DayOfYear();
    }

    // return the day of year
    return this->dayOfYearArray[index];
}

// contains func
bool DayOfYearSet::contains(const DayOfYear& day) const
{
    // check if the array is empty
    if (this->sizeArray == 0)
    {
        return false;
    }

    // find the day in the array
    auto index = this->find(day);

    // check if the day is found
    if (index == -1)
    {
        return false;
    }

    // return true
    return true;
}

// find func
int DayOfYearSet::find(const DayOfYear& day) const
{
    // check if the array is empty
    if (this->sizeArray == 0)
    {
        return -1;
    }

    // search the array
    for (int i = 0; i < this->sizeArray; i++)
    {
        // check if the day is found
        if (this->dayOfYearArray[i] == day)
        {
            return i;
        }
    }

    // return -1
    return -1;
}


// DayOfYear Implementation
// default constructor
DayOfYearSet::DayOfYear::DayOfYear()
{
    this->day = 0;
    this->month = 0;
    // initialize the active count
    activeCount++;
}

DayOfYearSet::DayOfYear::DayOfYear(int day, int month)
{
    this->day = day;
    this->month = month;
    this->activeCount++;
}

// overload print stream operator
std::ostream& operator<<(std::ostream& os, const DayOfYearSet::DayOfYear& dayOfYear)
{
    os << dayOfYear.getDay() << "/" << dayOfYear.getMonth();
    return os;
}

// overload istream operator
std::istream& operator>>(std::istream& is, DayOfYearSet::DayOfYear& dayOfYear)
{
    int day, month, year;
    is >> day >> month >> year;
    dayOfYear.setDay(day);
    dayOfYear.setMonth(month);
    return is;
}

// overload == operator
bool DayOfYearSet::DayOfYear::operator==(const DayOfYearSet::DayOfYear& other) const
{
    return (this->day == other.day && this->month == other.month);
}

// overload != operator
bool DayOfYearSet::DayOfYear::operator!=(const DayOfYearSet::DayOfYear& other) const
{
    return (this->day != other.day || this->month != other.month);
}

// overload ! operator
// remove from 365 days
DayOfYearSet::DayOfYear DayOfYearSet::DayOfYear::operator!() const
{

    int totalDay = day + month * 30;

    int newMonth = totalDay / 30;
    int newDay = totalDay % 30;

    // return the new day
    return DayOfYear(newDay, newMonth);
}

