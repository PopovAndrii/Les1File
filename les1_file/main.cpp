#include <windows.h>

#include <iostream>

int main()
{
    std::wstring path_from = L"D:\\cpp_project\\NextLevel\\\Les1File\\.gitignore";
    std::wstring path_to = L"D:\\cpp_project\\NextLevel\\\Les1File\\.gitignore1";

    WIN32_FIND_DATA FileData;
    HANDLE          hSearch;
    TCHAR           szNewPath[MAX_PATH];

    // Start searching for text files in the current directory. 
    hSearch = FindFirstFile(TEXT("E:\\cpp_project\\NextLevel\\.gitignore"), &FileData);
    
    if (hSearch == INVALID_HANDLE_VALUE){
        printf("No text files found.\n");
    }

    if(CopyFile(path_from.c_str(), path_to.c_str(), FALSE)){
        printf("Copy file.\n");
    } else {
        printf("Could not copy file.\n");
    }

    FindClose(hSearch);

}
