#include "stdafx.h"
#include "Box.h"
#include "Transform.h"

bool Box::IsColliding(const Box& _other)
{
	return false;
}

Box Box::GetTransformedBox(const Transform* _transform)
{
	Box ret = *this;

	// No need to scale the box, might change it later though
	//ret.pos.x *= _transform->PeekScale().x;
	//ret.pos.y *= _transform->PeekScale().y;
	//ret.pos.z *= _transform->PeekScale().z;
	//ret.width *= _transform->PeekScale().x;
	//ret.height *= _transform->PeekScale().y;
	//ret.depth *= _transform->PeekScale().z;

	ret.pos.x += _transform->PeekPosition().x;
	ret.pos.y += _transform->PeekPosition().y;
	ret.pos.z += _transform->PeekPosition().z;

	return ret;
}
