#pragma once
#include "Box.h"

namespace UI
{
	class VerticalBox : public Box
	{
	public:
		VerticalBox(Level* _level, const BoxData& _data, const string& _name = "VerticalBox");

	public:
		virtual void Update() override;
	};
}