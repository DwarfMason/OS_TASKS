project(L13 C)

find_package (Threads)
add_executable(${PROJECT_NAME}_queue queue.c utils.h utils.c)
target_link_libraries (${PROJECT_NAME}_queue ${CMAKE_THREAD_LIBS_INIT})
add_executable(${PROJECT_NAME}_cond queue_cond.c utils.h utils.c)
target_link_libraries (${PROJECT_NAME}_cond ${CMAKE_THREAD_LIBS_INIT})
add_executable(${PROJECT_NAME}_mutex queue_mutex.c utils.h utils.c)
target_link_libraries (${PROJECT_NAME}_mutex ${CMAKE_THREAD_LIBS_INIT})