# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjetCalculatriceIHM_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjetCalculatriceIHM_autogen.dir\\ParseCache.txt"
  "ProjetCalculatriceIHM_autogen"
  )
endif()
