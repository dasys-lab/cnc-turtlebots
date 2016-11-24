file(REMOVE_RECURSE
  "wumpus_simulator_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/roscpp_generate_messages_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
