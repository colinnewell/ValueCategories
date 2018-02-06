#include "EditMe.cpp"

bool success = true;

void Test(int result, int expected, const char* name) {
	if (result != expected) {
		std::cout << name << "Test failed " << std::endl;
		success = false;
	}
}

int main() {
	T t;
	T t2{t};
	Test(t2.GetValue(), 1, "T(T&)");
	t2 = t;
	Test(t2.GetValue(), 2, "T& operator=(T&)");
	T t3{static_cast<const T&>(t2)};
	Test(t3.GetValue(), 3, "T(const T&)");
	t3 = static_cast<const T&>(t2);
	Test(t3.GetValue(), 4, "T& operator=(const T&)");
	T t4{std::move(t3)};
	Test(t4.GetValue(), 5, "T(T&&)");
	Test(T::TestSix(t4).GetValue(), 5, "T::TestSix(T&)");
	if (success)
		std::cout << "All tests passed!" << std::endl;
	return 0;
}

