#pragma once

#include "Object.h"
class Asset : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Asset, Object)
protected:
	Asset();
	~Asset();

	friend class AssetManager;
};

