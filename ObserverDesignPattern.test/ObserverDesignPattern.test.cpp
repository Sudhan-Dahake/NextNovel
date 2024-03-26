#include "pch.h"
#include "CppUnitTest.h"
#include "../ObserverDesignPattern/ConcreteObserverA.h"
#include "../ObserverDesignPattern/ConcreteObserverB.h"
#include "../ObserverDesignPattern/ConcreteSubject.h"
#include "../ObserverDesignPattern/Observer.h"
#include "../ObserverDesignPattern/Subject.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ObserverDesignPatterntest
{
	TEST_CLASS(ObserverDesignPatterntest)
	{
	public:
		
		TEST_METHOD(TestMethod1_ConcreteObserver_Constructor)
		{
			//Arrange
			ConcreteSubject sub;
			int expected = 1;

			//Act
			ConcreteObserverA conObA(&sub);
			int actual = sub.observers.size(); //ensures that the sbject observer size increases

			//Assert
			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(TestMethod2_Subject_SetState_GetState)
		{
			//Arrange
			ConcreteSubject sub;
			int expected = 1;

			//Act
			sub.SetState(1);
			int actual = sub.GetState(); //ensures that the set state and get state functions work correctly
			

			//Assert
			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(TestMethod3_ConcreteObserver_Update)
		{
			//Arrange
			ConcreteSubject sub;
			int expected = 1;

			//Act
			ConcreteObserverA conObA(&sub);
			sub.SetState(1);
			conObA.Update();  //ensures that the update function works correctly
			int actual = conObA.sub->GetState();

			//Assert
			Assert::AreEqual(expected, actual);
		}



		TEST_METHOD(TestMethod4_Subject_Notify)
		{
			//Arrange
			ConcreteSubject sub;
			ConcreteObserverA obj1(&sub);

			//Act
			sub.SetState(5);
			sub.Notify(); //ensures that the notify function works correctly

			//Assert
			Assert::AreEqual(sub.GetState(), obj1.sub->GetState());
		}

	};
}

