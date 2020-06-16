#include "vec4.h"

namespace Engine { namespace Maths {

	/*Takes x, y, z, w*/
	vec4::vec4(const float& x, const float& y, const float& z, const float& w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4& vec4::add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	} 
	vec4& vec4::subtrac(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}
	vec4& vec4::multiply(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}
	vec4& vec4::divide(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;
	}
	/*Add operator*/
	vec4 operator+(vec4 left, const vec4& right)
	{
		return left.add(right);
	}
	/*Subtract operator*/
	vec4 operator-(vec4 left, const vec4& right)
	{
		return left.subtrac(right);
	}
	/*Multiply operator*/
	vec4 operator*(vec4 left, const vec4& right)
	{
		return left.multiply(right);
	}
	/*Divide operator*/
	vec4 operator/(vec4 left, const vec4& right)
	{
		return left.divide(right);
	}
	/*Plus equals */
	vec4& vec4::operator+=(const vec4& other)
	{
		*this = *this + other;
		return *this;
	}
	/*Minus equals */
	vec4& vec4::operator-=(const vec4& other)
	{
		*this = *this - other;
		return *this;
	}
	/*Muliply equals */
	vec4& vec4::operator*=(const vec4& other)
	{
		*this = *this * other;
		return *this;
	}
	/*Divide equals */
	vec4& vec4::operator/=(const vec4& other)
	{
		*this = *this / other;
		return *this;
	}
	/*Compare*/
	bool vec4::operator==(const vec4& other)
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}
	/*Does not equal*/
	bool vec4::operator!=(const vec4& other)
	{
		return x != other.x && y != other.y && z != other.z && w != other.w;
	}
		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
	{
		stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}
} }