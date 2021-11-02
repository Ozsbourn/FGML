#ifndef FGML_VECTOR3_HPP_
#include "Macros.hpp"
#include <cassert>
#include <iostream> // debug
#include <cmath>

#define FGML_VECTOR3_HPP_

namespace FGML {
	///
	///	Definition of Vec3 class
	///
	class Vector3 {
	private:
		float m_x; 
		float m_y;
		float m_z;
	public:
		Vector3() = default;

		explicit Vector3(  float x,
				  		   float y, 
				  		   float z  );

		friend inline float getXComponent(const Vector3& vec);
		friend inline float getYComponent(const Vector3& vec);
		friend inline float getZComponent(const Vector3& vec);

		friend Vector3 operator-(const Vector3& vec);
		friend Vector3 operator-(const Vector3& vec1, const Vector3& vec2);
		friend Vector3 operator+(const Vector3& vec1, const Vector3& vec2);
		friend Vector3 operator*(const Vector3& vec,  const float& scalar);
		friend Vector3 operator/(const Vector3& vec,  const float& scalar);

		void 	   	   operator-=(const float& scalar);
		void 	   	   operator+=(const float& scalar);
		void 	   	   operator*=(const float& scalar);
		void 	   	   operator/=(const float& scalar);

		inline float&  operator[](const size_t& shifting);

		friend inline Vector3 CrossProduct(const Vector3& vec1, const Vector3& vec2);
		friend inline float	    DotProduct(const Vector3& vec1, const Vector3& vec2);

		friend inline float	  Magnitude(const Vector3& vec);
		friend inline Vector3 Normalize(const Vector3& vec);

		~Vector3() = default;

		friend std::ostream& operator<<(std::ostream& out, const Vector3& vec);
	};
	///
	///	Definition of Vec3 class end
	///

	///
	///	Declaration of Vec3 methods
	///
	inline Vector3::Vector3(  float x = 0.0f,
						 	  float y = 0.0f, 
						 	  float z = 0.0f  ) 
	: m_x(x), m_y(y), m_z(z) {}

	inline float getXComponent(const Vector3& vec){
		return vec.m_x;
	}

	inline float getYComponent(const Vector3& vec){
		return vec.m_y;
	}

	inline float getZComponent(const Vector3& vec){
		return vec.m_z;
	}

	inline void Vector3::operator-=(const float& scalar){
		this->m_x -= scalar;
		this->m_y -= scalar;
		this->m_z -= scalar;
	}

	inline void Vector3::operator+=(const float& scalar){
		this->m_x += scalar;
		this->m_y += scalar;
		this->m_z += scalar;
	}

	inline void Vector3::operator*=(const float& scalar){
		this->m_x *= scalar;
		this->m_y *= scalar;
		this->m_z *= scalar;
	}

	inline void Vector3::operator/=(const float& scalar){
		this->m_x /= scalar;
		this->m_y /= scalar;
		this->m_z /= scalar;
	}

	inline float&  Vector3::operator[](const size_t& shifting){
		assert(shifting < 3uL && "Going beyond the vector");
		return *((&this->m_x) + shifting);
	}

	inline Vector3 CrossProduct(const Vector3& vec1, const Vector3& vec2){
		return Vector3(   (vec1.m_y * vec2.m_z - vec1.m_z * vec2.m_y),
						 -(vec1.m_x * vec2.m_z - vec1.m_z * vec2.m_x),	
						  (vec1.m_x * vec2.m_y - vec1.m_y * vec2.m_x)  );
	}

	inline float   DotProduct(const Vector3& vec1, const Vector3& vec2){
		return (vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y + vec1.m_z * vec2.m_z);
	}

	inline Vector3 operator+(const Vector3& vec1, const Vector3& vec2){
		return Vector3(vec1.m_x + vec2.m_x, vec1.m_y + vec2.m_y, vec1.m_z + vec2.m_z);
	}

	inline Vector3 operator-(const Vector3& vec){
		return Vector3(-vec.m_x, -vec.m_y, -vec.m_z);
	}

	inline Vector3 operator-(const Vector3& vec1, const Vector3& vec2){
		return Vector3(vec1.m_x - vec2.m_x, vec1.m_y - vec2.m_y, vec1.m_z - vec2.m_z);
	}

	inline Vector3 operator*(const Vector3& vec, const float& scalar){
		return Vector3(vec.m_x * scalar, vec.m_y * scalar, vec.m_z * scalar);
	}

	inline Vector3 operator/(const Vector3& vec, const float& scalar){
		float divCoeff = 1 / scalar;
		return Vector3(vec.m_x * divCoeff, vec.m_y * divCoeff, vec.m_z * divCoeff);
	}

	inline float   Magnitude(const Vector3& vec){
		return sqrt(SQR(vec.m_x) + SQR(vec.m_y) + SQR(vec.m_z));
	}

	inline Vector3 Normalize(const Vector3& vec){
		return (vec / Magnitude(vec));
	}

	std::ostream& operator<<(std::ostream& out, const FGML::Vector3& vec){
		std::cout << "{" << vec.m_x << ", " << vec.m_y << "," << vec.m_z << "}"<< std::endl;
		return out;
	}
	///
	///	Declaration of Vec3 methods end
	///
};

#endif // FGML_VECTOR3_HPP_