#include <QString>

#include <QDebug>

#include <doctest.h>

#include <comment_in_file_start_finder.h>
#include <header_file_cleaner.h>

SCENARIO("checking header guards") {
  GIVEN("name of a file with wrong header guards") {
    QString wrong_file_path =
        "../fix_header_guards-master/examples/wrong_example.h";

    WHEN("run the file through checker function in check mode") {
      auto function_result =
          HeaderFileCleaner::FixHeaderGuardsInFile(wrong_file_path, false);
      THEN("function should return 1") { CHECK(function_result == 1); }
    }
  }
}

SCENARIO("fixing the files with the comments in the beginning") {
  GIVEN("name of a file with wrong header guards") {
    QString commented_file_path =
        "../fix_header_guards-master/examples/example_with_comment.h";
    QString file_contents =
        HeaderFileCleaner::ReadContentsOfSourceFile(commented_file_path);

    WHEN("run the file through checker function in check mode") {
      auto comment =
          CommentInFileStartFinder::FindCommentInFileStart(file_contents);
      qDebug() << comment;
      THEN("Function should return 1 ") { REQUIRE(comment != ""); }
    }
  }
}
