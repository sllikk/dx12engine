
#include "Engine.h"


struct Data {

    int data;
    Data() = default;

    Data(const int& data)
        : data(data)
    {}

};


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    if(AllocConsole() == true);
    
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    std::clog.clear();
    std::cout.clear();

    freopen_s(&fp, "CONOUT$", "w", stderr);
    std::cerr.clear();

    while (true);

    return 0;
}
