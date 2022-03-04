#include "stdafx.h"
#include "Object.h"
#include "Asset.h"
#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "ComponentScript.h"
#include "Mesh.h"
#include "Collider.h"
#include "SphereCollider.h"
#include "BoxCollider.h"
#include "MeshCollider.h"
void registerUserClasses()
{

}

void registerEngineClasses()
{
	REGISTER_ABSTRACT_CLASS(Object);
	REGISTER_ABSTRACT_CLASS(Asset);
	REGISTER_ABSTRACT_CLASS(Component);
	REGISTER_ABSTRACT_CLASS(ComponentScript);
	REGISTER_ABSTRACT_CLASS(Collider);
	REGISTER_DYNAMIC_CLASS(GameObject);
	REGISTER_DYNAMIC_CLASS(Transform);
	REGISTER_DYNAMIC_CLASS(Mesh);
	REGISTER_DYNAMIC_CLASS(SphereCollider);
	REGISTER_DYNAMIC_CLASS(BoxCollider);
	REGISTER_DYNAMIC_CLASS(MeshCollider);

	registerUserClasses();
}