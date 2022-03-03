#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Iterable.h"
#include "GTUVector.h"
#include "GTUSet.h"
#include "GTUArray.h"

using namespace std;
using namespace Aysegul_GTU;

template<class T>
void testCommonIterableFunctions(Iterable<T>& iterable)
{
    cout << "Size: " << iterable.size() << endl;
    cout << "Empty: " << iterable.empty() << endl;
    cout << "Begin: " << *iterable.begin() << endl;
    cout << "End: " << *iterable.end() << endl;
    cout << "Cbegin: " << *iterable.cbegin() << endl;
    cout << "Cend: " << *iterable.cend() << endl;
    // clear and size
    iterable.clear();
    cout << "After clear" << endl;
    cout << "Size: " << iterable.size() << endl;
}

void iterableIntTests()
{
    // vector
    cout << "GTUVECTOR" << endl;
    GTUVector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    testCommonIterableFunctions(vec);

    // set
    cout << "GTUSET" << endl;
    GTUSet<int> set = {1,2,3,4,5,6,7,8,9,10};
    testCommonIterableFunctions(set);

    // array
    cout << "GTUARRAY" << endl;
    GTUArray<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};
    testCommonIterableFunctions(arr);
}

void iterableStringTests()
{
    // vector
    cout << "GTUVECTOR" << endl;
    GTUVector<string> vec = {"Aysegul", "Gul", "GTU", "CSE"};
    testCommonIterableFunctions(vec);

    // set
    cout << "GTUSET" << endl;
    GTUSet<string> set = {"Aysegul", "Gul", "GTU", "CSE"};
    testCommonIterableFunctions(set);

    // array
    cout << "GTUARRAY" << endl;
    GTUArray<string, 4> arr = {"Aysegul", "Gul", "GTU", "CSE"};
    testCommonIterableFunctions(arr);
}

// test vector functions
void testVectorFunctionsInt()
{
    GTUVector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    cout << "Add 11" << endl;
    vec.add(11);
    cout << "Size: " << vec.size() << endl;
    cout << "[] operator" << endl;
    cout << "vec[0]: " << vec[0] << endl;
    cout << "vec[1]: " << vec[1] << endl;
    cout << "vec[2]: " << vec[2] << endl;
    cout << "Last item: " << vec[vec.size() - 1] << endl;
    
}

void testVectorFunctionsString()
{
    GTUVector<string> vec = {"Aysegul", "Gul", "GTU", "CSE"};
    cout << "Add \"C++\"" << endl;
    vec.add("C++");
    cout << "Size: " << vec.size() << endl;
    cout << "[] operator" << endl;
    cout << "vec[0]: " << vec[0] << endl;
    cout << "vec[1]: " << vec[1] << endl;
    cout << "vec[2]: " << vec[2] << endl;
    cout << "Last item: " << vec[vec.size() - 1] << endl;
}

void testSetFunctionsInt()
{
    GTUSet<int> set = {1,2,3,4,5,6,7,8,9,10};
    cout << "Add 11" << endl;
    set.add(11);
    cout << "Size: " << set.size() << endl;
    cout << "Try adding an existing item" << endl;
    set.add(1);
    cout << "Size: " << set.size() << endl;

    // test intersection
    cout << "Intersection" << endl;
    cout << "Create a new set that contains {1,2,3,4,5,6,7,8,9}" << endl;
    GTUSet<int> set2 = {1,2,3,4,5,6,7,8,9};
    cout << "Intersection of set and set2" << endl;
    GTUSet<int> intersection = set.intersect(set2);
    cout << "Printing intersection" << endl;
    auto it = intersection.begin();
    for (it; it != intersection.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << *it << " ";
    cout << endl;

    // test union
    cout << "Union" << endl;
    cout << "Create a new set that contains {1,2,3,4,5,6,7,8,9,10,11}" << endl;
    GTUSet<int> set3 = {1,2,3,4,5,6,7,8,9,10,11};
    cout << "Union of set and set3" << endl;
    GTUSet<int> unionSet = set.unionSet(set3);
    cout << "Printing union" << endl;
    it = unionSet.begin();
    for (it; it != unionSet.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // test remove
    cout << "Remove [Delete]" << endl;
    cout << "Remove 1" << endl;
    set.remove(1);
    cout << "Printing set" << endl;
    for (auto it = set.begin(); it != set.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    
}

void testSetFunctionsString()
{
    GTUSet<string> set = {"Aysegul", "Gul", "GTU", "CSE"};
    cout << "Add \"C++\"" << endl;
    set.add("C++");
    cout << "Size: " << set.size() << endl;
    cout << "Try adding an existing item" << endl;
    set.add("Aysegul");
    cout << "Size: " << set.size() << endl;

    // test intersection
    cout << "Intersection" << endl;
    cout << "Create a new set that contains {\"Aysegul\", \"Gul\", \"GTU\"}" << endl;
    GTUSet<string> set2 = {"Aysegul", "Gul", "GTU"};
    cout << "Intersection of set and set2" << endl;
    GTUSet<string> intersection = set.intersect(set2);
    cout << "Size: " << intersection.size() << endl;
    cout << "Printing intersection" << endl;
    auto it = intersection.begin();
    int i = 0; 
    for (it; it != intersection.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // test union
    cout << "Union" << endl;
    cout << "Create a new set that contains {\"Aysegul\", \"Gul\", \"GTU\", \"CSE\", \"C++\"}" << endl;
    GTUSet<string> set3 = {"Aysegul", "Gul", "GTU", "CSE", "C++"};
    cout << "Union of set and set3" << endl;
    GTUSet<string> unionSet = set.unionSet(set3);
    cout << "Printing union" << endl;
    it = unionSet.begin();
    for (it; it != unionSet.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // test remove
    cout << "Remove [Delete]" << endl;
    cout << "Remove \"Aysegul\"" << endl;
    set.remove("Aysegul");
    cout << "Printing set" << endl;
    for (auto it = set.begin(); it != set.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

}

void testArrayFunctionsInt()
{
    cout << "Using an arr that contains {1,2,3,4}" << endl;
    GTUArray<int, 4> arr = {1,2,3,4};
    cout << "Size: " << arr.size() << endl;
    cout << "[] operator" << endl;
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;
    cout << "arr[2]: " << arr[2] << endl;
    cout << "Last item: " << arr[arr.size() - 1] << endl;

    // test at
    cout << "at" << endl;
    cout << "arr.at(0): " << arr.at(0) << endl;
    cout << "arr.at(1): " << arr.at(1) << endl;

    // test front
    cout << "front" << endl;
    cout << "arr.front(): " << arr.front() << endl;

    // test back
    cout << "back" << endl;
    cout << "arr.back(): " << arr.back() << endl;

    // test fill
    cout << "fill" << endl;
    cout << "Fill with 6" << endl;
    arr.fill(6);
    cout << "Printing arr" << endl;
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // test data
    cout << "data" << endl;
    int *data = arr.data();
    cout << "data[0]: " << data[0] << endl;

    // test max_size
    cout << "max_size:" << arr.max_size() << endl;

}

void testArrayFunctionsString()
{
    cout << "Using an array that contains {Aysegul, Gul, GTU, CSE}" << endl;
    GTUArray<string, 4> arr = {"Aysegul", "Gul", "GTU", "CSE"};
    cout << "Size: " << arr.size() << endl;
    cout << "[] operator" << endl;
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;
    cout << "arr[2]: " << arr[2] << endl;
    cout << "Last item: " << arr[arr.size() - 1] << endl;

    // test at
    cout << "at" << endl;
    cout << "arr.at(0): " << arr.at(0) << endl;
    cout << "arr.at(1): " << arr.at(1) << endl;

    // test front
    cout << "front" << endl;
    cout << "arr.front(): " << arr.front() << endl;

    // test back
    cout << "back" << endl;
    cout << "arr.back(): " << arr.back() << endl;

    // test fill
    cout << "fill" << endl;
    cout << "Fill with \"C++\"" << endl;
    arr.fill("C++");
    cout << "Printing arr" << endl;
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // test data
    cout << "data" << endl;
    string *data = arr.data();
    cout << "data[0]: " << data[0] << endl;

    // test max_size
    cout << "max_size:" << arr.max_size() << endl;
}

void testExceptions()
{
    cout << "Create a new vector, set and array that contains {1,2,3,4,5,6}" << endl;
    GTUVector<int> vector = {1,2,3,4,5,6};
    GTUSet<int> set = {1,2,3,4,5,6};
    GTUArray<int, 6> arr = {1,2,3,4,5,6};

    cout << "Try using [7] (invalid index) for vector" << endl;
    try
    {
        cout << "vector[7]: " << vector[7] << endl;
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }

    cout << "Try using [7] (invalid index) for array" << endl;
    try
    {
        cout << "set[7]: " << arr[7] << endl;
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }

    cout << "Try at function (at(7)) for array" << endl;
    try
    {
        cout << "arr.at(7): " << arr.at(7) << endl;
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }

    cout << "Try accesing front and back of null array and data" << endl;
    GTUArray<int, 0> arr2;
    try
    {
        cout << "arr2.front(): " << arr2.front() << endl;
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }
    try
    {
        int* data = arr2.data();
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }

    try
    {
        cout << "arr2.back(): " << arr2.back() << endl;
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }

    cout << "Try initializing 0 sized array with bigger list" << endl;
    try
    {
        GTUArray<int, 0> arr2 = {1,2,3,4,5,6};
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }

    cout << "Try empty set intersection and union" << endl;
    GTUSet<int> set1;
    GTUSet<int> set2;
    try
    {
        GTUSet<int> set3 = set1.intersect(set2);
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }

    try
    {
        GTUSet<int> set3 = set1.unionSet(set2);
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }

    cout << "Try accesing begin, end, cbegin, cend iterator of null set" << endl;
    GTUSet<int> set4;
    try
    {
        GTUIterator<int> it = set4.begin();
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }
    try
    {
        GTUIterator<int> it = set4.end();
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }
    try
    {
        GTUIteratorConst<int> it = set4.cbegin();
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }
    try
    {
        GTUIteratorConst<int> it = set4.cend();
    }
    catch (char const *e)
    {
        cout << "Exception: " << e << endl;
    }


}

void changeValueTo20(int &value)
{
    value = 20;
}

void changeValueToStringYSA(string &value)
{
    value = "YSA";
}

void testSTDFunctionsInt(Iterable<int>& iterable)
{
    cout << "Content of iterable: " << endl;

    cout << "begin():" << *(iterable.begin()) << endl;
    cout << "end(): " << *(iterable.end()) << endl;

    auto it = iterable.begin();
    while (it.getNode() != nullptr)
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    cout << "std::sort applied to iterable" << endl;
    std::sort(iterable.begin(), iterable.end());

    cout << "Content of iterable after std::sort: " << endl;
    it = iterable.begin();
    while (it.getNode() != nullptr)
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    cout << "std::find applied to iterable" << endl;
    cout << "find(5): " << *std::find(iterable.begin(), iterable.end(), 5) << endl;
    cout << "find(999) (not in the list - it will give last item): " << *std::find(iterable.begin(), iterable.end(), 999) << endl;

    cout << "std::for_each applied to iterable" << endl;
    cout << "changeValueTo20 func applied";
    std::for_each(iterable.begin(), iterable.end(), changeValueTo20);
    cout << "Content of iterable after std::for_each: " << endl;
    it = iterable.begin();
    while (it.getNode() != nullptr)
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void testSTDFunctionsString(Iterable<string>& iterable)
{
    cout << "Content of iterable: " << endl;
    auto it = iterable.begin();
    while (it.getNode() != nullptr)
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    cout << "std::sort applied to iterable" << endl;
    std::sort(iterable.begin(), iterable.end());

    cout << "Content of iterable after std::sort: " << endl;
    it = iterable.begin();
    while (it.getNode() != nullptr)
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    cout << "std::find applied to iterable" << endl;
    cout << "find(CSE): " << *std::find(iterable.begin(), iterable.end(), "CSE") << endl;
    cout << "find(MTU) (not in the list - it will give last item): " << *std::find(iterable.begin(), iterable.end(), "MTU") << endl;

    cout << "std::for_each applied to iterable" << endl;
    cout << "changeValueToStringYSA func applied";
    std::for_each(iterable.begin(), iterable.end(), changeValueToStringYSA);
    cout << "Content of iterable after std::for_each: " << endl;
    it = iterable.begin();
    while (it.getNode() != nullptr)
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void testAll()
{
    cout << "Welcome to GTU Collection Test" << endl;
    cout << "==========================================================" << endl;
    cout << "==========================================================" << endl;


    try
    {
        // int tests
        cout << "First, fill vector, set and array with {1,2,3,4,5,6,7,8,9,10}" << endl;
        cout << "After that test common iterable functions" << endl;
        iterableIntTests();
        cout << "==========================================================" << endl;

        // string tests
        cout << "Also test with strings" << endl;
        cout << "Initialize with {\"Aysegul\", \"Gul\", \"Gtu\", \"CSE\"}" << endl;
        iterableStringTests();

        cout << "==========================================================" << endl;
        cout << "Test vector functions" << endl;
        cout << "First test for int" << endl;
        testVectorFunctionsInt();
        cout << "==========================================================" << endl;
        cout << "Second test for string" << endl;
        testVectorFunctionsString();

        cout << "==========================================================" << endl;
        cout << "Test set functions" << endl;
        cout << "First test for int" << endl;
        testSetFunctionsInt();
        cout << "==========================================================" << endl;
        cout << "Second test for string" << endl;
        testSetFunctionsString();

        cout << "==========================================================" << endl;
        cout << "Test array functions" << endl;
        cout << "First test for int" << endl;
        testArrayFunctionsInt();
        cout << "==========================================================" << endl;
        cout << "Second test for string" << endl;
        testArrayFunctionsString();
    }
    catch(char const *e)
    {
        cout << "Exception: " << e << endl;
    } catch (...)
    {
        cout << "Exception: Unknown" << endl;
    }
    

    cout << "==========================================================" << endl;
    cout << "Test some expections" << endl;
    testExceptions();

    cout << "==========================================================" << endl;
    cout << "Test some STL functions" << endl;
    cout << "First test for int" << endl;
    cout << "Create vector, set and array that contains {1,5,7,4,2,17,15,18,10,20}" << endl;
    GTUVector<int> vector1 = {1,5,7,4,2,17,15,18,10,20};
    GTUSet<int> set1 = {1,5,7,4,2,17,15,18,10,20};
    GTUArray<int, 10> array1 = {1,5,7,4,2,17,15,18,10,20};
    cout << "Test Vector" << endl;
    testSTDFunctionsInt(vector1);
    cout << "==========================================================" << endl;
    cout << "Test Set" << endl;
    testSTDFunctionsInt(set1);
    cout << "==========================================================" << endl;
    cout << "Test Array" << endl;
    testSTDFunctionsInt(array1);

    cout << "==========================================================" << endl;
    cout << "Second test for string" << endl;
    cout << "Create vector, set and array that contains {\"Aysegul\", \"Gul\", \"CSE\", \"YSA\"}" << endl;
    GTUVector<string> vector2 = {"Aysegul", "Gul", "CSE", "YSA"};
    GTUSet<string> set2 = {"Aysegul", "Gul", "CSE", "YSA"};
    GTUArray<string, 4> array2 = {"Aysegul", "Gul", "CSE", "YSA"};
    cout << "Test Vector" << endl;
    testSTDFunctionsString(vector2);

    cout << "==========================================================" << endl;
    cout << "Test Set" << endl;
    testSTDFunctionsString(set2);
    
    cout << "==========================================================" << endl;
    cout << "Test Array" << endl;
    testSTDFunctionsString(array2);


    cout << "==========================================================" << endl;
    cout << "Test is finished" << endl;
    cout << "Goodbye" << endl;

    return;
    
}

int main()
{
    testAll();
    


}