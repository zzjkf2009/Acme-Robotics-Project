add_executable(shell-app main.cpp Astar.cpp BuildingMap.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries( shell-app ${OpenCV_LIBS})
