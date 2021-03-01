#include <QString>

#include <QDebug>

#include <doctest.h>

#include <comment_in_file_start_finder.h>
#include <header_file_cleaner.h>

SCENARIO("checking header guards") {
  GIVEN("name of a file with wrong header guards") {
    QString wrong_file_path = ":/files/examples/wrong_example.h";

    WHEN("run the file through checker function in check mode") {
      auto function_result =
          HeaderFileCleaner::FixHeaderGuardsInFile(wrong_file_path, false);
      THEN("function should return false") { CHECK_FALSE(function_result); }
    }
  }
}

SCENARIO("fixing the files with the comments in the beginning") {
  GIVEN("name of a file with wrong header guards") {
    QString commented_file_path = ":/files/examples/example_with_comment.h";
    const auto file_contents =
        HeaderFileCleaner::ReadContentsOfSourceFile(commented_file_path);

    WHEN("run the file through checker function in check mode") {
      const auto comment =
          CommentInFileStartFinder::FindCommentInFileStart(file_contents);
      const QString reference_comment =
          "// This is a comment.\n\n/* This is another comment.*/\n\n\n";
      THEN("Comment should be equal to reference ") {
        REQUIRE(comment == reference_comment);
      }
    }
  }
}
