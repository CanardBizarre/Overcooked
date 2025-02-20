#pragma once
#include "KitchenBlock.h"
#include "Ingredient.h"
#include "HandSocket.h"
#include "IngredientType.h"

class FoodSpawner : public KitchenBlock
{
    IngredientType type;
    MeshActor* icon;
public:
    FORCEINLINE void SetType(const IngredientType& _type)
    {
        type = _type;

        if (type == IT_COUNT) return;

        InitIcon();
    }
public:
    FoodSpawner(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle,
        const string& _name = "FoodSpawner");
    FoodSpawner(const FoodSpawner& _other);

public:
    Ingredient* SpawnIngredient(const IngredientType type, const string& _name = "Ingredient");
    virtual void Construct() override;
    void InitIcon();

    virtual bool ActionWithoutObject(HandSocket* _hand) override;

};