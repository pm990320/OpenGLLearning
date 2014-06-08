/*
 *  .file oglplus/enums/transform_feedback_primitive_type_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/transform_feedback_primitive_type.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	TransformFeedbackPrimitiveType*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_TRANSFORMFEEDBACKPRIMITIVETYPE)
#define OGLPLUS_IMPL_EVN_TRANSFORMFEEDBACKPRIMITIVETYPE
{
switch(value)
{
#if defined GL_TRIANGLES
	case GL_TRIANGLES: return StrLit("TRIANGLES");
#endif
#if defined GL_LINES
	case GL_LINES: return StrLit("LINES");
#endif
#if defined GL_POINTS
	case GL_POINTS: return StrLit("POINTS");
#endif
	default:;
}
OGLPLUS_FAKE_USE(value);
return StrLit();
}
#else
;
#endif
} // namespace enums

