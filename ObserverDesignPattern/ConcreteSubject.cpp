
#include "ConcreteSubject.h"

void ConcreteSubject::SetState(int value) {
    state = value;
    Notify();
}

int ConcreteSubject::GetState() {
    return state;
}