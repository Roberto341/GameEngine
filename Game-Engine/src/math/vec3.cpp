#include "vec3.h"

namespace Engine { namespace Maths {
	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
	}
	/*Takes x, y, z*/
	vec3::vec3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	} 
	vec3& vec3::subtrac(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}
	vec3& vec3::multiply(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}
	vec3& vec3::divide(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}
	/*Add operator*/
	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.add(right);
	}
	/*Subtract operator*/
	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.subtrac(right);
	}
	/*Multiply operator*/
	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.multiply(right);
	}
	/*Divide operator*/
	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.divide(right);
	}
	/*Plus equals */
	vec3& vec3::operator+=(const vec3& other)
	{
		*this = *this + other;
		return *this;
	}
	/*Minus equals */
	vec3& vec3::operator-=(const vec3& other)
	{
		*this = *this - other;
		return *this;
	}
	/*Muliply equals */
	vec3& vec3::operator*=(const vec3& other)
	{
		*this = *this * other;
		return *this;
	}
	/*Divide equals */
	vec3& vec3::operator/=(const vec3& other)
	{
		*this = *this / other;
		return *this;
	}
	/*Compare*/
	bool vec3::operator==(const vec3& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}
	/*Does not equal*/
	bool vec3::operator!=(const vec3& other)
	{
		return x != other.x && y != other.y && z != other.z;
	}
		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
	{
		stream << "vec3: (" << vector.x << ", " << vector.y << ", "<< vector.z << ")";
		return stream;
	}
} }