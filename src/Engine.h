#pragma once

#define USE_WIN_HEADER
#include "utils.hpp"


class Engine {


public: 		

	Engine(const Engine& other) = delete;
	Engine operator=(const Engine& other) = delete;

	bool init();
	void run();
	void shutdown();


};
