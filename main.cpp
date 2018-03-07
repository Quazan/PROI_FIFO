#include <iostream>
#include "fifo.h"


int main() {

	fifo_string test_obj;
	test_obj.push("PROI1");
	test_obj.push("PROI2");
	test_obj.push("PROI3");
	test_obj.push("PROI4");
	std::cout<<test_obj.get(-1.1)<<"\n\n";
        test_obj.push("PROI5");
        test_obj.push("PROI6");

	test_obj.get(100);
	std::cout<<test_obj;
	return 0;
}
