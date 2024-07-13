#include<iostream>
#include<optional>


int main() {
	std::optional<int> s;
	s = 3;
	if (s.has_value())std::cout << s.value() << std::endl;
	else std::cout << "not declared";
	std::cin.get();
}