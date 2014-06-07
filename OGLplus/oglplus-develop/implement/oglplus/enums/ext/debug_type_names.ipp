/*
 *  .file oglplus/enums/ext/debug_type_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/ext/debug_type.txt' instead.
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	DebugType*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_DEBUGTYPE)
#define OGLPLUS_IMPL_EVN_DEBUGTYPE
{
switch(value)
{
#if defined GL_DEBUG_TYPE_ERROR
	case GL_DEBUG_TYPE_ERROR: return StrLit("DEBUG_TYPE_ERROR");
#endif
#if defined GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return StrLit("DEBUG_TYPE_DEPRECATED_BEHAVIOR");
#endif
#if defined GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return StrLit("DEBUG_TYPE_UNDEFINED_BEHAVIOR");
#endif
#if defined GL_DEBUG_TYPE_PORTABILITY
	case GL_DEBUG_TYPE_PORTABILITY: return StrLit("DEBUG_TYPE_PORTABILITY");
#endif
#if defined GL_DEBUG_TYPE_PERFORMANCE
	case GL_DEBUG_TYPE_PERFORMANCE: return StrLit("DEBUG_TYPE_PERFORMANCE");
#endif
#if defined GL_DEBUG_TYPE_OTHER
	case GL_DEBUG_TYPE_OTHER: return StrLit("DEBUG_TYPE_OTHER");
#endif
#if defined GL_DEBUG_TYPE_MARKER
	case GL_DEBUG_TYPE_MARKER: return StrLit("DEBUG_TYPE_MARKER");
#endif
#if defined GL_DEBUG_TYPE_PUSH_GROUP
	case GL_DEBUG_TYPE_PUSH_GROUP: return StrLit("DEBUG_TYPE_PUSH_GROUP");
#endif
#if defined GL_DEBUG_TYPE_POP_GROUP
	case GL_DEBUG_TYPE_POP_GROUP: return StrLit("DEBUG_TYPE_POP_GROUP");
#endif
#if defined GL_DONT_CARE
	case GL_DONT_CARE: return StrLit("DONT_CARE");
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

