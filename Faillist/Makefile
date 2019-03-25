##
## Makefile 
##
## Made by Jonathan Bruel
##

CC	= gcc

-std=c11

all: libfaillist_ut.a

LIBRARYPATH = /usr/lib/

SOURCES =   ./src/file_handling/file_reader.c	                                    \
            ./src/file_handling/jsoneq.c                                            \
            ./src/file_handling/pars_faillure.c                                     \
            ./src/file_handling/pars_raised_error.c                                 \
            ./src/report/failure/failure_id/write_failure_id.c                      \
            ./src/report/failure/id_component_failure/write_id_component_failure.c  \
            ./src/report/failure/write_failure.c                                    \
            ./src/report/failure/write_failure_date.c                               \
            ./src/report/id_plane/write_id_plane.c                                  \
            ./src/report/type_plane/write_type_plane.c                              \
            ./src/report/init_report.c                                              \
            ./src/report/open_report.c                                              \
            ./src/report/write_report.c                                             \
            ./src/tool/embedded_localtime.c                                         \
            ./src/tool/is_number.c                                                  \
            ./lib/jsmn/src/jsmn.c

SOURCES_OBJS =  $(SOURCES:.c=.o)

libfaillist_ut.a: $(SOURCES_OBJS)
	ar ruv $@ $(SOURCES_OBJS)
	ranlib $@

NOVAPROVA_CFLAGS =  $(shell pkg-config --cflags novaprova)

NOVAPROVA_LIBS =    $(shell pkg-config --libs novaprova)

CFLAGS =    -g $(NOVAPROVA_CFLAGS) -std=c11 -Wall -W -Wextra -I./include -I./lib/jsmn/include -fprofile-arcs -ftest-coverage -Wno-unused-function

LDFLAGS	+=  -fprofile-arcs -ftest-coverage

test: testrunner
	./coverage_test

coverage: testrunner
	./coverage_test
	gcov -c -u -b ${SOURCES_OBJS}
	lcov --rc lcov_branch_coverage=1 --directory . -c -o coverage.info -t "coverage_result" -b .
	lcov --rc lcov_branch_coverage=1 --remove coverage.info "/usr/include/*" "/usr/local/*" "/opt/*" "*/test/*" "*/include/c++/*" "*/lib/*" -o filtered_coverage.info
	genhtml filtered_coverage.info  --branch-coverage --output-directory out_coverage.html
	lcov --list filtered_coverage.info

TEST_SOURCE =   ./test/test_file_handling/test_file_reader/test_file_reader.c \
        		./test/test_file_handling/test_jsoneq/test_jsoneq.c \
        		./test/test_file_handling/test_pars_faillure/test_pars_faillure.c \
        		./test/test_file_handling/test_pars_raised_error/test_pars_raised_error.c \
        		./test/test_report/test_failure/test_failure_id/test_write_failure_id/test_write_failure_id.c \
        		./test/test_report/test_failure/test_id_component_failure/test_write_id_component_failure/test_write_id_component_failure.c \
        		./test/test_report/test_failure/test_write_failure/test_write_failure.c \
        		./test/test_report/test_failure/test_write_failure_date/test_write_failure_date.c \
        		./test/test_report/test_id_plane/test_write_id_plane/test_write_id_plane.c \
        		./test/test_report/test_type_plane/test_write_type_plane/test_write_type_plane.c \
        		./test/test_report/test_init_report/test_init_report.c \
        		./test/test_report/test_open_report/test_open_report.c \
        		./test/test_report/test_write_report/test_write_report.c \
        		./test/test_tool/test_embedded_localtime/test_embedded_localtime.c \
        		./test/test_tool/test_is_number/test_is_number.c

TEST_OBJS   =   $(TEST_SOURCE:.c=.o)

COV_SOURCES	=   $(SOURCES:.c=.gcno) $(SOURCES:.c=.gcda)
COV_TEST	=   $(TEST_SOURCE:.c=.gcno) $(TEST_SOURCE:.c=.gcda)

testrunner: $(TEST_OBJS) libfaillist_ut.a
	$(LINK.c) -o $@ $(TEST_OBJS) libfaillist_ut.a $(NOVAPROVA_LIBS)
	$(CC) $(LDFLAGS) $(TEST_OBJS) -I./lib/jsmn/include -L$(LIBRARYPATH) -o coverage_test -lgcov libfaillist_ut.a $(NOVAPROVA_LIBS)

clean:
	$(RM) -rf testrunner coverage_test libfaillist_ut.a $(TEST_OBJS) $(SOURCES_OBJS) $(COV_SOURCES) $(COV_TEST) *.html *.gcov *.info out_coverage.html


.PHONY: all 

