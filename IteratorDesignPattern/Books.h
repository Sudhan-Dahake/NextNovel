#pragma once
#include <string>
using namespace std;

//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
class Books //List will be made up of these items
{
    string Name;
    string Author;
    string Info;
public:
    Books();

    Books(const string& name, const string& author, const string& info); //parameterized constructor

    const string& getName() const; //returns name

    const string& getAuthor() const; //returns author

    const string& getInfo() const; //returns info
};