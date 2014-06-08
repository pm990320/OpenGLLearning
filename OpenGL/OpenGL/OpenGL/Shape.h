#pragma once

#include <vector>

class Shape {
	/*
	* Defines an abstract class used to access different OpenGL drawable objects.
	*/ 
protected:
	int nVertices;
	int nIndices;
public:
	virtual void draw() const = 0;
	virtual void update() = 0;
};

class ShapeContainer {
	/*
	 *  Defines a handle on a vector to be able to access Shapes to draw them quickly.
	 */
	std::vector<Shape*> _shapes;
public:
	void drawShapes() const;
	void updateShapes();
	void addShape(Shape& s);
};
