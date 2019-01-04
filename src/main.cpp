#include "../include/instruction.h"

#include <iostream>


int main(){
	myvm::Register rax = {"rax", 10};
	myvm::Register rdi = {"rdi", 5};

	myvm::Instruction add{"add", 0x1 , myvm::instruction::add};

	add.register_to_map();

	add(rax, rdi);

	std::cout << std::hex << std::showbase << rax << std::endl;
}
