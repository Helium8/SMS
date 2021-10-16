#pragma once
#include "include.h"


#pragma warning(disable:4996)


typedef enum OPCODE
{
	_HELP,			//帮助信息
	_VIEW,			//查看全部
	_VIEWS,			//查看特定id所对应条目
	_INSERT,		//插入
	_DELETE,		//删除
	_REWRITE,		//修改
	_QUIT,			//退出
	_UNKNOWN		//未知命令
}OPCODE;


typedef struct STUINFO
{
	TCHAR* name;	//姓名
	__int64 id;		//id
	void* OtherInfo;//可追加的其他信息
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