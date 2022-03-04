#pragma once
#include <algorithm>

class Color
{
public:
	Color(float r, float g, float b, float a = 1.0f);
	Color(unsigned char r = 0u, unsigned char g = 0u, unsigned char b = 0u, unsigned char a = 0u);

	Color(const Color& _other);

	Color& operator=(const Color& _other);
	Color operator+(const Color& _other);
	Color& operator+=(const Color& _other);
	Color operator-(const Color& _other);
	Color& operator-=(const Color& _other);

	
	void SetR(unsigned char r) { color = (color & 0xFF00FFFFu) | (r << 16u); }
	void SetR(float r) 
	{ 
		r = std::clamp(r, 0.0f, 1.0f);
		SetR((unsigned char)(r * 255));
	}
	void GetR(unsigned char& out) const { out = (color >> 16u) & 0xFF; }
	void GetR(float& out) const 
	{ 
		unsigned char r;
		GetR(r);
		out = (float)r * 0.00392156862f; // multiply by 1/255
	}

	void SetG(unsigned char g) { color = (color & 0xFFFF00FFu) | (g << 8u); }
	void SetG(float g)
	{
		g = std::clamp(g, 0.0f, 1.0f);
		SetG((unsigned char)(g * 255));
	}
	void GetG(unsigned char& out) const { out = (color >> 8u) & 0xFF; }
	void GetG(float& out) const 
	{
		unsigned char g;
		GetG(g);
		out = (float)g * 0.00392156862f; // multiply by 1/255
	}

	void SetB(unsigned char b) { color = (color & 0xFFFFFF00u) | b; }
	void SetB(float b)
	{
		b = std::clamp(b, 0.0f, 1.0f);
		SetB((unsigned char)(b * 255));
	}
	void GetB(unsigned char& out) const { out = color & 0xFF; }
	void GetB(float& out) const 
	{
		unsigned char b;
		GetB(b);
		out = (float)b * 0.00392156862f; // multiply by 1/255
	}

	void SetA(unsigned char a) { color = (color & 0x00FFFFFFu) | (a << 24u); }
	void SetA(float a)
	{
		a = std::clamp(a, 0.0f, 1.0f);
		SetA((unsigned char)(a * 255));
	}
	void GetA(unsigned char& out) const { out = (color >> 24u) & 0xFF; }
	void GetA(float& out) const 
	{
		unsigned char a;
		GetA(a);
		out = (float)a * 0.00392156862f; // multiply by 1/255
	}

private:
	unsigned int color = 0;
};

