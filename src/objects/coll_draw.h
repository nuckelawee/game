#ifndef COLL_DRAW_H
#define COLL_DRAW_H

#include "shape_draw.h"
#include "../utility/resources.h"

namespace Graphic {

//Класс, риcующий коллизию.
class CollDraw {

	ShapeDraw **ppGraphic = NULL;
	unsigned int number;

public:
	
	CollDraw() {}

	void Init(Physic::Shape **ppShape, unsigned int numOfShapes
                , const glm::vec2 *pAABB);

    void DrawAABB(const Camera& camera, const glm::vec2 *pAABB
                                      , const glm::vec3& v3Pos) const;


	void Draw(const Camera& camera, const glm::vec3& v3Pos, float angle) const;

	~CollDraw();

};
}

#endif
