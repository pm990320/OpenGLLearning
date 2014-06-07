/**
 *  @file oglplus/limited_value.hpp
 *  @brief Generic OpenGL implementation-dependend limited value wrapper
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OGLPLUS_LIMITED_VALUE_1107121519_HPP
#define OGLPLUS_LIMITED_VALUE_1107121519_HPP

#include <oglplus/glfunc.hpp>
#include <oglplus/error/limit.hpp>
#include <cassert>

namespace oglplus {

template <GLenum Query>
class LimitedCount;

template <GLenum Query>
GLuint LimitedCountMax(const LimitedCount<Query>& lim_count);

/// Base class for limited implementation-dependent numeric values
/** This class checks if the given unsigned int value is in the
 *  implementation-dependent range of allowed valued and throws
 *  an @c LimitError exception if it is not.
 *
 *  @note Do not use this templates directly, use the derived types
 *  or the typedefs of instantiations instead.
 *
 *  @ingroup utility_classes
 */
template <GLenum Query>
class LimitedCount
{
private:
	GLuint _value;

	static GLuint _query_limit(void)
	{
		GLint limit = 0;
		OGLPLUS_GLFUNC(GetIntegerv)(Query, &limit);
		OGLPLUS_VERIFY_SIMPLE(GetIntegerv);
		return GLuint(limit);
	}

	static GLuint _limit(void)
	{
		static GLuint limit = _query_limit();
		return limit;
	}
protected:
	/**
	 *  @throws Error
	 *  @throws LimitError
	 */
	LimitedCount(GLuint value, const char* query_name)
	 : _value(value)
	{
		OGLPLUS_HANDLE_ERROR_IF(
			_value >= _limit(),
			GL_INVALID_VALUE,
			LimitError::Message(),
			LimitError,
			Value(_value).
			Limit(_limit()).
			EnumParam(Query, query_name)
		);
	}
public:

	LimitedCount& operator = (const LimitedCount& other)
	{
		_value = other._value;
		assert(_value < _limit());
		return *this;
	}

#if OGLPLUS_DOCUMENTATION_ONLY
	/// Returns the value
	template <typename Type>
	explicit operator Type(void) const;
#endif

	template <typename Type>
#if !OGLPLUS_NO_EXPLICIT_CONVERSION_OPERATORS
	explicit operator Type(void) const
#else
	operator Type(void) const
#endif
	{
		return Type(_value);
	}

	friend GLuint LimitedCountMax<Query>(const LimitedCount&);

	friend bool operator == (LimitedCount a, LimitedCount b)
	{
		return a._value == b._value;
	}

	friend bool operator != (LimitedCount a, LimitedCount b)
	{
		return a._value != b._value;
	}

	friend bool operator <= (LimitedCount a, LimitedCount b)
	{
		return a._value <= b._value;
	}

	friend bool operator <  (LimitedCount a, LimitedCount b)
	{
		return a._value <  b._value;
	}

	friend bool operator >= (LimitedCount a, LimitedCount b)
	{
		return a._value >= b._value;
	}

	friend bool operator >  (LimitedCount a, LimitedCount b)
	{
		return a._value >  b._value;
	}
};

template <GLenum Query>
inline GLuint LimitedCountMax(const LimitedCount<Query>& lim_count)
{
	return lim_count._limit();
}

inline GLuint LimitedCountMax(GLuint lim_count)
{
	return lim_count;
}

#define OGLPLUS_DECLARE_LIMITED_COUNT_TYPE(NAME, QUERY) \
class NAME \
 : public LimitedCount<GL_ ## QUERY> \
{ \
public: \
	typedef GLuint _value_type; \
	NAME(GLuint value = 0) \
	 : LimitedCount<GL_ ## QUERY>(value, #QUERY) \
	{ } \
};

} // namespace oglplus

#endif // include guard
