#include "stdafx.h"
#include "ComponentScript.h"
#include "GameObject.h"
#include "Collider.h"
IMPLEMENT_ABSTRACT_CLASS(ComponentScript)

ComponentScript::ComponentScript()
{

}

void ComponentScript::Initialize()
{
	Component::Initialize();

	// Setup any collision events
	std::vector<Component*> colliders = go->FindComponentsOfType(Collider::getClassHashCode());
	std::function<void(Collider*)> collisionEnterEvent = std::bind(&ComponentScript::OnCollision, this, std::placeholders::_1);

	for (Component* componentCollider : colliders)
	{
		Collider* collider = static_cast<Collider*>(componentCollider);
		collider->AddCollisionEvent(collisionEnterEvent);
	}
}
