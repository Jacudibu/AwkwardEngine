#include <SDL.h>
#include "Headers\Time.h"

float Time::_time = 0.0f;
float Time::_lastTime = 0.0f;
float Time::_deltaTime = 0.0f;

float Time::_unscaledTime = 0.0f;
float Time::_unscaledLastTime = 0.0f;
float Time::_unscaledDeltaTime = 0.0f;

int Time::_fps = 0;
int Time::_frameCount = 0;
float Time::_timeScale = 1.0f;

void Time::Update()
{
	_unscaledLastTime = _unscaledTime;
	_unscaledTime = SDL_GetTicks() * 1.0f;
	_unscaledDeltaTime = _unscaledTime - _unscaledLastTime;

	_deltaTime = _unscaledDeltaTime * _timeScale;
	_lastTime = _time;
	_time += _deltaTime;
	
	_unscaledDeltaTime /= 1000.0f;
	_deltaTime /= 1000.0f;


	// FPS Stuff
	_frameCount++;
	if ((int)_unscaledTime / 1000 > (int)_unscaledLastTime / 1000)
	{
		_fps = _frameCount;
		_frameCount = 0;
	}
}