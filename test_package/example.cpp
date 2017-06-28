#include <string>
#include <iostream>
#include "test.pb.h"

int main()
{
	TestMessage message;
	message.set_field("Nogi");
	
	std::cout << message.field() << std::endl;

	std::string s;
	std::cout << message.SerializeToString(&s) << std::endl;

	return 0;
}
