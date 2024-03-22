#include <iostream>
#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"

using namespace std;

//code from http://coursegalaxy.com/design-patterns/iterator-cpp.html
int main()
{
    ConcreteAggregate* bookCollection = new ConcreteAggregate();

    bookCollection->AddBook("FirstBookName", "Author1", "info1"); //add items to list
    bookCollection->AddBook("SecondBookName", "Author2", "info2");
    bookCollection->AddBook("ThirdBookName", "Author3", "info3");

    Iterator* iterator = bookCollection->CreateIterator(); //turn book vector into iterator
    int i = 0;
    for (iterator->First(); !(iterator->IsDone()); iterator->Next()) //loop through iterator to see all the items in it
    {
        cout << "\n Title: " << bookCollection->GetElement(i).getName() << "\n Author: " << bookCollection->GetElement(i).getAuthor() << "\n Description: " << bookCollection->GetElement(i).getInfo() << endl; //prints book to screen
        i++; //move on to next item
    }


    delete iterator; //delete iterator
    delete bookCollection; //delete book collection

    return 0;
}
