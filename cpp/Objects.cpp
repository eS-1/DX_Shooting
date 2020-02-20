#include "../header/Objects.h"


int obj::fontTitle;
int obj::fontInGame;
std::unique_ptr<MyObject> obj::player;
std::vector<std::unique_ptr<MyObject>> obj::bullets;
std::vector<std::unique_ptr<MyObject>> obj::enemys;
std::vector<std::unique_ptr<MyObject>> obj::enBullets;
MyKeyboard obj::myKeyboard;
