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
    DayOfYearSet(vector<DayOfYear> days);

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
    // dynamic DayOfYear array
    DayOfYear *dayOfYear;
    
};

class DayOfYearSet::DayOfYear {
    public:
        DayOfYear(int day, int month, int year);


        int getDay();
        int getMonth();
        int getYear();
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);

        // return active days of year
        static int getActiveDaysOfYear();

        // overload print
        friend ostream& operator<<(ostream& os, const DayOfYear& rhs);
        

    private:
        int day;
        int month;
        int year;

        // active dayofyear count
        static int count;

};


} // end namespace