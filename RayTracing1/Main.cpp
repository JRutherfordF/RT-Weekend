#include "Color.h"
#include "Vec3.h"

#include <iostream>


int main() {

	// Image

	int image_width = 256;
	int image_height = 256;

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
			auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0);
			write_color(std::cout, pixel_color);

			//OLD CODE
			/*auto r = double(i) / (image_width - 1); //auto detects a variable type based on its initialization
			auto g = double(j) / (image_height - 1); //auto is generally only recommended for long types (not basic types like double in this case) but for the sake of of following the book's instructions i'm using auto here.
			auto b = 0;

			int ir = static_cast<int>(255.999 * r); //the values in the original variables (r, g & b) range from 0 to 1, the multiplication scales them up to integer values ranging from 0 to 255 
			int ig = static_cast<int>(255.999 * g); //static cast converts the result of [255.999 * r] from a float to an int
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n'; */

		}
	}
	std::clog << "\rDone.                   \n";
}