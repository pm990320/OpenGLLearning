#include "Shape.h"

void ShapeContainer::drawShapes() const {
	for (auto& x : _shapes) {
		x->draw();
	}
}

void ShapeContainer::updateShapes() {
	for (auto& x : _shapes) {
		x->update();
	}
}

void ShapeContainer::addShape(Shape& s) {
	_shapes.push_back(&s);
}