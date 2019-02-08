#pragma once
#include <glm\ext.hpp>
#include <Gizmos.h>

enum ShapeType {
	PLANE = 0,
	SPHERE,
	BOX
};

class PhysicsObject
{
//	PhysicsObject();
//	~PhysicsObject();

public:
	virtual void fixedUpdate(glm::vec2 gravity, float timestep) = 0;
	virtual void debug() = 0;
	virtual void makeGizmo() = 0;
	virtual void resetPosition() {};

protected:
	PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID) {}
	ShapeType m_shapeID;
	
};

