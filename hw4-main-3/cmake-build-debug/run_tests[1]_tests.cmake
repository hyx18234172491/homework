add_test([=[DFSTest.TextbookExampleTopologicalSort]=]  D:/code/hw_4_foreign/homework/hw4-main-3/cmake-build-debug/run_tests.exe [==[--gtest_filter=DFSTest.TextbookExampleTopologicalSort]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DFSTest.TextbookExampleTopologicalSort]=]  PROPERTIES WORKING_DIRECTORY D:/code/hw_4_foreign/homework/hw4-main-3/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DFSTest.TextbookExampleDiscoveryTimes]=]  D:/code/hw_4_foreign/homework/hw4-main-3/cmake-build-debug/run_tests.exe [==[--gtest_filter=DFSTest.TextbookExampleDiscoveryTimes]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DFSTest.TextbookExampleDiscoveryTimes]=]  PROPERTIES WORKING_DIRECTORY D:/code/hw_4_foreign/homework/hw4-main-3/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  run_tests_TESTS DFSTest.TextbookExampleTopologicalSort DFSTest.TextbookExampleDiscoveryTimes)
