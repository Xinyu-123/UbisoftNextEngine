#include "stdafx.h"
#include "Object.h"
#include "Asset.h"
#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "ComponentScript.h"

void registerUserClasses()
{

}

void registerEngineClasses()
{
	REGISTER_ABSTRACT_CLASS(Object);
	REGISTER_ABSTRACT_CLASS(Asset);
	REGISTER_ABSTRACT_CLASS(Component);
	REGISTER_ABSTRACT_CLASS(ComponentScript);
	REGISTER_DYNAMIC_CLASS(GameObject);
	REGISTER_DYNAMIC_CLASS(Transform);

	registerUserClasses();
}