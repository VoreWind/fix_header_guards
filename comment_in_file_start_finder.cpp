#include "comment_in_file_start_finder.h"

#include <QString>

QString CommentInFileStartFinder::FindCommentInFileStart(const QString &file_text)
{
    if (file_text.startsWith("/*")){
        int closing_comment_position = file_text.indexOf("*/");
    }
}
