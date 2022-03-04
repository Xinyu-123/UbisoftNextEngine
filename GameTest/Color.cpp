#include "stdafx.h"
#include "Color.h"

Color::Color(float r, float g, float b, float a)
{
    SetA(a);
    SetR(r);
    SetG(g);
    SetB(b);
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    SetA(a);
    SetR(r);
    SetG(g);
    SetB(b);
}

Color::Color(const Color& _other)
{
    unsigned char a = (unsigned char)(_other.color >> 24u);
    unsigned char r = (unsigned char)(_other.color >> 16u);
    unsigned char g = (unsigned char)(_other.color >> 8u);
    unsigned char b = (unsigned char)(_other.color);
    color = color & 0x00FFFFFF | (a << 24u);
    color = color & 0xFF00FFFF | (r << 16u);
    color = color & 0xFFFF00FF | (g << 8u);
    color = color & 0xFFFFFF00 | b;
}

Color& Color::operator=(const Color& _other)
{
    color = _other.color;
    return *this;
}

Color Color::operator+(const Color& _other)
{
    unsigned char a, r, g, b;
    GetA(a);
    GetR(r);
    GetG(g);
    GetB(b);

    unsigned char other_a, other_r, other_g, other_b;

    _other.GetA(other_a);
    _other.GetR(other_r);
    _other.GetG(other_g);
    _other.GetB(other_b);

    short ret_a = std::clamp(a + other_a, 0, 255);
    short ret_r = std::clamp(r + other_r, 0, 255);
    short ret_g = std::clamp(g + other_g, 0, 255);
    short ret_b = std::clamp(b + other_b, 0, 255);

    Color ret;
    ret.SetA((unsigned char)ret_a);
    ret.SetR((unsigned char)ret_r);
    ret.SetG((unsigned char)ret_g);
    ret.SetB((unsigned char)ret_b);

    return ret;
}

Color& Color::operator+=(const Color& _other)
{
    *this = *this + _other;
    return *this;
}

Color Color::operator-(const Color& _other)
{
    unsigned char a;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    GetA(a);
    GetR(r);
    GetG(g);
    GetB(b);

    unsigned char other_a;
    unsigned char other_r;
    unsigned char other_g;
    unsigned char other_b;

    _other.GetA(other_a);
    _other.GetR(other_r);
    _other.GetG(other_g);
    _other.GetB(other_b);

    short ret_a = std::clamp(a - other_a, 0, 255);
    short ret_r = std::clamp(r - other_r, 0, 255);
    short ret_g = std::clamp(g - other_g, 0, 255);
    short ret_b = std::clamp(b - other_b, 0, 255);

    Color ret;
    ret.SetA((unsigned char)ret_a);
    ret.SetR((unsigned char)ret_r);
    ret.SetG((unsigned char)ret_g);
    ret.SetB((unsigned char)ret_b);

    return ret;
}

Color& Color::operator-=(const Color& _other)
{
    *this = *this - _other;
    return *this;
}
