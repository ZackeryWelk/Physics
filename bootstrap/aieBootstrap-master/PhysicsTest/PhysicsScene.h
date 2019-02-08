#pragma once
#include <glm\vec2.hpp>
#include "PhysicsObject.h"
#include <vector>
#include "Rigidbody.h"
#include <list>
#include <iostream>


class PhysicsObject;

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);
	void debugScene();
	void update(float dt);
	void updatedGizmos();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	glm::vec2 getGravity() const { return m_gravity; }

	void setTimeStep(const float timestep) { m_timeStep = timestep; }
	float getTimeStep() const { return m_timeStep; }


protected:
	glm::vec2 m_gravity;
	float m_timeStep;
	std::vector<PhysicsObject*> m_actors;
};

