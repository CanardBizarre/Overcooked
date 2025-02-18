#include "DebugLevel.h"
#include "WorkPlan.h"

#include "TestDummy.h"
#include "LevelLoader.h"
#include "FileManager.h"
using namespace File;

DebugLevel::DebugLevel() : Level("Debug")
{
	player = nullptr;
}

void DebugLevel::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "Level_1-1";
	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());
	M_LEVELLOADER.InterpretString(_texts);

	TestDummy* _dummy = SpawnActor<TestDummy>();
	_dummy->GetMesh()->SetOriginAtMiddle();
	_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));

	WorkPlan* _prop = SpawnActor<WorkPlan>(Vector2f(50.0f, 50.0f), Vector2f(100.0f, 100.0f));
	_prop->SetPosition({ 100.0f, 100.0f });
	//_prop->SetZOrder(1)

	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
}
