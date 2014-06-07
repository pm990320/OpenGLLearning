/**
 *  @file oglplus/dsa/vertex_attrib.hpp
 *  @brief VertexArrayAttrib wrappers with direct state access
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OGLPLUS_DSA_VERTEX_ATTRIB_1107121519_HPP
#define OGLPLUS_DSA_VERTEX_ATTRIB_1107121519_HPP

#include <oglplus/vertex_attrib.hpp>
#include <oglplus/error/object.hpp>

namespace oglplus {

#if OGLPLUS_DOCUMENTATION_ONLY || GL_EXT_direct_state_access

class DSAVertexArrayAttrib
 : public ProgVarCommonOps<tag::VertexAttrib>
{
private:
	GLuint _vao;
public:
	/// References the vertex attribute array at @p location
	/**
	 *  @glsymbols
	 *  @glfunref{GetAttribLocation}
	 */
	DSAVertexArrayAttrib(
		VertexArrayName vao,
		VertexAttribSlot location
	): ProgVarCommonOps<tag::VertexAttrib>(VertexAttribLoc(GLint(location)))
	 , _vao(GetGLName(vao))
	{ }

	/// References the vertex attrib array @p identifier of the @p program
	/**
	 *  @glsymbols
	 *  @glfunref{GetAttribLocation}
	 */
	DSAVertexArrayAttrib(
		VertexArrayName vao,
		ProgramName program,
		StrCRef identifier
	): ProgVarCommonOps<tag::VertexAttrib>(VertexAttribLoc(program, identifier))
	 , _vao(GetGLName(vao))
	{ }

	/// Setup the properties of this vertex attribute array
	/**
	 *  @glsymbols
	 *  @glfunref{VertexArrayVertexAttribOffsetEXT}
	 */
	const DSAVertexArrayAttrib& Offset(
		BufferName buffer,
		GLint values_per_vertex,
		DataType data_type,
		bool normalized,
		GLsizei stride,
		GLintptr offset
	) const
	{
		OGLPLUS_GLFUNC(VertexArrayVertexAttribOffsetEXT)(
			_vao,
			GetGLName(buffer),
			GLuint(_location),
			values_per_vertex,
			GLenum(data_type),
			normalized ? GL_TRUE : GL_FALSE,
			stride,
			offset
		);
		OGLPLUS_CHECK(
			VertexArrayVertexAttribOffsetEXT,
			ObjectPairError,
			Subject(buffer).
			Object(VertexArrayName(_vao)).
			EnumParam(data_type)
		);
		return *this;
	}

	/// Setup the properties of this vertex attribute array
	/**
	 *  @glsymbols
	 *  @glfunref{VertexArrayVertexAttribIOffsetEXT}
	 */
	const DSAVertexArrayAttrib& IOffset(
		BufferName buffer,
		GLint values_per_vertex,
		DataType data_type,
		GLsizei stride,
		GLintptr offset
	) const
	{
		OGLPLUS_GLFUNC(VertexArrayVertexAttribIOffsetEXT)(
			_vao,
			GetGLName(buffer),
			GLuint(_location),
			values_per_vertex,
			GLenum(data_type),
			stride,
			offset
		);
		OGLPLUS_CHECK(
			VertexArrayVertexAttribIOffsetEXT,
			ObjectPairError,
			Subject(buffer).
			Object(VertexArrayName(_vao)).
			EnumParam(data_type)
		);
		return *this;
	}

	const DSAVertexArrayAttrib& Setup(
		BufferName buffer,
		GLint values_per_vertex,
		std::integral_constant<
			typename enums::EnumValueType<DataType>::Type,
			OGLPLUS_CONST_ENUM_VALUE(DataType::Float)
		>
	) const
	{
		return Offset(
			buffer,
			values_per_vertex,
			DataType::Float,
			false,
			0,
			0
		);
	}

	template <typename enums::EnumValueType<DataType>::Type DataTypeValue>
	const DSAVertexArrayAttrib& Setup(
		BufferName buffer,
		GLint values_per_vertex,
		std::integral_constant<
			typename enums::EnumValueType<DataType>::Type,
			DataTypeValue
		>
	) const
	{
		return IOffset(
			buffer,
			values_per_vertex,
			DataTypeValue,
			0,
			0
		);
	}

	/// Setup the properties of this vertex array attribute
	/**
	 *  @see Offset
	 *  @see IOffset
	 *
	 *  @glsymbols
	 *  @glfunref{VertexArrayVertexAttribOffsetEXT}
	 *  @glfunref{VertexArrayVertexAttribIOffsetEXT}
	 */
	template <typename T>
	const DSAVertexArrayAttrib& Setup(
		BufferName buffer,
		GLuint n = 1
	) const
	{
		typedef decltype(_get_et((T*)nullptr)) elem_type;

		return Setup(
			buffer,
			_get_vpv((T*)nullptr)*n,
			typename DataTypeCT<elem_type>::type()
		);
	}

	/// Enable this vertex array attribute
	/**
	 *  @glsymbols
	 *  @glfunref{EnableVertexArrayAttribEXT}
	 */
	const DSAVertexArrayAttrib& Enable(void) const
	{
		OGLPLUS_GLFUNC(EnableVertexArrayAttribEXT)(
			_vao,
			GLuint(_location)
		);
		OGLPLUS_CHECK_SIMPLE(EnableVertexArrayAttribEXT);
		return *this;
	}

	/// Enable this specified vertex array attribute
	/**
	 *  @glsymbols
	 *  @glfunref{DisableVertexArrayAttribEXT}
	 */
	const DSAVertexArrayAttrib& Disable(void) const
	{
		OGLPLUS_GLFUNC(DisableVertexArrayAttribEXT)(
			_vao,
			GLuint(_location)
		);
		OGLPLUS_CHECK_SIMPLE(DisableVertexArrayAttribEXT);
		return *this;
	}
};

#endif // GL_EXT_direct_state_access

} // namespace oglplus

#endif // include guard
