#ifndef LEVEL_H
#define LEVEL_H

#include "../utility/resources.h"
#include "../utility/list.h"
#include "../objects.h"

enum Keys { W, S };

extern Camera camera;

//Интерфейс для уровней.
class ILevel {
public:

//Загрузка уровня.
	virtual void Load() = 0;

//Обновление состояния объектов уровня.
	virtual void UpDate(float delta_time, const bool *keys, const float angle) = 0;

//Отрисовка уровня.
	virtual void Render() = 0;

	virtual ~ILevel() {}
};

#endif