#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class ray {
public:
	ray() {}

	ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {} //equivalent to P(t)=A+tb

	point3 origin() const { return orig; }
	vec3 direction() const { return dir; }

	point3 at(double t) const { //at returns the value at a specified position in a vector
		return orig + t * dir;
	}

private:
	point3 orig;
	vec3 dir;
};

#endif