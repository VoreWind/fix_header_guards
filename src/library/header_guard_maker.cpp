#include <header_guard_maker.h>

#include <QRegExp>
#include <QString>

QString HeaderGuardMaker::ReadHeaderGuardFromText(
    const QString& text) noexcept {
  QString header_guard_prefix = "#ifndef ";
  const auto header_guard_position = text.indexOf(header_guard_prefix);
  const auto header_guard_start_position =
      header_guard_position + header_guard_prefix.count();
  const auto space_position =
      text.indexOf(QRegExp(" |\n"), header_guard_start_position);

  return text.mid(header_guard_start_position,
                  space_position - header_guard_start_position);
}

QString HeaderGuardMaker::ContructHeaderGuardForFileWithName(
    const QString& short_file_name) noexcept {
  auto updated_file_name = short_file_name;
  updated_file_name.replace(".", "_");
  updated_file_name = updated_file_name.toUpper();

  return updated_file_name;
}
