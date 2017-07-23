#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include "logger.hpp"
#include "space.hpp"

#include <map>

class PhysicsEngine
{
public:

	// Contructors
	PhysicsEngine();

	// Destructors

	// Methods
	void addSpace();
	Space * getSpace( int spaceID );

	// Accessors
	float gravity() { return gravity_; };
	int spaceCount() { return spaces_.size(); };
	Logger & logger() { return logger_; };
private:
	float gravity_;
	int spaceCount_;
	Logger logger_;
	std::map<int, Space> spaces_;
};

#endif
