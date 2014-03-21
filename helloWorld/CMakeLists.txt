
if ( BULLET_PATH_DEFINED )

	add_executable( btPhysicsTest bulletPhysicsTest.cxx )
	target_link_libraries( btPhysicsTest BulletDynamics BulletCollision LinearMath )

else()
	if (DEFINED ENV{BulletPhysics} )
		include_directories ( "$ENV{BulletPhysics}/core/src" )
		#link_directories ( "$ENV{BulletPhysics}/build/lib/Debug" )
		link_directories ( "$ENV{BulletPhysics}/build/lib/Release" )
		message ( "$ENV{BulletPhysics}/core/src" )

		add_executable( btPhysicsTest bulletPhysicsTest.cxx )
		target_link_libraries( btPhysicsTest BulletDynamics BulletCollision LinearMath )
		
	else()
		message ( " no \${BulletPhysics} find" )
		message ( " skip constructing hello world " )
	endif()
endif()

