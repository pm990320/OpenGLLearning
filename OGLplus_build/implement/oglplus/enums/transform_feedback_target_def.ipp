/*
 *  .file oglplus/enums/transform_feedback_target_def.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/transform_feedback_target.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifdef OGLPLUS_LIST_NEEDS_COMMA
# undef OGLPLUS_LIST_NEEDS_COMMA
#endif

#if defined GL_TRANSFORM_FEEDBACK
# if OGLPLUS_LIST_NEEDS_COMMA
   OGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined TransformFeedback
#  pragma push_macro("TransformFeedback")
#  undef TransformFeedback
   OGLPLUS_ENUM_CLASS_VALUE(TransformFeedback, GL_TRANSFORM_FEEDBACK)
#  pragma pop_macro("TransformFeedback")
# else
   OGLPLUS_ENUM_CLASS_VALUE(TransformFeedback, GL_TRANSFORM_FEEDBACK)
# endif
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#ifdef OGLPLUS_LIST_NEEDS_COMMA
# undef OGLPLUS_LIST_NEEDS_COMMA
#endif

