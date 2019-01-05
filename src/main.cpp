#include "../include/instruction.h"
#include "../include/assembler.h"
#include <iostream>

using namespace myvm;
using namespace myvm::instruction;

int main(){
	setup();

	adc('A'/2);

	sta(0x2ff);

	adc($(0x2ff));

	std::cout << std::hex << A << std::endl;
}
