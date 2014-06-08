/*
 *  .file oglplus/enums/ext/nv_path_metric_query_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/ext/nv_path_metric_query.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	PathNVMetricQuery*,
	GLbitfield value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_PATHNVMETRICQUERY)
#define OGLPLUS_IMPL_EVN_PATHNVMETRICQUERY
{
switch(value)
{
#if defined GL_GLYPH_WIDTH_BIT_NV
	case GL_GLYPH_WIDTH_BIT_NV: return StrLit("GLYPH_WIDTH_BIT_NV");
#endif
#if defined GL_GLYPH_HEIGHT_BIT_NV
	case GL_GLYPH_HEIGHT_BIT_NV: return StrLit("GLYPH_HEIGHT_BIT_NV");
#endif
#if defined GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV
	case GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV: return StrLit("GLYPH_HORIZONTAL_BEARING_X_BIT_NV");
#endif
#if defined GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV
	case GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV: return StrLit("GLYPH_HORIZONTAL_BEARING_Y_BIT_NV");
#endif
#if defined GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV
	case GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV: return StrLit("GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV");
#endif
#if defined GL_GLYPH_VERTICAL_BEARING_X_BIT_NV
	case GL_GLYPH_VERTICAL_BEARING_X_BIT_NV: return StrLit("GLYPH_VERTICAL_BEARING_X_BIT_NV");
#endif
#if defined GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV
	case GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV: return StrLit("GLYPH_VERTICAL_BEARING_Y_BIT_NV");
#endif
#if defined GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV
	case GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV: return StrLit("GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV");
#endif
#if defined GL_GLYPH_HAS_KERNING_BIT_NV
	case GL_GLYPH_HAS_KERNING_BIT_NV: return StrLit("GLYPH_HAS_KERNING_BIT_NV");
#endif
#if defined GL_FONT_X_MIN_BOUNDS_BIT_NV
	case GL_FONT_X_MIN_BOUNDS_BIT_NV: return StrLit("FONT_X_MIN_BOUNDS_BIT_NV");
#endif
#if defined GL_FONT_Y_MIN_BOUNDS_BIT_NV
	case GL_FONT_Y_MIN_BOUNDS_BIT_NV: return StrLit("FONT_Y_MIN_BOUNDS_BIT_NV");
#endif
#if defined GL_FONT_X_MAX_BOUNDS_BIT_NV
	case GL_FONT_X_MAX_BOUNDS_BIT_NV: return StrLit("FONT_X_MAX_BOUNDS_BIT_NV");
#endif
#if defined GL_FONT_Y_MAX_BOUNDS_BIT_NV
	case GL_FONT_Y_MAX_BOUNDS_BIT_NV: return StrLit("FONT_Y_MAX_BOUNDS_BIT_NV");
#endif
#if defined GL_FONT_UNITS_PER_EM_BIT_NV
	case GL_FONT_UNITS_PER_EM_BIT_NV: return StrLit("FONT_UNITS_PER_EM_BIT_NV");
#endif
#if defined GL_FONT_ASCENDER_BIT_NV
	case GL_FONT_ASCENDER_BIT_NV: return StrLit("FONT_ASCENDER_BIT_NV");
#endif
#if defined GL_FONT_DESCENDER_BIT_NV
	case GL_FONT_DESCENDER_BIT_NV: return StrLit("FONT_DESCENDER_BIT_NV");
#endif
#if defined GL_FONT_HEIGHT_BIT_NV
	case GL_FONT_HEIGHT_BIT_NV: return StrLit("FONT_HEIGHT_BIT_NV");
#endif
#if defined GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV
	case GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV: return StrLit("FONT_MAX_ADVANCE_WIDTH_BIT_NV");
#endif
#if defined GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV
	case GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV: return StrLit("FONT_MAX_ADVANCE_HEIGHT_BIT_NV");
#endif
#if defined GL_FONT_UNDERLINE_POSITION_BIT_NV
	case GL_FONT_UNDERLINE_POSITION_BIT_NV: return StrLit("FONT_UNDERLINE_POSITION_BIT_NV");
#endif
#if defined GL_FONT_UNDERLINE_THICKNESS_BIT_NV
	case GL_FONT_UNDERLINE_THICKNESS_BIT_NV: return StrLit("FONT_UNDERLINE_THICKNESS_BIT_NV");
#endif
#if defined GL_FONT_HAS_KERNING_BIT_NV
	case GL_FONT_HAS_KERNING_BIT_NV: return StrLit("FONT_HAS_KERNING_BIT_NV");
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

