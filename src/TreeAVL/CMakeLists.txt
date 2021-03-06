cmake_minimum_required(VERSION 3.7)

project(TreeAVL VERSION 0.0.1 LANGUAGES C)

add_library(TreeAVL SHARED TreeAVL.c TreeAVL.h )
add_library(TreeAVLStatic STATIC TreeAVL.c TreeAVL.h)
set_target_properties(TreeAVL PROPERTIES
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_VERSION_MAJOR}
)
set_target_properties(TreeAVLStatic PROPERTIES
	OUTPUT_NAME TreeAVL
)

# La librarie efence (ElectricFence https://en.wikipedia.org/wiki/Electric_Fence)
# permet de détecter au plus près les erreurs d'accès aux pointeurs,
# les erreurs d'allocations...
# Il est préférable de forcer l'utilisation de la librairie statique en utilisant
# les variables prédéfinies de cmake
# - CMAKE_STATIC_LIBRARY_PREFIX ("lib" sous linux)
# - CMAKE_STATIC_LIBRARY_SUFFIX (".a" sous linux)
# De plus, il est nécessaire que cette librairie soit la dernière à être ajoutée
find_library(EFENCE_LIB ${CMAKE_STATIC_LIBRARY_PREFIX}efence${CMAKE_STATIC_LIBRARY_SUFFIX})
if(EFENCE_LIB)
    # Ajout de la librairie efence en mode Debug seulement
    target_link_libraries(TreeAVL debug ${EFENCE_LIB})
endif()

install(
	TARGETS TreeAVL TreeAVLStatic
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)

install(
	FILES TreeAVL.h
	DESTINATION include
)

install(
	FILES TreeAVLConfig.cmake
	DESTINATION cmake
)

find_program(VALGRIND "valgrind")
# Récupération dans la variable FILES des fichiers de test
file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")

# Pour tous les fichiers de test
foreach(FILENAME ${FILES})
	# Récupération dans la variable SRC du nom sans le préfixe du dossier
	get_filename_component(SRC ${FILENAME} NAME)
	# Récupération dans la variable TEST du nom sans le préfixe du dossier
	# et sans le suffixe
	get_filename_component(TEST ${FILENAME} NAME_WE)
	# Ajout d'un exécutable dépendant également de connect4.h et
	add_executable(${TEST} ${SRC} TreeAVL.h)
	# Précision de l'ordre de construction: le programme de test doit se faire
	# après la librairie
	add_dependencies(${TEST} TreeAVL)
	# Assemblage du programme de test avec la librairie connect4
	target_link_libraries(${TEST} TreeAVL)
	if(VALGRIND)
		# Ajout d'un test en utilisant valgrind
		add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
		# Ajout d'un test normal
    	add_test("${TEST}[normal]" ./${TEST})
    else()
    	# Ajout d'un test simple
    	add_test("${TEST}" ./${TEST})
	endif()
endforeach()


# add_executable(test-TreeAVL test-TreeAVL.c TreeAVL.h)
# add_dependencies(test-TreeAVL TreeAVL)
# target_link_libraries(test-TreeAVL TreeAVL)

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_GENERATOR "ZIP")
set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_IGNORE_FILES "~$;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)

