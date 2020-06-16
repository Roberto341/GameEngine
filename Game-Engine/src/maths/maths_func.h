#pragma once

#include <math.h>

namespace Engine { namespace Maths {

	inline float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);

	}
}}