#include "TESTGameMode.h"
#include "Level.h"

TESTGameMode::TESTGameMode(Level* _level, const string& _name) : GameMode(_level, _name)
{
}
TESTGameMode::TESTGameMode(const TESTGameMode& _other) : GameMode(_other)
{

}
