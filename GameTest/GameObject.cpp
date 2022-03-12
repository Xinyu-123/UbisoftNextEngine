#include "stdafx.h"
#include "GameObject.h"
#include "Component.h"
#include "RenderSystem.h"
#include "IRenderable.h"
#include "Mesh.h"
#include "Transform.h"
#include "Camera.h"
#include "Collider.h"
#include "CollisionSystem.h"

IMPLEMENT_DYNAMIC_CLASS(GameObject);

GameObject::GameObject()
{
	if (transform == nullptr)
	{
		Transform* t = new Transform();
		AddComponent(t);
		transform = t;
	}
}

void GameObject::AddComponent(Component* _component)
{
	_component->go = this;
	_component->transform = transform;


	if (_component->renderable == true)
	{
		// Create a macro to cast Component to derived class to IRenderable
		IRenderable* r = dynamic_cast<IRenderable*>(_component);
		RenderSystem::Get().AddRenderable(r);

	}


	if (_component->getDerivedClassHashCode() == Camera::getClassHashCode())
	{
		RenderSystem::Get().AddCamera(static_cast<Camera*>(_component));
	}


	if (_component->collider == true)
	{
		Collider* c = static_cast<Collider*>(_component);
		CollisionSystem::Get().AddCollider(c);

		components[Collider::getClassHashCode()].push_back(_component);

		return;
	}


	components[_component->getDerivedClassHashCode()].push_back(_component);
}

void GameObject::RemoveComponent(Component* _component)
{
	auto& componentVector = components.at(_component->getDerivedClassHashCode());
	componentVector.erase(std::remove(componentVector.begin(), componentVector.end(), _component), componentVector.end() );

	delete _component;
}

Component* GameObject::FindComponentOfType(STRCODE _code)
{
	if (components.count(_code) <= 0)
		return nullptr;

	if (components.at(_code).size() <= 0)
		return nullptr;

	return components.at(_code)[0];
}

Component* GameObject::FindComponentOfType(const std::string& _name)
{
	return FindComponentOfType(CRtti::getRtti(_name).getClassHashCode());
}

const std::vector<Component*> GameObject::FindComponentsOfType(STRCODE _code)
{
	if (components.count(_code) <= 0)
		return {};

	return components.at(_code);
}

const std::vector<Component*> GameObject::FindComponentsOfType(const std::string& _name)
{
	return FindComponentsOfType(CRtti::getRtti(_name).getClassHashCode());
}

void GameObject::Update(float _dt)
{
	// Update all the components
	for (auto componentVec : components)
	{
		for (auto component : componentVec.second)
		{
			component->Update(_dt);
		}
	}
}

void GameObject::Initialize()
{
	Object::Initialize();

	for (auto pairs : components)
	{
		for (Component* c : pairs.second)
		{
			c->Initialize();
		}
	}
}

void GameObject::Cleanup()
{
	// remove all the components
	for (auto componentVec : components)
	{
		for (auto component : componentVec.second)
		{
			component->Cleanup();
			if (component->renderable == true)
			{
				// Create a macro to cast Component to derived class to IRenderable
				IRenderable* r = dynamic_cast<IRenderable*>(component);
				RenderSystem::Get().RemoveRenderable(r);

			}


			if (component->getDerivedClassHashCode() == Camera::getClassHashCode())
			{
				RenderSystem::Get().RemoveCamera();
			}


			if (component->collider == true)
			{
				Collider* c = static_cast<Collider*>(component);
				CollisionSystem::Get().RemoveCollider(c);

			}

			delete component;
		}
	}
}


