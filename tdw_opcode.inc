/** ======================================================================== **\
	Opcode

| Description:

| Version:
	1.0.0

| Dependencies:
	- n\a

| Compatible with the JIT plugin:
	- Yes

| License:
	Copyright (c) 2017 Double V

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgement in the product documentation would be
		appreciated but is not required.
	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source distribution.
\** ======================================================================== **/

#if defined _inc_tdw_opcode
	#undef _inc_tdw_opcode
#endif

#if defined _TDW_OPCODE
	#endinput
#endif

#define _TDW_OPCODE

// ----------------------------------------------------------------------------
// Opcode information

enum {
	OP_NONE,        OP_LOAD_PRI,   OP_LOAD_ALT,   OP_LOAD_S_PRI, OP_LOAD_S_ALT,
	OP_LREF_PRI,    OP_LREF_ALT,   OP_LREF_S_PRI, OP_LREF_S_ALT, OP_LOAD_I,
	OP_LODB_I,      OP_CONST_PRI,  OP_CONST_ALT,  OP_ADDR_PRI,   OP_ADDR_ALT,
	OP_STOR_PRI,    OP_STOR_ALT,   OP_STOR_S_PRI, OP_STOR_S_ALT, OP_SREF_PRI,
	OP_SREF_ALT,    OP_SREF_S_PRI, OP_SREF_S_ALT, OP_STOR_I,     OP_STRB_I,
	OP_LIDX,        OP_LIDX_B,     OP_IDXADDR,    OP_IDXADDR_B,  OP_ALIGN_PRI,
	OP_ALIGN_ALT,   OP_LCTRL,      OP_SCTRL,      OP_MOVE_PRI,   OP_MOVE_ALT,
	OP_XCHG,        OP_PUSH_PRI,   OP_PUSH_ALT,   OP_PUSH_R,     OP_PUSH_C,
	OP_PUSH,        OP_PUSH_S,     OP_POP_PRI,    OP_POP_ALT,    OP_STACK,
	OP_HEAP,        OP_PROC,       OP_RET,        OP_RETN,       OP_CALL,
	OP_CALL_PRI,    OP_JUMP,       OP_JREL,       OP_JZER,       OP_JNZ,
	OP_JEQ,         OP_JNEQ,       OP_JLESS,      OP_JLEQ,       OP_JGRTR,
	OP_JGEQ,        OP_JSLESS,     OP_JSLEQ,      OP_JSGRTR,     OP_JSGEQ,
	OP_SHL,         OP_SHR,        OP_SSHR,       OP_SHL_C_PRI,  OP_SHL_C_ALT,
	OP_SHR_C_PRI,   OP_SHR_C_ALT,  OP_SMUL,       OP_SDIV,       OP_SDIV_ALT,
	OP_UMUL,        OP_UDIV,       OP_UDIV_ALT,   OP_ADD,        OP_SUB,
	OP_SUB_ALT,     OP_AND,        OP_OR,         OP_XOR,        OP_NOT,
	OP_NEG,         OP_INVERT,     OP_ADD_C,      OP_SMUL_C,     OP_ZERO_PRI,
	OP_ZERO_ALT,    OP_ZERO,       OP_ZERO_S,     OP_SIGN_PRI,   OP_SIGN_ALT,
	OP_EQ,          OP_NEQ,        OP_LESS,       OP_LEQ,        OP_GRTR,
	OP_GEQ,         OP_SLESS,      OP_SLEQ,       OP_SGRTR,      OP_SGEQ,
	OP_EQ_C_PRI,    OP_EQ_C_ALT,   OP_INC_PRI,    OP_INC_ALT,    OP_INC,
	OP_INC_S,       OP_INC_I,      OP_DEC_PRI,    OP_DEC_ALT,    OP_DEC,
	OP_DEC_S,       OP_DEC_I,      OP_MOVS,       OP_CMPS,       OP_FILL,
	OP_HALT,        OP_BOUNDS,     OP_SYSREQ_PRI, OP_SYSREQ_C,   OP_FILE,
	OP_LINE,        OP_SYMBOL,     OP_SRANGE,     OP_JUMP_PRI,   OP_SWITCH,
	OP_CASETBL,     OP_SWAP_PRI,   OP_SWAP_ALT,   OP_PUSH_ADR,   OP_NOP,
	OP_SYSREQ_N,    OP_SYMTAG,     OP_BREAK,      OP_PUSH2_C,    OP_PUSH2,
	OP_PUSH2_S,     OP_PUSH2_ADR,  OP_PUSH3_C,    OP_PUSH3,      OP_PUSH3_S,
	OP_PUSH3_ADR,   OP_PUSH4_C,    OP_PUSH4,      OP_PUSH4_S,    OP_PUSH4_ADR,
	OP_PUSH5_C,     OP_PUSH5,      OP_PUSH5_S,    OP_PUSH5_ADR,  OP_LOAD_BOTH,
	OP_LOAD_S_BOTH, OP_CONST,      OP_CONST_S,
	// -------------------------
	OP_SYSREQ_D,   OP_SYSREQ_ND,
	// -------------------------
	OP_NUM_OPCODES
};

const TDW_NUM_OPCODES_IN_ARRAY = OP_NUM_OPCODES - 2;

static stock const TDW_g_sOpcodeName[TDW_NUM_OPCODES_IN_ARRAY][] = {
	// 0           1             2             3             4
	"none",        "load.pri",   "load.alt",   "load.s.pri", "load.s.alt",
	// 5           6             7             8             9
	"lref.pri",    "lref.alt",   "lref.s.pri", "lref.s.alt", "load.i",
	// 10          11            12            13            14
	"lodb.i",      "const.pri",  "const.alt",  "addr.pri",   "addr.alt",
	// 15          16            17            18            19
	"stor.pri",    "stor.alt",   "stor.s.pri", "stor.s.alt", "sref.pri",
	// 20          21            22            23            24
	"sref.alt",    "sref.s.pri", "sref.s.alt", "stor.i",     "strb.i",
	// 25          26            27            28            29
	"lidx",        "lidx.b",     "idxaddr",    "idxaddr.b",  "align.pri",
	// 30          31            32            33            34
	"align.alt",   "lctrl",      "sctrl",      "move.pri",   "move.alt",
	// 35          36            37            38            39
	"xchg",        "push.pri",   "push.alt",   "push.r",     "push.c",
	// 40          41            42            43            44
	"push",        "push.s",     "pop.pri",    "pop.alt",    "stack",
	// 45          46            47            48            49
	"heap",        "proc",       "ret",        "retn",       "call",
	// 50          51            52            53            54
	"call.pri",    "jump",       "jrel",       "jzer",       "jnz",
	// 55          56            57            58            59
	"jeq",         "jneq",       "jless",      "jleq",       "jgrtr",
	// 60          61            62            63            64
	"jgeq",        "jsless",     "jsleq",      "jsgrtr",     "jsgeq",
	// 65          66            67            68            69
	"shl",         "shr",        "sshr",       "shl.c.pri",  "shl.c.alt",
	// 70          71            72            73            74
	"shr.c.pri",   "shr.c.alt",  "smul",       "sdiv",       "sdiv.alt",
	// 75          76            77            78            79
	"umul",        "udiv",       "udiv.alt",   "add",        "sub",
	// 80          81            82            83            84
	"sub.alt",     "and",        "or",         "xor",        "not",
	// 85          86            87            88            89
	"neg",         "invert",     "add.c",      "smul.c",     "zero.pri",
	// 90          91            92            93            94
	"zero.alt",    "zero",       "zero.s",     "sign.pri",   "sign.alt",
	// 95          96            97            98            99
	"eq",          "neq",        "less",       "leq",        "grtr",
	// 100         101           102           103           104
	"geq",         "sless",      "sleq",       "sgrtr",      "sgeq",
	// 105         106           107           108           109
	"eq.c.pri",    "eq.c.alt",   "inc.pri",    "inc.alt",    "inc",
	// 110         111           112           113           114
	"inc.s",       "inc.i",      "dec.pri",    "dec.alt",    "dec",
	// 115         116           117           118           119
	"dec.s",       "dec.i",      "movs",       "cmps",       "fill",
	// 120         121           122           123           124
	"halt",        "bounds",     "sysreq.pri", "sysreq.c",   "file",
	// 125         126           127           128           129
	"line",        "symbol",     "srange",     "jump.pri",   "switch",
	// 130         131           132           133           134
	"casetbl",     "swap.pri",   "swap.alt",   "push.adr",   "nop",
	// 135         136           137           138           139
	"sysreq.n",    "symtag",     "break",      "push2.c",    "push2",
	// 140         141           142           143           144
	"push2.s",     "push2.adr",  "push3.c",    "push3",      "push3.s",
	// 145         146           147           148           149
	"push3.adr",   "push4.c",    "push4",      "push4.s",    "push4.adr",
	// 150         151           152           153           154
	"push5.c",     "push5",      "push5.s",    "push5.adr",  "load.both",
	// 155         156           157
	"load.s.both", "const",      "const.s"
};

static stock const TDW_g_sOpcodeOperands[TDW_NUM_OPCODES_IN_ARRAY] = {
	// 0-22
	0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	// 23-45
	0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
	// 46-68
	0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1,
	// 69-91
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1,
	// 92-114
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1,
	// 115-137
	1, 0, 1, 1, 1, 1, 1, 0, 1, 3, 2, 2, 2, 0, 1, 0, 0, 0, 1, 0, 2, 1, 0,
	// 138-157
	2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 2, 2, 2, 2
};

// ----------------------------------------------------------------------------
// AMX Header and memory reading/writing

#define TDW_g_sAmxHeader __TDW_g_sAmxHeader[0]
#define InitAmxHeader if (!__TDW_g_sAmxHeaderInitialized) __InitAmxHeader

#if defined TDW_SECURE
	#define TDW_STATIC static
#else
	#define TDW_STATIC
#endif

enum {
	AMXHDR_SIZE,
	AMXHDR_INFO_1,  // magic (2 bytes) file_version (1 byte) amx_version (1 byte)
	AMXHDR_INFO_2,  // flags (2 bytes) defsize (2 bytes)
	AMXHDR_COD,
	AMXHDR_DAT,
	AMXHDR_HEA,
	AMXHDR_STP,
	AMXHDR_CIP,
	AMXHDR_PUBLICS,
	AMXHDR_NATIVES,
	AMXHDR_LIBRARIES,
	AMXHDR_PUBVARS,
	AMXHDR_TAGS,
	AMXHDR_NAMETABLE
};

static stock
	bool:__TDW_g_sAmxHeaderInitialized = false;

TDW_STATIC stock
	__TDW_g_sAmxHeader[][] = { {} };

TDW_STATIC stock GetAmxData(&address) return address;

TDW_STATIC stock __InitAmxHeader()
{
	#emit const.alt __TDW_g_sAmxHeader
	#emit lctrl 1
	#emit neg
	#emit sub
	#emit stor.i

	__TDW_g_sAmxHeaderInitialized = true;
}

TDW_STATIC stock ReadMemory(address)
{
	#emit lref.s.pri address
	#emit retn
	return 0;
}

// OnGameModeInit
#if defined _TDWOPCODE@OnGameModeInit
	forward _TDWOPCODE@OnGameModeInit();
#endif
public OnGameModeInit()
{
	InitAmxHeader();
#if defined _TDWOPCODE@OnGameModeInit
	_TDWOPCODE@OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit _TDWOPCODE@OnGameModeInit

// ----------------------------------------------------------------------------
// Relocate/Unrelocate opcodes

#define InitOpcodeTable if (!TDW_g_sOpcodeTableInitialized) __InitOpcodeTable

static stock
	TDW_g_sOpcodeTable[OP_NUM_OPCODES],
	bool:TDW_g_sOpcodeTableInitialized = false;

static stock __InitOpcodeTable()
{
	for (new i = 0; i < OP_NUM_OPCODES; ++i) {
		TDW_g_sOpcodeTable[i] = __RelocateOpcode(i);
	}
	TDW_g_sOpcodeTableInitialized = true;
}

@_TDW_OPCODE_FIX_@();
@_TDW_OPCODE_FIX_@()
{
	#emit retn
	numargs();
}

static stock __dummy() {}
static stock __RelocateOpcode(opcode)
{
	new opcode_addr;
	switch (opcode) {
		case OP_LOAD_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit load.pri 0
		}
		case OP_LOAD_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit load.alt 0
		}
		case OP_LOAD_S_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit load.s.pri 0
		}
		case OP_LOAD_S_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit load.s.alt 0
		}
		case OP_LREF_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit lref.pri 0
		}
		case OP_LREF_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit lref.alt 0
		}
		case OP_LREF_S_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit lref.s.pri 0
		}
		case OP_LREF_S_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit lref.s.alt 0
		}
		case OP_LOAD_I: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit load.i
		}
		case OP_LODB_I: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit lodb.i 1  // we can use values in range (1,2,4)
		}
		case OP_CONST_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit const.pri 0
		}
		case OP_CONST_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit const.alt 0
		}
		case OP_ADDR_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit addr.pri 0
		}
		case OP_ADDR_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit addr.alt 0
		}
		case OP_STOR_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit stor.pri 0
		}
		case OP_STOR_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit stor.alt 0
		}
		case OP_STOR_S_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit stor.s.pri 0
		}
		case OP_STOR_S_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit stor.s.alt 0
		}
		case OP_SREF_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sref.pri 0
		}
		case OP_SREF_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sref.alt 0
		}
		case OP_SREF_S_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sref.s.pri 0
		}
		case OP_SREF_S_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sref.s.alt 0
		}
		case OP_STOR_I: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit stor.i
		}
		case OP_STRB_I: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit strb.i 1  // we can use values in range (1,2,4)
		}
		case OP_LIDX: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit lidx
		}
		case OP_LIDX_B: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit lidx.b 0
		}
		case OP_IDXADDR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit idxaddr
		}
		case OP_IDXADDR_B: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit idxaddr.b 0
		}
		case OP_ALIGN_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit align.pri 0
		}
		case OP_ALIGN_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit align.alt 0
		}
		case OP_LCTRL: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit lctrl 0
		}
		case OP_SCTRL: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sctrl 1
		}
		case OP_MOVE_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit move.pri
		}
		case OP_MOVE_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit move.alt
		}
		case OP_XCHG: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit xchg
		}
		case OP_PUSH_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit push.pri
		}
		case OP_PUSH_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit push.alt
		}
		// case OP_PUSH_R: {}
		case OP_PUSH_C: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit push.c 0
		}
		case OP_PUSH: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit push 0
		}
		case OP_PUSH_S: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit push.s 0
		}
		case OP_POP_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit pop.pri
		}
		case OP_POP_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit pop.alt
		}
		case OP_STACK: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit stack 0
		}
		case OP_HEAP: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit heap 0
		}
		case OP_PROC: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit proc
		}
		case OP_RET: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit ret
		}
		case OP_RETN: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit retn
		}
		case OP_CALL: {
			#emit lctrl 6
			#if debug >= 1
			#emit add.c 36  // 24 + 8 (push 0) + 4 (break)
			#else
			#emit add.c 32  // 24 + 8 (push 0)
			#endif
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			__dummy();
		}
		// case OP_CALL_PRI: {}
		case OP_JUMP: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jump 0
		}
		// case OP_JREL: {}
		case OP_JZER: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jzer 0
		}
		case OP_JNZ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jnz 0
		}
		case OP_JEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jeq 0
		}
		case OP_JNEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jneq 0
		}
		case OP_JLESS: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jless 0
		}
		case OP_JLEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jleq 0
		}
		case OP_JGRTR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jgrtr 0
		}
		case OP_JGEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jgeq 0
		}
		case OP_JSLESS: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jsless 0
		}
		case OP_JSLEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jsleq 0
		}
		case OP_JSGRTR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jsgrtr 0
		}
		case OP_JSGEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jsgeq 0
		}
		case OP_SHL: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit shl
		}
		case OP_SHR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit shr
		}
		case OP_SSHR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sshr
		}
		case OP_SHL_C_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit shl.c.pri 0
		}
		case OP_SHL_C_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit shl.c.alt 0
		}
		case OP_SHR_C_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit shr.c.pri 0
		}
		case OP_SHR_C_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit shr.c.alt 0
		}
		case OP_SMUL: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit smul
		}
		case OP_SDIV: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sdiv
		}
		case OP_SDIV_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sdiv.alt
		}
		case OP_UMUL: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit umul
		}
		case OP_UDIV: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit udiv
		}
		case OP_UDIV_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit udiv.alt
		}
		case OP_ADD: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit add
		}
		case OP_SUB: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sub
		}
		case OP_SUB_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sub.alt
		}
		case OP_AND: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit and
		}
		case OP_OR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit or
		}
		case OP_XOR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit xor
		}
		case OP_NOT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit not
		}
		case OP_NEG: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit neg
		}
		case OP_INVERT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit invert
		}
		case OP_ADD_C: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit add.c 0
		}
		case OP_SMUL_C: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit smul.c 0
		}
		case OP_ZERO_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit zero.pri
		}
		case OP_ZERO_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit zero.alt
		}
		case OP_ZERO: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit zero 0
		}
		case OP_ZERO_S: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit zero.s 0
		}
		case OP_SIGN_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sign.pri
		}
		case OP_SIGN_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sign.alt
		}
		case OP_EQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit eq
		}
		case OP_NEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit neq
		}
		case OP_LESS: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit less
		}
		case OP_LEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit leq
		}
		case OP_GRTR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit grtr
		}
		case OP_GEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit geq
		}
		case OP_SLESS: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sless
		}
		case OP_SLEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sleq
		}
		case OP_SGRTR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sgrtr
		}
		case OP_SGEQ: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sgeq
		}
		case OP_EQ_C_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit eq.c.pri 0
		}
		case OP_EQ_C_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit eq.c.alt 0
		}
		case OP_INC_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit inc.pri
		}
		case OP_INC_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit inc.alt
		}
		case OP_INC: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit inc 0
		}
		case OP_INC_S: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit inc.s 0
		}
		case OP_INC_I: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit inc.i
		}
		case OP_DEC_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit dec.pri
		}
		case OP_DEC_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit dec.alt
		}
		case OP_DEC: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit dec 0
		}
		case OP_DEC_S: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit dec.s 0
		}
		case OP_DEC_I: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit dec.i
		}
		case OP_MOVS: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit movs 0
		}
		case OP_CMPS: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit cmps 0
		}
		case OP_FILL: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit fill 0
		}
		case OP_HALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit halt 0
		}
		case OP_BOUNDS: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit bounds 0
		}
		case OP_SYSREQ_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sysreq.pri
		}
		case OP_SYSREQ_C: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit sysreq.c numargs
		}
		// case OP_FILE: {}
		// case OP_LINE: {}
		// case OP_SYMBOL: {}
		// case OP_SRANGE: {}
		case OP_JUMP_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit jump.pri
		}
		case OP_SWITCH: {
			#emit lctrl 6
			#if debug >= 1
			#emit add.c 32  // 24 + 4 (zero.pri) + 4 (break)
			#else
			#emit add.c 28  // 24 + 4 (zero.pri)
			#endif
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			switch (0) {
				case 0: {}
			}
		}
		case OP_CASETBL: {
			new x = 0;
			switch (x) {
				case 0: {
					#emit lctrl 6
					#emit add.c 32
					#emit stor.s.pri opcode_addr
					goto l_get_opcode;
				}
			}
		}
		case OP_SWAP_PRI: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit swap.pri
		}
		case OP_SWAP_ALT: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit swap.alt
		}
		case OP_PUSH_ADR: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit push.adr 0
		}
		case OP_NOP: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit nop
		}
		// case OP_SYSREQ_N: {}
		// case OP_SYMTAG: {}
		case OP_BREAK: {
			#emit lctrl 6
			#emit add.c 24
			#emit stor.s.pri opcode_addr
			goto l_get_opcode;
			#emit break
		}
		// case OP_PUSH2_C: {}
		// case OP_PUSH2: {}
		// case OP_PUSH2_S: {}
		// case OP_PUSH2_ADR: {}
		// case OP_PUSH3_C: {}
		// case OP_PUSH3: {}
		// case OP_PUSH3_S: {}
		// case OP_PUSH3_ADR: {}
		// case OP_PUSH4_C: {}
		// case OP_PUSH4: {}
		// case OP_PUSH4_S: {}
		// case OP_PUSH4_ADR: {}
		// case OP_PUSH5_C: {}
		// case OP_PUSH5: {}
		// case OP_PUSH5_S: {}
		// case OP_PUSH5_ADR: {}
		// case OP_LOAD_BOTH: {}
		// case OP_LOAD_S_BOTH: {}
		// case OP_CONST: {}
		// case OP_CONST_S: {}
		default: {
			return opcode;
		}
	}
l_get_opcode:
	#if debug >= 1
		opcode_addr += 4;  // for BREAK instruction
	#endif
	opcode_addr += GetAmxData(TDW_g_sAmxHeader[AMXHDR_COD]) - GetAmxData(TDW_g_sAmxHeader[AMXHDR_DAT]);
	return ReadMemory(opcode_addr);
}

stock RelocateOpcode(opcode)
{
	InitOpcodeTable();
	return TDW_g_sOpcodeTable[opcode];
}

stock UnrelocateOpcode(opcode)
{
	InitOpcodeTable();
	if (OP_NONE <= opcode < OP_NUM_OPCODES)
		return opcode;
	for (new i = 0; i < OP_NUM_OPCODES; ++i) {
		if (TDW_g_sOpcodeTable[i] == opcode)
			return i;
	}
	return opcode;
}

// ----------------------------------------------------------------------------
// Opcode functions

stock ReadOpcode(address)
{
	new opcode = ReadMemory(address);
	opcode = UnrelocateOpcode(opcode);
	if (_:(OP_NONE <= opcode < OP_NUM_OPCODES) == 0)
		return 0;
	return opcode;
}

stock ReadOperand(address, offset = 0, end_address = 0)
{
	if (TDW_g_sOpcodeOperands[ReadOpcode(address)] <= 0)
		return 0;
	if ((address += 4 + offset * (cellbits / charbits)) >= end_address)
		return 0;
	return ReadMemory(address);
}

stock FindNextOpcode(&next_address, &opcode, start_address = 0, end_address = 0)
{
	new
		current_opcode;
	next_address = start_address;
	current_opcode = ReadOpcode(next_address);
	next_address += 4;
	if (next_address >= end_address) {
		next_address = start_address;
		return 0;
	}
	if (current_opcode == OP_CASETBL) {
		next_address += 8 + 8 * ReadMemory(next_address);
	} else {
		next_address += 4 * TDW_g_sOpcodeOperands[current_opcode];
	}
	if (next_address >= end_address) {
		next_address = start_address;
		return 0;
	}
	opcode = ReadOpcode(next_address);
	return 1;
}

stock FindOpcode(&address, opcode, end = 0)
{
	new
		start_address = address,
		current_opcode;
	while (FindNextOpcode(address, current_opcode, address, end)) {
		if (current_opcode == opcode) {
			return 1;
		}
	}
	address = start_address;
	return 0;
}
