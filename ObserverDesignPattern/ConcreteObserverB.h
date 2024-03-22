#pragma once

#include "Observer.h"

using namespace std;

class ConcreteObserverB : public Observer
{
private:
	int state;
public:
	ConcreteObserverB(Subject* obj);

	void Update() override;
};