cmake_minimum_required(VERSION 3.12)
project(Checkers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Checkers main.cpp ChequerType.h Cell.cpp Cell.h GameController.cpp GameController.h Color.h ChequerRep.cpp ChequerRep.h BoardController.cpp BoardController.h BotController.cpp BotController.h Node.cpp Node.h Movement.cpp Movement.h Capture.cpp Capture.h)

set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window audio network system REQUIRED)
target_link_libraries(Checkers sfml-graphics sfml-window sfml-audio sfml-network sfml-system)