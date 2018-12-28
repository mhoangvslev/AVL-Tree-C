# Définit 3 variables
# - TREERB_INCLUDE_DIRS pour les dossiers d'entête
# - TREERB_LINK_DIRS pour les dossiers des librairies
# - TREERB_LIBRARIES pour les librairies

get_filename_component(TREERB_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)
get_filename_component(TREERB_DIR "${TREERB_CMAKE_DIR}" DIRECTORY)
set(TREERB_INCLUDE_DIRS "${TREERB_DIR}/include")
set(TREERB_LINK_DIRS "${TREERB_DIR}/lib" "${TREERB_DIR}/bin")
# set(TREERB_LIBRARIES polynomial)

