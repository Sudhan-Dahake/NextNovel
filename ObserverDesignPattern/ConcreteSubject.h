#pragma once

#include "Subject.h"

using namespace std;

class ConcreteSubject : public Subject
{
private:
	int state;
public:
	void SetState(int value) override;
	int GetState() override;
};