cmake_minimum_required (VERSION 2.8)

# ############################ #
# tests for dds2png executable #
# ############################ #

# add tests for --version and --help parameters
# default help parameter "--help"
add_test(NAME dds2png_help
         COMMAND $<TARGET_FILE:dds2png> --help)

# short help parameter with question mark "-?"
add_test(NAME dds2png_help_question_mark
         COMMAND $<TARGET_FILE:dds2png> -?)

# Windows-style help parameter "/?"
add_test(NAME dds2png_help_question_mark_windows
         COMMAND $<TARGET_FILE:dds2png> /?)

# parameter to show version number
add_test(NAME dds2png_version
         COMMAND $<TARGET_FILE:dds2png> --version)
