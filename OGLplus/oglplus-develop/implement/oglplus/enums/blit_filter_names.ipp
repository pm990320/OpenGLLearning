/*
 *  .file oglplus/enums/blit_filter_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/blit_filter.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	BlitFilter*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_BLITFILTER)
#define OGLPLUS_IMPL_EVN_BLITFILTER
{
switch(value)
{
#if defined GL_NEAREST
	case GL_NEAREST: return StrLit("NEAREST");
#endif
#if defined GL_LINEAR
	case GL_LINEAR: return StrLit("LINEAR");
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

