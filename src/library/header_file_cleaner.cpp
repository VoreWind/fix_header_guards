#include <header_file_cleaner.h>

#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QPair>
#include <QRegExp>
#include <QString>

#include <comment_in_file_start_finder.h>
#include <header_guard_fixer.h>

bool HeaderFileCleaner::FixHeaderGuardsInFile(const QString& file_name,
                                              bool is_edit_mode) noexcept {
  auto file_contents = ReadContentsOfSourceFile(file_name);

  QFileInfo working_file_info(file_name);
  const auto short_file_path = working_file_info.fileName();

  auto separated_file_text =
      CommentInFileStartFinder::RemoveCommentsFromBeginningOfFile(
          file_contents);

  if (is_edit_mode) {
    QString parsed_file = HeaderGuardFixer::FixHeaderGuardsInText(
        separated_file_text.second, short_file_path);

    file_contents = separated_file_text.first + separated_file_text.second;
    WriteChangesToFile(parsed_file, file_contents, file_name);

    return true;
  }

  return HeaderGuardFixer::IsFileHeaderGuardValid(separated_file_text.second,
                                                  short_file_path);
}

QString HeaderFileCleaner::ReadContentsOfSourceFile(
    const QString& file_name) noexcept {
  QFile working_file(file_name);
  working_file.open(QIODevice::ReadOnly);
  const auto file_contents = working_file.readAll();
  working_file.close();
  return file_contents;
}

void HeaderFileCleaner::WriteChangesToFile(const QString& parsed_file,
                                           const QString& file_contents,
                                           const QString& file_name) noexcept {
  if (parsed_file != file_contents) {
    QFile working_file(file_name);
    working_file.open(QIODevice::WriteOnly);
    QTextStream out(&working_file);
    out << parsed_file;

    working_file.close();
  }
}
