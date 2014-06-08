/*
 *  .file oglplus/enums/ext/nv_path_format_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/ext/nv_path_format.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	PathNVFormat*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_PATHNVFORMAT)
#define OGLPLUS_IMPL_EVN_PATHNVFORMAT
{
switch(value)
{
#if defined GL_PATH_FORMAT_SVG_NV
	case GL_PATH_FORMAT_SVG_NV: return StrLit("PATH_FORMAT_SVG_NV");
#endif
#if defined GL_PATH_FORMAT_PS_NV
	case GL_PATH_FORMAT_PS_NV: return StrLit("PATH_FORMAT_PS_NV");
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

