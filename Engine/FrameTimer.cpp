#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	lastTime = std::chrono::steady_clock::now();
}

float FrameTimer::deltaTime()
{
	std::chrono::steady_clock::time_point startTime = lastTime;
	lastTime = std::chrono::steady_clock::now();
	std::chrono::duration<float> delta = lastTime - startTime;
	return delta.count();
}
