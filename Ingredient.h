#pragma once
#include "HorizontalBox.h"
#include "ImageWidget.h"
#include "Level.h"


namespace CustomWidget
{
	class Ingredient :public HorizontalBox
	{
		string ingredientTexturePath;

	public: 
		Ingredient(Level* _level, const string& _path, const RenderType& _type = Screen);
		~Ingredient();
	private:
		void SetTextureRect(ImageWidget* _image, const int _value);
	};
}


