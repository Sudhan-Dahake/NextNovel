#include "ConcreteIterator.h"
#include "ConcreteAggregate.h"
//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
ConcreteIterator::ConcreteIterator(const ConcreteAggregate* obj)
{
    aggregateObj = obj;
    currentElement = 0;
}

void ConcreteIterator::First()
{
    currentElement = 0;
}

void ConcreteIterator::Next()
{
    currentElement++;
}

bool ConcreteIterator::IsDone()
{
    return currentElement >= aggregateObj->Size();
}

Books ConcreteIterator::CurrentItem()
{
    return aggregateObj->GetElement(currentElement);
}