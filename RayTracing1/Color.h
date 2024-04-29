#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3; // Since both colour and coordinate data will use vec3, aliases are used to make distinguishing them easier

void write_color(std::ostream& out, color pixel_color) {
	// Write the translated [0,255] value of each color component
	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif