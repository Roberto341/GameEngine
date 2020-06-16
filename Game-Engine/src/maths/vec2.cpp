#include "vec2.h"

namespace Engine { namespace Maths {
	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}
	/*Takes x, y*/
	vec2::vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}

	vec2& vec2::add(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	} 
	vec2& vec2::subtrac(const vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}
	vec2& vec2::multiply(const vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}
	vec2& vec2::divide(const vec2& other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}
	/*Add operator*/
	vec2 operator+(vec2 left, const vec2& right)
	{
		return left.add(right);
	}
	/*Subtract operator*/
	vec2 operator-(vec2 left, const vec2& right)
	{
		return left.subtrac(right);
	}
	/*Multiply operator*/
	vec2 operator*(vec2 left, const vec2& right)
	{
		return left.multiply(right);
	}
	/*Divide operator*/
	vec2 operator/(vec2 left, const vec2& right)
	{
		return left.divide(right);
	}
	/*Plus equals */
	vec2& vec2::operator+=(const vec2& other)
	{
		*this = *this + other;
		return *this;
	}
	/*Minus equals */
	vec2& vec2::operator-=(const vec2& other)
	{
		*this = *this - other;
		return *this;
	}
	/*Muliply equals */
	vec2& vec2::operator*=(const vec2& other)
	{
		*this = *this * other;
		return *this;
	}
	/*Divide equals */
	vec2& vec2::operator/=(const vec2& other)
	{
		*this = *this / other;
		return *this;
	}
	/*Compare*/
	bool vec2::operator==(const vec2& other)
	{
		return x == other.x && y == other.y;
	}
	/*Does not equal*/
	bool vec2::operator!=(const vec2& other)
	{
		return x != other.x && y != other.y;
	}
		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
	{
		stream << "vec2: (" << vector.x << ", " << vector.y << ")";
		return stream;
	}
} }