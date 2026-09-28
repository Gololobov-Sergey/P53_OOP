#pragma once


enum class TYPE
{
	INT, DOUDLE, STRING
};

class var
{
	TYPE type;
	void* value;
};