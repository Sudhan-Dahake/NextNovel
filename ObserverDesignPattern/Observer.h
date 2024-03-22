#pragma once

using namespace std;

class Subject;

class Observer
{
public:
	Subject* sub;
	virtual void Update() = 0;
};