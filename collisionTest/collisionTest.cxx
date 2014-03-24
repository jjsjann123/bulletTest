#include <iostream>

#include <btBulletCollisionCommon.h>

using namespace std;

int main (void)
{
	cout << "test" << endl;

	btBroadphaseInterface* broadphase = new btDbvtBroadphase();
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);

	btCollisionWorld* collisionworld = new btCollisionWorld( dispatcher, broadphase, collisionConfiguration );

	btMatrix3x3 basisA;
	basisA.setIdentity();
	basisA.setEulerZYX(0.25, 0, 0);
	btCollisionObject* objA = new btCollisionObject();
	objA->getWorldTransform().setBasis(basisA);
	btCollisionShape* boxA = new btBoxShape(btVector3(1, 1, 1));
	objA->setCollisionShape(boxA);
	
	btMatrix3x3 basisB;
	basisB.setIdentity();
	basisB.setEulerZYX(-0.25, 0, 0);
	btCollisionObject* objB = new btCollisionObject();
	objB->getWorldTransform().setBasis(basisB);
	btCollisionShape* boxB = new btBoxShape(btVector3(1, .5, .5));
	objB->setCollisionShape(boxB);
	
	collisionworld->addCollisionObject(objA);
	collisionworld->addCollisionObject(objB);

	collisionworld->performDiscreteCollisionDetection();

	int num = collisionworld->getDispatcher()->getNumManifolds();
	cout << "num of manifolds: " << num << endl;
	for ( int i = 0; i < num; i++ )
	{
		btPersistentManifold* contactManifold = collisionworld->getDispatcher()->getManifoldByIndexInternal(i);
		//btCollisionObject* obA = static_cast<btCollisionObject*>(contactManifold->getBody0());
		//btCollisionObject* obB = static_cast<btCollisionObject*>(contactManifold->getBody1());

		int numContacts = contactManifold->getNumContacts();
		cout << "****** # of contacts: " << numContacts << "***********" << endl;
		for (int j=0;j<numContacts;j++)
		{
			btManifoldPoint& pt = contactManifold->getContactPoint(j);
		
			btVector3 ptA = pt.getPositionWorldOnA();
			btVector3 ptB = pt.getPositionWorldOnB();
			cout << " from ( " << ptA.getX() << ", " << ptA.getY() << ", " << ptA.getZ() << ") to ( " << ptB.getX() << ", " << ptB.getY() << ", " << ptB.getZ() << ")" << endl;
		}

	}



	delete boxB;
	delete boxA;
	delete objB;
	delete objA;

	delete collisionworld;
	delete collisionConfiguration;
	delete dispatcher;
	delete broadphase;

	return 0;

}