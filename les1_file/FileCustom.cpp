#include "FileCustom.h"

void FileCustom::Copy(char& from, char& to) {

	HANDLE hR = SetHandle(from);
	HANDLE hW = SetHandle(to);

	for (;;) {
		Read(hR);

		// if empty file (copy empty file)
		if (m_lpNumberOfBytesRead == 0) break;

		Write(hW);
	}

	CloseHandle(hR);
	CloseHandle(hW);
}

HANDLE FileCustom::SetHandle(char& path) {
	return CreateFileA(
		&path,
		GENERIC_WRITE | GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
}

bool FileCustom::Read(HANDLE hR) {
	return ReadFile(
		hR,
		&m_lpBuffer,
		1, // sizeof(m_lpBuffer)
		&m_lpNumberOfBytesRead,
		NULL
	);
}

bool FileCustom::Write(HANDLE hW) {
	return WriteFile(
		hW,
		&m_lpBuffer,
		1,
		&m_lpNumberOfBytesRead,
		NULL
	);
}
