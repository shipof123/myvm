#include "instruction.h"
#include <cctype>
#include <iostream>

namespace myvm {

	namespace debug {
		void debug_mem(uint16_t start, uint16_t len) {
			for(auto i = 0; i < len; i++) {
				char char_version = memory[start+i];
				if(!isprint(char_version)) {
					char_version = '.';
				}
				std::cerr << std::hex << '[' << start+i << "]: " << int(memory[start+i]) << " " << char_version << std::endl;
			}
		}
	}

}
