# Définit 3 variables
# - NTREE_INCLUDE_DIRS pour les dossiers d'entête
# - NTREE_LINK_DIRS pour les dossiers des librairies
# - NTREE_LIBRARIES pour les librairies

get_filename_component(NTREE_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)
get_filename_component(NTREE_DIR "${NTREE_CMAKE_DIR}" DIRECTORY)
set(NTREE_INCLUDE_DIRS "${NTREE_DIR}/include")
set(NTREE_LINK_DIRS "${NTREE_DIR}/lib" "${NTREE_DIR}/bin")
# set(NTREE_LIBRARIES polynomial)

