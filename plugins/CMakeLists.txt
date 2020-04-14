function(enable_plugin target)
    set_target_properties(${target} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_DIR}
    )
endfunction()

# ui controller
add_subdirectory(ui_controller)

# Qt Mqtt
find_package(Qt5 COMPONENTS Mqtt)

if(Qt5Mqtt_FOUND)
  message(STATUS "Looking for Qt5Mqtt - found")
  add_subdirectory(qt_mq_controller)
else()
  message(STATUS "Looking for Qt5Mqtt - not found")
endif()

#  MQTT Client for Qt https://emqx.io/
find_package(Qt5 COMPONENTS Qmqtt)

if(Qt5Qmqtt_FOUND)
  message(STATUS "Looking for Qmqtt - found")
  add_subdirectory(em_mq_controller)
else()
  message(STATUS "Looking for Qmqtt - not found")
endif()

#add_subdirectory(qt_mq_controller)
#add_subdirectory(em_mq_controller)

