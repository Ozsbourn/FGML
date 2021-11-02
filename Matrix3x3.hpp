#include "Vector3.hpp"
#include <cassert>
#include <cstddef>

#ifndef FGML_MATRIX3X3_HPP_
#define FGML_MATRIX3X3_HPP_

namespace FGML {
	///
	///	Definition of Mat3x3 class
	///
	class Matrix3x3 {
	private:
		float m_arr[3][3];
	public:
		Matrix3x3() = default;

		explicit Matrix3x3(	float v11, float v12, float v13,
							float v21, float v22, float v23,
							float v31, float v32, float v33 );

		explicit Matrix3x3( Vector3 vec1,
							Vector3 vec2,
							Vector3 vec3 );

		inline Matrix3x3 Identity(void);

		inline void operator-=(const float& scalar);
		inline void operator+=(const float& scalar);
		inline void operator*=(const float& scalar);
		inline void operator/=(const float& scalar);

		inline void operator-=(const Matrix3x3& mat);
		inline void operator+=(const Matrix3x3& mat);
		// inline void operator*=(const Matrix3x3& mat);

		friend inline Matrix3x3 operator-(const Matrix3x3& mat);
		friend inline Matrix3x3 operator-(const Matrix3x3& mat1, const Matrix3x3& mat2);
		friend inline Matrix3x3 operator+(const Matrix3x3& mat1, const Matrix3x3& mat2);
		friend inline Matrix3x3 operator*(const Matrix3x3& mat1, const Matrix3x3& mat2);

		friend inline Vector3   operator*(const Matrix3x3& mat,  const Vector3& vec);

		friend inline Matrix3x3 operator-(const Matrix3x3& mat,  const float& scalar);
		friend inline Matrix3x3 operator+(const Matrix3x3& mat,  const float& scalar);
		friend inline Matrix3x3 operator*(const Matrix3x3& mat,  const float& scalar);
		friend inline Matrix3x3 operator/(const Matrix3x3& mat,  const float& scalar);

		inline Vector3 operator[](size_t i);

		~Matrix3x3() = default;

		friend std::ostream& operator<<(std::ostream& out, Matrix3x3 m);
	};
	///
	///	Definition of Mat3x3 class end
	///

	///
	///	Declaration of Mat3x3 methods
	///
	Matrix3x3::Matrix3x3( float v11 = 0.0f, float v12 = 0.0f, float v13 = 0.0f,
						  float v21 = 0.0f, float v22 = 0.0f, float v23 = 0.0f,
						  float v31 = 0.0f, float v32 = 0.0f, float v33 = 0.0f ) 
	: m_arr{ v11, v12, v13,
			 v21, v22, v23,
			 v31, v32, v33 } {}

	Matrix3x3::Matrix3x3( Vector3 vec1,
						  Vector3 vec2,
						  Vector3 vec3 ) 
	: m_arr{ getXComponent(vec1), getYComponent(vec1), getZComponent(vec1),
			 getXComponent(vec2), getYComponent(vec2), getZComponent(vec2),
			 getXComponent(vec3), getYComponent(vec3), getZComponent(vec3) } {}

	inline Matrix3x3 Matrix3x3::Identity(void){
		return Matrix3x3( 1.0f, 0.0f, 0.0f,
						  0.0f, 1.0f, 0.0f,
						  0.0f, 0.0f, 1.0f );
	}

	inline void Matrix3x3::operator-=(const float& scalar){
		this->m_arr[0][0] -= scalar; this->m_arr[0][1] -= scalar; this->m_arr[0][2] -= scalar;
		this->m_arr[1][0] -= scalar; this->m_arr[1][1] -= scalar; this->m_arr[1][2] -= scalar;
		this->m_arr[2][0] -= scalar; this->m_arr[2][1] -= scalar; this->m_arr[2][2] -= scalar;
	}

	inline void Matrix3x3::operator+=(const float& scalar){
		this->m_arr[0][0] += scalar; this->m_arr[0][1] += scalar; this->m_arr[0][2] += scalar;
		this->m_arr[1][0] += scalar; this->m_arr[1][1] += scalar; this->m_arr[1][2] += scalar;
		this->m_arr[2][0] += scalar; this->m_arr[2][1] += scalar; this->m_arr[2][2] += scalar;
	}

	inline void Matrix3x3::operator*=(const float& scalar){
		this->m_arr[0][0] *= scalar; this->m_arr[0][1] *= scalar; this->m_arr[0][2] *= scalar;
		this->m_arr[1][0] *= scalar; this->m_arr[1][1] *= scalar; this->m_arr[1][2] *= scalar;
		this->m_arr[2][0] *= scalar; this->m_arr[2][1] *= scalar; this->m_arr[2][2] *= scalar;
	}

	inline void Matrix3x3::operator-=(const Matrix3x3& mat){
		this->m_arr[0][0] -= mat.m_arr[0][0]; this->m_arr[0][1] -= mat.m_arr[0][1]; this->m_arr[0][2] -= mat.m_arr[0][2];
		this->m_arr[1][0] -= mat.m_arr[1][0]; this->m_arr[1][1] -= mat.m_arr[1][1]; this->m_arr[1][2] -= mat.m_arr[1][2];
		this->m_arr[2][0] -= mat.m_arr[2][0]; this->m_arr[2][1] -= mat.m_arr[2][1]; this->m_arr[2][2] -= mat.m_arr[2][2];
	}

	inline void Matrix3x3::operator+=(const Matrix3x3& mat){
		this->m_arr[0][0] += mat.m_arr[0][0]; this->m_arr[0][1] += mat.m_arr[0][1]; this->m_arr[0][2] += mat.m_arr[0][2];
		this->m_arr[1][0] += mat.m_arr[1][0]; this->m_arr[1][1] += mat.m_arr[1][1]; this->m_arr[1][2] += mat.m_arr[1][2];
		this->m_arr[2][0] += mat.m_arr[2][0]; this->m_arr[2][1] += mat.m_arr[2][1]; this->m_arr[2][2] += mat.m_arr[2][2];
	}

	// inline void Matrix3x3::operator*=(const Matrix3x3& mat){
	// 	this->m_arr[0][0] = this->m_arr[0][0] * mat.m_arr[0][0] + this->m_arr[0][1] * mat.m_arr[1][0] + this->m_arr[0][2] * mat.m_arr[2][0];
	// 	this->m_arr[0][1] = this->m_arr[0][0] * mat.m_arr[0][1] + this->m_arr[0][1] * mat.m_arr[1][1] + this->m_arr[0][2] * mat.m_arr[2][1];
	// 	this->m_arr[0][2] = this->m_arr[0][0] * mat.m_arr[0][2] + this->m_arr[0][1] * mat.m_arr[1][2] + this->m_arr[0][2] * mat.m_arr[2][2];

	// 	this->m_arr[1][0] = this->m_arr[1][0] * mat.m_arr[0][0] + this->m_arr[1][1] * mat.m_arr[1][0] + this->m_arr[1][2] * mat.m_arr[2][0];
	// 	this->m_arr[1][1] = this->m_arr[1][0] * mat.m_arr[0][1] + this->m_arr[1][1] * mat.m_arr[1][1] + this->m_arr[1][2] * mat.m_arr[2][1];
	// 	this->m_arr[1][2] = this->m_arr[1][0] * mat.m_arr[0][2] + this->m_arr[1][1] * mat.m_arr[1][2] + this->m_arr[1][2] * mat.m_arr[2][2];

	// 	this->m_arr[2][0] = this->m_arr[2][0] * mat.m_arr[0][0] + this->m_arr[2][1] * mat.m_arr[1][0] + this->m_arr[2][2] * mat.m_arr[2][0];
	// 	this->m_arr[2][1] = this->m_arr[2][0] * mat.m_arr[0][1] + this->m_arr[2][1] * mat.m_arr[1][1] + this->m_arr[2][2] * mat.m_arr[2][1];
	// 	this->m_arr[2][2] = this->m_arr[2][0] * mat.m_arr[0][2] + this->m_arr[2][1] * mat.m_arr[1][2] + this->m_arr[2][2] * mat.m_arr[2][2];
	// }

	inline void Matrix3x3::operator/=(const float& scalar){
		float divCoeff = 1 / scalar;
		this->m_arr[0][0] *= divCoeff; this->m_arr[0][1] *= divCoeff; this->m_arr[0][2] *= divCoeff;
		this->m_arr[1][0] *= divCoeff; this->m_arr[1][1] *= divCoeff; this->m_arr[1][2] *= divCoeff;
		this->m_arr[2][0] *= divCoeff; this->m_arr[2][1] *= divCoeff; this->m_arr[2][2] *= divCoeff;
	}

	inline Matrix3x3 operator-(const Matrix3x3& mat){
		return Matrix3x3(  -mat.m_arr[0][0], -mat.m_arr[0][1], -mat.m_arr[0][2],
						   -mat.m_arr[1][0], -mat.m_arr[1][1], -mat.m_arr[1][2],
						   -mat.m_arr[2][0], -mat.m_arr[2][1], -mat.m_arr[2][2] );
	}

	inline Matrix3x3 operator-(const Matrix3x3& mat1, const Matrix3x3& mat2){
		return Matrix3x3( mat1.m_arr[0][0] - mat2.m_arr[0][0], mat1.m_arr[0][1] - mat2.m_arr[0][1], mat1.m_arr[0][2] - mat2.m_arr[0][2],
						  mat1.m_arr[1][0] - mat2.m_arr[1][0], mat1.m_arr[1][1] - mat2.m_arr[1][1], mat1.m_arr[1][2] - mat2.m_arr[1][2],
						  mat1.m_arr[2][0] - mat2.m_arr[2][0], mat1.m_arr[2][1] - mat2.m_arr[2][1], mat1.m_arr[2][2] - mat2.m_arr[2][2] );
	}

	inline Matrix3x3 operator+(const Matrix3x3& mat1, const Matrix3x3& mat2){
		return Matrix3x3( mat1.m_arr[0][0] + mat2.m_arr[0][0], mat1.m_arr[0][1] + mat2.m_arr[0][1], mat1.m_arr[0][2] + mat2.m_arr[0][2],
						  mat1.m_arr[1][0] + mat2.m_arr[1][0], mat1.m_arr[1][1] + mat2.m_arr[1][1], mat1.m_arr[1][2] + mat2.m_arr[1][2],
						  mat1.m_arr[2][0] + mat2.m_arr[2][0], mat1.m_arr[2][1] + mat2.m_arr[2][1], mat1.m_arr[2][2] + mat2.m_arr[2][2] );
	}

	inline Matrix3x3 operator*(const Matrix3x3& mat1, const Matrix3x3& mat2){
		return Matrix3x3( mat1.m_arr[0][0] * mat2.m_arr[0][0] + mat1.m_arr[0][1] * mat2.m_arr[1][0] + mat1.m_arr[0][2] * mat2.m_arr[2][0],
						  mat1.m_arr[0][0] * mat2.m_arr[0][1] + mat1.m_arr[0][1] * mat2.m_arr[1][1] + mat1.m_arr[0][2] * mat2.m_arr[2][1],
						  mat1.m_arr[0][0] * mat2.m_arr[0][2] + mat1.m_arr[0][1] * mat2.m_arr[1][2] + mat1.m_arr[0][2] * mat2.m_arr[2][2],

						  mat1.m_arr[1][0] * mat2.m_arr[0][0] + mat1.m_arr[1][1] * mat2.m_arr[1][0] + mat1.m_arr[1][2] * mat2.m_arr[2][0],
						  mat1.m_arr[1][0] * mat2.m_arr[0][1] + mat1.m_arr[1][1] * mat2.m_arr[1][1] + mat1.m_arr[1][2] * mat2.m_arr[2][1],
						  mat1.m_arr[1][0] * mat2.m_arr[0][2] + mat1.m_arr[1][1] * mat2.m_arr[1][2] + mat1.m_arr[1][2] * mat2.m_arr[2][2],

						  mat1.m_arr[2][0] * mat2.m_arr[0][0] + mat1.m_arr[2][1] * mat2.m_arr[1][0] + mat1.m_arr[2][2] * mat2.m_arr[2][0],
						  mat1.m_arr[2][0] * mat2.m_arr[0][1] + mat1.m_arr[2][1] * mat2.m_arr[1][1] + mat1.m_arr[2][2] * mat2.m_arr[2][1],
						  mat1.m_arr[2][0] * mat2.m_arr[0][2] + mat1.m_arr[2][1] * mat2.m_arr[1][2] + mat1.m_arr[2][2] * mat2.m_arr[2][2] );
	}

	inline Vector3   operator*(const Matrix3x3& mat,  const Vector3& vec){
		return   Vector3( mat.m_arr[0][0] * getXComponent(vec) + mat.m_arr[0][1] * getYComponent(vec) + mat.m_arr[0][2] * getZComponent(vec),
						  mat.m_arr[1][0] * getXComponent(vec) + mat.m_arr[1][1] * getYComponent(vec) + mat.m_arr[1][2] * getZComponent(vec),
						  mat.m_arr[2][0] * getXComponent(vec) + mat.m_arr[2][1] * getYComponent(vec) + mat.m_arr[2][2] * getZComponent(vec) );
	}

	inline Matrix3x3 operator-(const Matrix3x3& mat,  const float& scalar){
		return Matrix3x3( mat.m_arr[0][0] - scalar, mat.m_arr[0][1] - scalar, mat.m_arr[0][2] - scalar,
						  mat.m_arr[1][0] - scalar, mat.m_arr[1][1] - scalar, mat.m_arr[1][2] - scalar,
						  mat.m_arr[2][0] - scalar, mat.m_arr[2][1] - scalar, mat.m_arr[2][2] - scalar );
	}

	inline Matrix3x3 operator+(const Matrix3x3& mat,  const float& scalar){
		return Matrix3x3( mat.m_arr[0][0] + scalar, mat.m_arr[0][1] + scalar, mat.m_arr[0][2] + scalar,
						  mat.m_arr[1][0] + scalar, mat.m_arr[1][1] + scalar, mat.m_arr[1][2] + scalar,
						  mat.m_arr[2][0] + scalar, mat.m_arr[2][1] + scalar, mat.m_arr[2][2] + scalar );
	}

	inline Matrix3x3 operator*(const Matrix3x3& mat,  const float& scalar){
		return Matrix3x3( mat.m_arr[0][0] * scalar, mat.m_arr[0][1] * scalar, mat.m_arr[0][2] * scalar,
						  mat.m_arr[1][0] * scalar, mat.m_arr[1][1] * scalar, mat.m_arr[1][2] * scalar,
						  mat.m_arr[2][0] * scalar, mat.m_arr[2][1] * scalar, mat.m_arr[2][2] * scalar );
	}

	inline Matrix3x3 operator/(const Matrix3x3& mat,  const float& scalar){
		float divCoeff = 1 / scalar;
		return Matrix3x3( mat.m_arr[0][0] * divCoeff, mat.m_arr[0][1] * divCoeff, mat.m_arr[0][2] * divCoeff,
						  mat.m_arr[1][0] * divCoeff, mat.m_arr[1][1] * divCoeff, mat.m_arr[1][2] * divCoeff,
						  mat.m_arr[2][0] * divCoeff, mat.m_arr[2][1] * divCoeff, mat.m_arr[2][2] * divCoeff );
	}

	inline Vector3 Matrix3x3::operator[](size_t i){
		assert(i < 3uL && "Going beyond the vector!");
		//return (*reinterpret_cast<Vector3>(this->m_arr[i]));
		return Vector3(m_arr[i][0], m_arr[i][1], m_arr[i][2]);
	}

	std::ostream& operator<<(std::ostream& out, Matrix3x3 m){
		std::cout << m.m_arr[0][0] << " | " << m.m_arr[0][1] << " | " << m.m_arr[0][2] << std::endl;
		std::cout << m.m_arr[1][0] << " | " << m.m_arr[1][1] << " | " << m.m_arr[1][2] << std::endl;
		std::cout << m.m_arr[2][0] << " | " << m.m_arr[2][1] << " | " << m.m_arr[2][2] << std::endl;
		return out;
	}
	///
	///	Declaration of Mat3x3 methods end
	///
};

#endif // FGML_MATRIX3X3_HPP_