#pragma once

class Time
{
public:
	/* This is called once at the beginning of a new Frame.
	 * If you don't want to burn in hell, don't call this. //TODO: #friend Game Class so nopony enters dis
	 */
	static void Update();

	// Returns the amount of Milliseconds since the game got initialized.
	static float getTime()				{ return _time; }
	
	// Returns the amount of Milliseconds since the game got initalized of the last Frame.
	static float getLastTime()			{ return _lastTime; }

	// Returns the Milliseconds that have passed since the last frame.
	static float getDeltaTime()		{ return _deltaTime; }

	// Returns the amount of Milliseconds since the game got initialized. Unaffected by timeScale.
	static float getUnscaledTime()		{ return _unscaledTime; }

	// Returns the amount of Milliseconds since the game got initalized of the last Frame. Unaffected by timeScale.
	static float getUnscaledLastTime()	{ return _unscaledLastTime; }

	// Returns the Milliseconds that have passed since the last frame. Unaffected by timeScale.
	static float getUnscaledDeltaTime(){ return _unscaledDeltaTime; }

	// Returns current FPS.
	static int getFPS()				{ return _fps; }

	// Returns the current timeScale.
	static float getTimeScale()		{ return _timeScale; }

	// Sets the current timeScale. Affects time, lastTime and deltaTime. Use unscaledTime for unaffected values.
	static void setTimeScale(float scale) { _timeScale = scale; }

	// Returns the current Windows Time as unsinged long.
	static long getWindowsTime();

private:
	static float _time;
	static float _lastTime;
	static float _deltaTime;

	static float _unscaledTime;
	static float _unscaledLastTime;
	static float _unscaledDeltaTime;

	static int _fps;
	static int _frameCount;
	static float _timeScale;


};