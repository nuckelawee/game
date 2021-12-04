#ifndef COLLISION_H
#define COLLISION_H

#include <cstdio>
#include "coll_draw.h"

namespace Physic {

class PCollisions;

//Класс cодержит форму, для которой расчитываются столкновения.
class Collision {
	friend class PCollisions;

//Массив указателей на класс Shape.
	Shape **ppShapes;
	Graphic::CollDraw *pShRender = NULL;

	unsigned int numOfShapes; 	//Размер массива.

	float angle;
	glm::vec3 v3Position = glm::vec3(0.0f);

//Хранит нижнюю левую и верхнюю правую точки прямоугольника.
	glm::vec2 pV2AABB[2];

	void find_AABB_points();

	void PrintState();

public:

//Для работы добавь в PCollisions.
	Collision(Shape** arrayOfShapes, const unsigned int num);

	Collision(const Shape* arrayOfShapes, const unsigned int num);

    //Collision(const char* sCollis) {}

	Collision(const Collision& obj);

//Объединение двух коллизий в одну.
    void Join(const Collision& obj, const glm::vec2& v2Offset = glm::vec2(0));

	void Draw(const Camera& camera) const;

    void BeginDraw(Graphic::Shader& coll, Graphic::Shader& aabb
                 , Graphic::Texture2D& collTex);

	void Movement(glm::vec3 v3NewPos);

	void Rotation(float angle);

    int HowManyShapes() const;

	~Collision();

};
}

#endif
