# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Hh_Dest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Hh_Dest_autogen.dir/ParseCache.txt"
  "Hh_Dest_autogen"
  )
endif()
