#include <QString>

#include <doctest.h>

#include <header_file_cleaner.h>

SCENARIO("Checking header guards") {
  GIVEN("Name of a file with wrong header guards") {
    QString wrong_file_path = "../examples/wrong_example.h";

    WHEN("Run the file through checker function in check mode") {
      auto function_result =
          HeaderFileFixer::FixHeaderGuardsInFile(wrong_file_path, false);
      THEN("Function should return 1 ") { REQUIRE(function_result == 1); }
    }
  }
}
