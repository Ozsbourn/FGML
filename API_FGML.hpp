#ifndef FGML_API_FGML_HPP_
#define FGML_API_FGML_HPP_

#include <cstddef>
#include <cassert>
#include <cmath>

#include "Constants.hpp"
#include "Macros.hpp"

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#include "Matrix3x3.hpp"
#include "Matrix4x4.hpp"

namespace FGML {
	///
	///	FGML Type declarations
	///
	using vec2_t = Vector2;
	using vec3_t = Vector3;
	using vec4_t = Vector4;

	using mat3_t = Matrix3x3;
	using mat4_t = Matrix4x4;
	///
	///	FGML Type declarations end
	///
};

#endif // FGML_API_FGML_HPP_