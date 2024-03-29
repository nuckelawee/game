cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(PROJECT_NAME game)

project(${PROJECT_NAME})

set (CMAKE_BUILD_TYPE Debug)
#set (CMAKE_BUILD_TYPE Release)


add_executable(game 					src/main.cpp 
	src/game.cpp						src/game.h
	src/levels/level.h			
	src/levels/first_level.cpp			src/levels/first_level.h
    src/levels/collisions_editor.cpp    src/levels/collisions_editor.h
    src/levels/object_loader.cpp        src/levels/object_loader.h

	src/objects/AircraftParts/body.cpp			src/objects/AircraftParts/body.h
	src/objects/AircraftParts/engine.cpp		src/objects/AircraftParts/engine.h	
	src/objects/AircraftParts/wings.cpp			src/objects/AircraftParts/wings.h
	src/objects/AircraftParts/tail.cpp			src/objects/AircraftParts/tail.h

	src/objects/AircraftParts/rusty_engine.cpp	src/objects/AircraftParts/rusty_engine.h
	src/objects/AircraftParts/rusty_body.cpp	src/objects/AircraftParts/rusty_body.h
	src/objects/AircraftParts/rusty_wings.cpp	src/objects/AircraftParts/rusty_wings.h
	src/objects/AircraftParts/rusty_tail.cpp	src/objects/AircraftParts/rusty_tail.h

	src/objects/plane.cpp				src/objects/plane.h

	src/objects/physical_object.cpp		src/objects/physical_object.h
	src/objects/graphic_object.cpp		src/objects/graphic_object.h
	src/objects/shape.cpp				src/objects/shape.h
	src/objects/collision.cpp			src/objects/collision.h	
	src/objects/collision_pointers.cpp	src/objects/collision_pointers.h
	src/objects/coll_draw.cpp			src/objects/coll_draw.h	
	src/objects/shape_draw.cpp			src/objects/shape_draw.h	

	src/utility/shader.cpp 				src/utility/shader.h
	src/utility/texture.cpp 			src/utility/texture.h
	src/utility/resources.cpp 			src/utility/resources.h
	src/utility/list.cpp				src/utility/list.h		
    src/utility/temp_list.cpp
    src/utility/collision_in_files.cpp  src/utility/collision_in_files.h
    src/utility/string.cpp              src/utility/string.h
    src/utility/visual_string.cpp       src/utility/visual_string.h
    src/utility/coordinate_system.cpp   src/utility/coordinate_system.h

    src/interface/button.cpp            src/interface/button.h
    src/interface/load_button.cpp       src/interface/load_button.h
    src/interface/interface.cpp         src/interface/interface.h
    src/interface/coll_edit_gui.cpp     src/interface/coll_edit_gui.h
    src/interface/color_button.cpp      src/interface/color_button.h
    src/interface/show_hide_button.cpp  src/interface/show_hide_button.h

	external/stb_image/stb_image.cpp	external/stb_image/stb_image.h
	src/camera.cpp                      src/camera.h
    src/free_camera.cpp                 src/free_camera.h
    src/game_camera.cpp                 src/game_camera.h
    src/input.cpp                       src/input.h
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++11")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GL_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

add_subdirectory(external/freetype)
target_link_libraries(${PROJECT_NAME} freetype)

include_directories(external/glm)
