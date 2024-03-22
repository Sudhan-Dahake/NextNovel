#include "Books.h"
//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
Books::Books() : Name(""), Author(""), Info("") {}

Books::Books(const string& name, const string& author, const string& info) : Name(name), Author(author), Info(info) {}

const string& Books::getName() const
{
    return Name;
}

const string& Books::getAuthor() const
{
    return Author;
}

const string& Books::getInfo() const
{
    return Info;
}