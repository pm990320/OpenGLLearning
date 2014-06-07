/**
 *  @file advanced/cloud_trace/cloud_data.hpp
 *  @brief Declares data structures storing cloud parameters
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2008-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef OGLPLUS_ADVANCED_CLOUD_TRACE_CLOUD_DATA_1119071146_HPP
#define OGLPLUS_ADVANCED_CLOUD_TRACE_CLOUD_DATA_1119071146_HPP

#include "app_data.hpp"
#include "resources.hpp"

#include <oglplus/gl.hpp>
#include <oglplus/fix_gl_version.hpp>
#include <oglplus/buffer.hpp>
#include <oglplus/math/matrix.hpp>

#include <vector>
#include <iosfwd>

namespace oglplus {
namespace cloud_trace {

struct CloudData
{
	std::vector<Mat4f> storage;

	CloudData(const AppData&);

	void LoadCSV(const AppData&, std::istream&);

	void Load(const AppData&);
	void Generate(const AppData&);
};

class CloudBuffer : public Buffer
{
public:
	const unsigned count;
	const GLuint ub_idx;

	CloudBuffer(const AppData&, const CloudData&, ResourceAllocator&);

	void Use(void);
};

} // namespace cloud_trace
} // namespace oglplus

#endif // include guard
