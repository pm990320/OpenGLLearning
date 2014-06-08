/*
 *  .file oglplus/enums/ext/nv_path_dash_offset_reset_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/ext/nv_path_dash_offset_reset.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	PathNVDashOffsetReset*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_PATHNVDASHOFFSETRESET)
#define OGLPLUS_IMPL_EVN_PATHNVDASHOFFSETRESET
{
switch(value)
{
#if defined GL_MOVE_TO_RESET_NV
	case GL_MOVE_TO_RESET_NV: return StrLit("MOVE_TO_RESET_NV");
#endif
#if defined GL_MOVE_TO_CONTINUES_NV
	case GL_MOVE_TO_CONTINUES_NV: return StrLit("MOVE_TO_CONTINUES_NV");
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

