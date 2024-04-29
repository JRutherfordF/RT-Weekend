#include "Color.h"
#include "Ray.h"
#include "Vec3.h"

#include <iostream>

//Hardcoded red sphere intersection test
bool hit_sphere(const point3& center, double radius, const ray& r) {
	vec3 oc = center - r.origin(); // (C - Q)
	auto a = dot(r.direction(), r.direction()); // (d ⋅ d)
	auto b = -2.0 * dot(r.direction(), oc); // -2d ⋅ (C - Q)
	auto c = dot(oc, oc) - radius * radius; // (C - Q) ⋅ (C - Q) - r^2
	auto discriminant = b * b - 4 * a * c; // for quadratic formula
	return (discriminant >= 0);
}

color ray_color(const ray& r) {
	if (hit_sphere(point3(0, 0, -1), 0.5, r))
		return color(1, 0, 0);

	vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}


int main() {

	// Image

	auto aspect_ratio = 16.0 / 9.0;

	int image_width = 400;

	int image_height = static_cast<int>(image_width / aspect_ratio); //Calculates the image height based on the aspect ratio
	image_height = (image_height < 1) ? 1 : image_height; //Ensures the height is at least 1

	// Camera

	auto focal_length = 1.0;

	//Viewport widths less than one are ok since they are real valued.
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);

	auto camera_center = point3(0, 0, 0);

	//Calculate the vectors across the horizontal and down the vertical viewport edges.
	auto viewport_u = vec3(viewport_width, 0, 0);
	auto viewport_v = vec3(0, -viewport_height, 0);

	//Calcualte the horizontal and vertical delta vectors from pixel to pixel.
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	//Calculate the location of the upper left pixel
	auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
	auto pixel00_1oc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	//Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; ++j)
		// While there's no difference in a for loop, 
		// ++j is preferred over j++ in C++ because ++j will increment the value and return the incremented value 
		// whereas j++ will increment the value but return the original (pre incrementation) value
	{
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush; //outputs using cLog are buffered, meaning they are written to a variable and written in one go, which is more efficient than unbuffered outputs for logging.

		for (int i = 0; i < image_width; ++i)
		{
			auto pixel_center = pixel00_1oc + (i * pixel_delta_u) + (j * pixel_delta_v);
			auto ray_direction = pixel_center - camera_center;
			ray r(camera_center, ray_direction);

			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}
	std::clog << "\rDone.                   \n";
}