#pragma once

#include <windows.h>
#include <iostream>

class FileCostom
{
public:

	FileCostom(){

	}
	~FileCostom(){
		CloseHandle(m_hFile);
	}

	void CopyFileCostom(char &from, char &to) {

	}

	void ReadFileCostom() {
		m_hFile = CreateFileA(
			"E:\\cpp_project\\NextLevel\\.gitignore1",
			GENERIC_WRITE | GENERIC_READ,          // open for writing
			0,                      // do not share
			NULL,                   // default security
			CREATE_NEW,             // create new file only
			FILE_ATTRIBUTE_NORMAL,  // normal file
			NULL);                  // no attr. template
	
	}

	void WriteFileCostom() {
		char DataBuffer[] = "This is some test file.";
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);

		m_bErrorFlag = WriteFile(
			m_hFile,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&m_dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
	}


	HANDLE m_hFile = 0;
	//char DataBuffer[] = "This is some test file.";
	//DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD m_dwBytesWritten = 0;
	BOOL m_bErrorFlag = FALSE;
	//eax.me/winapi-files/
};

