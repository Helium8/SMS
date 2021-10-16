#include "main.h"
#include "declar.h"

#define CmpStr(A, strA) {			\
	if (!wcscmp(input, strA))		\
	{								\
		return A;					\
	}								\
}									\

			



extern INSTRUCTION g_inst;

OPCODE GetOpcode(TCHAR* input)
{
	CmpStr(_HELP, TEXT("help"));
	CmpStr(_VIEW, TEXT("view"));
	CmpStr(_VIEWS, TEXT("views"));
	CmpStr(_INSERT, TEXT("insert"));
	CmpStr(_DELETE, TEXT("delete"));
	CmpStr(_REWRITE, TEXT("rewrite"));
	CmpStr(_QUIT, TEXT("quit"));
	return _UNKNOWN;
}

void ParaAnaly()
{
	g_inst.isFault = FALSE;

	TCHAR opc[512];
	TCHAR* N = (TCHAR*)malloc(1024 * sizeof(TCHAR));
	TCHAR*  I = (TCHAR*)malloc(1024 * sizeof(TCHAR));



	switch (g_inst.opcode)
	{
	case _VIEWS:
	{
		for (int i = 0; i < 2; i++)
		{
			wscanf(L"%ls", opc);

			if (wcscmp(opc, L"-i") == 0)
			{
				wscanf(L"%ls", I);
				g_inst.isI = TRUE;
				g_inst.i = atoll(I);
			}
			else if (wcscmp(opc, L"-n") == 0)
			{
				wscanf(L"%ls", N);
				if (wcscmp(N, L"NULL") == 0)
				{
					g_inst.isN = FALSE;
					goto l1;
				}

				g_inst.isN = TRUE;
				g_inst.n = N;
			l1:
				;
			}
			else
			{
				g_inst.isFault = TRUE;
			}
		}
	}
	break;
	case _INSERT:
	{
		for (int i = 0; i < 2; i++)
		{
			wscanf(L"%ls", opc);

			if (wcscmp(opc, L"-i") == 0)
			{
				wscanf(L"%ls", I);
				g_inst.isI = TRUE;
				g_inst.i = atoll(I);
			}
			else if (wcscmp(opc, L"-n") == 0)
			{
				wscanf(L"%ls", N);
				g_inst.isN = TRUE;
				g_inst.n = N;
			}
			else
			{
				g_inst.isFault = TRUE;
			}
		}
	}
		break;
	case _DELETE:
	{
		for (int i = 0; i < 2; i++)
		{
			wscanf(L"%ls", opc);

			if (wcscmp(opc, L"-i") == 0)
			{
				wscanf(L"%ls", I);
				if (wcscmp(I, L"NULL") == 0)
				{
					g_inst.isI = FALSE;
					goto l3;
				}

				g_inst.isI = TRUE;
				g_inst.i = atoll(I);
			l3:
				;
			}
			else if (wcscmp(opc, L"-n") == 0)
			{
				wscanf(L"%ls", N);
				if (wcscmp(N, L"NULL") == 0)
				{
					g_inst.isN = FALSE;
					goto l2;
				}

				g_inst.isN = TRUE;
				g_inst.n = N;
			l2:
				;
			}
			else
			{
				g_inst.isFault = TRUE;
			}
		}
	}
		break;
	case _REWRITE:
	{
		for (int i = 0; i < 4; i++)
		{
			wscanf(L"%ls", opc);

			if (wcscmp(opc, L"-i") == 0)
			{
				wscanf(L"%ls", I);
				if (wcscmp(I, L"NULL") == 0)
				{
					g_inst.isI = FALSE;
					goto l4;
				}

				g_inst.isI = TRUE;
				g_inst.i = atoll(I);
			l4:
				;
			}
			else if (wcscmp(opc, L"-n") == 0)
			{
				wscanf(L"%ls", N);
				if (wcscmp(N, L"NULL") == 0)
				{
					g_inst.isN = FALSE;
					goto l5;
				}

				g_inst.isN = TRUE;
				g_inst.n = N;
			l5:
				;
			}
			else if (wcscmp(opc, L"-ci") == 0)
			{
				wscanf(L"%ls", I);
				if (wcscmp(I, L"NULL") == 0)
				{
					g_inst.isI = FALSE;
					goto l6;
				}

				g_inst.isCI = TRUE;
				g_inst.ci = atoll(I);
			l6:
				;
			}
			else if (wcscmp(opc, L"-cn") == 0)
			{
				wscanf(L"%ls", N);
				if (wcscmp(N, L"NULL") == 0)
				{
					g_inst.isN = FALSE;
					goto l7;
				}

				g_inst.isCN = TRUE;
				g_inst.cn = N;
			l7:
				;
			}
			else
			{
				g_inst.isFault = TRUE;
			}
		}
	}
		break;
	default:
		InitInst(&g_inst);
		break;
	}
}