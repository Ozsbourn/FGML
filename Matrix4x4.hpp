#include <cstddef>
#include <cassert>
#include "Vector4.hpp"

#include <iostream>

#ifndef FGML_MATRIX4x4_HPP_
#define FGML_MATRIX4X4_HPP_

namespace FGML {
	///
	///	Definition of Mat4x4 class
	///
	class Matrix4x4 {
	private:
		float m_arr[4][4];
	public:
		Matrix4x4() = default;

		explicit Matrix4x4( float v11, float v12, float v13, float v14,
							float v21, float v22, float v23, float v24,
							float v31, float v32, float v33, float v34,
							float v41, float v42, float v43, float v44 );

		explicit Matrix4x4( Vector4 vec1,
							Vector4 vec2,
							Vector4 vec3,
							Vector4 vec4 );

		inline Matrix4x4 Identity(void);

		inline void operator-=(const float& scalar);
		inline void operator+=(const float& scalar);
		inline void operator*=(const float& scalar);
		inline void operator/=(const float& scalar);

		inline void operator-=(const Matrix4x4& mat);
		inline void operator+=(const Matrix4x4& mat);
		// inline void operator*=(const Matrix4x4& mat);

		friend inline Matrix4x4 operator-(const Matrix4x4& mat);
		friend inline Matrix4x4 operator-(const Matrix4x4& mat1, const Matrix4x4& mat2);
		friend inline Matrix4x4 operator+(const Matrix4x4& mat1, const Matrix4x4& mat2);
		friend inline Matrix4x4 operator*(const Matrix4x4& mat1, const Matrix4x4& mat2);

		friend inline Vector4   operator*(const Matrix4x4& mat,  const Vector4& vec);

		friend inline Matrix4x4 operator-(const Matrix4x4& mat,  const float& scalar);
		friend inline Matrix4x4 operator+(const Matrix4x4& mat,  const float& scalar);
		friend inline Matrix4x4 operator*(const Matrix4x4& mat,  const float& scalar);
		friend inline Matrix4x4 operator/(const Matrix4x4& mat,  const float& scalar);

		inline Vector4 operator[](size_t rowNumber);

		~Matrix4x4() = default;

		friend std::ostream& operator<<(std::ostream& out, Matrix4x4 m);
	};
	///
	///	Definition of Mat4x4 class end
	///

	///
	///	Declaration of Mat4x4 methods
	///
	Matrix4x4::Matrix4x4( float v11 = 0.0f, float v12 = 0.0f, float v13 = 0.0f, float v14 = 0.0f,
						  float v21 = 0.0f, float v22 = 0.0f, float v23 = 0.0f, float v24 = 0.0f,
						  float v31 = 0.0f, float v32 = 0.0f, float v33 = 0.0f, float v34 = 0.0f,
						  float v41 = 0.0f, float v42 = 0.0f, float v43 = 0.0f, float v44 = 0.0f )
	: m_arr{ v11, v12, v13, v14,
			 v21, v22, v23, v24,
			 v31, v32, v33, v34,
			 v41, v42, v43, v44 } {}

	Matrix4x4::Matrix4x4( Vector4 vec1,
						  Vector4 vec2,
						  Vector4 vec3,
						  Vector4 vec4 ) 
	: m_arr{ getXComponent(vec1), getYComponent(vec1), getZComponent(vec1), getWComponent(vec1),
		  	 getXComponent(vec2), getYComponent(vec2), getZComponent(vec2), getWComponent(vec2),
		  	 getXComponent(vec3), getYComponent(vec3), getZComponent(vec3), getWComponent(vec3),
		  	 getXComponent(vec4), getYComponent(vec4), getZComponent(vec4), getWComponent(vec4) } {}


	inline Matrix4x4 Matrix4x4::Identity(void){
		return Matrix4x4( 1.0f, 0.0f, 0.0f, 0.0f,
						  0.0f, 1.0f, 0.0f, 0.0f,
						  0.0f, 0.0f, 1.0f, 0.0f,
						  0.0f, 0.0f, 0.0f, 1.0f );
	}

	inline void Matrix4x4::operator-=(const float& scalar){
		this->m_arr[0][0] -= scalar; this->m_arr[0][1] -= scalar; this->m_arr[0][2] -= scalar, this->m_arr[0][3] -= scalar;
		this->m_arr[1][0] -= scalar; this->m_arr[1][1] -= scalar; this->m_arr[1][2] -= scalar, this->m_arr[1][3] -= scalar;
		this->m_arr[2][0] -= scalar; this->m_arr[2][1] -= scalar; this->m_arr[2][2] -= scalar, this->m_arr[2][3] -= scalar;
		this->m_arr[3][0] -= scalar; this->m_arr[3][1] -= scalar; this->m_arr[3][2] -= scalar, this->m_arr[3][3] -= scalar;
	}

	inline void Matrix4x4::operator+=(const float& scalar){
		this->m_arr[0][0] += scalar; this->m_arr[0][1] += scalar; this->m_arr[0][2] += scalar, this->m_arr[0][3] += scalar;
		this->m_arr[1][0] += scalar; this->m_arr[1][1] += scalar; this->m_arr[1][2] += scalar, this->m_arr[1][3] += scalar;
		this->m_arr[2][0] += scalar; this->m_arr[2][1] += scalar; this->m_arr[2][2] += scalar, this->m_arr[2][3] += scalar;
		this->m_arr[3][0] += scalar; this->m_arr[3][1] += scalar; this->m_arr[3][2] += scalar, this->m_arr[3][3] += scalar;
	}

	inline void Matrix4x4::operator*=(const float& scalar){
		this->m_arr[0][0] *= scalar; this->m_arr[0][1] *= scalar; this->m_arr[0][2] *= scalar, this->m_arr[0][3] *= scalar;
		this->m_arr[1][0] *= scalar; this->m_arr[1][1] *= scalar; this->m_arr[1][2] *= scalar, this->m_arr[1][3] *= scalar;
		this->m_arr[2][0] *= scalar; this->m_arr[2][1] *= scalar; this->m_arr[2][2] *= scalar, this->m_arr[2][3] *= scalar;
		this->m_arr[3][0] *= scalar; this->m_arr[3][1] *= scalar; this->m_arr[3][2] *= scalar, this->m_arr[3][3] *= scalar;
	}

	inline void Matrix4x4::operator/=(const float& scalar){
		float divCoeff = 1 / scalar;
		this->m_arr[0][0] *= divCoeff; this->m_arr[0][1] *= divCoeff; this->m_arr[0][2] *= divCoeff, this->m_arr[0][3] *= divCoeff;
		this->m_arr[1][0] *= divCoeff; this->m_arr[1][1] *= divCoeff; this->m_arr[1][2] *= divCoeff, this->m_arr[1][3] *= divCoeff;
		this->m_arr[2][0] *= divCoeff; this->m_arr[2][1] *= divCoeff; this->m_arr[2][2] *= divCoeff, this->m_arr[2][3] *= divCoeff;
		this->m_arr[3][0] *= divCoeff; this->m_arr[3][1] *= divCoeff; this->m_arr[3][2] *= divCoeff, this->m_arr[3][3] *= divCoeff;
	}

	inline void Matrix4x4::operator-=(const Matrix4x4& mat){
		this->m_arr[0][0] -= mat.m_arr[0][0]; this->m_arr[0][1] -= mat.m_arr[0][1]; this->m_arr[0][2] -= mat.m_arr[0][2], this->m_arr[0][3] -= mat.m_arr[0][3];
		this->m_arr[1][0] -= mat.m_arr[1][0]; this->m_arr[1][1] -= mat.m_arr[1][1]; this->m_arr[1][2] -= mat.m_arr[1][2], this->m_arr[1][3] -= mat.m_arr[1][3];
		this->m_arr[2][0] -= mat.m_arr[2][0]; this->m_arr[2][1] -= mat.m_arr[2][1]; this->m_arr[2][2] -= mat.m_arr[2][2], this->m_arr[2][3] -= mat.m_arr[2][3];
		this->m_arr[3][0] -= mat.m_arr[3][0]; this->m_arr[3][1] -= mat.m_arr[3][1]; this->m_arr[3][2] -= mat.m_arr[3][2], this->m_arr[3][3] -= mat.m_arr[3][3];
	}

	inline void Matrix4x4::operator+=(const Matrix4x4& mat){
		this->m_arr[0][0] += mat.m_arr[0][0]; this->m_arr[0][1] += mat.m_arr[0][1]; this->m_arr[0][2] += mat.m_arr[0][2], this->m_arr[0][3] += mat.m_arr[0][3];
		this->m_arr[1][0] += mat.m_arr[1][0]; this->m_arr[1][1] += mat.m_arr[1][1]; this->m_arr[1][2] += mat.m_arr[1][2], this->m_arr[1][3] += mat.m_arr[1][3];
		this->m_arr[2][0] += mat.m_arr[2][0]; this->m_arr[2][1] += mat.m_arr[2][1]; this->m_arr[2][2] += mat.m_arr[2][2], this->m_arr[2][3] += mat.m_arr[2][3];
		this->m_arr[3][0] += mat.m_arr[3][0]; this->m_arr[3][1] += mat.m_arr[3][1]; this->m_arr[3][2] += mat.m_arr[3][2], this->m_arr[3][3] += mat.m_arr[3][3];
	}

	// inline void Matrix4x4::operator*=(const Matrix4x4& mat){
	// 	this->m_arr[0][0] = this->m_arr[0][0] * mat.m_arr[0][0] + this->m_arr[0][1] * mat.m_arr[1][0] + this->m_arr[0][2] * mat.m_arr[2][0] + this->m_arr[0][3] * mat.m_arr[3][0];
	// 	this->m_arr[0][1] = this->m_arr[0][0] * mat.m_arr[0][1] + this->m_arr[0][1] * mat.m_arr[1][1] + this->m_arr[0][2] * mat.m_arr[2][1] + this->m_arr[0][3] * mat.m_arr[3][1];
	// 	this->m_arr[0][2] = this->m_arr[0][0] * mat.m_arr[0][2] + this->m_arr[0][1] * mat.m_arr[1][2] + this->m_arr[0][2] * mat.m_arr[2][2] + this->m_arr[0][3] * mat.m_arr[3][2];
	// 	this->m_arr[0][3] = this->m_arr[0][0] * mat.m_arr[0][3] + this->m_arr[0][1] * mat.m_arr[1][3] + this->m_arr[0][2] * mat.m_arr[2][3] + this->m_arr[0][3] * mat.m_arr[3][3];

	// 	this->m_arr[1][0] = this->m_arr[1][0] * mat.m_arr[0][0] + this->m_arr[1][1] * mat.m_arr[1][0] + this->m_arr[1][2] * mat.m_arr[2][0] + this->m_arr[1][3] * mat.m_arr[3][0];
	// 	this->m_arr[1][1] = this->m_arr[1][0] * mat.m_arr[0][1] + this->m_arr[1][1] * mat.m_arr[1][1] + this->m_arr[1][2] * mat.m_arr[2][1] + this->m_arr[1][3] * mat.m_arr[3][1];
	// 	this->m_arr[1][2] = this->m_arr[1][0] * mat.m_arr[0][2] + this->m_arr[1][1] * mat.m_arr[1][2] + this->m_arr[1][2] * mat.m_arr[2][2] + this->m_arr[1][3] * mat.m_arr[3][2];
	// 	this->m_arr[1][3] = this->m_arr[1][0] * mat.m_arr[0][3] + this->m_arr[1][1] * mat.m_arr[1][3] + this->m_arr[1][2] * mat.m_arr[2][3] + this->m_arr[1][3] * mat.m_arr[3][3];

	// 	this->m_arr[2][0] = this->m_arr[2][0] * mat.m_arr[0][0] + this->m_arr[2][1] * mat.m_arr[1][0] + this->m_arr[2][2] * mat.m_arr[2][0] + this->m_arr[2][3] * mat.m_arr[3][0];
	// 	this->m_arr[2][1] = this->m_arr[2][0] * mat.m_arr[0][1] + this->m_arr[2][1] * mat.m_arr[1][1] + this->m_arr[2][2] * mat.m_arr[2][1] + this->m_arr[2][3] * mat.m_arr[3][1];
	// 	this->m_arr[2][2] = this->m_arr[2][0] * mat.m_arr[0][2] + this->m_arr[2][1] * mat.m_arr[1][2] + this->m_arr[2][2] * mat.m_arr[2][2] + this->m_arr[2][3] * mat.m_arr[3][2];
	// 	this->m_arr[2][3] = this->m_arr[2][0] * mat.m_arr[0][3] + this->m_arr[2][1] * mat.m_arr[1][3] + this->m_arr[2][2] * mat.m_arr[2][3] + this->m_arr[2][3] * mat.m_arr[3][3];

	// 	this->m_arr[3][0] = this->m_arr[3][0] * mat.m_arr[0][0] + this->m_arr[3][1] * mat.m_arr[1][0] + this->m_arr[3][2] * mat.m_arr[2][0] + this->m_arr[3][3] * mat.m_arr[3][0];
	// 	this->m_arr[3][1] = this->m_arr[3][0] * mat.m_arr[0][1] + this->m_arr[3][1] * mat.m_arr[1][1] + this->m_arr[3][2] * mat.m_arr[2][1] + this->m_arr[3][3] * mat.m_arr[3][1];
	// 	this->m_arr[3][2] = this->m_arr[3][0] * mat.m_arr[0][2] + this->m_arr[3][1] * mat.m_arr[1][2] + this->m_arr[3][2] * mat.m_arr[2][2] + this->m_arr[3][3] * mat.m_arr[3][2];
	// 	this->m_arr[3][3] = this->m_arr[3][0] * mat.m_arr[0][3] + this->m_arr[3][1] * mat.m_arr[1][3] + this->m_arr[3][2] * mat.m_arr[2][3] + this->m_arr[3][3] * mat.m_arr[3][3];
	// }

	inline Matrix4x4 operator-(const Matrix4x4& mat){
		return Matrix4x4( -mat.m_arr[0][0], -mat.m_arr[0][1], -mat.m_arr[0][2], -mat.m_arr[0][3],
						  -mat.m_arr[1][0], -mat.m_arr[1][1], -mat.m_arr[1][2], -mat.m_arr[1][3],
						  -mat.m_arr[2][0], -mat.m_arr[2][1], -mat.m_arr[2][2], -mat.m_arr[2][3],
						  -mat.m_arr[3][0], -mat.m_arr[3][1], -mat.m_arr[3][2], -mat.m_arr[3][3] );
	}

	inline Matrix4x4 operator-(const Matrix4x4& mat1, const Matrix4x4& mat2){
		return Matrix4x4( mat1.m_arr[0][0] - mat2.m_arr[0][0], mat1.m_arr[0][1] - mat2.m_arr[0][1], mat1.m_arr[0][2] - mat2.m_arr[0][2], mat1.m_arr[0][3] - mat2.m_arr[0][3],
						  mat1.m_arr[1][0] - mat2.m_arr[1][0], mat1.m_arr[1][1] - mat2.m_arr[1][1], mat1.m_arr[1][2] - mat2.m_arr[1][2], mat1.m_arr[1][3] - mat2.m_arr[1][3],
						  mat1.m_arr[2][0] - mat2.m_arr[2][0], mat1.m_arr[2][1] - mat2.m_arr[2][1], mat1.m_arr[2][2] - mat2.m_arr[2][2], mat1.m_arr[2][3] - mat2.m_arr[2][3],
						  mat1.m_arr[3][0] - mat2.m_arr[3][0], mat1.m_arr[3][1] - mat2.m_arr[3][1], mat1.m_arr[3][2] - mat2.m_arr[3][2], mat1.m_arr[3][3] - mat2.m_arr[3][3] );
	}

	inline Matrix4x4 operator+(const Matrix4x4& mat1, const Matrix4x4& mat2){
		return Matrix4x4( mat1.m_arr[0][0] + mat2.m_arr[0][0], mat1.m_arr[0][1] + mat2.m_arr[0][1], mat1.m_arr[0][2] + mat2.m_arr[0][2], mat1.m_arr[0][3] + mat2.m_arr[0][3],
						  mat1.m_arr[1][0] + mat2.m_arr[1][0], mat1.m_arr[1][1] + mat2.m_arr[1][1], mat1.m_arr[1][2] + mat2.m_arr[1][2], mat1.m_arr[1][3] + mat2.m_arr[1][3],
						  mat1.m_arr[2][0] + mat2.m_arr[2][0], mat1.m_arr[2][1] + mat2.m_arr[2][1], mat1.m_arr[2][2] + mat2.m_arr[2][2], mat1.m_arr[2][3] + mat2.m_arr[2][3],
						  mat1.m_arr[3][0] + mat2.m_arr[3][0], mat1.m_arr[3][1] + mat2.m_arr[3][1], mat1.m_arr[3][2] + mat2.m_arr[3][2], mat1.m_arr[3][3] + mat2.m_arr[3][3] );
	}

	inline Matrix4x4 operator*(const Matrix4x4& mat1, const Matrix4x4& mat2){
		return Matrix4x4( mat1.m_arr[0][0] * mat2.m_arr[0][0] + mat1.m_arr[0][1] * mat2.m_arr[1][0] + mat1.m_arr[0][2] * mat2.m_arr[2][0],
						  mat1.m_arr[0][0] * mat2.m_arr[0][1] + mat1.m_arr[0][1] * mat2.m_arr[1][1] + mat1.m_arr[0][2] * mat2.m_arr[2][1],
						  mat1.m_arr[0][0] * mat2.m_arr[0][2] + mat1.m_arr[0][1] * mat2.m_arr[1][2] + mat1.m_arr[0][2] * mat2.m_arr[2][2],
						  mat1.m_arr[0][0] * mat2.m_arr[0][3] + mat1.m_arr[0][1] * mat2.m_arr[1][3] + mat1.m_arr[0][2] * mat2.m_arr[2][3],

						  mat1.m_arr[1][0] * mat2.m_arr[0][0] + mat1.m_arr[1][1] * mat2.m_arr[1][0] + mat1.m_arr[1][2] * mat2.m_arr[2][0],
						  mat1.m_arr[1][0] * mat2.m_arr[0][1] + mat1.m_arr[1][1] * mat2.m_arr[1][1] + mat1.m_arr[1][2] * mat2.m_arr[2][1],
						  mat1.m_arr[1][0] * mat2.m_arr[0][2] + mat1.m_arr[1][1] * mat2.m_arr[1][2] + mat1.m_arr[1][2] * mat2.m_arr[2][2],
						  mat1.m_arr[1][0] * mat2.m_arr[0][3] + mat1.m_arr[1][1] * mat2.m_arr[1][3] + mat1.m_arr[1][2] * mat2.m_arr[2][3],

						  mat1.m_arr[2][0] * mat2.m_arr[0][0] + mat1.m_arr[2][1] * mat2.m_arr[1][0] + mat1.m_arr[2][2] * mat2.m_arr[2][0],
						  mat1.m_arr[2][0] * mat2.m_arr[0][1] + mat1.m_arr[2][1] * mat2.m_arr[1][1] + mat1.m_arr[2][2] * mat2.m_arr[2][1],
						  mat1.m_arr[2][0] * mat2.m_arr[0][2] + mat1.m_arr[2][1] * mat2.m_arr[1][2] + mat1.m_arr[2][2] * mat2.m_arr[2][2],
						  mat1.m_arr[2][0] * mat2.m_arr[0][3] + mat1.m_arr[2][1] * mat2.m_arr[1][3] + mat1.m_arr[2][2] * mat2.m_arr[2][3],

						  mat1.m_arr[3][0] * mat2.m_arr[0][0] + mat1.m_arr[3][1] * mat2.m_arr[1][0] + mat1.m_arr[3][2] * mat2.m_arr[2][0],
						  mat1.m_arr[3][0] * mat2.m_arr[0][1] + mat1.m_arr[3][1] * mat2.m_arr[1][1] + mat1.m_arr[3][2] * mat2.m_arr[2][1],
						  mat1.m_arr[3][0] * mat2.m_arr[0][2] + mat1.m_arr[3][1] * mat2.m_arr[1][2] + mat1.m_arr[3][2] * mat2.m_arr[2][2],
						  mat1.m_arr[3][0] * mat2.m_arr[0][3] + mat1.m_arr[3][1] * mat2.m_arr[1][3] + mat1.m_arr[3][2] * mat2.m_arr[2][3] );
	}

	inline Vector4   operator*(const Matrix4x4& mat,  const Vector4& vec){
		return   Vector4( mat.m_arr[0][0] * getXComponent(vec) + mat.m_arr[0][1] * getYComponent(vec) + mat.m_arr[0][2] * getZComponent(vec) + mat.m_arr[0][3] * getWComponent(vec),
						  mat.m_arr[1][0] * getXComponent(vec) + mat.m_arr[1][1] * getYComponent(vec) + mat.m_arr[1][2] * getZComponent(vec) + mat.m_arr[1][3] * getWComponent(vec),
						  mat.m_arr[2][0] * getXComponent(vec) + mat.m_arr[2][1] * getYComponent(vec) + mat.m_arr[2][2] * getZComponent(vec) + mat.m_arr[2][3] * getWComponent(vec),
						  mat.m_arr[3][0] * getXComponent(vec) + mat.m_arr[3][1] * getYComponent(vec) + mat.m_arr[3][2] * getZComponent(vec) + mat.m_arr[3][3] * getWComponent(vec) );
	}

	inline Matrix4x4 operator-(const Matrix4x4& mat,  const float& scalar){
		return Matrix4x4( mat.m_arr[0][0] - scalar, mat.m_arr[0][1] - scalar, mat.m_arr[0][2] - scalar, mat.m_arr[0][3] - scalar,
						  mat.m_arr[1][0] - scalar, mat.m_arr[1][1] - scalar, mat.m_arr[1][2] - scalar, mat.m_arr[1][3] - scalar,
						  mat.m_arr[2][0] - scalar, mat.m_arr[2][1] - scalar, mat.m_arr[2][2] - scalar, mat.m_arr[2][3] - scalar,
						  mat.m_arr[3][0] - scalar, mat.m_arr[3][1] - scalar, mat.m_arr[3][2] - scalar, mat.m_arr[3][3] - scalar );
	}

	inline Matrix4x4 operator+(const Matrix4x4& mat,  const float& scalar){
		return Matrix4x4( mat.m_arr[0][0] + scalar, mat.m_arr[0][1] + scalar, mat.m_arr[0][2] + scalar, mat.m_arr[0][3] + scalar,
						  mat.m_arr[1][0] + scalar, mat.m_arr[1][1] + scalar, mat.m_arr[1][2] + scalar, mat.m_arr[1][3] + scalar,
						  mat.m_arr[2][0] + scalar, mat.m_arr[2][1] + scalar, mat.m_arr[2][2] + scalar, mat.m_arr[2][3] + scalar,
						  mat.m_arr[3][0] + scalar, mat.m_arr[3][1] + scalar, mat.m_arr[3][2] + scalar, mat.m_arr[3][3] + scalar );
	}

	inline Matrix4x4 operator*(const Matrix4x4& mat,  const float& scalar){
		return Matrix4x4( mat.m_arr[0][0] * scalar, mat.m_arr[0][1] * scalar, mat.m_arr[0][2] * scalar, mat.m_arr[0][3] * scalar,
						  mat.m_arr[1][0] * scalar, mat.m_arr[1][1] * scalar, mat.m_arr[1][2] * scalar, mat.m_arr[1][3] * scalar,
						  mat.m_arr[2][0] * scalar, mat.m_arr[2][1] * scalar, mat.m_arr[2][2] * scalar, mat.m_arr[2][3] * scalar,
						  mat.m_arr[3][0] * scalar, mat.m_arr[3][1] * scalar, mat.m_arr[3][2] * scalar, mat.m_arr[3][3] * scalar );
	}

	inline Matrix4x4 operator/(const Matrix4x4& mat,  const float& scalar){
		float divCoeff = 1 / scalar;
		return Matrix4x4( mat.m_arr[0][0] * divCoeff, mat.m_arr[0][1] * divCoeff, mat.m_arr[0][2] * divCoeff, mat.m_arr[0][3] * divCoeff,
						  mat.m_arr[1][0] * divCoeff, mat.m_arr[1][1] * divCoeff, mat.m_arr[1][2] * divCoeff, mat.m_arr[1][3] * divCoeff,
						  mat.m_arr[2][0] * divCoeff, mat.m_arr[2][1] * divCoeff, mat.m_arr[2][2] * divCoeff, mat.m_arr[2][3] * divCoeff,
						  mat.m_arr[3][0] * divCoeff, mat.m_arr[3][1] * divCoeff, mat.m_arr[3][2] * divCoeff, mat.m_arr[3][3] * divCoeff );
	}

	inline Vector4 Matrix4x4::operator[](size_t i){
		assert(i < 4uL && "Going beyond the vector!");
		//return (*reinterpret_cast<Vector4>(this->m_arr[i]));
		return Vector4(m_arr[i][0], m_arr[i][1], m_arr[i][2], m_arr[i][3]);
	}

	std::ostream& operator<<(std::ostream& out, Matrix4x4 m){
		std::cout << m.m_arr[0][0] << " | " << m.m_arr[0][1] << " | " << m.m_arr[0][2] << " | " << m.m_arr[0][3] << std::endl;
		std::cout << m.m_arr[1][0] << " | " << m.m_arr[1][1] << " | " << m.m_arr[1][2] << " | " << m.m_arr[1][3] << std::endl;
		std::cout << m.m_arr[2][0] << " | " << m.m_arr[2][1] << " | " << m.m_arr[2][2] << " | " << m.m_arr[2][3] << std::endl;
		std::cout << m.m_arr[3][0] << " | " << m.m_arr[3][1] << " | " << m.m_arr[3][2] << " | " << m.m_arr[3][3] << std::endl;
		return out;
	}
	///
	///	Declaration of Mat4x4 methods end
	///
};

#endif // FGML_MATRIX4x4_HPP_