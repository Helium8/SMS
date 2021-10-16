
#include "main.h"
#include "declar.h"


extern INSTRUCTION g_inst;


int main()
{
	_wsetlocale(LC_ALL, L"chs");
	TCHAR* input = (TCHAR*)malloc(1024 * sizeof(TCHAR));
	OPCODE opcode = _UNKNOWN;
	
	Initialize();
	InitInst(&g_inst);

loop:
	wprintf(L"sms>");
	wscanf(L"%ls", input);
	opcode = GetOpcode(input);
	switch (opcode)
	{
	case _HELP:
		help(input);
		break;
	case _VIEW:
		view(input);
		break;
	case _VIEWS:
		views(input);
		break;
	case _INSERT:
		insert(input);
		break;
	case _DELETE:
		delete(input);
		break;
	case _REWRITE:
		rewrite(input);
		break;
	case _QUIT:
		goto end;
		break;
	case _UNKNOWN:
		wprintf(TEXT("Unknown Command\n"));
		break;
	default:
		printf("Unknow error,program exit\n");
		goto end;
		break;
	}
	goto loop;


	end:
	return 0;
}