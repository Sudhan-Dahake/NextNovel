#pragma once

#include "Iterator.h"
#include "ConcreteAggregate.h"
using namespace std;


//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
class ConcreteIterator : public Iterator //inherits from iterator class
{
private:
    const ConcreteAggregate* aggregateObj; //pointer to aggregate object
    int currentElement; //keeps track of current element we are on
public:
    ConcreteIterator(const ConcreteAggregate* obj);

    void First() override; //gives first element

    void Next() override; //gives next element

    bool IsDone() override; //determines if done iterating through list

    Books CurrentItem() override; //returns current book item
};