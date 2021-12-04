#include <iostream>
#include <vector>

using namespace std;

// namespace
namespace Aysegul_DayOfYearSet
{

class DayOfYearSet
{
public:
    class DayOfYear;

    DayOfYearSet();
    DayOfYearSet(int size);
    DayOfYearSet(vector<DayOfYear>& days);

    // big three provided
    DayOfYearSet(const DayOfYearSet& rhs);
    DayOfYearSet& operator=(const DayOfYearSet& rhs);
    ~DayOfYearSet();

    // big five
    friend ostream& operator<<(ostream& os, const DayOfYearSet& rhs);
    friend istream& operator>>(istream& is, DayOfYearSet& rhs);

    // overload == and !=
    bool operator==(const DayOfYearSet& rhs) const;
    bool operator!=(const DayOfYearSet& rhs) const;

    // add func
    void add(const DayOfYear& day);

    // remove
    void remove(const DayOfYear& day);

    // size
    int size() const;

    // contains
    bool contains(const DayOfYear& day) const;

    // find index
    int find(const DayOfYear& day) const;

    // unary ! overload
    DayOfYearSet operator!() const;

    // binary + overload
    DayOfYearSet operator+(const DayOfYearSet& rhs) const;
    
    // binary - overload
    DayOfYearSet operator-(const DayOfYearSet& rhs) const;

    // binary ^ overload
    DayOfYearSet operator^(const DayOfYearSet& rhs) const;

    // binary [] overload
    DayOfYear operator[](int index) const;

    // static func that returns active days of year number
    static int getActiveDaysOfYear();

    
private:
    DayOfYear *dayOfYearArray;
    int sizeArray;
    int capacity;

    // helper func

    
};

class DayOfYearSet::DayOfYear {
    public:
        // default constructor
        DayOfYear();
        DayOfYear(int day, int month);


        int getDay() const;
        int getMonth() const;

        void setDay(int day);
        void setMonth(int month);

        // return active days of year
        static int getActiveDaysOfYear();

        // print function
        void print() const;


        // overload == and !=
        bool operator==(const DayOfYear& rhs) const;
        bool operator!=(const DayOfYear& rhs) const;

        // overload unary ! operator
        DayOfYear operator!() const;

    private:
        int day;
        decltype(day) month;

        // active dayofyear count
        static int activeCount;

};

// inline setters getters
inline int DayOfYearSet::size() const { return this->sizeArray; }

inline int DayOfYearSet::DayOfYear::getDay() const {return day;}
inline int DayOfYearSet::DayOfYear::getMonth() const {return month;}

inline void DayOfYearSet::DayOfYear::setDay(int day) {this->day = day;}
inline void DayOfYearSet::DayOfYear::setMonth(int month) {this->month = month;}

// get static active days of year
inline int DayOfYearSet::DayOfYear::getActiveDaysOfYear() {return activeCount;}



} // end namespace