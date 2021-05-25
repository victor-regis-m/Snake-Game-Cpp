#pragma once
#include <chrono>

class FrameTimer
{
private:
	std::chrono::steady_clock::time_point lastTime;
public:
	FrameTimer();
	float deltaTime();
};