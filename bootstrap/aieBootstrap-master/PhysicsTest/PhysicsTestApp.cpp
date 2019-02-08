#include "PhysicsTestApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <glm\ext.hpp>

PhysicsTestApp::PhysicsTestApp() {

}

PhysicsTestApp::~PhysicsTestApp() {

}

bool PhysicsTestApp::startup() {
	// increase the 2d line count to maximise the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, -10));
	m_physicsScene->setTimeStep(0.01f);

	/*Projectile Physics Pt2*/
	float radius = 1.0f;
	float speed = 20;
	glm::vec2 startPos(-40, 0);
	float inclination = 45;
	
	glm::vec2 initialSpeed = glm::vec2(cos(inclination * 0.017) * speed, sin(inclination * 0.017) * speed);
	
	m_test = new Sphere(startPos, initialSpeed, 2, radius, glm::vec4(1,0,0,1));
	m_physicsScene->addActor(m_test);
	


	/*projectile physics Pt 1*/
	//setupContinuousDemo(glm::vec2(-40, 0), 45, 30, -10);





	/* linear force and momentum tutorial*/

	//Sphere* circle1 = new Sphere(glm::vec2(-20, 0), glm::vec2(0, 0), 4.0f, 4, glm::vec4(1, 0, 0, 1));
	//Sphere* circle2 = new Sphere(glm::vec2(10, 0), glm::vec2(0, 0), 4.0f, 4, glm::vec4(0, 1, 0, 1));
	//
	//m_physicsScene->addActor(circle1);
	//m_physicsScene->addActor(circle2);
	//
	//circle1->applyForceToActor(circle2, glm::vec2(2, 0));
	//
	//circle1->applyForce(glm::vec2(30, 0));
	//circle2->applyForce(glm::vec2(-15, 0));
	

	
	
	return true;
}

void PhysicsTestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;

	delete m_physicsScene;
}

void PhysicsTestApp::setupContinuousDemo(glm::vec2 startPos, float inclination, float speed, float gravity)
{
	float t = 0;
	float tStep = 0.5f;
	float radius = 1.0f;
	int segments = 12;
	glm::vec4 colour = glm::vec4(1, 1, 0, 1);

	while (t <= 5)
	{
		glm::vec2 initial = glm::vec2(cos(inclination * 0.017) * speed, sin(inclination * 0.017) * speed);
			

		float x = startPos.x + initial.x * t;
		float y = startPos.y + initial.y * t + (gravity * (t * t)) /2;

		aie::Gizmos::add2DCircle(glm::vec2(x, y), radius, segments, colour);
		t += tStep;
	}
}

void PhysicsTestApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	
//	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime);
	m_physicsScene->updatedGizmos();

	//allows the object to rise
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		m_test->applyForce(glm::vec2(0, 2));
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsTestApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}