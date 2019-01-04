#ifndef INSTRUCT_H_
#define INSTRUCT_H_

#include <string>
#include <cstdint>
#include <functional>
#include <map>

namespace myvm {

	struct Register {
		std::string name;
		uint64_t    value;

		void register_to_map();

		operator int() {
			return this->value;
		}
	};


	struct Instruction {
		std::string name;
		uint64_t opcode;

		std::function<void(Register&, const uint64_t)> func;

		void register_to_map();

		void operator()(Register& r, const uint64_t v){
			func(r , v);
		}
	};

	namespace instruction {
		void add(Register& r, const uint64_t n) {
			r.value += n;
		}
	}


	std::map <std::string, Instruction> instruction_map;
	std::map <std::string, Register>    register_map;

	void Instruction::register_to_map() {
		instruction_map[this->name] = *this;
	}

	void Register::register_to_map() {
		register_map[this->name] = *this;
	}
}

#endif
