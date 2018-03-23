#ifndef HEADER_GUARD_FIXER_H
#define HEADER_GUARD_FIXER_H

#include <QString>

class QFile;

class HeaderFileFixer {
 public:
  static int FixHeaderGuardsInFile(const QString& file_name, bool is_edit_mode);

 private:
  static QString ReadHeaderGuardFromText(const QString& text);
  static QString ContructHeaderGuardForFileWithName(
      const QString& short_file_name);

  static bool IsFileHeaderGuardValid(const QString& source_file_text,
                                     const QString& short_file_name);

  static QString FixHeaderGuardsInText(const QString& source_file_text,
                                       const QString& short_file_name);
  static void WriteChangesToFile(QString parsed_file,
                                 QString file_contents,
                                 const QString& file_name);
  static QString ReadContentsOfSourceFile(const QString& file_name);
};

#endif  // HEADER_GUARD_FIXER_H
