#include "rusty_engine.h"

RustyEngine::RustyEngine(const Shader& shader) :
		Engine(
			RUST_ENGINE, 20000, vec3(15000, 0.0, 0.0),
			vec3(500, 0.0, 0.0), 500, 4, 1000, 400, shader,
			resources.LoadTexture("engine", "../resources/Engines/Rusty_engine.png"),
			vec3(0.0, 0.0, 0.0), vec3(0.59*1.568, 0.59*1.0, 1.0), vec3(0.0, 0.0, 0.0)
		) {}

