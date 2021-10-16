#pragma once
#include "include.h"


#pragma warning(disable:4996)


typedef enum OPCODE
{
	_HELP,			//������Ϣ
	_VIEW,			//�鿴ȫ��
	_VIEWS,			//�鿴�ض�id����Ӧ��Ŀ
	_INSERT,		//����
	_DELETE,		//ɾ��
	_REWRITE,		//�޸�
	_QUIT,			//�˳�
	_UNKNOWN		//δ֪����
}OPCODE;


typedef struct STUINFO
{
	TCHAR* name;	//����
	__int64 id;		//id
	void* OtherInfo;//��׷�ӵ�������Ϣ
}STUINFO;

typedef struct INSTRUCTION
{
	OPCODE opcode;
	
	BOOL isI;
	INT64 i;

	BOOL isN;
	TCHAR* n;

	BOOL isCI;
	INT64 ci;

	BOOL isCN;
	TCHAR* cn;

	BOOL isFault;
}INSTRUCTION;

//if Prev equs NULL, that means this unit is the start of the chain
//if Next equs NULL, that means this unit is the end of the chain
typedef struct CHAINUNIT
{
	STUINFO* Prev;
	STUINFO* Info;
	STUINFO* Next;
}CHAINUNIT;