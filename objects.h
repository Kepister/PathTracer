#ifndef HOBJECTS
#define HOBJECTS
#include <math.h>
#include <stdlib.h>

struct _vec3
{
	float x;
	float y;
	float z;
} typedef Vec3;

float rfloat()
{
	return ((float) rand())/((float) RAND_MAX);
}

float norm(Vec3 v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

float norm_squared(Vec3 v)
{
	return v.x*v.x + v.y*v.y + v.z*v.z;
}

Vec3 normalize(Vec3 v)
{
	float n = norm(v);

	return (Vec3) {v.x/n, v.y/n, v.z/n};
}

void normalizei(Vec3 *v)
{
	float n = norm(*v);

	v->x /= n;
	v->y /= n;
	v->z /= n;
}

Vec3 add(Vec3 v0, Vec3 v1)
{
	return (Vec3) {v0.x + v1.x, v0.y + v1.y, v0.z + v1.z};
}

void addi(Vec3 *v0, Vec3 v1)
{
	v0->x += v1.x;
	v0->y += v1.y;
	v0->z += v1.z;
}

Vec3 sub(Vec3 v0, Vec3 v1)
{
	return (Vec3) {v0.x - v1.x, v0.y - v1.y, v0.z - v1.z};
}

void subi(Vec3 *v0, Vec3 v1)
{
	v0->x -= v1.x;
	v0->y -= v1.y;
	v0->z -= v1.z;
}

Vec3 mult(Vec3 v, float a)
{
	return (Vec3) {v.x*a, v.y*a, v.z*a};
}

void multi(Vec3 *v, float a)
{
	v->x *= a;
	v->y *= a;
	v->z *= a;
}

float dot(Vec3 v0, Vec3 v1)
{
	return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z;
}

Vec3 crossp(Vec3 v0, Vec3 v1)
{
	return (Vec3) {v0.y*v1.z - v0.z*v1.y, v0.x*v1.z - v0.z*v1.x, v0.y*v1.z - v0.z*v1.y};
}

/* Graphics */

struct _image
{
	int width;
	int height;

	float **buffer;
	float *samples;
} typedef Image;

struct _ray
{
	Vec3 direction;
	Vec3 origin;
} typedef Ray;

struct _brdf
{
	/*TODO*/
} typedef BRDF;

struct _material
{
	/*TODO*/
} typedef Material;

struct _hit
{
	/*TODO*/
} typedef Hit;

/* Objects */

struct _triangle
{
	Vec3 v0;
	Vec3 v1;
	Vec3 v2;
	Vec3 normal;
} typedef Triangle;

struct _disk
{
	Vec3 position;
	Vec3 normal;
	float radius;
} typedef Disk;

struct _sphere
{
	Vec3 position;
	float radius;
} typedef Sphere;

struct _plain
{
	Vec3 position;
	Vec3 normal;
	float width;
	float height;
} typedef Plain;

struct _scene
{
	Disk *disks;
	Sphere *spheres;
	Plain *plains;

	Disk *disk_l;
	Sphere *spheres_l;
	Plain *plains_l;

} typedef Scene;

Hit hit_disk(Disk *disk, Ray *r)
{
	/*TODO*/
	return (Hit) {};
}

Hit hit_sphere(Sphere *sphere, Ray *r)
{
	/*TODO*/
	return (Hit) {};
}

Hit hit_plain(Plain *plain, Ray *r)
{
	/*TODO*/
	return (Hit) {};
}

Hit hit_triangle(Triangle *triangle, Ray *r)
{
	/*TODO*/
	return (Hit) {};
}

Triangle get_triangle(Vec3 v0, Vec3 v1, Vec3 v2)
{
	Vec3 d0 = sub(v0, v1);
	Vec3 d1 = sub(v0, v2);

	Vec3 n = crossp(d0, d1);

	return (Triangle) {v0, v1, v2, n};
}

/* Support functions */

Image get_image(const int width, const int height)
{
	float **buffer = (float**) malloc(sizeof(float*)*3);
	for (int i = 0; i < 3; i++) buffer[i] = (float*) calloc(width*height, sizeof(float));

	return (Image) {width, height, buffer, (float*) calloc(width*height, sizeof(float))};
}

void free_image(Image *image)
{
	for (int i = 0; i < 3; i++) free(image->buffer[i]);
	free(image->buffer);
	free(image->samples);
}

/* Samplers */

Vec3 sample_hemisphere(Vec3 n)
{
	float a = rfloat();
	float b = rfloat();
	float c = rfloat();

	Vec3 sample = (Vec3) {a, b, c};
	normalizei(&sample);

	float angl = dot(sample, n);

	return angl < 0.0f ? (Vec3) {-sample.x, -sample.y, -sample.z} : sample;
}

#endif
