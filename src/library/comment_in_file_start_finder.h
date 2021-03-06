#ifndef COMMENT_IN_FILE_START_FINDER_H
#define COMMENT_IN_FILE_START_FINDER_H

#include <QPair>

class QString;

class CommentInFileStartFinder {
 public:
  static QString FindCommentInFileStart(const QString& file_text) noexcept;
  static QPair<QString, QString> RemoveCommentsFromBeginningOfFile(
      const QString& file_text) noexcept;

 private:
  static QString GetComment(const QString& file_text,
                            const QString& line_break) noexcept;
};

#endif  // COMMENT_IN_FILE_START_FINDER_H
