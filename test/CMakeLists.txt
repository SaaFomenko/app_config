find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
# add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

file(GLOB
	app_config "../*.cpp"
	app_exceptin "../lib/app_exception/*.cpp")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(app_config_lib STATIC 
	${app_config}
	${app_exception})

# These tests need their own main
add_executable(tests test-main.cpp
	${app_config}
	${app_exception})

target_link_libraries(tests PRIVATE Catch2::Catch2)
