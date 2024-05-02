#ifndef COLOR_H
#define COLOR_H

#include "Interval.h"
#include "Vec3.h"

using color = vec3; // Since both colour and coordinate data will use vec3, aliases are used to make distinguishing them easier

void write_color(std::ostream& out, color pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// Translate the [0.1] component values to the byte range [0,255]
	static const interval intensity(0.000, 0.999);
	int rbyte = int(256 * intensity.clamp(r));
	int gbyte = int(256 * intensity.clamp(g));
	int bbyte = int(256 * intensity.clamp(b));

	// Write out the pixel color components
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif