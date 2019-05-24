#ifndef COMMENT_IN_FILE_START_FINDER_H
#define COMMENT_IN_FILE_START_FINDER_H

#include <QPair>

class QString;

class CommentInFileStartFinder
{
public:
    static QString FindCommentInFileStart(const QString& file_text);
    static QPair<QString, QString> RemoveCommentsFromBeginningOfFile(const QString& file_text);
};

#endif // COMMENT_IN_FILE_START_FINDER_H
