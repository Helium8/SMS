#include "include.h"
#include "main.h"

int Initialize()
{
	FILE* file[4];
	if (!(file[0] = fopen(".\\sms\\created", "r")))	//�����ļ���δ����
	{
		system("mkdir sms");
		system("mkdir sms\\users");
		system("mkdir sms\\users\\default");
		file[1] = fopen(".\\sms\\created", "w");	//��־�ļ����Ѵ���
		file[2] = fopen(".\\sms\\conf.ini", "w");	//�����ļ�
		file[3] = fopen(".\\sms\\users\\default\\sms.json", "w");	//��Ϣ�ļ�
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