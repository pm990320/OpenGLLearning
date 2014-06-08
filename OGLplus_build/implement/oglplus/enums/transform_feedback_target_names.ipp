/*
 *  .file oglplus/enums/transform_feedback_target_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/transform_feedback_target.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	TransformFeedbackTarget*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_TRANSFORMFEEDBACKTARGET)
#define OGLPLUS_IMPL_EVN_TRANSFORMFEEDBACKTARGET
{
switch(value)
{
#if defined GL_TRANSFORM_FEEDBACK
	case GL_TRANSFORM_FEEDBACK: return StrLit("TRANSFORM_FEEDBACK");
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

