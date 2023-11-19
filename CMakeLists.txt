CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(QUIZ_MAKER)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

INCLUDE_DIRECTORIES(header)

SET(SOURCES
	src/Question.cpp
	srd/QuestionOutput.cpp
	src/QuestionMCQ.cpp
	src/QuestionFRQ.cpp
    src/QuestionTF.cpp
	test/TestQuestion.cpp
)

ADD_EXECUTABLE(TestProgram
	src/Question.cpp
	src/QuestionMCQ.cpp
	src/QuestionFRQ.cpp
	test/TestQuestionProgram.cpp
)

ADD_EXECUTABLE(RunAllTests
	${SOURCES}
)

TARGET_COMPILE_OPTIONS(TestProgram
	PRIVATE -g
)

#SET_TARGET_PROPERTIES(RunAllTests
#	PROPERTIES
#	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
#)

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/test/googletest)
target_link_libraries(RunAllTests gtest gtest_main)