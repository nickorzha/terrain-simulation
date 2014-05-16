//=======================================================================================================================|
// Created 2014.04.28 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _t3d_HEIGHT_MAP_H
#define _t3d_HEIGHT_MAP_H

#include "../Main.h"
#include <vector>

namespace t3d
{
	class HeightMap
	{
	private:
		std::vector<Float> mHeightData;
		Uint mSize;

		std::vector<Float> mVertexData;
		std::vector<Uint> mIndexData;

	public:
		static const Uint PRIMITIVE_RESTART_INDEX = 40000000;
		
		HeightMap()
		{
			mSize = 0;
		}


		void reserve(Uint size);
		void set(Uint index, Float height);
		void set(Uint indexX, Uint indexY, Float height);
		Uint8 get(Uint index);
		Uint8 get(Uint indexX, Uint indexY);

		void buildVertexData();
		std::vector<Float> *getVertexData();

		void buildIndexData();
		std::vector<Uint> *getIndexData();

		Uint getSize() { return mSize; }
	};
};


#endif

