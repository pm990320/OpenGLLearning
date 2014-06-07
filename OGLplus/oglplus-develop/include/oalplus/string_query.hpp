/**
 *  @file oalplus/string_query.hpp
 *  @brief OpenAL string query enumeration
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OALPLUS_STRING_QUERY_1303292057_HPP
#define OALPLUS_STRING_QUERY_1303292057_HPP

#include <oalplus/enumerations.hpp>

namespace oalplus {

/// OpenAL string query enumeration
/**
 *  @ingroup enumerations
 */
OALPLUS_ENUM_CLASS_BEGIN(StringQuery, ALenum)
#include <oalplus/enums/string_query.ipp>
OALPLUS_ENUM_CLASS_END(StringQuery)

#if !OALPLUS_NO_ENUM_VALUE_NAMES
#include <oalplus/enums/string_query_names.ipp>
#endif

#if !OALPLUS_ENUM_VALUE_RANGES
#include <oalplus/enums/string_query_range.ipp>
#endif

} // namespace oglplus

#endif // include guard
