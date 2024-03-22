#pragma once

#include "Books.h"
using namespace std;



//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
class Iterator 
{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Books CurrentItem() = 0;
};