#pragma once

#include <iostream>
#include <chrono>
namespace Engine {
	class Timer
	{
	private:
		float m_ticks = 0;
	public:
		Timer()
		{

		}
		float updateTime()
		{			
			// Delta time is the difference in ticks from last frame
			// (converted to seconds)
			float deltaTime = (glfwGetTime() - m_ticks) / 1000.0f;
			// Update tick counts (for next frame)
			m_ticks = glfwGetTime();
			return m_ticks;
		}
	};
}