#pragma once

#include "Observer.h"

using namespace std;

class ConcreteObserverA : public Observer
{
private:
	int state;
public:
	ConcreteObserverA(Subject* obj);

	void Update() override;
};