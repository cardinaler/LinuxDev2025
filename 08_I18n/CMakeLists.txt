cmake_minimum_required(VERSION 3.10)
project(Predictior C)

add_subdirectory(src)

set(PO_DIR "${CMAKE_SOURCE_DIR}/po")

add_custom_target(update_po
	COMMAND ${CMAKE_COMMAND} -E make_directory ${PO_DIR}
	COMMAND xgettext -k_ --from-code=UTF-8 -o ${PO_DIR}/prog.pot ${CMAKE_SOURCE_DIR}/src/prog.c
	COMMAND msgmerge --update ${PO_DIR}/ru.po ${PO_DIR}/prog.pot
	COMMENT "Update done."
	VERBATIM
)
add_custom_target(compile_po ALL
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/locale
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/locale/ru/LC_MESSAGES
	COMMAND msgfmt -o ${CMAKE_BINARY_DIR}/locale/ru/LC_MESSAGES/prog.mo ${PO_DIR}/ru.po
	COMMENT "Compile done."
	VERBATIM
)

add_custom_target(clean_locals
	COMMAND ${CMAKE_COMMAND} -E remove ${PO_DIR}/prog.pot
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/locale
	COMMENT "Clean done."
)
	
