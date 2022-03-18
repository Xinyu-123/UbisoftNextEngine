#include "stdafx.h"


#include "CharacterController.h"
#include "ConstantRotation.h"
#include "Projectile.h"
#include "PlayerProjectile.h"
#include "EnemyController.h"
#include "TurretEnemyController.h"
#include "StandardEnemyShip.h"
#include "PredictionEnemyTurret.h"

void registerUserClasses()
{
	REGISTER_ABSTRACT_CLASS(Projectile);
	REGISTER_ABSTRACT_CLASS(EnemyController);
	REGISTER_DYNAMIC_CLASS(PlayerProjectile);
	REGISTER_DYNAMIC_CLASS(CharacterController);
	REGISTER_DYNAMIC_CLASS(ConstantRotation);
	REGISTER_DYNAMIC_CLASS(TurretEnemyController);
	REGISTER_DYNAMIC_CLASS(StandardEnemyShip);
	REGISTER_DYNAMIC_CLASS(PredictionEnemyTurret);
}

#include "Object.h"
#include "Asset.h"
#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "ComponentScript.h"
#include "Mesh.h"
#include "Camera.h"
#include "Collider.h"
#include "SphereCollider.h"
#include "BoxCollider.h"
#include "MeshCollider.h"
#include "PhysicsPoint.h"
#include "UIComponent.h"
#include "Sprite.h"
#include "Text.h"

void registerEngineClasses()
{
	REGISTER_ABSTRACT_CLASS(Object);
	REGISTER_ABSTRACT_CLASS(Asset);
	REGISTER_ABSTRACT_CLASS(Component);
	REGISTER_ABSTRACT_CLASS(ComponentScript);
	REGISTER_ABSTRACT_CLASS(Collider);
	REGISTER_ABSTRACT_CLASS(UIComponent);
	REGISTER_DYNAMIC_CLASS(GameObject);
	REGISTER_DYNAMIC_CLASS(Transform);
	REGISTER_DYNAMIC_CLASS(Mesh);
	REGISTER_DYNAMIC_CLASS(SphereCollider);
	REGISTER_DYNAMIC_CLASS(BoxCollider);
	REGISTER_DYNAMIC_CLASS(MeshCollider);
	REGISTER_DYNAMIC_CLASS(Camera);
	REGISTER_DYNAMIC_CLASS(PhysicsPoint);
	REGISTER_DYNAMIC_CLASS(Sprite);
	REGISTER_DYNAMIC_CLASS(Text);
	registerUserClasses();
}


