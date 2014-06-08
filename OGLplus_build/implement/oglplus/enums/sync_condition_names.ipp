/*
 *  .file oglplus/enums/sync_condition_names.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/sync_condition.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
OGLPLUS_LIB_FUNC StrLit ValueName_(
	SyncCondition*,
	GLenum value
)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVN_SYNCCONDITION)
#define OGLPLUS_IMPL_EVN_SYNCCONDITION
{
switch(value)
{
#if defined GL_SYNC_GPU_COMMANDS_COMPLETE
	case GL_SYNC_GPU_COMMANDS_COMPLETE: return StrLit("SYNC_GPU_COMMANDS_COMPLETE");
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

