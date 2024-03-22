#pragma once

#include <vector>

#include "Aggregate.h"
#include "Books.h"


using namespace std;

//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
class ConcreteAggregate : public Aggregate //inherits from Aggregate class
{
private:
    vector<Books> elements; //vector of books
public:
    Iterator* CreateIterator() override; //overrides the Create Iterator function

    int Size() const; //determines the size of the vector

    void AddBook(const string& title, const string& author, const string& description); //adds book to vector

    Books GetElement(int index) const; //returns book element
};
