#include "physics_engine.hpp"

PhysicsEngine::PhysicsEngine()
{
	gravity_ = 0.0;
	spaceCount_ = 0;
	Logger logger( "engine.log" );
	logger_ = logger;
	logger.log( "PhysicsEngine Constructor", Logger::Severity::Error );
}

void PhysicsEngine::addSpace()
{
	Space space;
	int spaceID = spaceCount(); 
	spaces_.emplace( std::make_pair( spaceID, space ) );
}

Space * PhysicsEngine::getSpace( int spaceID )
{
	auto space = spaces_.find( spaceID );

	if( space != spaces_.end() )
	{
		return &(space->second);
	}

	logger_.log( "Space not found.", Logger::Severity::Error );
	return nullptr;
}
