/**
 *  @file oglplus/renderbuffer.ipp
 *  @brief Implementation of Renderbuffer functions
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <oglplus/lib/incl_begin.ipp>
#include <oglplus/images/image_spec.hpp>
#include <oglplus/lib/incl_end.ipp>

namespace oglplus {

OGLPLUS_LIB_FUNC
GLenum ObjBindingOps<tag::Renderbuffer>::
_binding_query(RenderbufferTarget target)
{
	switch(GLenum(target))
	{
#include <oglplus/enums/renderbuffer_target_bq.ipp>
		default:;
	}
	return 0;
}

OGLPLUS_LIB_FUNC
GLuint ObjBindingOps<tag::Renderbuffer>::
_binding(RenderbufferTarget target)
{
	GLint name = 0;
	OGLPLUS_GLFUNC(GetIntegerv)(_binding_query(target), &name);
	OGLPLUS_VERIFY(
		GetIntegerv,
		Error,
		EnumParam(_binding_query(target))
	);
	return name;
}

OGLPLUS_LIB_FUNC
void ObjectOps<tag::ExplicitSel, tag::Renderbuffer>::
Storage(
	Target target,
	const images::ImageSpec& image_spec
)
{
	Storage(
		target,
		image_spec.internal_format,
		image_spec.width,
		image_spec.height
	);
}

} // namespace oglplus

