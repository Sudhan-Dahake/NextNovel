
#include "Subject.h"

void Subject::Attach(Observer* obj) {
    observers.push_back(obj);
}

void Subject::Detach(Observer* obj) {

}

void Subject::Notify() {
    for (int i = 0; i < observers.size(); ++i) {
        observers[i]->Update();
    }
}