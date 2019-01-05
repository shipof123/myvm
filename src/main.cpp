#include "../include/instruction.h"
#include "../include/debug.h"

#define wr_buff 0x0f00

using namespace myvm;
using namespace myvm::instruction;
using namespace myvm::debug;


int user_code() {
	/*
	        Your code here;
	        Mostly based of 6502 assembly

                Registers:
                        A = main accumulator 8-bit
                        X & Y = indexing     8-bit each

                Addressing memory:
                        use $(0xhex_number) ex: $(0x20)
                        can use value of registers ex: $(0x30 + X) or $(X)

                Hello World

                        lda('H');
                        pra();
                        lda('e');
                        pra();
                        lda('l');
                        pra();
                        lda('l');
                        pra();
                        lda('o');
                        pra();
                        lda('\n');
                        pra();

                Hello World - Memory IO & debugger & Using register X
                        lda('H');
                        sta(($(0x200 +X)));
                        inx();

                        lda('e');
                        sta(($(0x200 +X)));
                        inx();

                        lda('l');
                        sta(($(0x200 +X)));
                        inx();

                        lda('l');
                        sta(($(0x200 +X)));
                        inx();

                        lda('o');
                        sta(($(0x200 +X)));
                        inx();

                        lda('\n');
                        sta($(0x200 + X));
                        debug_mem(0x200, 7);
	 */

                        lda('H');
                        sta(($(0x200 +X)));
                        inx();

                        lda('e');
                        sta(($(0x200 +X)));
                        inx();

                        lda('l');
                        sta(($(0x200 +X)));
                        inx();

                        lda('l');
                        sta(($(0x200 +X)));
                        inx();

                        lda('o');
                        sta(($(0x200 +X)));
                        inx();

                        lda('\n');
                        sta($(0x200 + X));
                        debug_mem(0x200, 7);

			return 0;
}

int main() {
	setup();

	return user_code();
}
