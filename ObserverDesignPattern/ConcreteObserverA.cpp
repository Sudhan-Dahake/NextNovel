
#include "ConcreteObserverA.h"
#include "Subject.h"

ConcreteObserverA::ConcreteObserverA(Subject* obj) {
    sub = obj;
    sub->Attach(this);
}

void ConcreteObserverA::Update() {
    state = sub->GetState();
}