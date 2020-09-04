#include "FileCustom.h"

int main()
{

    FileCustom* f = new FileCustom();

    char from[] = "E:/cpp_project/NextLevel/.gitignore";
    char to[] = "E:/cpp_project/NextLevel/.gitignore1";

    f->Copy(*from, *to);
}
