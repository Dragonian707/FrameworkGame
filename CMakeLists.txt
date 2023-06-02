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
	game/testscene.cpp
	game/testscene.h
	game/scene.h
	game/scene.cpp
	game/resourcemanager.h
	game/resourcemanager.cpp
	game/core.cpp
	game/core.h
	game/object.cpp
	game/object.h
	game/testobj.cpp
	game/testobj.h
	game/spriteobject.cpp
	game/spriteobject.h
)
file(
	COPY game/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release mode
