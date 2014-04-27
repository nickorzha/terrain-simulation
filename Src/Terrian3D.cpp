//=======================================================================================================================|
// Created 2014.04.26 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Terrain3D.h"
#include "./Core/Core.h"


namespace t3d
{	
	Terrain3D::Terrain3D()
	{
	}


	void Terrain3D::loadShaders()
	{
		Uint shaders[2];
		shaders[0] = Shader::loadShader(String(gDefaultPathShaders) + "standard.vert", GL_VERTEX_SHADER);
		shaders[1] = Shader::loadShader(String(gDefaultPathShaders) + "standard.frag", GL_FRAGMENT_SHADER);

		mProgram = Shader::linkFromShaders(shaders, 2);
	}


	void Terrain3D::onStartup()
	{
		loadShaders();

		glUseProgram(0);

		//vertex data
		glGenBuffers(1, &mVbo);
		glBindBuffer(GL_ARRAY_BUFFER, mVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData_cube), vertexData_cube, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//index data
		glGenBuffers(1, &mIbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData_cube), indexData_cube, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		
		//vertex array
		glGenVertexArrays(1, &mVao);
		glBindVertexArray(mVao);

		glBindBuffer(GL_ARRAY_BUFFER, mVbo);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
		
		
		glBindVertexArray(0);
	}

	
	void Terrain3D::onUpdate(Double timeSinceStartup)
	{
		static const Float clearColor[] = { 1.0f, 1.0f, 0.9f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, clearColor);

		glUseProgram(mProgram);
		glBindVertexArray(mVao);

		glDrawElements(GL_TRIANGLES, ARRAY_COUNT(indexData_cube), GL_UNSIGNED_SHORT, 0);
	}


	void Terrain3D::onKey(Int key, Int action)
	{
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
			{
				terminate();
			}
		}
	}

	
	void Terrain3D::onResize(Int width, Int height)
	{
		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	}


	void Terrain3D::onTerminate()
	{
	}	
};