#pragma once

#define STRCODE size_t

// Generate a hashcode from a string usign FVN-1
constexpr STRCODE getHashCode(const char* str)
{
	const size_t fnv_prime = 0x811C9DC5;
	size_t hash = 0;
	char end = '\0';

	for (const char* ref = str; *ref != end; ++ref)
	{
		hash *= fnv_prime;
		hash ^= *ref;
	}

	return hash;
}

#define DECLARE_SINGLETON(className)\
private:\
	className();\
	~className();\
	explicit className(className const&) = delete;\
	className& operator=(className const&) = delete;\
	friend class Singleton<className>;