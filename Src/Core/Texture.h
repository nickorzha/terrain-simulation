//=======================================================================================================================|
// Created 2014.05.31 by Daniel L. Watkins
//
// Copyright (C) 2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _t3d_TEXTURE_H
#define _t3d_TEXTURE_H

#include "../Main.h"
#include "Image.h"

namespace t3d
{
	class Texture
	{
	private:
		Uint mProgram;
		Uint mTexture;
		Uint mVao;

		void loadShaders();
		void unloadTexure();

	public:
		Texture();
		~Texture();

		void initWithImage(const Image &image);
		void render();
	};
};

#endif
