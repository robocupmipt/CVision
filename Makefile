CONFIG_NAME_FOR_TESTING		= linux-sdk
CONFIG_NAME_FOR_ROBOT		= atom-sdk
IP				    = 192.168.1.2
CMakeListsTest		= CMakeListsTest.txt
CMakeListsLib		= CMakeListsLib.txt
CMakeLists			= CMakeLists.txt

all: compil_for_testing compil_for_robot run

compil_for_testing: $(CMakeListsTest)
	cp -f $(CMakeListsTest) $(CMakeLists)
	qibuild configure -c $(CONFIG_NAME_FOR_TESTING)
	qibuild make      -c $(CONFIG_NAME_FOR_TESTING)

compil_for_robot: $(CMakeListsLib)
	cp -f $(CMakeListsLib) $(CMakeLists)
	qibuild configure -c $(CONFIG_NAME_FOR_ROBOT)
	qibuild make      -c $(CONFIG_NAME_FOR_ROBOT)

make_test: compil_for_testing run

make_lib: compil_for_robot

run:
	./build-$(CONFIG_NAME_FOR_TESTING)/sdk/bin/remotevision --pip ${IP}