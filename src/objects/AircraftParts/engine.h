#ifndef ENGINE_H
#define ENGINE_H

#include "../physical_object.h"
#include "../../utility/resources.h"

namespace Aircraft {

enum planeEngines { RUST_ENGINE };

//Двигатель для самолёта.
//Расчитывает силу тяги.
class Engine : public Physic::PhysicObject {
	friend class Plane;

	const enum planeEngines Name;

	const float maxThrustForce; 	//Максимальная сила тяги двигателя

//Вектор текущей силы тяги двигателя.
//Всегда сонаправлен вектору скорости самолёта.
	glm::vec3 v3ThrustForce; 				

//Вектор изменения силы тигя двигателя.
//Сонаправлен вектору силы тяги двигателя.
	glm::vec3 v3PowerPulse;
	const float Pulse; //Длина векторы PowerPulse.
	const float averFuelConsumption;//Средний расход топлива при нормальной работе
	float fuelConsumption;			//Расход топлива

private:

	//Обновляет состояние объекта.
	virtual void Work(const float delta_time, float angle
						    , bool gas = 0, bool brake = 0);

	virtual void SideEffect();

	//void ChangeAverFuelConsumption(float newConsumption)
	
	void CalcFuelConsumption(const float delta_time);
	
	bool MaxForce(const float delta_time);

public:

	Engine(enum planeEngines name
					, float maxForce, const glm::vec3& startForce
					, const glm::vec3& Ppulse, float pulse
                    , float consumption
                    , const char* fCollis, float m 
					, float coof, Graphic::Shader& sh
                    , Graphic::Texture2D& tex
					, const glm::vec3& v3Pos = glm::vec3(0)
                    , const glm::vec3& v3Size = glm::vec3(1)
					, const glm::vec3& v3Speed = glm::vec3(0));


	virtual ~Engine() {}

};
}

#endif
