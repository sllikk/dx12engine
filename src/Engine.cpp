
#include "engine.h"

HWND Window::m_hwnd = NULL;
HINSTANCE Window::m_instance = NULL;
LPCSTR Window::m_name = "";
int Window::nCmdShow = 0;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{    
    Engine* engine = new Engine();
    engine->m_window->m_instance = hInstance;
    engine->m_window->nCmdShow = nCmdShow;
    engine->init();
    engine->run();
    engine->shutdown();
    delete engine;

    return 0;
}


bool Engine::init() const
{
    m_dx12Render->init();
    m_window->create();
    return false;
}

void Engine::run()
{
    while (true) {
        m_dx12Render->update();
        m_dx12Render->render();
    }
}

void Engine::shutdown()
{
    m_dx12Render->shutdown();
}


LRESULT Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
        {

        }

        return 0;

        }

        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

}

void Window::create_console()
{
    if (AllocConsole()) {
        OutputDebugStringW(L"ConsoleCreated\n");
    }

    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    std::clog.clear();
    std::cout.clear();

    freopen_s(&fp, "CONOUT$", "w", stderr);
    std::cerr.clear();

}




void Window::create()
{
    const wchar_t CLASS_NAME[] = L"Render Class";
    
    WNDCLASS wc{};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = m_instance;
    wc.lpszClassName = "E";

    RegisterClass(&wc);
    create_console();

    m_hwnd = CreateWindowEx(
        0, "E", "E", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1900, 900, NULL, NULL, m_instance, NULL
    );

    if (m_hwnd == NULL)
    {
        MessageBoxW(NULL, L"Error Create Window", NULL, NULL);
        return;
    }

    ShowWindow(m_hwnd, nCmdShow);

}




void Window::destroy()
{
    FreeConsole();
    OutputDebugStringW(L"ConsoleDestroyed\n");
}
