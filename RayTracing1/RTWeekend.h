#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// C++ Std usings
using std::make_shared;
using std::shared_ptr;
using std::sqrt;

// Constraints
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions
inline double degrees_to_radians(double degrees) {
	return degrees * pi / 180.0;
}

// Common headers
#include "Color.h"
#include "Interval.h"
#include "Ray.h"
#include "Vec3.h"

#endif // !RTWEEKEND_H
