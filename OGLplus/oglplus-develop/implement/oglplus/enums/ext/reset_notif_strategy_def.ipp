/*
 *  .file oglplus/enums/ext/reset_notif_strategy_def.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/ext/reset_notif_strategy.txt' instead.
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifdef OGLPLUS_LIST_NEEDS_COMMA
# undef OGLPLUS_LIST_NEEDS_COMMA
#endif

#if defined GL_NO_RESET_NOTIFICATION_ARB
# if OGLPLUS_LIST_NEEDS_COMMA
   OGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined NoResetNotification
#  pragma push_macro("NoResetNotification")
#  undef NoResetNotification
   OGLPLUS_ENUM_CLASS_VALUE(NoResetNotification, GL_NO_RESET_NOTIFICATION_ARB)
#  pragma pop_macro("NoResetNotification")
# else
   OGLPLUS_ENUM_CLASS_VALUE(NoResetNotification, GL_NO_RESET_NOTIFICATION_ARB)
# endif
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined GL_LOSE_CONTEXT_ON_RESET_ARB
# if OGLPLUS_LIST_NEEDS_COMMA
   OGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined LoseContextOnReset
#  pragma push_macro("LoseContextOnReset")
#  undef LoseContextOnReset
   OGLPLUS_ENUM_CLASS_VALUE(LoseContextOnReset, GL_LOSE_CONTEXT_ON_RESET_ARB)
#  pragma pop_macro("LoseContextOnReset")
# else
   OGLPLUS_ENUM_CLASS_VALUE(LoseContextOnReset, GL_LOSE_CONTEXT_ON_RESET_ARB)
# endif
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#ifdef OGLPLUS_LIST_NEEDS_COMMA
# undef OGLPLUS_LIST_NEEDS_COMMA
#endif

