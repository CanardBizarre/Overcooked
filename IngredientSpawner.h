#pragma once
#include "Ingredient.h"



class IngredientSpawner
{
    MeshActor* box;

public:
    IngredientSpawner(MeshActor* _box);

    
    Ingredient* SpawnIngredient(const IngredientType type, const CookingStatus status = CS_FRESH)
    {
        return new Ingredient(type, status);
    }
};

