#ifndef INSTRUCT_H_
#define INSTRUCT_H_

#include <string>
#include <cstdint>
#include <functional>
#include <map>
#include <tuple>
#include <iostream>

#define $(a) myvm::_addr{(uint16_t)a}

namespace myvm {
	uint8_t memory[(0x1<<16)];

	struct _addr {
		uint16_t value;

		operator uint16_t() {
			return value;
		}
		operator uint8_t() {
			return value;
		}
	};

	struct Register {
		uint8_t    code;
		uint8_t    value;

		void register_to_map();

		operator int() {
			return this->value;
		}
	};

	std::ostream& operator << (std::ostream o, const struct Register& r){
		return (o << "A: " << std::hex << r.value << " " << char(r.value));
	}

	struct Register A, X, Y;

	namespace instruction {
		void adc(const uint8_t n) {
			A.value += n;
		}

		void adc(const struct _addr addr){
			A.value += memory[addr.value];
		}

		void inx() {
			X.value++;
		}

		void iny() {
			Y.value++;
		}

		void tax() {
			X.value = A.value;
		}

		void tay() {
			Y.value = A.value;
		}


		void lda(uint8_t value) {
			A.value = value;
		}

		void lda(uint16_t addr){
			A.value = memory[addr];
		}

		void sta(uint16_t addr) {
			memory[addr] = A.value;
		}
	}

	void setup() {
		A = {0x01, 0};
		X = {0x02, 0};
		Y = {0x03, 0};
	}
}

#endif
