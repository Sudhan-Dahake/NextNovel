#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"
//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
Iterator* ConcreteAggregate::CreateIterator()
{
    return new ConcreteIterator(this);
}

int ConcreteAggregate::Size() const
{
    return elements.size();
}

void ConcreteAggregate::AddBook(const string& title, const string& author, const string& description)
{
    elements.push_back(Books(title, author, description));
}

Books ConcreteAggregate::GetElement(int index) const
{
    return elements.at(index);
}