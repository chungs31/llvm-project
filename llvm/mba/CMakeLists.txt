configure_lit_site_cfg(
  ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in
  ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
  MAIN_CONFIG
  ${CMAKE_CURRENT_SOURCE_DIR}/lit.cfg.py
  )

set(MBA_TEST_DEPENDS
  opt
)

add_lit_testsuite(check-mba "Running the MBA tests"
${CMAKE_CURRENT_BINARY_DIR}
DEPENDS ${MBA_TEST_DEPENDS})

set_target_properties(check-mba PROPERTIES FOLDER "Tests")
add_lit_testsuites(MBA ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS ${MBA_TEST_DEPENDS}
  )

