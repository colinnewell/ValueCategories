#include <iostream>
#include <utility>

//Each call in main will pass a certain value category and expect a specific number.

//Your job is to implement the correct functions/constructors in T.
//The first two tests have already been done for you.

struct T {
	//Implement a constructor taking a reference to its own type(T). v should be set to 1. (DONE)
	T(T&) {
		v = 1;
	}

	//Implement an operator= also taking a reference to its own type. v should be set to 2. (DONE)
	T& operator=(T&) {
		v = 2;
		return *this;
	}

	//Implement a constructor taking a const reference to its own type (T). v should be set to 3.
	T(const T&) : v(3) {};

	//Implement an operator= also taking a reference to its own type. v should be set to 4.
	T& operator=(const T&) {
		v = 4;
		return *this;
	}


	//Implement a constructor taking an rvalue reference to its own type. v should be set to 5.
	T(T&&) : v(5) {};


	//Implement a static function called TestSix that returns a T and takes a T&.
	//  The T it returns should have v set to 5.
	//  Your function MUST NOT just set v to 5.
	static T TestSix(T& t) {
		return std::move(t);
	}

//STOP HERE. DO NOT modify/add/delete anything below this line.
	T() = default;
	int GetValue() { return v; }
  private:
	int v = 0;
};


