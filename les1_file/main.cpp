#include <windows.h>

#include <iostream>

int main()
{
    std::string path_from = "E:\\cpp_project\\NextLevel\\.gitignore";
    std::string path_to = "E:\\cpp_project\\NextLevel\\les1_file\\.gitignore";

    WIN32_FIND_DATA FileData;
    HANDLE          hSearch;
    TCHAR           szNewPath[MAX_PATH];

    // Start searching for text files in the current directory. 
    hSearch = FindFirstFile(TEXT("E:\\cpp_project\\NextLevel\\.gitignore"), &FileData);
    
    if (hSearch == INVALID_HANDLE_VALUE){
        printf("No text files found.\n");
    }

    if(CopyFile(FileData.cFileName, L"E:\\cpp_project\\NextLevel\\.gitignore1", FALSE)){
        printf("Copy file.\n");
    } else {
        printf("Could not copy file.\n");
    }

    FindClose(hSearch);

}
