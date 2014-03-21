cmake_minimum_required (VERSION 2.4.3)
project (BulletTest)

if (DEFINED ENV{BulletPhysics} )
	include_directories ( "$ENV{BulletPhysics}/core/src" )
	#link_directories ( "$ENV{BulletPhysics}/build/lib/Debug" )
	link_directories ( "$ENV{BulletPhysics}/build/lib/Release" )
	message ( "$ENV{BulletPhysics}/core/src" )
	set ( BULLET_PATH_DEFINED 1)
else()
	message ( " no \${BulletPhysics} find" )
endif()

include_directories( ${CMAKE_SOURCE_DIR} )

add_subdirectory( helloWorld )

add_subdirectory( testLib )
add_subdirectory( useLib )

add_subdirectory( collisionTest )