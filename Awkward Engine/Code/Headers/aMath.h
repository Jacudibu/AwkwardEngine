// aMath
// A namespace containing awkward Math related functions.

namespace aMath
{
	// Clamp
	// Returns value while min < value < max, elsewise min or max.
	inline float clamp(float value, float min, float max);

	// --- Interpolations ---

	// Linaer Interpolation
	// Returns the current position if p% of the distance has been passed.
	inline float lerp(float start, float end, float p);

	// Sinus Interpolation
	// Returns the current position if p% of the distance has been passed, getting slower over time.
	inline float sinlerp(float start, float end, float p);

	// Cosinus Interpolation
	// Returns the current position if p% of the distance has been passed, getting faster over time.
	inline float coslerp(float start, float end, float p);

	// Smooth Interpolation
	// Returns the current position if p% of the distance has been passed, gaining speed in the beginning and slowing down when reaching the end.
	inline float smoothlerp(float start, float end, float p);

	// Smoother Interpolation than with smoothlerp
	// Returns the current position if p% of the distance has been passed, gaining speed in the beginning and slowing down when reaching the end.
	inline float smootherlerp(float start, float end, float p);

}