#pragma once

#include <PeachPit/PeachPit.h>

class CoolLayer : public Peach::Layer
{

	void OnAttach() override
	{
		Peach::Shader shader("res/test.shader");
	}

	void OnDetach() override
	{

	}

	void OnUpdate() override
	{

	}

};
