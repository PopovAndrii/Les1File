#include "FileCustom.h"

void FileCustom::Copy(char& from, char& to) {

	SetHandle(from);

	if (Read()) {
		CloseHandle(m_hFile);
	}
	else {
		std::cout << GetLastError() << "\n";
	}

	SetHandle(to);

	if (Write()) {
		CloseHandle(m_hFile);
	}
	else {
		std::cout << GetLastError() << "\n";
	}
}

void FileCustom::SetHandle(char& path) {
	m_hFile = CreateFileA(
		&path,
		GENERIC_WRITE | GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
}

bool FileCustom::Read() {
	DWORD tmp;
	return ReadFile(
		m_hFile,
		&m_lpBuffer,
		sizeof(m_lpBuffer),
		&tmp,
		NULL
	);
}

bool FileCustom::Write() {
	return WriteFile(
		m_hFile,
		&m_lpBuffer,
		sizeof(m_lpBuffer),
		&m_lpNumberOfBytesRead,
		NULL
	);
}
