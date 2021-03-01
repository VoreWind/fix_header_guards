#ifndef HEADER_FILE_CLEANER_H
#define HEADER_FILE_CLEANER_H

class QFile;
class QString;

class HeaderFileCleaner {
 public:
  static bool FixHeaderGuardsInFile(const QString& file_name,
                                    bool is_edit_mode) noexcept;
  static QString ReadContentsOfSourceFile(const QString& file_name) noexcept;

 private:
  static void WriteChangesToFile(const QString& parsed_file,
                                 const QString& file_contents,
                                 const QString& file_name) noexcept;
};

#endif  // HEADER_FILE_CLEANER_H
