#include "main.h"
#include "declar.h"


extern INSTRUCTION g_inst;


void pr()
{
	wprintf(TEXT("opcode = %d\n"), g_inst.opcode);
	wprintf(TEXT("isI = %d, i = %I64d\n"), g_inst.isI, g_inst.i);
	wprintf(TEXT("isN = %d, n = %ls\n"), g_inst.isN, g_inst.n);
	wprintf(TEXT("isCI = %d, ci = %I64d\n"), g_inst.isCI, g_inst.ci);
	wprintf(TEXT("isCN = %d, cn = %ls\n"), g_inst.isCN, g_inst.cn);
	wprintf(TEXT("isFault = %d\n"), g_inst.isFault);
}

void help(TCHAR* input)
{
	wprintf(TEXT("Permitted command: help   view   views   insert   delete   rewrite   quit\n\n"));
	wprintf(TEXT("\thelp\n\t\tget help info\n"));
	wprintf(TEXT("\tview\n\t\tview all student information\n"));
	wprintf(TEXT("\tviews [-i id](optional) [-n name](optional)\n\t\tuse id or name to check specific entries\n"));
	wprintf(TEXT("\tinsert [-i id](must) [-n name](must)\n\t\tinsert an entry with id and name\n"));
	wprintf(TEXT("\tdelete [-i id](optional) [-n name](optional)\n\t\tdelete an entry with id or name\n"));
	wprintf(TEXT("\trewrite [-i id](optional) [-n name(optional)] [-ci another id](optional) [-cn another name](optional)\n\t\tchange information sprcified by id or name, use -ci and  -cn to specify another id and name\n"));
	wprintf(TEXT("\tquit\n\t\tquit the program\n"));
	wprintf(TEXT("All optional paraments must be specified as NULL, or there will be an error.\n"));
}

void view(TCHAR* input)
{
	g_inst.opcode = _VIEW;
	ParaAnaly();
	pr();
}

void views(TCHAR* input)
{
	g_inst.opcode = _VIEWS;
	
	ParaAnaly();
	pr();
}

void insert(TCHAR* input)
{
	
	g_inst.opcode = _INSERT;
	ParaAnaly();
	pr();
}

void delete(TCHAR* input)
{

	g_inst.opcode = _DELETE;
	ParaAnaly();
	pr();
}

void rewrite(TCHAR* input)
{
	g_inst.opcode = _REWRITE;
	ParaAnaly();
	pr();
}