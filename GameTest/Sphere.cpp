#include "stdafx.h"
#include "Sphere.h"
#include "Vector3.h"
#include "App/AppSettings.h"
#include "Mat4.h"
#include "Quaternion.h"
void Sphere::GetSphere(std::vector<Vector3<float>>& _verts, std::vector<unsigned short>& _indices, size_t lat_divides, size_t long_divides)
{
	// set up the sphere
	_verts.clear();
	_indices.clear();

	assert(lat_divides >= 3);
	assert(long_divides >= 3);

	const float radius = 1.0f;
	const Vector3<float> base = { 0.0f, 0.0f, radius };
	const float lat_angle = PI / lat_divides;
	const float long_angle = 2.0f * PI / lat_divides;

	for (size_t iLat = 1; iLat < lat_divides; iLat++)
	{
		const Vector3<float> latBase = Quaternion<float>::RotationQuaternion(lat_angle * iLat, { 1.0f, 0.0f, 0.0f }).RotateAround(base);

		for (int iLong = 0; iLong < long_divides; ++iLong)
		{
			const Vector3<float> v = Quaternion<float>::RotationQuaternion(lat_angle * iLat, { 0.0f, 0.0f, 1.0f }).RotateAround(latBase);
			_verts.push_back(v);
		}
	}
}
