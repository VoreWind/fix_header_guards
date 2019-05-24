#include <QString>

#include <QDebug>

#include <doctest.h>

#include <comment_in_file_start_finder.h>
#include <header_file_cleaner.h>

SCENARIO("Checking header guards") {
  GIVEN("Name of a file with wrong header guards") {
    QString wrong_file_path =
        "../fix_header_guards-master/examples/wrong_example.h";

    WHEN("Run the file through checker function in check mode") {
      auto function_result =
          HeaderFileCleaner::FixHeaderGuardsInFile(wrong_file_path, false);
      THEN("Function should return 1 ") { REQUIRE(function_result == 1); }
    }
  }
}

SCENARIO("Fixing the files with the comments in the beginning") {
  GIVEN("Name of a file with wrong header guards") {
    QString commented_file_path =
        "../fix_header_guards-master/examples/example_with_comment.h";
    QString file_contents =
        HeaderFileCleaner::ReadContentsOfSourceFile(commented_file_path);

    WHEN("Run the file through checker function in check mode") {
      auto comment =
          CommentInFileStartFinder::FindCommentInFileStart(file_contents);
      THEN("Function should return 1 ") { REQUIRE(comment != ""); }
    }
  }
}
