#include <header_guard_fixer.h>

#include <QString>

#include <header_guard_maker.h>

bool HeaderGuardFixer::IsFileHeaderGuardValid(const QString& source_file_text,
                                              const QString& short_file_name) {
  QString header_guard_from_file =
      HeaderGuardMaker::ContructHeaderGuardForFileWithName(short_file_name);

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

QString HeaderGuardFixer::FixHeaderGuardsInText(
    const QString& source_file_text, const QString& short_file_name) {
  QString return_string = source_file_text;

  QString header_guard =
      HeaderGuardMaker::ReadHeaderGuardFromText(source_file_text);
  QString header_guard_from_file =
      HeaderGuardMaker::ContructHeaderGuardForFileWithName(short_file_name);

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
