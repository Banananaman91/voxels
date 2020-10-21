set(SHADER_FILES
  FragmentShader.glsl
  YellowFragment.glsl
  VertexShader.glsl
)

foreach(shader ${SHADER_FILES})
  configure_file(${shader} ${shader} COPYONLY)
endforeach()

add_executable(Shaders IMPORTED GLOBAL)
set_target_properties(Shaders
  PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/IF_YOU_SEE_THIS_YOU_TRIED_TO_RUN_THE_SHADERS_TARGET
)