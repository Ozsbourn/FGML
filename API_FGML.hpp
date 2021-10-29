#ifndef FGML_API_FGML_HPP_
#define FGML_API_FGML_HPP_

//#define FGML_DEBUG 
#ifdef FGML_DEBUG
	#include "util.hpp"
#endif // FGML_DEBUG

#include "Constants.hpp"
#include "Macros.hpp"

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

namespace FGML {
	///
	///	FGML Type declarations
	///
	using vec2_t = FGML::Vector2;
	using vec3_t = FGML::Vector3;
	using vec4_t = FGML::Vector4;
	///
	///	FGML Type declarations end
	///
};

#endif // FGML_API_FGML_HPP_