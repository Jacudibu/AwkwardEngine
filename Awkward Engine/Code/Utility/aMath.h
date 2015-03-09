// aMath
// A namespace containing awkward Math related functions.

namespace aMath
{
	// Clamp
	// Returns value while min < value < max, elsewise min or max.
	float clamp(float value, float min, float max);

	// --- Interpolations ---

	// Linaer Interpolation
	// Returns the current position if p% of the distance has been passed.
	float lerp(float start, float end, float p);

	// Sinus Interpolation
	// Returns the current position if p% of the distance has been passed, getting slower over time.
	float sinlerp(float start, float end, float p);

	// Cosinus Interpolation
	// Returns the current position if p% of the distance has been passed, getting faster over time.
	float coslerp(float start, float end, float p);

	// Smooth Interpolation
	// Returns the current position if p% of the distance has been passed, gaining speed in the beginning and slowing down when reaching the end.
	float smoothlerp(float start, float end, float p);

	// Smoother Interpolation than with smoothlerp
	// Returns the current position if p% of the distance has been passed, gaining speed in the beginning and slowing down when reaching the end.
	float smootherlerp(float start, float end, float p);

}