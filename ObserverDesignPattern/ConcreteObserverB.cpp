
#include "ConcreteObserverB.h"
#include "Subject.h"

ConcreteObserverB::ConcreteObserverB(Subject* obj) {
    sub = obj;
    sub->Attach(this);
}

void ConcreteObserverB::Update() {
    state = sub->GetState();
}