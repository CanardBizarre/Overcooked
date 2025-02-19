#include "RecipeWidget.h"

RecipeWidget::RecipeWidget(ProgressBarWidget* _progressBar, ImageWidget* _image, ImageWidget* _recipeSlide, CanvasWidget* _canvas, vector<ImageWidget*> _ingredientsImage, vector<IngredientType> _ingredientsArray, RecipeType _recipeType)
{
	chrono = new Chronometer(0, 40);
	progressBar = _progressBar;
	image = _image;
	recipeSlide = _recipeSlide;
	canvas = _canvas;
	ingredientsImage = _ingredientsImage;
	ingredients.push_back(new IngredientWidget(_ingredientsImage[0], _ingredientsArray[0]));
	ingredients.push_back(new IngredientWidget(_ingredientsImage[1], _ingredientsArray[1]));
	ingredients.push_back(new IngredientWidget(_ingredientsImage[2], _ingredientsArray[2]));
	recipeType = _recipeType;
	InitRecipe();
}

RecipeWidget::~RecipeWidget()
{
	delete chrono;
	delete progressBar;
	delete image;
	delete canvas;
}

void RecipeWidget::InitRecipe()
{
	canvas->AddChild(image);
	canvas->AddChild(recipeSlide);
	canvas->AddChild(progressBar);
	canvas->AddChild(ingredients.at(0)->GetImage());
	canvas->AddChild(ingredients.at(1)->GetImage());
	canvas->AddChild(ingredients.at(2)->GetImage());

	image->SetOriginAtMiddle();
	image->SetPosition(Vector2f(85.0f, 50.0f));
	image->SetZOrder(11);

	image->SetRect(IntRect(Vector2i(124 * recipeType, 0), Vector2i(124, 124)));

	recipeSlide->SetPosition(Vector2f(10.0f, 10.0f));
	recipeSlide->SetZOrder(9);

	progressBar->SetZOrder(10);
	progressBar->SetPosition({ 10.0f, 10.0f });
	progressBar->SetValue(chrono->GetMaxTime());
	progressBar->GetForeground()->SetFillColor(Color::Green);

	ingredients.at(0)->GetImage()->SetPosition(Vector2f(36.0f, 92.0f));
	ingredients.at(0)->GetImage()->SetZOrder(20);
	ingredients.at(1)->GetImage()->SetPosition(Vector2f(74.0f, 92.0f));
	ingredients.at(1)->GetImage()->SetZOrder(21);
	ingredients.at(2)->GetImage()->SetPosition(Vector2f(110.0f, 92.0f));
	ingredients.at(2)->GetImage()->SetZOrder(22);

	new Timer([&]() {chrono->DecrementCurrentTime(); progressBar->SetValue(chrono->GetCurrentTime());
	if (chrono->GetCurrentTime() < ((chrono->GetMaxTime() * 2) / 3))  progressBar->GetForeground()->SetFillColor(Color::Yellow);
	if (chrono->GetCurrentTime() < chrono->GetMaxTime() / 3)  progressBar->GetForeground()->SetFillColor(Color::Red); }, seconds(1), true, true);

}