#pragma once

#include "Object.h"

class Component;
class Transform;
class GameObject final : public Object
{
	DECLARE_DYNAMIC_DERIVED_CLASS(GameObject, Object)
public:
	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);

	Component* FindComponentOfType(STRCODE _code);
	Component* FindComponentOfType(const std::string& _name);
	const std::vector<Component*>& FindComponentsOfType(STRCODE _code);
	const std::vector<Component*>& FindComponentsOfType(const std::string& _name);

	// Getters/Setters
	const inline std::string& GetTag() const { return tag; }
	inline void SetTag(const std::string& _tagName) { tag = _tagName; }

	inline Transform* GetTransform() { return transform; }
private:
	GameObject() = default;
	~GameObject() = default;

	GameObject(const GameObject& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;

	void Update(float _dt);
	void Initialize() override;
	void Cleanup();
private:
	std::unordered_map<STRCODE, std::vector<Component*>> components;
	std::string tag = "NONE";
	Transform* transform;
	bool toBeDestroyed = false;

	friend class GameObjectManager;
};

