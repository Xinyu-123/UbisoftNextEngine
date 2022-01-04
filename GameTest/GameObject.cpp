#include "stdafx.h"
#include "GameObject.h"
#include "Component.h"
IMPLEMENT_DYNAMIC_CLASS(GameObject);

void GameObject::AddComponent(Component* _component)
{
	components.at(_component->getDerivedClassHashCode()).push_back(_component);
}

void GameObject::RemoveComponent(Component* _component)
{
	auto& componentVector = components.at(_component->getDerivedClassHashCode());
	//componentVector.erase(std::remove(componentVector.begin(), componentVector.end(), _component), componentVector.end() );
	

	// Lets get a little funky
	// I don't care about order so I will swap the component with the end of the vector and pop O(n) time complexity
	// Should be faster than remove-erase idiom since there is always only 2 copies (for the swap)
	auto vecItr = std::find(componentVector.begin(), componentVector.end(), _component);
	std::iter_swap(vecItr, componentVector.end());
	componentVector.pop_back();
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

const std::vector<Component*>& GameObject::FindComponentsOfType(STRCODE _code)
{
	if (components.count(_code) <= 0)
		return {};

	return components.at(_code);
}

const std::vector<Component*>& GameObject::FindComponentsOfType(const std::string& _name)
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
}

void GameObject::Cleanup()
{
}


