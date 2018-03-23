#include "header_file_cleaner.h"

#include <QDebug>
#include <QFileInfo>
#include <QRegExp>

#include <QFile>

int HeaderFileFixer::FixHeaderGuardsInFile(const QString& file_name,
                                           bool is_edit_mode) {
  QString file_contents = ReadContentsOfSourceFile(file_name);

  QFileInfo working_file_info(file_name);
  QString short_file_path = working_file_info.fileName();

  if (is_edit_mode) {
    QString parsed_file = FixHeaderGuardsInText(file_contents, short_file_path);

    WriteChangesToFile(parsed_file, file_contents, file_name);

    return 0;
  }

  bool is_guard_ok = IsFileHeaderGuardValid(file_contents, short_file_path);
  return is_guard_ok ? 0 : 1;
}

QString HeaderFileFixer::ReadContentsOfSourceFile(const QString& file_name) {
  QFile working_file(file_name);
  working_file.open(QIODevice::ReadOnly);
  QString file_contents = working_file.readAll();
  working_file.close();
  return file_contents;
}

void HeaderFileFixer::WriteChangesToFile(QString parsed_file,
                                         QString file_contents,
                                         const QString& file_name) {
  if (parsed_file != file_contents) {
    QFile working_file(file_name);
    working_file.open(QIODevice::WriteOnly);
    QTextStream out(&working_file);
    out << parsed_file;

    working_file.close();
  }
}

bool HeaderFileFixer::IsFileHeaderGuardValid(const QString& source_file_text,
                                             const QString& short_file_name) {
  QString header_guard_from_file =
      ContructHeaderGuardForFileWithName(short_file_name);

  QString first_guard = "#ifndef " + header_guard_from_file;
  QString second_guard = "#define " + header_guard_from_file;
  QString third_guard = "#endif  // " + header_guard_from_file;

  if (!source_file_text.contains(first_guard) ||
      !source_file_text.contains(second_guard) ||
      !source_file_text.contains(third_guard)) {
    return false;
  }

  return true;
}

QString HeaderFileFixer::FixHeaderGuardsInText(const QString& source_file_text,
                                               const QString& short_file_name) {
  QString return_string = source_file_text;

  QString header_guard = ReadHeaderGuardFromText(source_file_text);
  QString header_guard_from_file =
      ContructHeaderGuardForFileWithName(short_file_name);

  if (return_string.count(header_guard) > 3 ||
      !source_file_text.contains("#define " + header_guard)) {
    return "";
  }

  return_string.replace(header_guard, header_guard_from_file);

  QString endif_string = "#endif";
  int last_endif_position = return_string.lastIndexOf(endif_string);
  return_string.truncate(last_endif_position + endif_string.count());
  return_string.append("  // " + header_guard_from_file + "\n");

  return return_string;
}

QString HeaderFileFixer::ReadHeaderGuardFromText(const QString& text) {
  QString header_guard_prefix = "#ifndef ";
  int header_guard_position = text.indexOf(header_guard_prefix);
  int header_guard_start_position =
      header_guard_position + header_guard_prefix.count();
  int space_position =
      text.indexOf(QRegExp(" |\n"), header_guard_start_position);

  return text.mid(header_guard_start_position,
                  space_position - header_guard_start_position);
}

QString HeaderFileFixer::ContructHeaderGuardForFileWithName(
    const QString& short_file_name) {
  QString updated_file_name = short_file_name;
  updated_file_name.replace(".", "_");
  updated_file_name = updated_file_name.toUpper();

  return updated_file_name;
}
