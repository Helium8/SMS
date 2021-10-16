#include "include.h"
#include "main.h"

int Initialize()
{
	FILE* file[4];
	if (!(file[0] = fopen(".\\sms\\created", "r")))	//程序文件夹未创建
	{
		system("mkdir sms");
		system("mkdir sms\\users");
		system("mkdir sms\\users\\default");
		file[1] = fopen(".\\sms\\created", "w");	//标志文件夹已创建
		file[2] = fopen(".\\sms\\conf.ini", "w");	//配置文件
		file[3] = fopen(".\\sms\\users\\default\\sms.json", "w");	//信息文件
		fclose(file[1]);
		fclose(file[2]);
		fclose(file[3]);
		return 0;
	}
	fclose(file[0]);
	return 0;
}

void InitInst(INSTRUCTION* Inst)
{
	Inst->opcode = _UNKNOWN;

	Inst->isI = FALSE;
	Inst->i = -1;

	Inst->isN = FALSE;
	Inst->n = NULL;

	Inst->isCI = FALSE;
	Inst->ci = -1;

	Inst->isCN = FALSE;
	Inst->cn = NULL;

	Inst->isFault = TRUE;
}