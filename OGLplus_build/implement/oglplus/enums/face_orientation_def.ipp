/*
 *  .file oglplus/enums/face_orientation_def.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/face_orientation.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifdef OGLPLUS_LIST_NEEDS_COMMA
# undef OGLPLUS_LIST_NEEDS_COMMA
#endif

#if defined GL_CW
# if OGLPLUS_LIST_NEEDS_COMMA
   OGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined CW
#  pragma push_macro("CW")
#  undef CW
   OGLPLUS_ENUM_CLASS_VALUE(CW, GL_CW)
#  pragma pop_macro("CW")
# else
   OGLPLUS_ENUM_CLASS_VALUE(CW, GL_CW)
# endif
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined GL_CCW
# if OGLPLUS_LIST_NEEDS_COMMA
   OGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined CCW
#  pragma push_macro("CCW")
#  undef CCW
   OGLPLUS_ENUM_CLASS_VALUE(CCW, GL_CCW)
#  pragma pop_macro("CCW")
# else
   OGLPLUS_ENUM_CLASS_VALUE(CCW, GL_CCW)
# endif
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#ifdef OGLPLUS_LIST_NEEDS_COMMA
# undef OGLPLUS_LIST_NEEDS_COMMA
#endif

