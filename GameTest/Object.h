#pragma once
class Object
{
	DECLARE_ABSTRACT_BASE_CLASS(Object)

public:
	inline virtual void Initialize() { initialized = true; }
	inline bool IsInitialized() const { return initialized; }
	inline int GetId() const { return id; }

protected:
	Object();
	virtual ~Object();

	inline void SetId(int _id) { id = _id; }
private:
	bool initialized = false;
	int id = -1;
};

