#pragma once

class vec2f
{
public:
	vec2f(){ x = y = 0; }
	vec2f(float a, float b){ x = a; y = b; }

	vec2f&operator +(vec2f&v){ return vec2f(+x + v.x, y + v.y); }
	vec2f&operator -(vec2f&v){ return vec2f(+x - v.x, y - v.y); }
	vec2f&operator *(vec2f&v){ return vec2f(+x * v.x, y * v.y); }
	vec2f&operator /(vec2f&v){ return vec2f(+x / v.x, y / v.y); }

public:
	float x, y;
};

class vec4f
{
public:
	vec4f(){ x = y = z = w = 0; }
	vec4f(float a, float b, float c, float d){ x = a; y = b; z = c; w = d; }
public:
	float x, y, z, w;
};