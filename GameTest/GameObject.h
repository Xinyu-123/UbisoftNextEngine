#pragma once

#include "Object.h"

class Component;
class Transform;
class GameObject final : public Object
{
	DECLARE_DYNAMIC_DERIVED_CLASS(GameObject, Object)
public:
	GameObject();
	~GameObject() = default;

	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);

	Component* FindComponentOfType(STRCODE _code);
	Component* FindComponentOfType(const std::string& _name);
	const std::vector<Component*> FindComponentsOfType(STRCODE _code);
	const std::vector<Component*> FindComponentsOfType(const std::string& _name);

	// Getters/Setters
	const std::string& GetTag() const { return tag; }
	void SetTag(const std::string& _tagName) { tag = _tagName; }
	
	const std::string& GetName() const { return name; }
	void SetName(const std::string& _name) { name = _name; }

	Transform* GetTransform() { return transform; }
	const Transform* PeekTransform() const { return transform; }

	bool IsActive() const { return active; }
	void SetActive(bool _active) { active = _active; }
private:
	GameObject(const GameObject& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;

	void Update(float _dt);
	void Initialize() override;
	void Cleanup();
private:
	std::unordered_map<STRCODE, std::vector<Component*>> components;
	std::string tag = "NONE";
	std::string name = "NONE";
	Transform* transform = nullptr;
	bool toBeDestroyed = false;
	bool active = true;

	friend class GameObjectManager;
};

