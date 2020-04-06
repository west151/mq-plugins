function(enable_plugin target)
    set_target_properties(${target} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_DIR}
    )
endfunction()

add_subdirectory(ui_controller)
add_subdirectory(qt_mq_controller)
add_subdirectory(em_mq_controller)
