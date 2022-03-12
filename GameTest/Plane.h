#pragma once
#include "Vector3.h"
class Plane
{
public:
	void GeneratePlane(const Vector3<float>& p1, const Vector3<float>& p2, const Vector3<float>& p3)
	{

	}

	void GenerateBoundedPlane(const std::vector<Vector3<float>>& _points)
	{
		if (_points.size() < 3)
			throw "Tried to generate a bounded plane with less than 3 vertices";

		planeNormal = ((_points[1] - _points[0]).GetNormalized()).Cross((_points[2] - _points[0]).GetNormalized());
		if (planeNormal == Vector3<float>{0.0f, 0.0f, 0.0f})
		{

		}
		planeScalar = -planeNormal.x * _points[0].x - planeNormal.y * _points[0].y - planeNormal.z * _points[0].z;

		bounds = _points;
	}

	Vector3<float> GetClosestPoint(const Vector3<float>& _point)
	{
		if (bounds.size() >= 3 && planeNormal.Dot(bounds[0] - _point) > 0.0f)
		{
			planeNormal *= -1;
			planeScalar *= -1;
		}

		Vector3<float> point_to_plane = planeNormal * -1;

		float t = -(planeScalar + planeNormal.x * _point.x + planeNormal.y * _point.y + planeNormal.z * _point.z) 
					/ 
					(planeNormal.x * point_to_plane.x + planeNormal.y * point_to_plane.y + planeNormal.z * point_to_plane.z);

		Vector3<float> closest_point_on_plane = {_point.x + point_to_plane.x * t,_point.y + point_to_plane.y * t,_point.z + point_to_plane.z * t, };

		if (bounds.size() == 0)
			return closest_point_on_plane;

		// check if point in within bounds
		if (bounds.size() == 4)
		{
			if (bounds[0].x > bounds[3].x)
				std::swap(bounds[0], bounds[3]);


			Vector3<float> point_to_A = (bounds[0] - _point).GetNormalized();
			Vector3<float> point_to_D = (bounds[3] - _point).GetNormalized();

			Vector3<float> A_to_B = (bounds[1] - bounds[0]).GetNormalized();
			Vector3<float> A_to_C = (bounds[2] - bounds[0]).GetNormalized();
			Vector3<float> D_to_B = (bounds[1] - bounds[3]).GetNormalized();
			Vector3<float> D_to_C = (bounds[2] - bounds[3]).GetNormalized();

			// find the zone the point is in and find the closest point 
			if (point_to_A.Dot(A_to_B) > 0.0f && point_to_A.Dot(A_to_C) > 0.0f)
				return bounds[0];
			
			if (point_to_D.Dot(D_to_B) > 0.0f && point_to_D.Dot(D_to_C) > 0.0f)
				return bounds[3];

			if (point_to_A.Dot(A_to_B) > 0.0f)
			{
				Vector3<float> perp_vector = planeNormal.Cross(A_to_C);
				if (perp_vector.Dot(A_to_B) < 0.0f)
					perp_vector *= -1;

				float t = (bounds[0].x - closest_point_on_plane.x) / (perp_vector.x - A_to_C.x);
				return closest_point_on_plane + (perp_vector * t);
			}

			if (point_to_A.Dot(A_to_C) > 0.0f)
			{
				Vector3<float> perp_vector = planeNormal.Cross(A_to_B);
				if (perp_vector.Dot(A_to_C) < 0.0f)
					perp_vector *= -1;

				float t = (bounds[0].x - closest_point_on_plane.x) / (perp_vector.x - A_to_B.x);
				return closest_point_on_plane + (perp_vector * t);
			}
			
			if (point_to_D.Dot(D_to_B) > 0.0f)
			{
				Vector3<float> perp_vector = planeNormal.Cross(D_to_C);
				if (perp_vector.Dot(D_to_B) < 0.0f)
					perp_vector *= -1;

				float t = (bounds[3].x - closest_point_on_plane.x) / (perp_vector.x - D_to_C.x);
				return closest_point_on_plane + (perp_vector * t);
			}

			if (point_to_D.Dot(D_to_C) > 0.0f)
			{
				Vector3<float> perp_vector = planeNormal.Cross(D_to_B);
				if (perp_vector.Dot(D_to_C) < 0.0f)
					perp_vector *= -1;

				float t = (bounds[3].x - closest_point_on_plane.x) / (perp_vector.x - D_to_B.x);
				return closest_point_on_plane + (perp_vector * t);
			}

		}

		return closest_point_on_plane;
	}
public:
	Vector3<float> planeNormal;
	float planeScalar;
	std::vector<Vector3<float>> bounds;
};

