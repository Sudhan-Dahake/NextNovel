#pragma once

#include "Observer.h"
#include <vector>

using namespace std;

class Subject
{
public:
	vector <Observer*> observers;
public:
	void Attach(Observer* obj);

	void Detach(Observer* obj);

	void Notify();

	virtual void SetState(int value) = 0;
	virtual int GetState() = 0;
};