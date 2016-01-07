#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <io.h>

#define access _access

//  SHORTCUT OF 
#define CPU_TIME GetTickCount64()
uint64_t ReadULLtxt(std::string filepath);

class TimerHost {
private:
	std::ofstream fp;
	std::string stdPath;
	uint64_t startTime;

public:
	TimerHost();
	void set(uint64_t delay);
	void order();
};

class TimerClient {
private:
	//  std::ofstream fp;
	uint64_t aprxTime;  //  appointedTime
public:
	TimerClient();
	void wait();
};