#include "comment_in_file_start_finder.h"

#include <QString>

QString
CommentInFileStartFinder::FindCommentInFileStart(const QString &file_text) {
  QString comment;
  if (file_text.startsWith("/*")) {
    QString line_break = "*/";
    int closing_comment_position = file_text.indexOf(line_break);
    comment = file_text.left(closing_comment_position + line_break.size());
  } else if (file_text.startsWith("//")) {
    int line_end_position = file_text.indexOf("\n");
    comment = file_text.left(line_end_position + 1);
  }
  if (comment != "") {
    QString truncated_file_text =
        file_text.right(file_text.count() - comment.count());
    comment.append(FindCommentInFileStart(truncated_file_text));
  }

  return comment;
}

QPair<QString, QString>
CommentInFileStartFinder::RemoveCommentsFromBeginningOfFile(
    const QString &file_text) {
  QString comment = FindCommentInFileStart(file_text);
  QString main_body = file_text.left(comment.count());
  return {comment, main_body};
}
