#pragma once

#include "Ingredient.h"
#include "KitchenBlock.h"
#include "KitchenBlock.h"

class FoodSpawner : public KitchenBlock
{
    IngredientType type;
    MeshActor* icon;
public:
    FORCEINLINE void SetType(const IngredientType& _type)
    {
        type = _type;
    }
public:
    FoodSpawner(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, 
        const BlockType& _type, const string& _name);
    FoodSpawner(const FoodSpawner& _other);
    
    Ingredient* SpawnIngredient(const IngredientType type, const IngredientState status = IS_RAW, const string& _name = "Ingredient");
    virtual void Construct() override;
};

