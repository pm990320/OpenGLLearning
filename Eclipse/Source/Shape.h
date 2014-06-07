/*
 * Shape.h
 *
 *  Created on: 6 Jun 2014
 *      Author: Patrick
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include <oglplus/gl.hpp>
#include <oglplus/all.hpp>
#include <oglplus/shader.hpp>

class Shape {
public:
	int nVertices;

	Shape();
	virtual ~Shape();
	virtual void update();
	virtual void draw(oglplus::Context gl);
};

#endif /* SHAPE_H_ */
