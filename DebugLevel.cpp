#include "DebugLevel.h"
#include "MeshActor.h"

DebugLevel::DebugLevel() : Level("Debug")
{

}

void DebugLevel::InitLevel()
{
	Super::InitLevel();
	MeshActor* _actor = SpawnActor<MeshActor>(RectangleShapeData({ 1200, 600 }), "test");
	//_actor->SetPosition({ 100.0f,100.0f });
}
