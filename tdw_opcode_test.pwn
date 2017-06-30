#include <a_samp>
#include "exp\tdw_opcode\tdw_opcode"


main()
{
	new
		cod = GetAmxData(TDW_g_sAmxHeader[AMXHDR_COD]),
		dat = GetAmxData(TDW_g_sAmxHeader[AMXHDR_DAT]),
		address = cod - dat;
	printf("Start address: %d", address);
	FindOpcode(address, OP_PROC);
	printf("End address: %d (%d)", address, ReadMemory(address));
}
