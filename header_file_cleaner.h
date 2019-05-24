#ifndef HEADER_FILE_CLEANER_H
#define HEADER_FILE_CLEANER_H

class QFile;
class QString;

class HeaderFileCleaner {
 public:
  static int FixHeaderGuardsInFile(const QString& file_name, bool is_edit_mode);
  static QString ReadContentsOfSourceFile(const QString& file_name);

 private:
  static void WriteChangesToFile(QString parsed_file,
                                 QString file_contents,
                                 const QString& file_name);
};

#endif  // HEADER_FILE_CLEANER_H
