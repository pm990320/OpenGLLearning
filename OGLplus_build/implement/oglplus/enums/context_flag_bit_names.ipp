/*
 *  .file oglplus/enums/context_flag_bit_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/context_flag_bit.txt' instead.
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	ContextFlagBit*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_CONTEXTFLAGBIT)
#define OGLPLUS_IMPL_EVN_CONTEXTFLAGBIT
{
switch(value)
{
#if defined GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
	case GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT: return StrLit("CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT");
#endif
#if defined GL_CONTEXT_FLAG_DEBUG_BIT
	case GL_CONTEXT_FLAG_DEBUG_BIT: return StrLit("CONTEXT_FLAG_DEBUG_BIT");
#endif
#if defined GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
	case GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB: return StrLit("CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB");
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

