#pragma once
#include "Box.h"

namespace UI
{
	class HorizontalBox : public Box
	{
	public:
		HorizontalBox(Level* _level, const BoxData& _data, const string& _name);

	public:
		virtual void Update() override;
	};
}