#include "comment_in_file_start_finder.h"

#include <QRegExp>
#include <QString>

QString CommentInFileStartFinder::FindCommentInFileStart(
    const QString& file_text) noexcept {
  QString line_break;
  if (file_text.startsWith("/*")) {
    line_break = "\\*/";
  } else if (file_text.startsWith("//")) {
    line_break = "\n";
  }
  auto comment = GetComment(file_text, line_break);

  if (comment != "") {
    const auto truncated_file_text =
        file_text.right(file_text.count() - comment.count());
    comment.append(FindCommentInFileStart(truncated_file_text));
  }

  return comment;
}

QPair<QString, QString>
CommentInFileStartFinder::RemoveCommentsFromBeginningOfFile(
    const QString& file_text) noexcept {
  const auto comment = FindCommentInFileStart(file_text);
  const auto main_body = file_text.right(file_text.count() - comment.count());

  return {comment, main_body};
}

QString CommentInFileStartFinder::GetComment(
    const QString& file_text, const QString& line_break) noexcept {
  QRegExp closing_statement(line_break + "\n*");

  const auto line_end_position = closing_statement.indexIn(file_text, 0);
  return file_text.left(line_end_position + closing_statement.matchedLength());
}
