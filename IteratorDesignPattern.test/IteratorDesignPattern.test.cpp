#include "pch.h"
#include "CppUnitTest.h"
#include "../IteratorDesignPattern/Aggregate.h"
#include "../IteratorDesignPattern/Books.h"
#include "../IteratorDesignPattern/ConcreteAggregate.h"
#include "../IteratorDesignPattern/ConcreteIterator.h"
#include "../IteratorDesignPattern/Iterator.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IteratorDesignPatterntest
{
	TEST_CLASS(IteratorDesignPatterntest)
	{
	public:
		
		TEST_METHOD(TestMethod1_DefaultConstructor_Name)
		{
			//Arrange
			Books book;
			string expectedName = ""; //default constructor sets name to ""

			//Act
			string actual = book.getName();


			//Assert
			Assert::AreEqual(expectedName, actual);
		}

		TEST_METHOD(TestMethod2_DefaultConstructor_Author)
		{
			//Arrange
			Books book;
			string expecteAuthor = ""; //default constructor sets author to ""


			//Act
			string actual = book.getAuthor();


			//Assert
			Assert::AreEqual(expecteAuthor, actual);
		}

		TEST_METHOD(TestMethod3_DefaultConstructor_Info)
		{
			//Arrange
			Books book;
			string expecteInfo = ""; //default constructor sets info to ""


			//Act
			string actual = book.getInfo();


			//Assert
			Assert::AreEqual(expecteInfo, actual);
		}

		TEST_METHOD(TestMethod4_GetName)
		{
			//Arrange
			Books book("BookName", "BookAuthor", "BookInfo");
			string expecteName = "BookName"; 


			//Act
			string actual = book.getName(); //get name function returns the set name in parameterized constructor


			//Assert
			Assert::AreEqual(expecteName, actual);
		}


		TEST_METHOD(TestMethod5_GetAuthor)
		{
			//Arrange
			Books book("BookName", "BookAuthor", "BookInfo");
			string expecteAuthor = "BookAuthor";


			//Act
			string actual = book.getAuthor(); //get author function returns the set author in parameterized constructor


			//Assert
			Assert::AreEqual(expecteAuthor, actual);
		}

		TEST_METHOD(TestMethod6_GetInfo)
		{
			//Arrange
			Books book("BookName", "BookAuthor", "BookInfo");
			string expectedInfo = "BookInfo";


			//Act
			string actual = book.getInfo(); //get info function returns the set author in parameterized constructor


			//Assert
			Assert::AreEqual(expectedInfo, actual);
		}

		TEST_METHOD(TestMethod7_ConcreteAggregate_Size)
		{
			//Arrange
			ConcreteAggregate conAgg;
			int expected = 0;
			
			
			//Act
			int actual = conAgg.Size(); //size of Concrete Aggregate should initially be 0


			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod8_ConcreteAggregate_Size)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName", "BookAuthor", "BookInfo");
			int expected = 1;


			//Act
			int actual = conAgg.Size(); //size with one book in it should be 1


			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod9_GetElement_0_Name)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName", "BookAuthor", "BookInfo");
			string expectedName = "BookName";


			//Act
			string actual = conAgg.GetElement(0).getName(); //get element should return the element at the index


			//Assert
			Assert::AreEqual(expectedName, actual);
		}

		TEST_METHOD(TestMethod10_GetElement_2_Info)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName1", "BookAuthor1", "BookInfo1");
			conAgg.AddBook("BookName2", "BookAuthor2", "BookInfo2");
			conAgg.AddBook("BookName3", "BookAuthor3", "BookInfo3");
			string expectedInfo = "BookInfo3";


			//Act
			string actual = conAgg.GetElement(2).getInfo(); //get element should return the eleent at the index


			//Assert
			Assert::AreEqual(expectedInfo, actual);
		}
		
		TEST_METHOD(TestMethod11_CreateIterator)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName1", "BookAuthor1", "BookInfo1");
			Iterator* it = nullptr; //sets to nullpointer
		
			//Act
			it = conAgg.CreateIterator(); //should sucessfully create the iterator to point to the concrete aggregate and no longer be nullpointer


			//Assert
			Assert::IsNotNull(it);
		}

		TEST_METHOD(TestMethod12_ConcreteIterator_CurrentItem)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName1", "BookAuthor1", "BookInfo1");
			conAgg.AddBook("BookName2", "BookAuthor2", "BookInfo2");
			conAgg.AddBook("BookName3", "BookAuthor3", "BookInfo3");
			Iterator* it = conAgg.CreateIterator();
			ConcreteIterator conIt(&conAgg);
			string expected = "BookName1";


			//Act
			string actual = conIt.CurrentItem().getName(); //current item should be first book in vector

			
			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod13_ConcreteIterator_Next)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName1", "BookAuthor1", "BookInfo1");
			conAgg.AddBook("BookName2", "BookAuthor2", "BookInfo2");
			conAgg.AddBook("BookName3", "BookAuthor3", "BookInfo3");
			Iterator* it = conAgg.CreateIterator();
			ConcreteIterator conIt(&conAgg);
			string expected = "BookName3";
		


			//Act
			conIt.Next(); //should be at the second book now
			conIt.Next(); //should be at the end of the vector now
			string actual = conIt.CurrentItem().getName(); //current item should be the last book added


			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod14_ConcreteIterator_First)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName1", "BookAuthor1", "BookInfo1");
			conAgg.AddBook("BookName2", "BookAuthor2", "BookInfo2");
			conAgg.AddBook("BookName3", "BookAuthor3", "BookInfo3");
			Iterator* it = conAgg.CreateIterator();
			ConcreteIterator conIt(&conAgg);
			string expected = "BookName1";


			//Act
			conIt.Next(); //second book
			conIt.Next(); //third book
			conIt.First(); //back to first book
			string actual = conIt.CurrentItem().getName(); //current item should be the first book added


			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod15_IsDone_True)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName1", "BookAuthor1", "BookInfo1");
			conAgg.AddBook("BookName2", "BookAuthor2", "BookInfo2");
			conAgg.AddBook("BookName3", "BookAuthor3", "BookInfo3");
			Iterator* it = conAgg.CreateIterator();
			ConcreteIterator conIt(&conAgg);
			bool expected = true;


			//Act
			conIt.Next(); //second
			conIt.Next(); //third
			conIt.Next(); //end
			bool actual = conIt.IsDone(); //should be at the end of the iterator so should be done


			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod16_IsDone_False)
		{
			//Arrange
			ConcreteAggregate conAgg;
			conAgg.AddBook("BookName1", "BookAuthor1", "BookInfo1");
			conAgg.AddBook("BookName2", "BookAuthor2", "BookInfo2");
			conAgg.AddBook("BookName3", "BookAuthor3", "BookInfo3");
			Iterator* it = conAgg.CreateIterator();
			ConcreteIterator conIt(&conAgg);
			bool expected = false;


			//Act
			conIt.Next(); //second item
			bool actual = conIt.IsDone(); //should not be done


			//Assert
			Assert::AreEqual(expected, actual);
		}
	};
}

