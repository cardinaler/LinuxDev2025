cmake_minimum_required(VERSION 3.10)
project(Rhasher C)


find_path(RHASH_INCLUDE_DIR rhash.h)
find_library(RHASH_LIBRARY rhash)

if (NOT RHASH_LIBRARY OR NOT RHASH_INCLUDE_DIR)

	set(RHASH_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/RHash-master/librhash")
	set(RHASH_LIBRARY "${RHASH_INCLUDE_DIR}/librhash.so")

	if (EXISTS "${RHASH_LIBRARY}" AND EXISTS "${RHASH_INCLUDE_DIR}/rhash.h")
		message(STATUS "rhash lib detected")
	else()
        	message(FATAL_ERROR "rhash lib not found")
    	endif()
endif()

option(USE_READLINE "getline switched to getline" OFF)
message(STATUS "USE_READLINE=${USE_READLINE}")

add_executable(rhasher rhasher.c)

if(USE_READLINE)
	find_path(READLINE_INCLUDE_DIR readline/readline.h)
	find_library(READLINE_LIBRARY NAMES readline)
	if(READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
		include_directories(${READLINE_INCLUDE_DIR})
		target_link_libraries(rhasher ${READLINE_LIBRARY})
		target_compile_definitions(rhasher PRIVATE USE_READLINE)
	else()
		message(STATUS "readline lib not found. Program will be without readline.")
		set(USE_READLINE OFF)
	endif()	
endif()

include_directories(${RHASH_INCLUDE_DIR})


target_link_libraries(rhasher ${RHASH_LIBRARY})

enable_testing()


add_test(NAME SHA1 COMMAND echo 'SHA1 test.txt' | ./rhasher | awk '{print $NF}' | diff - <(sha1sum test.txt | cut -d ' ' -f1))

add_test(NAME MD5 COMMAND echo 'MD5 test.txt' | ./rhasher | awk '{print $NF}' | diff - <(md5sum test.txt | cut -d ' ' -f1))

add_test(NAME sha1 COMMAND echo 'sha1 test.txt' | ./rhasher | awk '{print $NF}' | diff - <(openssl dgst -sha1 -binary test.txt | base64))

add_test(NAME md5 COMMAND echo 'sha1 test.txt' | ./rhasher | awk '{print $NF}' | diff - <(openssl dgst -md5 -binary test.txt | base64))

add_custom_target(distclean COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake_clean.cmake)
