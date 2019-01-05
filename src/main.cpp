#include "../include/instruction.h"
#include "../include/debug.h"

#define wr_buff 0x0f00

using namespace myvm;
using namespace myvm::instruction;

int main(){
	setup();
	ldx(0);

	lda('H');
	sta(wr_buff+X);
	inx();

	lda('I');
	sta(wr_buff+X);
	inx();

	lda('!');
	sta(wr_buff+X);
	inx();

	lda('\n');
	sta(wr_buff+X);

	myvm::debug::debug_mem(wr_buff, X);
}

