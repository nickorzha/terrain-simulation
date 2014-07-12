//==================================================================================================================|
// Created 2014.06.11 by Daniel L. Watkins
//
// Copyright (C) 2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//==================================================================================================================|

#ifndef _t3d_SPRITE_SHEET
#define _t3d_SPRITE_SHEET

#include "../Main.h"
#include "Sprite.h"

namespace t3d
{
	/**
	 * \brief A specialized sprite that can draw regular sized sub-rects easily.
	 */
	//TODO it would be better to have a RawSprite base class that Sprite and SpriteSheet both inherit
	class SpriteSheet
	{
	private:
		Sprite mSprite;
		int mNumberOfFramesX, mNumberOfFramesY;
		Vec2f mFrameSize;

	public:
		/**
		 * Tells the sprite to use the specified image. Also configures the 
		 */
		void init(const Image &image, int numberOfFramesX, int numberOfFramesY);
		void setNumberOfFrames(int numberOfFramesX, int numberOfFramesY);

		void render(const OpenGLWindow &window, int frameIndex);
	};
};

#endif

