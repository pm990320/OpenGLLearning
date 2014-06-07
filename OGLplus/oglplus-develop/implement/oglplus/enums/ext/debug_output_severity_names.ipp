/*
 *  .file oglplus/enums/ext/debug_output_severity_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/ext/debug_output_severity.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	DebugOutputARBSeverity*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_DEBUGOUTPUTARBSEVERITY)
#define OGLPLUS_IMPL_EVN_DEBUGOUTPUTARBSEVERITY
{
switch(value)
{
#if defined GL_DEBUG_SEVERITY_HIGH_ARB
	case GL_DEBUG_SEVERITY_HIGH_ARB: return StrLit("DEBUG_SEVERITY_HIGH_ARB");
#endif
#if defined GL_DEBUG_SEVERITY_MEDIUM_ARB
	case GL_DEBUG_SEVERITY_MEDIUM_ARB: return StrLit("DEBUG_SEVERITY_MEDIUM_ARB");
#endif
#if defined GL_DEBUG_SEVERITY_LOW_ARB
	case GL_DEBUG_SEVERITY_LOW_ARB: return StrLit("DEBUG_SEVERITY_LOW_ARB");
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

