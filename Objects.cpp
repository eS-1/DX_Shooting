#include "Objects.h"


void Objects_End()
{
	delete obj::player;
	for (Enemy* en : obj::enemys) { delete en; }
	for (Bullet* bul : obj::bullets) { delete bul; }
	for (Bullet* bul : obj::enBullets) { delete bul; }
}