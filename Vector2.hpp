#include <iostream>

#ifndef FGML_VECTOR2_HPP_
#define FGML_VECTOR2_HPP_

namespace FGML {
	///
	///	Definition of Vec2 class
	///
	class Vector2 {
	private:
		float m_x; 
		float m_y;
	public:
		explicit Vector2() = default;

		explicit Vector2( float x, 
				 		  float y );

		friend inline float getXComponent(const Vector2& vec);
		friend inline float getYComponent(const Vector2& vec);

		friend Vector2 operator-(const Vector2& vec);
		friend Vector2 operator-(const Vector2& vec1, const Vector2& vec2);
		friend Vector2 operator+(const Vector2& vec1, const Vector2& vec2);
		friend Vector2 operator*(const Vector2& vec,  const float& scalar);
		friend Vector2 operator/(const Vector2& vec,  const float& scalar);

		inline void    operator-=(const float& scalar);
		inline void    operator+=(const float& scalar);
		inline void    operator*=(const float& scalar);
		inline void    operator/=(const float& scalar);

		inline float&  operator[](const size_t& shifting);

		friend inline float   DotProduct(const Vector2& vec1, const Vector2& vec2);

		friend inline float   Magnitude(const Vector2& vec);
		friend inline Vector2 Normalize(const Vector2& vec);

		~Vector2() = default;

		friend std::ostream& operator<< (std::ostream& out, Vector2& vec);
	};
	///
	///	Definition of Vec2 class end
	///

	///
	///	Declaration of Vec2 methods
	///
	Vector2::Vector2(  float x = 0.0f, 
					   float y = 0.0f  ) 
	: m_x(x), m_y(y) {}

	inline float getXComponent(const Vector2& vec){
		return vec.m_x;
	}

	inline float getYComponent(const Vector2& vec){
		return vec.m_y;
	}

	inline void Vector2::operator-=(const float& scalar){
		this->m_x -= scalar; 
		this->m_y -= scalar;
	}

	inline void Vector2::operator+=(const float& scalar){
		this->m_x += scalar; 
		this->m_y += scalar;
	}

	inline void Vector2::operator*=(const float& scalar){
		this->m_x *= scalar; 
		this->m_y *= scalar;
	}

	inline void Vector2::operator/=(const float& scalar){
		this->m_x /= scalar; 
		this->m_y /= scalar;
	}

	inline float&  Vector2::operator[](const size_t& shifting){
		assert(shifting < 2uL && "Going beyond the vector");
		return *((&this->m_x) + shifting);
	}

	inline Vector2 operator+(const Vector2& vec1, const Vector2& vec2){
		return Vector2(vec1.m_x + vec2.m_x, vec1.m_y + vec2.m_y);
	}

	inline Vector2 operator-(const Vector2& vec){
		return Vector2(-(vec.m_x), -(vec.m_y));
	};

	inline Vector2 operator-(const Vector2& vec1, const Vector2& vec2){
		return Vector2(vec1.m_x - vec2.m_x, vec1.m_y - vec2.m_y);
	};

	inline Vector2 operator*(const Vector2& vec, const float& scalar){
		return Vector2(vec.m_x * scalar, vec.m_y * scalar);
	};

	inline Vector2 operator/(const Vector2& vec, const float& scalar){
		// assert((scalar - 0.0f) > EPSILON);
		float divCoeff = 1 / scalar;
		return Vector2(vec.m_x * divCoeff, vec.m_y * divCoeff);
	};

	inline float   DotProduct(const Vector2& vec1, const Vector2& vec2){
		return (vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y);
	}

	inline float   Magnitude(const Vector2& vec){	
		return sqrt(SQR(vec.m_x) + SQR(vec.m_y));
	}

	inline Vector2 Normalize(const Vector2& vec){
		return (vec / Magnitude(vec));
	}

	std::ostream& operator<< (std::ostream& out, Vector2& vec){
			std::cout << "{" << vec.m_x << ", " << vec.m_y << "}" << std::endl;
			return out;
	}
	///
	///	Declaration of Vec2 methods end
	///
};

#endif // FGML_VECTOR2_HPP_