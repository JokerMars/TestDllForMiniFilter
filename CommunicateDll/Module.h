#pragma once

#ifndef _MODULE_H
#define _MODULE_H

#include "stdafx.h"

#define SERVER_PORT_NAME		L"\\FileEncryptPort"
#define SERVER_MAX_COUNT		1

//
// Message code
//

#define CODE_OPEN_SYSTEM		0X0001
#define CODE_CLOSE_SYSTEM		0X0002
#define CODE_SEND_STRATEGY		0X0003

#define CODE_SEND_KEY			0X0004
#define CODE_IS_RUNNING			0X0005
#define CODE_SUCCESS			0X0006

#define CODE_UNSUCCESS			0X0007
#define CODE_UNKNOW_CODE		0X0008
#define CODE_RUNNING			0X0009

#define CODE_CLOSED				0X000A

typedef struct _MESSAGE_DATA
{
	INT32 code;
	INT32 bufferLen;
	CHAR buffOffset[1];
}MESSAGE_DATA, *PMESSAGE_DATA;


typedef struct _MESSAGE_BACK
{
	INT32 code;
}MESSAGE_BACK, *PMESSAGE_BACK;

HANDLE hPort;


extern "C" __declspec(dllexport)
bool ConnectPort(_In_ LPCWSTR lpPortName);

extern "C" __declspec(dllexport)
void ClosePort();

extern "C" __declspec(dllexport)
bool OpenSystem();

extern "C" __declspec(dllexport)
bool CloseSystem();

extern "C" __declspec(dllexport)
bool IsSystemRunning();

extern "C" __declspec(dllexport)
bool SendKey(PCHAR key);

extern "C" __declspec(dllexport)
bool SendStrategy(PCHAR strategy);



#endif
