//==================================================================================================================|
// Created 2014.10.19 by Daniel L. Watkins
//
// Copyright (C) 2014-2015 Daniel L. Watkins
// This file is licensed under the MIT License.
//==================================================================================================================|

#ifndef _t3d_TERRAIN_RENDERER_H
#define _t3d_TERRAIN_RENDERER_H

#include <Library.h>
#include <World/Terrain/Data.h>

namespace t3d { namespace world { namespace terrain
{
	enum class Mode
	{
		Normal,
		WireFrame
	};


	class Renderer : protected OpenGLFunctions
	{
	public:
		Renderer() {}

		void init(Data *terrainData);
		void cleanup();
		void render(Vec3f cameraPos, const Mat4 &modelViewMatrix, const Mat4 &perspectiveMatrix);

		void setLodFactor(float lodFactor) { mLodFactor = lodFactor; }
		void setMode(Mode mode) { mMode = mode; }
		Mode getMode() { return mMode; }

	private:
		Q_DISABLE_COPY(Renderer)

		Data *mTerrainData;
		QOpenGLShaderProgram mProgram;
		GLuint mVao;
		GLuint mVbo[2];

		float mLodFactor;
		Mode mMode = Mode::Normal;

		struct
		{
			GLint terrainSize;
			GLint height;
			GLint mvMatrix;
			GLint projMatrix;

			GLint spacing;
			GLint textureMapResolution;
			GLint heightMapSize;
		} mUniforms;

		struct
		{
			GLuint heightMap;
			GLuint lightMap;
			GLuint indicies;
			GLuint terrain;
		} mTextures;


	private:
		void loadShaders();
		void loadTextures();

		void uploadTerrainData();
	};
}}}

#endif

