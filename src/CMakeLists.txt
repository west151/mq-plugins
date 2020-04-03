add_executable(${PROJECT_NAME}
  main.cpp
  system_manager.cpp
  system_manager.h
)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Qml Qt5::Quick)
