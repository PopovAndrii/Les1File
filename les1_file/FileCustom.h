#pragma once

#include <windows.h>
#include <iostream>

class FileCustom
{
public:

	explicit FileCustom() {}
	~FileCustom() {}

	void Copy(char& from, char& to);

private:
	void SetHandle(char& path);
	bool Read();
	bool Write();

	HANDLE m_hFile = 0;
	DWORD m_lpBuffer = NULL;
	DWORD m_lpNumberOfBytesRead = NULL;
};

