
#include <iostream>
#include "ConcreteSubject.h"
#include "ConcreteObserverA.h"
#include "ConcreteObserverB.h"

using namespace std;


int main()
{
	Subject* obj = new ConcreteSubject();

	Observer* obj1 = new ConcreteObserverA(obj);
	Observer* obj2 = new ConcreteObserverB(obj);

	obj->SetState(1);

	delete obj;
	delete obj1;
	delete obj2;

	return 0;
}