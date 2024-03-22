#pragma once

using namespace std;
class Iterator;

//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
class Aggregate //interface equivalent - abstract class
{
public:
    virtual Iterator* CreateIterator() = 0; //pure virtual function
};
