#include "test_util.cpp"

#include "../physics_engine.cpp"
#include "../space.cpp"

TEST( PhysicsEngineTest, DefaultValues )
{
	PhysicsEngine pe;
	ASSERT_EQ( 0.0, pe.gravity() );
	ASSERT_EQ( 0, pe.spaceCount() );
}


TEST( PhysicsEngineTest, LogOnEngineInitalize )
{
	Logger logger( "engine.log" );
	PhysicsEngine pe;
	ASSERT_TRUE( isLogIn( "PhysicsEngine Constructor", logger ) );
}


TEST( PhysicsEngineTest, AddSpace )
{
	PhysicsEngine pe;
	pe.addSpace();
	ASSERT_EQ( 1, pe.spaceCount() );
}

TEST( PhysicsEngineTest, GetSpace )
{
	PhysicsEngine pe;
	pe.addSpace();

	ASSERT_EQ( 1, pe.spaceCount() );

	Space * space = pe.getSpace( 0 );
	ASSERT_NE( nullptr, space );
}


TEST( PhysicsEngineTest, GetSpecificSpace )
{
	PhysicsEngine pe;
	pe.addSpace();
	pe.addSpace();

	ASSERT_EQ( 2, pe.spaceCount() );

	Space * first_space = pe.getSpace( 0 );
	ASSERT_NE( nullptr, first_space );
	
	Space * second_space = pe.getSpace( 1 );
	ASSERT_NE( nullptr, second_space );

	ASSERT_NE( first_space, second_space );
}

TEST( PhysicsEngineTest, GetInvalidSpace )
{
	Logger logger( "engine.log" );
	PhysicsEngine pe;
	ASSERT_EQ( 0, pe.spaceCount() );
	
	Space * space = pe.getSpace( 5 );
	ASSERT_EQ( nullptr, space );

	ASSERT_TRUE( isLogIn( "Space not found", logger ) );
}
