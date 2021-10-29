#include "util.hpp"

#ifndef FGML_VECTOR4_HPP_
#define FGML_VECTOR4_HPP_

namespace FGML {
	///
	///	Definition of Vec4 class
	///
	class Vector4 {
	private:
		float m_x;
		float m_y;
		float m_z;
		float m_w;
	public:
		Vector4() = default;

		Vector4(  float x,
				  float y, 
				  float z,
				  float w  );

		friend Vector4 operator-(const Vector4& vec);
		friend Vector4 operator-(const Vector4& vec1, const Vector4& vec2);
		friend Vector4 operator+(const Vector4& vec1, const Vector4& vec2);
		friend Vector4 operator*(const Vector4& vec, const float& scalar);
		friend Vector4 operator/(const Vector4& vec, const float& scalar);

		inline void    operator-=(const float& scalar);
		inline void    operator+=(const float& scalar);
		inline void    operator*=(const float& scalar);
		inline void    operator/=(const float& scalar);

		inline float&  operator[](const size_t& shifting);

		friend inline float	    DotProduct(const Vector4& vec1, const Vector4& vec2);

		friend inline float	  Magnitude(const Vector4& vec);
		friend inline Vector4 Normalize(const Vector4& vec);

		~Vector4() = default;

		friend std::ostream& operator<<(std::ostream& out, const Vector4& vec);	
	};
	///
	///	Definition of Vec4 class end
	///

	///
	///	Declaration of Vec4 methods
	///
	Vector4::Vector4(  float x = 0.0f,
				  	   float y = 0.0f, 
				  	   float z = 0.0f,
				  	   float w = 0.0f  ) 
	: m_x(x), m_y(y), m_z(z), m_w(w) {}

	inline Vector4 operator-(const Vector4& vec){
		return Vector4(-vec.m_x, -vec.m_y, -vec.m_z, -vec.m_w);
	}

	inline Vector4 operator-(const Vector4& vec1, const Vector4& vec2){
		return Vector4( vec1.m_x - vec2.m_x,
						vec1.m_y - vec2.m_y,
						vec1.m_z - vec2.m_z,
						vec1.m_w - vec2.m_w );
	}

	inline Vector4 operator+(const Vector4& vec1, const Vector4& vec2){
		return Vector4( vec1.m_x + vec2.m_x,
						vec1.m_y + vec2.m_y,
						vec1.m_z + vec2.m_z,
						vec1.m_w + vec2.m_w );
	}

	inline Vector4 operator*(const Vector4& vec,  const float& scalar){
		return Vector4( vec.m_x * scalar,
						vec.m_y * scalar,
						vec.m_z * scalar,
						vec.m_w * scalar );
	}

	inline Vector4 operator/(const Vector4& vec,  const float& scalar){
		float divCoeff = 1 / scalar;
		return Vector4( vec.m_x * divCoeff,
						vec.m_y * divCoeff,
						vec.m_z * divCoeff,
						vec.m_w * divCoeff );
	}

	inline void   Vector4::operator-=(const float& scalar){
		this->m_x -= scalar;
		this->m_y -= scalar;
		this->m_z -= scalar;
		this->m_w -= scalar;
	}

	inline void   Vector4::operator+=(const float& scalar){
		this->m_x += scalar;
		this->m_y += scalar;
		this->m_z += scalar;
		this->m_w += scalar;
	}

	inline void   Vector4::operator*=(const float& scalar){
		this->m_x *= scalar;
		this->m_y *= scalar;
		this->m_z *= scalar;
		this->m_w *= scalar;
	}

	inline void   Vector4::operator/=(const float& scalar){
		this->m_x /= scalar;
		this->m_y /= scalar;
		this->m_z /= scalar;
		this->m_w /= scalar;
	}

	inline float& Vector4::operator[](const size_t& shifting){
		assert(shifting < 4 && "Going beyond the vector");
		return *((&this->m_x) + shifting);
	}

	inline float   DotProduct(const Vector4& vec1, const Vector4& vec2){
		return (vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y + vec1.m_z * vec2.m_z + vec1.m_w * vec2.m_w);
	}

	inline float	Magnitude(const Vector4& vec){
		return sqrt(SQR(vec.m_x) + SQR(vec.m_y) + SQR(vec.m_z) + SQR(vec.m_w));
	}

	inline Vector4  Normalize(const Vector4& vec){
		return (vec / Magnitude(vec));
	}

	std::ostream& operator<<(std::ostream& out, const Vector4& vec){
		std::cout << "{" << vec.m_x << ", " << vec.m_y << "," << vec.m_z << "," << vec.m_w << "}"<< std::endl;
		return out;
	}
	///
	///	Declaration of Vec4 methods end
	///
};

#endif // FGML_VECTOR4_HPP_