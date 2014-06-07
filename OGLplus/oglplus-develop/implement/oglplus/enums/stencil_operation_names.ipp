/*
 *  .file oglplus/enums/stencil_operation_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/stencil_operation.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	StencilOperation*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_STENCILOPERATION)
#define OGLPLUS_IMPL_EVN_STENCILOPERATION
{
switch(value)
{
#if defined GL_KEEP
	case GL_KEEP: return StrLit("KEEP");
#endif
#if defined GL_ZERO
	case GL_ZERO: return StrLit("ZERO");
#endif
#if defined GL_REPLACE
	case GL_REPLACE: return StrLit("REPLACE");
#endif
#if defined GL_INCR
	case GL_INCR: return StrLit("INCR");
#endif
#if defined GL_DECR
	case GL_DECR: return StrLit("DECR");
#endif
#if defined GL_INVERT
	case GL_INVERT: return StrLit("INVERT");
#endif
#if defined GL_INCR_WRAP
	case GL_INCR_WRAP: return StrLit("INCR_WRAP");
#endif
#if defined GL_DECR_WRAP
	case GL_DECR_WRAP: return StrLit("DECR_WRAP");
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

