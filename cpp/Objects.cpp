#include "../header/Objects.h"


int obj::fontTitle;
int obj::fontInGame;
Player* obj::player;
std::vector<Bullet*> obj::bullets;
std::vector<Enemy*> obj::enemys;
std::vector<Bullet*> obj::enBullets;

void Objects_End()
{
	delete obj::player;
	for (Enemy* en : obj::enemys) { delete en; }
	for (Bullet* bul : obj::bullets) { delete bul; }
	for (Bullet* bul : obj::enBullets) { delete bul; }
}