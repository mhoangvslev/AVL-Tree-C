# Définit 3 variables
# - TREEAVL_INCLUDE_DIRS pour les dossiers d'entête
# - TREEAVL_LINK_DIRS pour les dossiers des librairies
# - TREEAVL_LIBRARIES pour les librairies

get_filename_component(TREEAVL_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)
get_filename_component(TREEAVL_DIR "${TREEAVL_CMAKE_DIR}" DIRECTORY)
set(TREEAVL_INCLUDE_DIRS "${TREEAVL_DIR}/include")
set(TREEAVL_LINK_DIRS "${TREEAVL_DIR}/lib" "${TREEAVL_DIR}/bin")
# set(TREEAVL_LIBRARIES polynomial)

