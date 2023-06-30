cmake_minimum_required(VERSION 3.0)
project(FrameworkGame C CXX)

set(CMAKE_CXX_STANDARD 20)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(${PROJECT_NAME} 
	game/main.cpp
	game/settings.h
	game/resourcemanager.h
	game/resourcemanager.cpp
	game/core.cpp
	game/core.h
	game/sprite.cpp
	game/sprite.h
	game/drawsprite.cpp
	game/drawsprite.h
	game/textsprite.cpp
	game/textsprite.h
	game/scene.h
	game/scene.cpp

	game/gamescene.cpp
	game/gamescene.h
	game/spike.cpp
	game/spike.h
	game/player.cpp
	game/player.h
	game/spawner.cpp
	game/spawner.h
	game/scenemanager.cpp
	game/scenemanager.h
	game/startscene.cpp
	game/startscene.h
	game/button.cpp
	game/button.h
	game/pausehud.cpp
	game/pausehud.h
	game/optionscene.cpp
	game/optionscene.h
)
file(
	COPY game/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release mode
