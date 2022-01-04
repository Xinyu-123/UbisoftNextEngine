#pragma once

template<class T>
class Singleton
{
public:
	static T& Get()
	{
		static T instance;
		return instance;
	}

protected:
	Singleton() = default;
	virtual ~Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton operator=(const Singleton&) = delete;
};