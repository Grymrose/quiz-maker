CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(QUIZ_MAKER)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

INCLUDE_DIRECTORIES(
	header
	test/googletest/googletest/include
)

SET(SOURCES
	src/User.cpp
	src/Instructor.cpp
	src/Student.cpp
	src/Question.cpp
	src/QuestionOutput.cpp
	src/QuestionMCQ.cpp
	src/QuestionFRQ.cpp
	src/QuestionTF.cpp
	src/QuestionPool.cpp
	src/Quiz.cpp
	src/QuizSession.cpp
)

ADD_EXECUTABLE(TestProgram
	${SOURCES}
	test/TestQuestionProgram.cpp
)

TARGET_COMPILE_OPTIONS(TestProgram
	PRIVATE -g
)

ADD_EXECUTABLE(RunQuestionTests
	${SOURCES}
	test/TestQuestion.cpp
)

TARGET_COMPILE_OPTIONS(RunQuestionTests
	PRIVATE -g
)

ADD_EXECUTABLE(RunQuestionPoolTests
	${SOURCES}
	test/TestQuestionPool.cpp
)

TARGET_COMPILE_OPTIONS(RunQuestionPoolTests
	PRIVATE -g
)

ADD_EXECUTABLE(RunUserTests
	${SOURCES}
	test/TestUser.cpp
)

TARGET_COMPILE_OPTIONS(RunUserTests
	PRIVATE -g
)

#SET_TARGET_PROPERTIES(RunAllTests
#	PROPERTIES
#	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
#)

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/test/googletest)
target_link_libraries(RunQuestionTests gtest gtest_main)
target_link_libraries(RunQuestionPoolTests gtest gtest_main)
target_link_libraries(RunUserTests gtest gtest_main)
