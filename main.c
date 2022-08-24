#include <stdio.h>
#include <stdlib.h>

#include "objects.h"


void sample(Image *image, const int bounces, Scene *scene)
{
	/* Generate random ray */

	/*TODO*/

	/* Trace ray through scene */

	/* Apply color to pixel */
}

/* Output parameters */

const int IMAGE_WIDTH  = 500;
const int IMAGE_HEIGHT = 500;
const int NRAYS = 1000;
const int NBOUNCES = 4;

int main()
{
	/* Create image resources */

	Image image = get_image(IMAGE_WIDTH, IMAGE_HEIGHT);	

	/* Create scene */

	Scene scene;

	/* Draw image */

	for (int i = 0; i < NRAYS; i++)
	{
		sample(&image, NBOUNCES, &scene);
	}

	/* Free resources */

	free_image(&image);
}

