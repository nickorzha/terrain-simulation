//==================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//==================================================================================================================|

#ifndef _MAIN_H
#define _MAIN_H

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <algorithm>

#include <fstream>
#include <istream>
#include <string>
#include <sstream>

#include <vector>
#include <list>
#include <deque>

#include <thread>

#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstdlib>

#define WIN32_LEAN_AND_MEAN 1

//Lua Includes
extern "C"
{
	#include <lua/lua.h>
	#include <lua/lualib.h>
	#include <lua/lauxlib.h>
}


//GLM Includes
#pragma warning(push)
#pragma warning(disable:4201)
	#include <glm/glm.hpp>
	#include <glm/ext.hpp>
#pragma warning(pop)


//SFML Includes
#define SFML_STATIC
#include <SFML/System.hpp>


//Linkage
#ifdef WIN32
	#pragma once

	#include <Windows.h>

	#ifdef _DEBUG
		#pragma comment (lib, "glfw3-d.lib")
		#pragma comment (lib, "lua-d.lib")
		#pragma comment (lib, "sfml-system-d.lib")
		//#pragma comment (lib, "sfml-main-d.lib")
	#else
		#pragma comment (lib, "glfw3-r.lib")
		#pragma comment (lib, "lua-r.lib")
		#pragma comment (lib, "sfml-system-r.lib")
	#endif

	#pragma comment (lib, "OpenGL32.lib")
#else
	#error "Non Windows toolchain detected"
#endif


//GLFW Includes
#define GLFW_NO_GLU 1
#define GLFW_INCLUDE_GLCOREARB 1
#include "GL/glfw3.h"
#include "GL/gl3w.h"


//typedef common types
typedef long long			int64;
typedef unsigned long long	uint64;


typedef glm::vec2			Vec2f;
typedef glm::vec3			Vec3f;
typedef glm::vec4			Vec4f;

typedef glm::i32vec2		Vec2i;
typedef glm::i32vec3		Vec3i;
typedef glm::i32vec4		Vec4i;

typedef glm::bvec1			Vec1b;
typedef glm::bvec2			Vec2b;
typedef glm::bvec3			Vec3b;
typedef glm::bvec4			Vec4b;

typedef glm::mat2			Mat2;
typedef glm::mat3			Mat3;
typedef glm::mat4			Mat4;

struct Color { float r, g, b, a; };

typedef std::string			String;

#ifdef WIN32
	#include <memory>
#endif


//Project Includes
#include "Constants.h"
#include "./Core/Helper.h"

#endif

