// CommunicateDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Module.h"
#include <corecrt_malloc.h>


bool ConnectPort(_In_ LPCWSTR lpPortName)
{
	DWORD hResult = FilterConnectCommunicationPort(
		lpPortName,
		0,
		NULL,
		0,
		NULL,
		&hPort
	);

	if (hResult != S_OK)
	{
		printf("connet failed\n");
		return false;
	}
	printf("connect success\n");
	return true;
}

void ClosePort()
{
	CloseHandle(hPort);
}





bool OpenSystem()
{
	MESSAGE_DATA msg;
	msg.code = CODE_OPEN_SYSTEM;

	MESSAGE_BACK back;

	DWORD bytesReturned = 0;
	DWORD hResult = 0;

	hResult = FilterSendMessage(hPort, &msg, sizeof(MESSAGE_DATA),
		&back, sizeof(MESSAGE_BACK), &bytesReturned);

	if (bytesReturned < sizeof(MESSAGE_BACK))
	{
		return false;
	}

	if (back.code == CODE_SUCCESS)
	{
		return true;
	}

	return false;
}




bool CloseSystem()
{
	MESSAGE_DATA msg;
	msg.code = CODE_CLOSE_SYSTEM;

	MESSAGE_BACK back;
	DWORD bytesReturned = 0;
	DWORD hResult = 0;

	hResult = FilterSendMessage(
		hPort,
		&msg,
		sizeof(MESSAGE_DATA),
		&back,
		sizeof(MESSAGE_BACK),
		&bytesReturned
	);

	if (bytesReturned < sizeof(MESSAGE_BACK))
	{
		return false;
	}

	if (back.code == CODE_SUCCESS)
	{
		return true;
	}

	return false;

}




bool IsSystemRunning()
{

	MESSAGE_DATA msg;
	msg.code = CODE_IS_RUNNING;

	MESSAGE_BACK back;
	DWORD bytesReturned = 0;
	DWORD hResult = 0;

	hResult = FilterSendMessage(
		hPort,
		&msg,
		sizeof(MESSAGE_DATA),
		&back,
		sizeof(MESSAGE_BACK),
		&bytesReturned
	);

	if (bytesReturned < sizeof(MESSAGE_BACK))
	{
		return false;
	}

	if (back.code == CODE_RUNNING)
	{
		return true;
	}

	return false;

}

bool SendKey(PCHAR key)
{
	DWORD bytesReturned = 0;
	DWORD hResult = 0;

	MESSAGE_BACK back;
	size_t len = strlen(key);
	PMESSAGE_DATA msg = (PMESSAGE_DATA)malloc(sizeof(MESSAGE_DATA) + len + 1);

	if (msg == NULL)
	{
		return false;
	}

	memset(msg, 0, sizeof(MESSAGE_DATA) + len + 1);
	msg->code = CODE_SEND_KEY;
	msg->bufferLen = len;

	memcpy(msg->buffOffset, key, len);

	hResult = FilterSendMessage(
		hPort,
		msg,
		sizeof(MESSAGE_DATA) + len + 1,
		&back,
		sizeof(MESSAGE_BACK),
		&bytesReturned
	);

	free(msg);

	//printf("%d : %d\n", bytesReturned, back.code);

	if (bytesReturned < sizeof(MESSAGE_BACK))
	{

		return false;
	}

	if (back.code == CODE_SUCCESS)
	{
		return true;
	}

	return false;


}

bool SendStrategy(PCHAR strategy)
{
	DWORD bytesReturned = 0;
	DWORD hResult = 0;
	MESSAGE_BACK back;

	size_t len = strlen(strategy);
	PMESSAGE_DATA msg = (PMESSAGE_DATA)malloc(sizeof(MESSAGE_DATA) + len + 1);
	if (msg == NULL)
	{
		return false;
	}

	memset(msg, 0, sizeof(MESSAGE_DATA) + len + 1);
	msg->code = CODE_SEND_STRATEGY;
	msg->bufferLen = len;
	memcpy(msg->buffOffset, strategy, len);

	hResult = FilterSendMessage(hPort, msg, sizeof(MESSAGE_DATA) + len + 1,
		&back, sizeof(MESSAGE_BACK), &bytesReturned);

	free(msg);

	if (bytesReturned < sizeof(MESSAGE_BACK))
	{
		return false;
	}

	if (back.code == CODE_SUCCESS)
	{
		return true;
	}

	return false;
}

