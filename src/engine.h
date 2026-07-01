#pragma once

#define USE_WIN_HEADER
#include "utils.hpp"
#include "dx12render.h"

#ifndef UNICODE
#define UNICODE
#endif 

// figure out architecture 

class Window {
public:
	uint32_t m_width;
	uint32_t m_height;
  	static HWND m_hwnd;
    static HINSTANCE m_instance;
	static LPCSTR m_name;
	static int nCmdShow;

	bool m_is_running;

public:
	
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static void create_console();
 	static void create();
	void destroy();
	
	
	Window(const uint32_t& width, const uint32_t& height) : m_width(width), m_height(height), m_is_running(false) {};

	uint32_t get_width() const { return m_width; }
	uint32_t get_height() const { return m_height; }
	HWND get_hwnd() const { return m_hwnd; }

	void set_width(const uint32_t& width) { m_width = width; }
	void set_height(const uint32_t& height) { m_height = height; }

};


class Engine {

public:
	
	eastl::unique_ptr<DX12Render> m_dx12Render;
	eastl::unique_ptr<Window> m_window;

public: 		

	Engine() {
		
		m_dx12Render = eastl::make_unique<DX12Render>();
		m_window = eastl::make_unique<Window>(1280, 900);
	};
	

	Engine(const Engine& other) = delete;
	Engine operator=(const Engine& other) = delete;

	bool init() const;
	void run();
	void shutdown();


};
