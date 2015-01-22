//==================================================================================================================|
// Created 2015.01.13 by Daniel L. Watkins
//
// Copyright (C) 2014-2015 Daniel L. Watkins
// This file is licensed under the MIT License.
//==================================================================================================================|

#ifndef _t3d_World_Entity_RenderComponent_H
#define _t3d_World_Entity_RenderComponent_H

#include "BaseEntity.h"
#include "Component.h"

namespace t3d { namespace Asset {
	class Mesh;
}}

namespace t3d { namespace World { namespace Entity
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent() = delete;
		RenderComponent(BaseEntity *baseEntity);

		void setMesh(weak<Asset::Mesh> mesh);
		void render(const Mat4 &cameraMatrix);

	private:
		weak<Asset::Mesh> mMesh;
	};
}}}

#endif

